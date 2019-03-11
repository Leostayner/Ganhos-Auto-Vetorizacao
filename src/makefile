#Makefile para programas do curso do Supercomputação
CXX    = g++
FLAGS  = -std=c++11 
PROGS  = mainn  \
		 mainv  \
		 mainvx \
		 mainvx2 \
		 exe

all : $(PROGS)

mainn : main.o funcs.o	
	$(CXX) $(FLAGS) -o $@ $^ -lboost_random -ljsoncpp  

mainv : main.o funcs.o
	$(CXX) $(FLAGS) -o $@ $^ -lboost_random -ljsoncpp -ftree-vectorize -O3  

mainvx : main.o funcs.o
	$(CXX) $(FLAGS) -o $@ $^ -lboost_random -ljsoncpp -ftree-vectorize -mavx -O3 

mainvx2 : main.o funcs.o
	$(CXX) $(FLAGS) -o $@ $^ -lboost_random -ljsoncpp -ftree-vectorize -mavx2 -O3 


main.o : main.cpp 
	$(CXX) $(FLAGS) -c -o $@ $^ 

funcs.o : funcs.cpp 
	$(CXX) $(FLAGS) -c -o $@ $^ 

clean:
	rm -f $(PROGS)

exe : exe.o
	$(CXX) $(FLAGS) -o $@ $^ 


