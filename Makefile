CC = g++
CXXFLAGS = -Wall -O2

# mytime3.o : mytime3.h mytime3.cpp
# 						g++ -c mytime3.cpp
%.o : %.cpp %.h
			$(CC) $(CXXFLAGS) -c $<

usetime3.o : mytime3.h usetime3.cpp 
						g++ -c usetime3.cpp
usetime3 : mytime3.o usetime3.o
						g++ mytime3.o usetime3.o -o usetime3

randwalk.o : randwalk.cpp vect.h
						$(CC) -c randwalk.cpp
randwalk : randwalk.o vect.o
						$(CC) randwalk.o vect.o -o randwalk


clean:
	rm -f mytime3.o usetime3.o usetime3