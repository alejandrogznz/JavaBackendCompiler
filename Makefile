GCC=g++ -std=c++17
OBJ=main.o ClassFile.o 
INC=./include/
SRC=./source/

main: $(OBJ)
	$(GCC) $(OBJ) -o main

main.o: main.cpp
	$(GCC) main.cpp -c

ClassFile.o: $(INC)ClassFile.hpp $(SRC)ClassFile.cpp
	$(GCC) $(SRC)ClassFile.cpp -c

clean:
	rm -f *.o main