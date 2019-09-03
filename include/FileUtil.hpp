# ifndef JAVABACKENDCOMPILER_FILEUTIL_H_
# define JAVABACKENDCOMPILER_FILEUTIL_H_

# include <iostream>
# include <fstream>
# include <arpa/inet.h>

static unsigned char * readCharsFromFileStream(std::ifstream &openFile, unsigned int length)
{
	char * str = new char[length + 1];
	openFile.read(str, length + 1);
	str[length] = '\0';
	unsigned char * uchar = reinterpret_cast<unsigned char *>(str);
	return uchar;
}

static short int readShortFromFile(std::ifstream &openFile);

static unsigned short int readUnsignedShortFromFile(std::ifstream &openFile)
{
    unsigned short int res = 0;
    char * buf = new char[2];
    openFile.read(buf, 2);
    void * v_char = reinterpret_cast<void *>(buf);
    unsigned short int * i_char = reinterpret_cast<unsigned short int *>(v_char);
    res = *i_char;
    delete [] buf;
    return htons(res);
}

static int readWordFromFile(std::ifstream &openFile);

static unsigned int readUnsignedWordFromFile(std::ifstream &openFile)
{
	unsigned int res = 0;
	char * buf = new char[4];
	openFile.read(buf, 4);
	void * v_char = reinterpret_cast<void *>(buf);
	unsigned int * i_char = reinterpret_cast<unsigned int *>(v_char);
	res = *i_char;
	delete [] buf;
	return htonl(res);
}

# endif // JAVABACKENDCOMPILER_FILEUTIL_H_