CC = gcc
CFLAGS = -W -Wall
TARGET = manage
OBJECT = manage.o main.c

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $^ -o $@
clean :
	rm *.o $(TARGET)