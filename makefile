CPP = g++
CPPFLAGS = -c
TARGET = test.exe
OBJS = uop.o

all: $(TARGET)

$(TARGET): test.cpp $(OBJS)
	$(CPP) test.cpp $(OBJS) -o $(TARGET)

uop.o: uop.cpp uop.h
	$(CPP) $(CPPFLAGS) uop.cpp -o uop.o

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
