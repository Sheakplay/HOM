#ifndef STARTMENU_H
#define STARTMENU_H

#include <View.h>
#include <TextControl.h>

class StartMenu : public BView {
public:
    StartMenu(BRect frame);
    void Draw(BRect updateRect) override;
    void MessageReceived(BMessage* message) override;
};

#endif // STARTMENU_H
