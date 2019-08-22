#ifndef JAVABACKENDCOMPILER_CLASSFILE_H_
#define JAVABACKENDCOMPILER_CLASSFILE_H_

# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <arpa/inet.h>

# include "ConstantPool.hpp"

class ClassFile
{
protected:

    std::string fileName;

    unsigned int magicNumber;

    unsigned short int minorVersion;

    unsigned short int majorVersion;

    unsigned short int constantPoolCount;

public:
	ClassFile();

	ClassFile(const char * filename);

	ClassFile(std::string filename);

    std::string getString();

	std::string getInterprettedOutput();

    std::string generateMachineCode();

private:

	void buildClassFileFromFile();

    static short int readShortFromFile(std::ifstream &openFile);

    static unsigned short int readUnsignedShortFromFile(std::ifstream &openFile);

    static int readWordFromFile(std::ifstream &openFile);

    static unsigned int readUnsignedWordFromFile(std::ifstream &openFile);

};

# endif //JAVABACKENDCOMPILER_CLASSFILE_H_