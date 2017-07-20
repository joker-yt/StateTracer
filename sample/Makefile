TARGET=app
SRC=main.cpp CSampleCordinator.cpp CSampleState1.cpp CSampleState2.cpp
OBJS=$(subst .cpp,.o,$(SRC))
INCLUDES=../src
HEADER= CState.h, CTestState.h, CStateChanger.h
CPPFLAGS=-g
CPPFLAGS+=-std=c++11
CPPFLAGS+=-I$(INCLUDES)
LDFLAGS=-L../
EXTERNAL_OBJS=../src/CStateCordinator.o ../src/CState.o

CXX=g++

.PHONY:	all	check-syntax clean

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ $^ $(EXTERNAL_OBJS) -o $@ $(CPPFLAGS)

.cpp.o:
	g++ -c $< $(CPPFLAGS)

exec: $(TARGET)
	./$<


check-syntax:
	$(CXX) -o null -fsyntax-only $(CHK_SOURCES) $(INCLUDES) $(CPPFLAGS)

clean:
	rm -fr $(TARGET) *.o *.gch
