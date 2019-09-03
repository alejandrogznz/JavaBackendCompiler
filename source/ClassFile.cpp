# include "../include/ClassFile.hpp"

using namespace std;

ClassFile::ClassFile()
    :fileName("")
{}

ClassFile::ClassFile(const char * filename)
{
    fileName = string(filename);
    buildClassFileFromFile();
}

ClassFile::ClassFile(std::string filename)
{
    fileName = filename;
    buildClassFileFromFile();
}

string ClassFile::toString()
{
    stringstream outString;
    outString << "ClassFile: " << fileName << endl;
    outString << "Magic Number: 0x" << hex << magicNumber << endl;
    outString << "Minor Version: 0x" << hex << minorVersion << endl;
    outString << "Major Version: 0x" << hex << majorVersion << endl;
	outString << "Access Flags: 0x" << hex << accessFlags << endl;
	outString << "This Class: 0x" << hex << thisClass << endl;
	outString << "Super Class: 0x" << hex << superClass << endl;
	outString << "Interface Count: 0x" << hex << interfaceCount << endl;
	outString << "Fields Count: 0x" << hex << fieldsCount << endl;
	outString << "Mehtods Count: 0x" << hex << methodsCount << endl;
	outString << "Attributes Count: 0x" << hex << attributesCount << endl;
    outString << "Constant Pool Count: 0x" << hex << constantPoolCount << endl;
	outString << "Constant Pool Members\n" << endl;
	for (auto m : methods)
	{
		outString << m->toString() << endl;
	}
	// TODO outString << constantPool->toString();

    return string(outString.str());
}

// Implementation

void ClassFile::buildClassFileFromFile()
{
    // Open the file and begin reading the contents into the 
    // class. If the file does not exist, throw and exception
    // TODO throw an exception if there is no 0xCAFEBABE in the first 4 bytes
    unsigned int magic_num = 0xCAFEBABE;
    char c;
	unsigned char d;
    ifstream readfile(fileName.c_str(), ios::in | ios::binary);

    // Assignment
    magicNumber = readUnsignedWordFromFile(readfile);
    minorVersion = readUnsignedShortFromFile(readfile);
    majorVersion = readUnsignedShortFromFile(readfile);
    constantPoolCount = readUnsignedShortFromFile(readfile);
	constantPool = new ConstantPool(constantPoolCount, readfile);
	accessFlags = readUnsignedShortFromFile(readfile);
	thisClass = readUnsignedShortFromFile(readfile);
	superClass = readUnsignedShortFromFile(readfile);
	interfaceCount = readUnsignedShortFromFile(readfile);
	// TODO There are no interfaces in this project, so for now we'll skip over them
	fieldsCount = readUnsignedShortFromFile(readfile);
	// TODO There are also no fields in this assignment, so skip over this too
	methodsCount = readUnsignedShortFromFile(readfile);
	readMethodsFromFile(readfile);
	//attributesCount = readUnsignedShortFromFile(readfile);


	while (readfile.good())
	{
		readfile.read(&c, 1);
		d = c;
		printf("%02X", d);
	}
	printf("\n");
    readfile.close();
}

void ClassFile::readMethodsFromFile(ifstream &openFile)
{
	Method * m = nullptr;
	//for (int i = 0; i < methodsCount; ++i)
	{
		m = new Method(openFile);
		methods.push_back(m);
		m = nullptr;
	}
}

unsigned short int ClassFile::readUnsignedShortFromFile(ifstream &openFile)
{
    unsigned short int res = 0;
    char * buf = new char[2];
    openFile.read(buf, 2);
    void * v_char = reinterpret_cast<void *>(buf);
    unsigned short int  * i_char = reinterpret_cast<unsigned short int  *>(v_char);
    res = *i_char;
    delete [] buf;
    return htons(res);
}

unsigned int ClassFile::readUnsignedWordFromFile(ifstream &openFile)
{
    unsigned int res = 0;
    char * buf = new char[4];
    openFile.read(buf, 4);
    void * v_char = reinterpret_cast<void *>(buf);
    unsigned int  * i_char = reinterpret_cast<unsigned int  *>(v_char);
    res = *i_char;
    delete [] buf;
    return htonl(res);
}
