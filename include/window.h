#ifndef WINDOW_H
#define WINDOW_H

#include <Window.h>
#include <View.h>
#include <Button.h>

class AppWindow : public BWindow {
public:
    AppWindow(BRect frame, const char* title);
    void MessageReceived(BMessage* message) override;
    bool QuitRequested() override;
};

#endif // WINDOW_H
