# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <arpa/inet.h>

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