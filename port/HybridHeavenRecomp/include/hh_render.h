#pragma once

#include <cstdint>
#include <memory>

#include "ultramodern/ultramodern.hpp"
#include "ultramodern/config.hpp"

namespace RT64 {
    struct Application;
}

namespace hh {
    class RT64Context : public ultramodern::renderer::RendererContext {
    public:
        RT64Context(uint8_t* rdram, ultramodern::renderer::WindowHandle window_handle, bool developer_mode);
        ~RT64Context() override;

        bool valid() override;
        bool update_config(const ultramodern::renderer::GraphicsConfig& old_config, const ultramodern::renderer::GraphicsConfig& new_config) override;
        void enable_instant_present() override;
        void send_dl(const OSTask* task) override;
        void send_dummy_workload(uint32_t fb_address) override;
        void update_screen() override;
        void shutdown() override;
        uint32_t get_display_framerate() const override;
        float get_resolution_scale() const override;

    private:
        std::unique_ptr<RT64::Application> app;
        // Address of the most recently submitted display list (RAM address), replayed
        // when rendering a framebuffer that was not submitted with a display list.
        uint32_t last_dl_address = 0;
    };
}