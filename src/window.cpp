#include "window.h"
#include <Application.h>
#include <String.h>

AppWindow::AppWindow(BRect frame, const char* title, window_look look)
    : BWindow(frame, title, look, B_NORMAL_WINDOW_FEEL,
              B_QUIT_ON_WINDOW_CLOSE | B_AUTO_UPDATE_SIZE_LIMITS) {

    fMainView = new BView(Bounds(), "MainView", B_FOLLOW_ALL, B_WILL_DRAW);
    fMainView->SetViewColor(240, 240, 240);
    AddChild(fMainView);

    BButton* closeButton = new BButton(BRect(10, 10, 100, 30), "closeBtn",
                                       "Закрыть", new BMessage(B_QUIT_REQUESTED));
    closeButton->SetTarget(this);
    fMainView->AddChild(closeButton);
}

AppWindow::~AppWindow() {
    // fMainView is cleaned up by BWindow destructor
}

void AppWindow::MessageReceived(BMessage* message) {
    switch (message->what) {
        case B_QUIT_REQUESTED:
            Quit();
            break;
        default:
            BWindow::MessageReceived(message);
    }
}

bool AppWindow::QuitRequested() {
    return true;
}
