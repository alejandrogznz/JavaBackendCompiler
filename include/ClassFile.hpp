#ifndef JAVABACKENDCOMPILER_CLASSFILE_H_
#define JAVABACKENDCOMPILER_CLASSFILE_H_

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <arpa/inet.h>

# include "ConstantPool.hpp"
# include "ClassMethod.hpp"
# include "Instruction.hpp"
# include "ByteCodes.hpp"

class ClassFile
{
protected:

    std::string fileName;

    unsigned int magicNumber;

    unsigned short int minorVersion;

    unsigned short int majorVersion;

    unsigned short int constantPoolCount;

	ConstantPool * constantPool;

	unsigned short int accessFlags;

	unsigned short int thisClass;

	unsigned short int superClass;

	unsigned short int interfaceCount;

	unsigned short int fieldsCount;

	unsigned short int methodsCount;

	std::vector<Method *> methods;

	unsigned short int attributesCount;

	std::vector<Method *> attributes;

	std::vector<std::vector<Instruction *>> instructionMethods;

public:
	ClassFile();

	ClassFile(const char * filename);

	ClassFile(std::string filename);

    std::string toString();

	std::string getInterprettedOutput();

    std::string generateMachineCode();

private:

	void buildClassFileFromFile();

	void readMethodsFromFile(std::ifstream &openFile);

    static short int readShortFromFile(std::ifstream &openFile);

    static unsigned short int readUnsignedShortFromFile(std::ifstream &openFile);

    static int readWordFromFile(std::ifstream &openFile);

    static unsigned int readUnsignedWordFromFile(std::ifstream &openFile);

	// Machine Code Generation
	
	void buildInstructionList();

	static void readByteCode(unsigned char * code, unsigned int length);

};

# endif //JAVABACKENDCOMPILER_CLASSFILE_H_