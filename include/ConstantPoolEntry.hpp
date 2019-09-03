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

	virtual std::string toString() = 0;

};

class ConstantClass
	:public ConstantPoolEntry
{
protected:

	unsigned short int name_index;

public:
	ConstantClass(unsigned int tag, std::ifstream &openFile);

	std::string toString();

};

class ConstantFieldRef
	:public ConstantPoolEntry
{
protected:

    unsigned short int class_index;

    unsigned short int name_and_type_index;

public:

    ConstantFieldRef(unsigned int tag, std::ifstream &openFile);

	std::string toString();
};


class ConstantMethodRef
    :public ConstantPoolEntry
{
protected:

    unsigned short int class_index;

    unsigned short int name_and_type_index;

public:

    ConstantMethodRef(unsigned int tag, std::ifstream &openFile);

	std::string toString();
};

class ConstantInterfaceMethodRef;

class ConstantString;

class ConstantInteger;

class ConstantFloat;

class ConstantLong;

class ConstantNameAndType
	:public ConstantPoolEntry
{
protected:

	unsigned short int name_index;

	unsigned short int descriptor_index;

public:

	ConstantNameAndType(unsigned int tag, std::ifstream &openFile);

	std::string toString();
};

class ConstantUtf8 // Tag 0x01
	:public ConstantPoolEntry
{
protected:

	unsigned int length;
	
	std::string bytes;

public:

	ConstantUtf8(unsigned int tag, std::ifstream &openFile);

	std::string toString();

private:

	std::string readStringFromFileStream(std::ifstream &openfile);
};

class ConstantMethodHandle;

class ConstantMethodType;

class ConstantInvokeDynamic;

# endif // JAVABACKENDCOMPILER_CONSTANTPOOLENTRY_H_
