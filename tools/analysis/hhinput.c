/* hhinput: minimal Zilmar-spec N64 input plugin. Reads work/debug/hh_keys.bin (2 bytes,
 * N64 little-host-order button mask: A=0x8000 B=0x4000 Z=0x2000 START=0x1000
 * DPad U/D/L/R=0x0800/0x0400/0x0200/0x0100, CUDLR=0x0010/0x0020/0x0040/0x0080,
 * R/L=0x0008/0x0004) and maps to mupen's BUTTONS.Value bit order. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HOST_API_VERSION 0x020200
#define PLUGIN_VERSION   0x020000
#define CONT_TYPE_STANDARD 0

typedef int m64p_error;
typedef void *m64p_dynlib_handle;

typedef struct {
    int Present;
    int RawData;
    int Plugin;
    int Type;
} CONTROL;
typedef struct {
    CONTROL *Controls;
} CONTROL_INFO;

typedef union {
    unsigned int Value;
    struct {
        unsigned R_DPAD       : 1;
        unsigned L_DPAD       : 1;
        unsigned D_DPAD       : 1;
        unsigned U_DPAD       : 1;
        unsigned START_BUTTON : 1;
        unsigned Z_TRIG       : 1;
        unsigned B_BUTTON     : 1;
        unsigned A_BUTTON     : 1;
        unsigned R_CBUTTON    : 1;
        unsigned L_CBUTTON    : 1;
        unsigned D_CBUTTON    : 1;
        unsigned U_CBUTTON    : 1;
        unsigned R_TRIG       : 1;
        unsigned L_TRIG       : 1;
        unsigned Reserved1    : 1;
        unsigned Reserved2    : 1;
        signed   X_AXIS       : 8;
        signed   Y_AXIS       : 8;
    };
} BUTTONS;

/* ---- plugin exports (Zilmar spec) ---- */
void PluginShutdown(void);
m64p_error PluginStartup(m64p_dynlib_handle core, void *config, void *dbg);
void GetKeys(int Control, BUTTONS *Keys);
void ControllerCommand(int Control, unsigned char *Cmd);
void ReadController(int Control, unsigned char *Cmd);
void InitiateControllers(CONTROL_INFO ControlInfo);
int RomOpen(void);
void RomClosed(void);
void SDL_KeyDown(int kc, int ks) { (void)kc; (void)ks; }
void SDL_KeyUp(int kc, int ks)   { (void)kc; (void)ks; }

static CONTROL controls[4];
static int g_keys_loaded = 0;

void PluginShutdown(void) {}

/* PluginGetVersion must match m64p_plugin.h exactly */
m64p_error PluginGetVersion(int *PluginType, int *PluginVersion, int *APIVersion,
                            const char **PluginNamePtr, int *Capabilities)
{
    if (PluginType)      *PluginType = 4;      /* M64PLUGIN_INPUT */
    if (PluginVersion)   *PluginVersion = PLUGIN_VERSION >> 16;
    if (APIVersion)      *APIVersion = HOST_API_VERSION;
    if (PluginNamePtr)   *PluginNamePtr = "hhinput";
    if (Capabilities)    *Capabilities = 0;
    return 0;
}

m64p_error PluginStartup(m64p_dynlib_handle core, void *config, void *dbg)
{
    (void)core; (void)config; (void)dbg;
    return 0;
}

void InitiateControllers(CONTROL_INFO ControlInfo)
{
    memset(controls, 0, sizeof(controls));
    for (int i = 0; i < 4; i++) {
        controls[i].Present = (i == 0) ? 1 : 0;
        controls[i].RawData = 0;
        controls[i].Plugin  = 0;  /* PLUGIN_NONE */
        controls[i].Type    = CONT_TYPE_STANDARD;
    }
    if (ControlInfo.Controls)
        memcpy(ControlInfo.Controls, controls, sizeof(controls));
}

int RomOpen(void) { return 1; }
void RomClosed(void) {}

/* work/debug/hh_keys.bin format: 4 bytes BE: [0]=mask lo, [1]=mask hi, [2]=Y_AXIS, [3]=X_AXIS */
/* (mask is the N64 little-host-order button bits used above; a 2-byte file is
 *  treated as mask with zeroed analog, keeping old callers working). */
static void read_keys(unsigned short *m_out, signed char *y_out, signed char *x_out)
{
    unsigned short m = 0;
    signed char y = 0, x = 0;
    FILE *f = fopen("work/debug/hh_keys.bin", "rb");
    if (f) {
        unsigned char b[4] = {0, 0, 0, 0};
        int n = (int)fread(b, 1, 4, f);
        if (n < 2) { /* corrupted: reset */ }
        else {
            m = (b[0] << 8) | b[1];
            if (n >= 4) { y = (signed char)b[2]; x = (signed char)b[3]; }
        }
        fclose(f);
    }
    g_keys_loaded = 1;
    if (m_out) *m_out = m;
    if (y_out) *y_out = y;
    if (x_out) *x_out = x;
}

void GetKeys(int Control, BUTTONS *Keys)
{
    Keys->Value = 0;
    Keys->X_AXIS = 0;
    Keys->Y_AXIS = 0;
    if (Control != 0) return;
    unsigned short m = 0; signed char ya = 0, xa = 0;
    read_keys(&m, &ya, &xa);
    Keys->X_AXIS = xa;
    Keys->Y_AXIS = ya;
    /* mupen.Value bit mapping from N64 mask bits */
    if (m & 0x0100) Keys->Value |= (1u << 0);  /* D-Pad R  */
    if (m & 0x0200) Keys->Value |= (1u << 1);  /* D-Pad L  */
    if (m & 0x0400) Keys->Value |= (1u << 2);  /* D-Pad D  */
    if (m & 0x0800) Keys->Value |= (1u << 3);  /* D-Pad U  */
    if (m & 0x1000) Keys->Value |= (1u << 4);  /* START    */
    if (m & 0x2000) Keys->Value |= (1u << 5);  /* Z        */
    if (m & 0x4000) Keys->Value |= (1u << 6);  /* B        */
    if (m & 0x8000) Keys->Value |= (1u << 7);  /* A        */
    if (m & 0x0080) Keys->Value |= (1u << 8);  /* C-R      */
    if (m & 0x0040) Keys->Value |= (1u << 9);  /* C-L      */
    if (m & 0x0020) Keys->Value |= (1u << 10); /* C-D      */
    if (m & 0x0010) Keys->Value |= (1u << 11); /* C-U      */
    if (m & 0x0008) Keys->Value |= (1u << 12); /* R trig   */
    if (m & 0x0004) Keys->Value |= (1u << 13); /* L trig   */
}

void ControllerCommand(int Control, unsigned char *Cmd)
{
    (void)Control; (void)Cmd;
}

void ReadController(int Control, unsigned char *Cmd)
{
    (void)Control; (void)Cmd;
}