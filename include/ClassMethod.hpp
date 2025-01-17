# ifndef JAVABACKENDCOMPILER_CLASSMETHOD_H_
# define JAVABACKENDCOMPILER_CLASSMETHOD_H_

# include <iostream>
# include <fstream>
# include <string>
# include <vector>

# include "FileUtil.hpp"

class CodeAttribute
{
protected:

	unsigned short int attributeNameIndex;

	unsigned int attributeLength;

	unsigned short int maxStack;

	unsigned short int maxLocals;

	unsigned int codeLength;

	unsigned char * code;

	// Ignore the Excpetion table and skip over it

	// Also ignore the second attribute_count

public:

	CodeAttribute(std::ifstream & openFile);
	
	unsigned char * getCode();

	unsigned int getCodeLength();

	unsigned short int getMaxStack();

	unsigned short int getMaxLocals();

	std::string toString();

};

class Method
{
protected:

	unsigned short int accessFlags;

	unsigned short int nameIndex;

	unsigned short int descriptorIndex;

	unsigned short int attributesCount;

	CodeAttribute * codeAttribute;

public:

	Method(std::ifstream &openFile);

	CodeAttribute * getCodeAttribute();

	std::string toString();

private:

	void buildMethodFromOpenFile(std::ifstream &openFile);

	CodeAttribute * readCodeAttributeFromFileStream(std::ifstream &openFile);

};

# endif // JAVABACKENDCOMPILER_CLASSMETHOD_H_