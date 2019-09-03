# include "../include/ConstantPoolEntry.hpp"

using namespace std;

ConstantPoolEntry::ConstantPoolEntry(unsigned int newTag)
	:tag(newTag)
{
	
}

ConstantClass::ConstantClass(unsigned int tag, ifstream &openFile)
	:ConstantPoolEntry(tag)
{
	name_index = readUnsignedShortFromFile(openFile);
}

string ConstantClass::toString()
{
	string res = "ConstantClass\n";
	res += "Name Index: " + to_string(name_index) + "\n";
	return res;
}

ConstantFieldRef::ConstantFieldRef(unsigned int tag, ifstream &openFile)
	:ConstantPoolEntry(tag)
{
	class_index = readUnsignedShortFromFile(openFile);
	name_and_type_index = readUnsignedShortFromFile(openFile);
}

string ConstantFieldRef::toString()
{
	string res = "ConstantFieldRef\n";
	res += "Class Index: " + to_string(class_index) + "\n";
	res += "Name and Type Index: " + to_string(name_and_type_index) + "\n";
	return res;
}

ConstantMethodRef::ConstantMethodRef(unsigned int tag, ifstream &openFile)
    :ConstantPoolEntry(tag)
{
    class_index = readUnsignedShortFromFile(openFile);
    name_and_type_index = readUnsignedShortFromFile(openFile);
}

string ConstantMethodRef::toString()
{
	string res = "ConstantMethodRef\n";
	res += "Class Index: " + to_string(class_index) + "\n";
	res += "Name and Type Index: " + to_string(name_and_type_index) + "\n";
	return res;
}

ConstantNameAndType::ConstantNameAndType(unsigned int tag, ifstream &openFile)
	:ConstantPoolEntry(tag)
{
	name_index = readUnsignedShortFromFile(openFile);
	descriptor_index = readUnsignedShortFromFile(openFile);
}

string ConstantNameAndType::toString()
{
	string res = "Constant Name And Type\n";
	res += "Name Index: " + to_string(name_index) + "\n";
	res += "Descriptor Index: " + to_string(descriptor_index) + "\n";
	return res;
}

ConstantUtf8::ConstantUtf8(unsigned int tag, ifstream &openFile)
	:ConstantPoolEntry(tag)
{
	length = readUnsignedShortFromFile(openFile);
	bytes = readStringFromFileStream(openFile);
}

string ConstantUtf8::toString()
{
	string res = "ConstantUtf8\n";
	res += "Length: " + to_string(length) + "\n";
	res += bytes + "\n";
	return res;
}

string ConstantUtf8::readStringFromFileStream(ifstream &openFile)
{
	string res;
	char * str_info = new char[length + 1];
	openFile.read(str_info, length);
	str_info[length] = '\0';
	printf("%s\n", str_info);
	res = string(str_info);
	delete [] str_info;
	return res;
}