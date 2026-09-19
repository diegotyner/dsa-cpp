CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Icommon

# usage: make run FILE=sliding-window/003-longest-substring/approach-sliding-window.cpp
run: $(FILE)
	$(CXX) $(CXXFLAGS) -o /tmp/sol $(FILE)
	/tmp/sol

run-java: $(FILE)
	javac $(FILE)
	java -cp $(dir $(FILE)) Solution

# usage: make build FILE=...
build: $(FILE)
	$(CXX) $(CXXFLAGS) -o /tmp/sol $(FILE)
