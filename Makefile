# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Executable name
TARGET = load_balancer

# Source files
SRCS = main.cpp \
       Request.cpp \
       WebServer.cpp \
       RequestQueue.cpp \
       LoadBalancer.cpp

# Header files
HDRS = Request.h \
       WebServer.h \
       RequestQueue.h \
       LoadBalancer.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file to an object file
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
