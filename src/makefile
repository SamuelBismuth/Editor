CXX = g++
CXXFLAGS = -std=c++0x

all: main.o Editor.o Document.o 
	$(CXX) $(CXXFLAGS) main.o Editor.o Document.o 
	./a.out

Editor.o: Editor.cpp Editor.h
	$(CXX) $(CXXFLAGS) -c Editor.cpp -o Editor.o

Document.o: Document.cpp Document.h
	$(CXX) $(CXXFLAGS) -c Document.cpp -o Document.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm *.o a.out