CC = gcc
CFLAGS = -Wall -g
TARGET = ctest.exe
SRC = ctest.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
