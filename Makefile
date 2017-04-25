CXX=g++-4.8

BUILD_DIR=objs

CXXFLAGS =
CXXFLAGS+=-O3
CXXFLAGS+=-Wall

CXXFLAGS+=-std=c++11

#CXXFLAGS+=-pg
CXXFLAGS+=-march=native
CXXFLAGS+=-lm
CXXFLAGS+=-funroll-loops
CXXFLAGS+=-m64
CXXFLAGS+=-fopenmp

CXXLIBS=-fopenmp

SRCS=$(shell ls *.cpp)
OBJS=$(SRCS:.cpp=.o)

PROGRAM=cpp_neural

all : $(BUILD_DIR) $(patsubst %,$(BUILD_DIR)/%,$(PROGRAM))

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(BUILD_DIR)/$(PROGRAM) : $(patsubst %,$(BUILD_DIR)/%,$(OBJS))
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -o $@ $^
	mv $(BUILD_DIR)/$(PROGRAM) ./
	rm -f ?*~

clean:
	rm -f $(BUILD_DIR)/* $(PROGRAM) ?*~
	echo "dummy" > $(BUILD_DIR)/dummy
