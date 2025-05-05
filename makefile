CC = g++
CFLAGS = -std=c++11 -Wall -I /path/to/haiku/include
LDFLAGS = -L /path/to/haiku/lib -lbe -lstdc++

SRC = src/main.cpp src/Taskbar.cpp src/StartMenu.cpp src/Desktop.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = MyWindowManager

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)
