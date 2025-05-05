#include "Taskbar.h"
#include <Font.h>

Taskbar::Taskbar(BRect frame) : BView(frame, "Taskbar", B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW) {
    SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}

void Taskbar::Draw(BRect updateRect) {
    // Рисуем фон панели задач
    SetHighColor(100, 100, 100);
    FillRect(Bounds());

    // Рисуем иконки приложений, например
    SetHighColor(255, 255, 255);
    DrawString("App1", BPoint(10, 20));
}

void Taskbar::AddAppButton(const char* label, BMessage* msg) {
    BButton* appButton = new BButton(BRect(10, 10, 50, 50), label, label, msg);
    AddChild(appButton);
}
