CC=g++
CDEFINES=
SOURCES=Dispatcher.cpp Mode.cpp precomp.cpp profanity.cpp SpeedSample.cpp
OBJECTS=$(SOURCES:.cpp=.o)

UNAME_S := $(shell uname -s)

# TODO better way of detecting MSYS?
ifeq ($(UNAME_S),MINGW64_NT-10.0-19044)
	EXECUTABLE=profanity2.exe
else
	EXECUTABLE=profanity2.x64
endif

# TODO better way of detecting MSYS?
ifeq ($(UNAME_S),MINGW64_NT-10.0-19044)
	LDFLAGS=-s -lOpenCL -lws2_32 -L"/c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.7/lib/x64"
	CFLAGS=-c -std=c++11 -Wall -mmmx -O2
else
	ifeq ($(UNAME_S),Darwin)
		LDFLAGS=-framework OpenCL
		CFLAGS=-c -std=c++11 -Wall -mmmx -O2
	else
		LDFLAGS=-s -lOpenCL -mcmodel=large
		CFLAGS=-c -std=c++11 -Wall -mmmx -O2 -mcmodel=large 
	endif
endif

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(CDEFINES) $< -o $@

clean:
	rm -rf *.o

