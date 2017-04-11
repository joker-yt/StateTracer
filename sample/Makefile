TARGET=app
SRC= main.cpp
INCLUDES=../src
HEADER= CState.h, CTestState.h, CStateChanger.h
CPPFLAGS=-g
CPPFLAGS=-std=c++11
CPPFLAGS+=-I$(INCLUDES)

all: $(TARGET)

$(TARGET): $(SRC)
	g++ $< -o $@ $(CPPFLAGS)

exec: $(TARGET)
	./$<
