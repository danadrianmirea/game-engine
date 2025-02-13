#include "window_events.hpp"

#include "core/window_manager.hpp"

namespace win32
{
    void WindowEvents::update() const
    {
        MSG msg;

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                core::WindowManager::instance().close();
                break;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    LRESULT WindowEvents::process(HWND hwnd, const uint32_t msg, const WPARAM wparam, const LPARAM lparam)
    {
        switch (msg)
        {
            case WM_CLOSE:
            {
                PostQuitMessage(0);
                return 0;
            }
            case WM_SIZE:
            {
                const int32_t width  = LOWORD(lparam);
                const int32_t height = HIWORD(lparam);

                core::WindowManager::instance().resize({ width, height });
                return 0;
            }
            case WM_ERASEBKGND:
            {
                return 1;
            }
            case WM_SYSCOMMAND:
            {
                switch (wparam)
                {
                    case SC_SCREENSAVE:
                    case SC_MONITORPOWER:
                    {
                        return 0;
                    }
                    default:
                        break;
                }
            }
            default:
                return DefWindowProc(hwnd, msg, wparam, lparam);
        }

        return 0;
    }
}