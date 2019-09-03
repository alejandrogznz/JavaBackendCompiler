GCC=g++ -std=c++17
OBJ=main.o ClassFile.o ConstantPool.o ConstantPoolEntry.o ClassMethod.o
INC=./include/
SRC=./source/

main: $(OBJ)
	$(GCC) $(OBJ) -o main

main.o: main.cpp
	$(GCC) main.cpp -c

ClassFile.o: $(INC)ClassFile.hpp $(SRC)ClassFile.cpp
	$(GCC) $(SRC)ClassFile.cpp -c

ConstantPool.o: $(INC)ConstantPool.hpp $(SRC)ConstantPool.cpp
	$(GCC) $(SRC)ConstantPool.cpp -c

ConstantPoolEntry.o: $(INC)ConstantPoolEntry.hpp $(SRC)ConstantPoolEntry.cpp
	$(GCC) $(SRC)ConstantPoolEntry.cpp -c 

ClassMethod.o: $(INC)ClassMethod.hpp $(SRC)ClassMethod.cpp
	$(GCC) $(SRC)ClassMethod.cpp -c


clean:
	rm -f *.o main