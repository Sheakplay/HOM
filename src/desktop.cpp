#include "Desktop.h"
#include <Bitmap.h>
#include <File.h>
#include <Entry.h>

Desktop::Desktop(BRect frame) : BView(frame, "Desktop", B_FOLLOW_ALL, B_WILL_DRAW) {
    SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}

void Desktop::Draw(BRect updateRect) {
    // Рисуем фон рабочего стола
    BBitmap* backgroundImage = new BBitmap("background.jpg");
    if (backgroundImage != nullptr) {
        DrawBitmap(backgroundImage);
    }
}
