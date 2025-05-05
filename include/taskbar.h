#ifndef TASKBAR_H
#define TASKBAR_H

#include <View.h>
#include <Button.h>

class Taskbar : public BView {
public:
    Taskbar(BRect frame);
    void Draw(BRect updateRect) override;
    void AddAppButton(const char* label, BMessage* msg);
};

#endif // TASKBAR_H
