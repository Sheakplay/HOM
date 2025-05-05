#include "StartMenu.h"
#include <Menu.h>
#include <MenuItem.h>

StartMenu::StartMenu(BRect frame) : BView(frame, "StartMenu", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW) {
    SetViewColor(220, 220, 220);

    BTextControl* searchField = new BTextControl(BRect(10, 10, 200, 30), "search", "Search", "", new BMessage('SRCH'));
    AddChild(searchField);
}

void StartMenu::Draw(BRect updateRect) {
    SetHighColor(0, 0, 0);
    FillRect(Bounds());
}

void StartMenu::MessageReceived(BMessage* message) {
    if (message->what == 'SRCH') {
        // Реализуем поиск
    } else {
        BView::MessageReceived(message);
    }
}
