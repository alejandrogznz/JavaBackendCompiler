# include "../include/ClassMethod.hpp"

using namespace std;

CodeAttribute::CodeAttribute(ifstream & openFile)
{
	attributeNameIndex = readUnsignedShortFromFile(openFile);
	attributeLength = readUnsignedWordFromFile(openFile);
	maxStack = readUnsignedShortFromFile(openFile);
	maxLocals = readUnsignedShortFromFile(openFile);
	codeLength = readUnsignedWordFromFile(openFile);

	cout << attributeNameIndex << endl;
	cout << attributeLength << endl;
	cout << maxStack << endl;
	cout << maxLocals << endl;
	cout << codeLength << endl;
	

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