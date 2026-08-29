#include "desktopwindow.h"
#include "desktop.h"
#include "taskbar.h"
#include "startmenu.h"
#include "windowmanager.h"
#include <Application.h>
#include <View.h>
#include <Message.h>

DesktopWindow::DesktopWindow()
    : BWindow(BRect(100, 100, 1000, 700), "Window Manager Desktop",
              B_DOCUMENT_WINDOW_LOOK, B_NORMAL_WINDOW_FEEL,
              B_QUIT_ON_WINDOW_CLOSE | B_AUTO_UPDATE_SIZE_LIMITS) {

    // Initialize window manager
    fWindowManager = new WindowManager();
    fWindowManager->Initialize();

    // Create desktop view (fills window below taskbar)
    BRect desktopFrame = Bounds();
    fDesktop = new Desktop(BRect(0, 50, desktopFrame.Width(), desktopFrame.Height() - 50));
    fDesktop->SetBackgroundImage("resources/background.jpg");
    AddChild(fDesktop);

    // Create taskbar at top
    fTaskbar = new Taskbar(BRect(0, 0, desktopFrame.Width(), 50));
    AddChild(fTaskbar);

    // Create start menu (hidden initially)
    fStartMenu = new StartMenu(BRect(10, 55, 250, 350));
    fStartMenu->HideMenu();
    AddChild(fStartMenu);

    // Add a start button to taskbar manually for quick access
    // (In a full version, the Taskbar handles its own buttons)
    fWindowManager->RefreshTaskbar(fTaskbar);
}

DesktopWindow::~DesktopWindow() {
    delete fWindowManager;
}

void DesktopWindow::MessageReceived(BMessage* message) {
    switch (message->what) {
        case 'STRT':
            // Toggle start menu
            if (fStartMenu->IsVisible()) {
                fStartMenu->HideMenu();
            } else {
                fStartMenu->ShowMenu();
                fWindowManager->RefreshTaskbar(fTaskbar);
            }
            break;

        case 'LAUN':
            {
                const char* signature = "application/x-vnd.Haiku-StyledEdit";
                if (message->FindString("signature", &signature) == B_OK) {
                    fWindowManager->LaunchApp(signature);
                }
            }
            break;

        default:
            BWindow::MessageReceived(message);
    }
}

bool DesktopWindow::QuitRequested() {
    return true;
}
