CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra
LDFLAGS = -pthread
INCLUDES = -I.

EXECUTABLE = phone_manager
TEST_EXECUTABLE = test/test
SOURCES = main.cpp list.cpp entity.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_SOURCES = test/test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)


MAKE := make

all: docs run clean

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

docs:
	doxygen Doxyfile

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
	rm -rf docs

run: $(EXECUTABLE)
	./$(EXECUTABLE)


 