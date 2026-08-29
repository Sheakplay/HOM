#ifndef DESKTOP_H
#define DESKTOP_H

#include <View.h>
#include <Bitmap.h>

class Desktop : public BView {
public:
    Desktop(BRect frame);
    ~Desktop();

    void Draw(BRect updateRect) override;
    void MessageReceived(BMessage* message) override;

    void SetBackgroundImage(const char* path);

private:
    BBitmap* fBackground;
    BString fImagePath;
};

#endif // DESKTOP_H
