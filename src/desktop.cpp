#include "desktop.h"
#include <Bitmap.h>
#include <File.h>
#include <TranslationUtils.h>
#include <String.h>

Desktop::Desktop(BRect frame)
    : BView(frame, "Desktop", B_FOLLOW_ALL_SIDES, B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE) {
    fBackground = NULL;
    SetViewColor(50, 60, 90); // Dark blue-gray background
}

Desktop::~Desktop() {
    delete fBackground;
}

void Desktop::SetBackgroundImage(const char* path) {
    fImagePath = path ? path : "";
    delete fBackground;
    fBackground = NULL;

    if (path && strlen(path) > 0) {
        BFile file(path, B_READ_ONLY);
        if (file.InitCheck() == B_OK) {
            fBackground = BTranslationUtils::GetBitmap(&file);
        }
    }

    Invalidate();
}

void Desktop::Draw(BRect updateRect) {
    // Fill background
    if (fBackground != NULL) {
        DrawBitmap(fBackground, BPoint(0, 0));
    } else {
        SetHighColor(50, 60, 90);
        FillRect(Bounds(), B_SOLID_HIGH);
    }

    // Draw desktop label
    SetHighColor(255, 255, 255);
    SetFont(be_plain_font);
    SetFontSize(12);
    DrawString("Window Manager Desktop", BPoint(10, 20));
}

void Desktop::MessageReceived(BMessage* message) {
    BView::MessageReceived(message);
}
