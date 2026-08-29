#ifndef TASKBAR_H
#define TASKBAR_H

#include <View.h>
#include <Button.h>
#include <String.h>

class Taskbar : public BView {
public:
    Taskbar(BRect frame);
    ~Taskbar();

    void Draw(BRect updateRect) override;
    void MessageReceived(BMessage* message) override;

    void AddAppButton(const char* label, BMessage* message);
    void ClearAppButtons();
    void RefreshApps(const char** names, int count);

private:
    BView* fAppArea;
    BButton* fStartButton;
    BString fAppAreaName;
};

#endif // TASKBAR_H
