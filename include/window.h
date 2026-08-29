#ifndef WINDOW_H
#define WINDOW_H

#include <Window.h>
#include <View.h>
#include <Button.h>

class AppWindow : public BWindow {
public:
    AppWindow(BRect frame, const char* title, window_look look = B_TITLED_WINDOW_LOOK);
    ~AppWindow();

    void MessageReceived(BMessage* message) override;
    bool QuitRequested() override;

private:
    BView* fMainView;
};

#endif // WINDOW_H
