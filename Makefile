# Makefile for Window Manager (Haiku OS)
# Adjust paths if your Haiku SDK is in a different location.

CC = g++
CFLAGS = -std=c++11 -Wall -I./include
# For Haiku SDK builds, uncomment and adjust:
# CFLAGS += -I/boot/system/develop/headers/os -I/boot/system/develop/headers/os/app -I/boot/system/develop/headers/os/interface

LDFLAGS = -lbe -lstdc++ -ltranslation
# For Haiku SDK builds, uncomment and adjust library path:
# LDFLAGS += -L/boot/system/develop/lib/x86_64

SRC = src/main.cpp \
      src/app.cpp \
      src/desktopwindow.cpp \
      src/desktop.cpp \
      src/taskbar.cpp \
      src/startmenu.cpp \
      src/windowmanager.cpp \
      src/window.cpp

OBJ = $(SRC:.cpp=.o)
EXEC = WindowManager

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJ)

install: $(EXEC)
	cp $(EXEC) /boot/home/config/apps/
