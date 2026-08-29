#ifndef STARTMENU_H
#define STARTMENU_H

#include <View.h>
#include <TextControl.h>
#include <Button.h>
#include <String.h>
#include <Menu.h>

class StartMenu : public BView {
public:
    StartMenu(BRect frame);
    ~StartMenu();

    void Draw(BRect updateRect) override;
    void MessageReceived(BMessage* message) override;
    void ShowMenu();
    void HideMenu();
    bool IsVisible() const { return fVisible; }

private:
    bool fVisible;
    BTextControl* fSearchField;
    BMenu* fAppMenu;
};

#endif // STARTMENU_H
