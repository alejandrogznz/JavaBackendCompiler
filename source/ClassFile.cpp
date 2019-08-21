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

string ClassFile::getString()
{
    stringstream outString;
    outString << "ClassFile: " << fileName << endl;
    outString << "Magic Number: 0x" << hex << magicNumber << endl;
    outString << "Minor Version: 0x" << hex << minorVersion << endl;
    outString << "Major Version: 0x" << hex << majorVersion << endl;
    outString << "Constant Pool Count: 0x" << hex << constantPoolCount << endl;


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
    ifstream readfile(fileName.c_str(), ios::in | ios::binary);

    // Assignment
    magicNumber = readUnsignedWordFromFile(readfile);
    minorVersion = readUnsignedShortFromFile(readfile);
    majorVersion = readUnsignedShortFromFile(readfile);
    constantPoolCount = readUnsignedShortFromFile(readfile);

    readfile.close();
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
