CC = g++

CFLAGS = -std=c++11 -Wall

TARGET = library

SOURCES = src/book.cpp src/library.cpp src/main.cpp

HEADERS = include/book.h include/library.h

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -Iinclude

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q $(subst /,\,$(OBJECTS)) $(TARGET).exe

run: $(TARGET)
	$(TARGET).exe

