GCC = g++
GCC_FLAGS = -std=c++11
PROGRAM = diary

all: $(PROGRAM)

$(PROGRAM): App.o Date.o Time.o Utils.o Diary.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAM) App.o Date.o Time.o Utils.o Diary.o main.o
	rm *.o
main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Time.o: src/Time.cpp include/Time.h
	$(GCC) $(GCC_FLAGS) -c src/Time.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp	

Utils.o: src/Utils.cpp include/Utils.h
	$(GCC) $(GCC_FLAGS) -c src/Utils.cpp

