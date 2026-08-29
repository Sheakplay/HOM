#include "taskbar.h"
#include <Font.h>
#include <Application.h>
#include <Window.h>
#include <Message.h>
#include <MenuItem.h>

Taskbar::Taskbar(BRect frame)
    : BView(frame, "Taskbar", B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW) {
    SetViewColor(30, 30, 40);

    // Start button
    fAppArea = new BView(BRect(60, 5, frame.Width() - 10, 40), "AppArea",
                         B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW);
    fAppArea->SetViewColor(40, 40, 50);
    AddChild(fAppArea);

    fStartButton = new BButton(BRect(5, 5, 50, 35), "startBtn", "Start",
                                new BMessage('STRT'));
    fStartButton->SetTarget(be_app);
    AddChild(fStartButton);
}

Taskbar::~Taskbar() {
    // Buttons are cleaned up automatically by BView destructor
}

void Taskbar::Draw(BRect updateRect) {
    // Draw taskbar background
    SetHighColor(30, 30, 40);
    FillRect(Bounds(), B_SOLID_HIGH);

    // Draw top line
    SetHighColor(100, 100, 120);
    StrokeLine(BPoint(0, 0), BPoint(Bounds().Width(), 0));

    // Draw bottom line
    StrokeLine(BPoint(0, Bounds().Height()),
               BPoint(Bounds().Width(), Bounds().Height()));

    // Draw label
    SetHighColor(200, 200, 220);
    DrawString("Window Manager", BPoint(Bounds().Width() - 150, 35));
}

void Taskbar::MessageReceived(BMessage* message) {
    switch (message->what) {
        default:
            BView::MessageReceived(message);
    }
}

void Taskbar::AddAppButton(const char* label, BMessage* message) {
    BButton* btn = new BButton(BRect(5, 5, 80, 35), (label ? label : "App"), label,
                                message ? message : new BMessage(0));
    btn->SetTarget(be_app);
    fAppArea->AddChild(btn);
    fAppArea->Invalidate();
}

void Taskbar::ClearAppButtons() {
    BView* child = fAppArea->ChildAt(0);
    while (child != NULL) {
        BView* next = fAppArea->ChildAt(0);
        fAppArea->RemoveChild(child);
        delete child;
        child = next;
    }
}

void Taskbar::RefreshApps(const char** names, int count) {
    ClearAppButtons();
    float x = 5;
    for (int i = 0; i < count && i < 10; i++) {
        BString label = names ? names[i] : "App";
        BMessage* msg = new BMessage('ACTV');
        msg->AddString("app", label);
        BButton* btn = new BButton(BRect(x, 5, x + 70, 35), label.String(), label.String(), msg);
        btn->SetTarget(be_app);
        fAppArea->AddChild(btn);
        x += 75;
    }
    fAppArea->Invalidate();
}
