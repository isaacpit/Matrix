
CXX = g++
CXXFLAGS = -std=c++14

targ = main

main: $(targ).o
	$(CXX) $(CXXFLAGS) $(targ).o -o $(targ)

$(targ).o: $(targ).cpp 
	$(CXX) $(CXXFLAGS) -c $(targ).cpp 

clean: 
	rm *.o
	rm main