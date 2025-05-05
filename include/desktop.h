#ifndef DESKTOP_H
#define DESKTOP_H

#include <View.h>

class Desktop : public BView {
public:
    Desktop(BRect frame);
    void Draw(BRect updateRect) override;
};

#endif // DESKTOP_H
