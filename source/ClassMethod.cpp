# include "../include/ClassMethod.hpp"

using namespace std;

CodeAttribute::CodeAttribute(ifstream & openFile)
{
	attributeNameIndex = readUnsignedShortFromFile(openFile);
	attributeLength = readUnsignedWordFromFile(openFile);
	maxStack = readUnsignedShortFromFile(openFile);
	maxLocals = readUnsignedShortFromFile(openFile);
	codeLength = readUnsignedWordFromFile(openFile);
	code = readCharsFromFileStream(openFile, codeLength);
}

string CodeAttribute::toString()
{
	string s = "";
	s = "Code Attribute:\n";
	s += "\tAttribute Name Index: " + to_string(attributeNameIndex) + "\n";
	s += "\tAttribute Length: " + to_string(attributeLength) + "\n";
	s += "\tMax Stack: " + to_string(maxStack) + "\n";
	s += "\tMax Locals: " + to_string(maxLocals) + "\n";
	s += "\tCode Length: " + to_string(codeLength) + "\n";
	for (int i = 0; i < codeLength; ++i)
		printf("%x\n", code[i]);
	return s;
}

Method::Method(ifstream &openFile)
{
	buildMethodFromOpenFile(openFile);
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