#ifndef DESKTOP_WINDOW_H
#define DESKTOP_WINDOW_H

#include <Window.h>
#include <View.h>
#include <String.h>

class Desktop;
class Taskbar;
class StartMenu;
class WindowManager;

class DesktopWindow : public BWindow {
public:
    DesktopWindow();
    ~DesktopWindow();

    void MessageReceived(BMessage* message) override;
    bool QuitRequested() override;

    Desktop* GetDesktop() const { return fDesktop; }
    Taskbar* GetTaskbar() const { return fTaskbar; }

private:
    Desktop* fDesktop;
    Taskbar* fTaskbar;
    StartMenu* fStartMenu;
    WindowManager* fWindowManager;
};

#endif // DESKTOP_WINDOW_H
