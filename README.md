# Window Manager for Haiku OS

Это нативное приложение-оболочка ("настоящий оконный менеджер" в рамках Haiku API) с рабочим столом, панелью задач и меню "Пуск".

## Архитектура
- `WindowManagerApp` — приложение (`BApplication`)
- `DesktopWindow` — главное окно с рабочим столом и панелью задач
- `Desktop` — фон с поддержкой изображения
- `Taskbar` — панель с кнопкой "Пуск" и кнопками приложений
- `StartMenu` — выпадающее меню с поиском
- `WindowManager` — управление приложениями через `BRoster`
- `AppWindow` — шаблон окна приложения

## Сборка на Haiku
```bash
# Если SDK в стандартном месте:
make

# Или с явными путями:
make CFLAGS="-std=c++11 -Wall -I./include -I/boot/system/develop/headers/os -I/boot/system/develop/headers/os/app -I/boot/system/develop/headers/os/interface" LDFLAGS="-L/boot/system/develop/lib/x86_64 -lbe -lstdc++ -ltranslation"
```

## Особенности
- Использует нативное Haiku API (`BApplication`, `BWindow`, `BView`, `BRoster`)
- Управляет запуском и переключением приложений
- Поддерживает фон (`resources/background.jpg`)
