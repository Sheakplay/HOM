#include <Application.h>
#include <Window.h>
#include <View.h>
#include <Button.h>
#include "Taskbar.h"
#include "StartMenu.h"
#include "Desktop.h"

class MainWindow : public BWindow {
public:
    MainWindow();
    void MessageReceived(BMessage* message) override;
};

MainWindow::MainWindow()
    : BWindow(BRect(100, 100, 800, 600), "Window Manager", B_TITLED_WINDOW, B_QUIT_ON_WINDOW_CLOSE) {
    // Добавляем панель задач
    BView *taskbarView = new Taskbar(BRect(0, 0, Frame().Width(), 40));
    AddChild(taskbarView);

    // Добавляем рабочий стол
    BView *desktopView = new Desktop(BRect(0, 40, Frame().Width(), Frame().Height()));
    AddChild(desktopView);

    // Добавляем меню "Пуск"
    BView *startMenuView = new StartMenu(BRect(10, 50, 200, 300));
    AddChild(startMenuView);
}

void MainWindow::MessageReceived(BMessage* message) {
    switch (message->what) {
        // Обработка сообщений (например, закрытие окна, минимизация и т.д.)
        default:
            BWindow::MessageReceived(message);
    }
}

int main() {
    BApplication app("application/x-vnd.MyWindowManager");
    MainWindow* mainWindow = new MainWindow();
    mainWindow->Show();
    app.Run();
    return 0;
}
