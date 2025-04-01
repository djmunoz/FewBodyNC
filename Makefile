CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = few_body_nc
SRC_DIR = src


#SRCS = src/main.cpp src/body.cpp src/solver.cpp src/io.cpp src/leapfrog.cpp src/globals.cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/io/*.cpp)
#SRCS+= src/io/io.cpp src/io/output.cpp src/io/input.cpp

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

