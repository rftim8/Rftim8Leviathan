#include "rft_vulkan.hh"

int main()
{
    std::system("cls");

    RFT_FATAL("Test fatal message: %f", 3.14f);
    RFT_ERROR("Test error message: %f", 3.14f);
    RFT_WARN("Test warn message: %f", 3.14f);
    RFT_INFO("Test info message: %f", 3.14f);
    RFT_DEBUG("Test debug message: %f", 3.14f);
    RFT_TRACE("Test trace message: %f", 3.14f);

    platform_state state;
    if (platform_startup(&state, "Rftim3VKEngine", 100, 100, 1280, 720))
    {
        while (TRUE)
        {
            platform_pump_messages(&state);            
        }
    }

    platform_shutdown(&state);

    return 0;
}