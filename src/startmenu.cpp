#include "startmenu.h"
#include <Menu.h>
#include <MenuItem.h>
#include <Application.h>
#include <Window.h>
#include <String.h>
#include <Font.h>

StartMenu::StartMenu(BRect frame)
    : BView(frame, "StartMenu", B_FOLLOW_TOP | B_FOLLOW_LEFT, B_WILL_DRAW) {
    fVisible = false;
    SetViewColor(220, 220, 230);

    // Search field
    fSearchField = new BTextControl(BRect(10, 10, 220, 30), "searchField",
                                     "Search apps...", "", new BMessage('SRCH'));
    fSearchField->SetTarget(be_app);
    AddChild(fSearchField);

    // App menu
    fAppMenu = new BMenu("Apps");
    fAppMenu->AddItem(new BMenuItem("StyledEdit", new BMessage('LAUN')));
    fAppMenu->AddItem(new BMenuItem("Terminal", new BMessage('LAUN')));
    fAppMenu->AddItem(new BMenuItem("WebPositive", new BMessage('LAUN')));
    fAppMenu->AddItem(new BMenuItem("Tracker", new BMessage('LAUN')));

    // Add a separator and shutdown
    fAppMenu->AddSeparatorItem();
    fAppMenu->AddItem(new BMenuItem("Quit Window Manager", new BMessage(B_QUIT_REQUESTED)));
}

StartMenu::~StartMenu() {
    delete fAppMenu;
}

void StartMenu::Draw(BRect updateRect) {
    if (!fVisible) return;

    // Menu background
    SetHighColor(230, 230, 240);
    FillRect(Bounds(), B_SOLID_HIGH);

    // Border
    SetHighColor(100, 100, 120);
    StrokeRect(Bounds());

    // Title
    SetHighColor(0, 0, 0);
    DrawString("Window Manager Menu", BPoint(10, Frame().Height() - 15));
}

void StartMenu::MessageReceived(BMessage* message) {
    switch (message->what) {
        case 'SRCH':
            // Basic search handling
            break;
        default:
            BView::MessageReceived(message);
    }
}

void StartMenu::ShowMenu() {
    fVisible = true;
    fAppMenu->SetTargetForItems(be_app);
    ConvertToScreen(NULL);
    fAppMenu->Go(BPoint(10, Frame().bottom + 5), true, false, true);
    Invalidate();
}

void StartMenu::HideMenu() {
    fVisible = false;
    Invalidate();
}
