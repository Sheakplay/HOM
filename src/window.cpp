#include "Window.h"
#include <Application.h>
#include <stdio.h>

AppWindow::AppWindow(BRect frame, const char* title)
    : BWindow(frame, title, B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE | B_AUTO_UPDATE_SIZE_LIMITS) {
    
    BView* mainView = new BView(Bounds(), "MainView", B_FOLLOW_ALL, B_WILL_DRAW);
    mainView->SetViewColor(240, 240, 240);
    AddChild(mainView);

    // Пример кнопки
    BButton* closeButton = new BButton(BRect(10, 10, 100, 30), "close", "Закрыть",
                                       new BMessage(B_QUIT_REQUESTED));
    mainView->AddChild(closeButton);
}

void AppWindow::MessageReceived(BMessage* message) {
    switch (message->what) {
        default:
            BWindow::MessageReceived(message);
    }
}

bool AppWindow::QuitRequested() {
    return true;
}
