#include "app.h"
#include "desktopwindow.h"

WindowManagerApp::WindowManagerApp()
    : BApplication("application/x-vnd.WindowManager") {}

void WindowManagerApp::ReadyToRun() {
    BApplication::ReadyToRun();
}

void WindowManagerApp::MessageReceived(BMessage* message) {
    switch (message->what) {
        case B_QUIT_REQUESTED:
            PostMessage(B_QUIT_REQUESTED);
            break;
        default:
            BApplication::MessageReceived(message);
    }
}
