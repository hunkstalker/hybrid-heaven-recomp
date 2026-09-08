#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char**argv){
  if(argc<3){fprintf(stderr,"xshot DISPLAY out.ppm\n");return 1;}
  Display*d=XOpenDisplay(argv[1]); if(!d){fprintf(stderr,"no display %s\n",argv[1]);return 1;}
  Window r=DefaultRootWindow(d);
  int w=640,h=480;
  XImage*im=XGetImage(d,r,0,0,w,h,AllPlanes,ZPixmap);
  if(!im){fprintf(stderr,"XGetImage fail\n");return 2;}
  FILE*f=fopen(argv[2],"wb"); fprintf(f,"P6\n%d %d\n255\n",im->width,im->height);
  for(int y=0;y<im->height;y++) for(int x=0;x<im->width;x++){
    unsigned long p=XGetPixel(im,x,y);
    unsigned char rgb[3];
    if(im->red_mask){rgb[0]=(p>>16)&0xff;rgb[1]=(p>>8)&0xff;rgb[2]=p&0xff;}
    else {rgb[0]=p&0xff;rgb[1]=(p>>8)&0xff;rgb[2]=(p>>16)&0xff;}
    fwrite(rgb,3,1,f);}
  fclose(f); XFree(im); XCloseDisplay(d); return 0;}