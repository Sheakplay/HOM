#ifndef APP_H
#define APP_H

#include <Application.h>

class WindowManagerApp : public BApplication {
public:
    WindowManagerApp();
    void ReadyToRun() override;
    void MessageReceived(BMessage* message) override;
};

#endif // APP_H
