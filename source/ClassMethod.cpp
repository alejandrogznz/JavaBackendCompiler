# include "../include/ClassMethod.hpp"

using namespace std;

CodeAttribute::CodeAttribute(ifstream & openFile)
{
	char * buf = new char[2048];
	attributeNameIndex = readUnsignedShortFromFile(openFile);
	attributeLength = readUnsignedWordFromFile(openFile);
	maxStack = readUnsignedShortFromFile(openFile);
	maxLocals = readUnsignedShortFromFile(openFile);
	codeLength = readUnsignedWordFromFile(openFile);
	code = readCharsFromFileStream(openFile, codeLength);

	// Ignore the remainder of the code attribute
	cout << attributeLength - 2 - 2 - 4 - codeLength << endl;
	openFile.read(buf, attributeLength - 2 - 2 - 4 - codeLength - 1);
}

unsigned char * CodeAttribute::getCode()
{
	return code;
}

unsigned int CodeAttribute::getCodeLength()
{
	return codeLength;
}

unsigned short int CodeAttribute::getMaxStack()
{
	return maxStack;
}

unsigned short int CodeAttribute::getMaxLocals()
{
	return maxLocals;
}

string CodeAttribute::toString()
{
	string s = "";
	string t = "";
	s = "Code Attribute:\n";
	s += "\tAttribute Name Index: " + to_string(attributeNameIndex) + "\n";
	s += "\tAttribute Length: " + to_string(attributeLength) + "\n";
	s += "\tMax Stack: " + to_string(maxStack) + "\n";
	s += "\tMax Locals: " + to_string(maxLocals) + "\n";
	s += "\tCode Length: " + to_string(codeLength) + "\n";
	cout << "Code: " << endl;
	for (int i = 0; i < codeLength; ++i)
		printf("%x\n", code[i]);
	return s;
}

Method::Method(ifstream &openFile)
{
	buildMethodFromOpenFile(openFile);
}

CodeAttribute * Method::getCodeAttribute()
{
	return codeAttribute;
}

string Method::toString()
{
	string s = "";
	s = "Method: \n";
	s += "Access Flags: " + to_string(accessFlags) + "\n";
	s += "Name Index: " + to_string(nameIndex) + "\n";
	s += "Descriptor Index: " + to_string(descriptorIndex) + "\n";
	s += "Attribute Count: " + to_string(attributesCount) + "\n";
	s += codeAttribute->toString();
	return s;
}

void Method::buildMethodFromOpenFile(ifstream &openFile)
{
	accessFlags = readUnsignedShortFromFile(openFile);
	nameIndex = readUnsignedShortFromFile(openFile);
	descriptorIndex = readUnsignedShortFromFile(openFile);
	attributesCount = readUnsignedShortFromFile(openFile);
	codeAttribute = readCodeAttributeFromFileStream(openFile);
}

CodeAttribute * Method::readCodeAttributeFromFileStream(ifstream &openFile)
{
	return new CodeAttribute(openFile);
}