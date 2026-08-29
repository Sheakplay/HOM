#include "app.h"
#include "desktopwindow.h"

int main() {
    WindowManagerApp app;
    DesktopWindow* desktop = new DesktopWindow();
    desktop->Show();
    app.Run();
    return 0;
}
