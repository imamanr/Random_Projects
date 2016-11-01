CXXFLAGS =	-std=c++11 -O2 -g -Wall -fmessage-length=0 -I/usr/local/include

OBJS =		rushhour.o

LIBS =		—lcppunit -L/usr/local/lib

TARGET =	rush-hour

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)