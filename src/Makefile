SRC=CStateCordinator.cpp CState.cpp
OBJS=$(subst .cpp,.o,$(SRC))
CPPFLAGS=-std=c++11 -MMD -g

CXX=g++

.PHONY: all clean check-syntax
all: $(OBJS)
-include $(DEPS)

.SUFFIXES:	.cpp .o
.cpp.o:
	g++ -c $< $(CPPFLAGS)

clean:
	rm -fr *.o *.gch *.d

check-syntax:
	$(CXX) -o null -fsyntax-only $(CHK_SOURCES) $(INCLUDES) $(CPPFLAGS)
