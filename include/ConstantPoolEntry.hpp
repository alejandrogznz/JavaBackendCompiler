# ifndef JAVABACKENDCOMPILER_CONSTANTPOOLENTRY_H_
# define JAVABACKENDCOMPILER_CONSTANTPOOLENTRY_H_

# include <iostream>
# include <fstream>
# include <string>
# include "FileUtil.hpp"

class ConstantPoolEntry
{
protected:

	unsigned int tag; 	// Describes the type of the ConstantPoolEntry

public:

	ConstantPoolEntry(unsigned int newTag);

};

class ConstantClass;

class ConstantFieldRef;

class ConstantMethodRef
    :public ConstantPoolEntry
{
protected:

    unsigned short int class_index;

    unsigned short int name_and_type_index;

public:

    ConstantMethodRef(unsigned int tag, std::ifstream &openFile);
};

class ConstantInterfaceMethodRef;

class ConstantString;

class ConstantInteger;

class ConstantFloat;

class ConstantLong;

class ConstantNameAndType;

class ConstantUtf8;

class ConstantMethodHandle;

class ConstantMethodType;

class ConstantInvokeDynamic;

# endif // JAVABACKENDCOMPILER_CONSTANTPOOLENTRY_H_
