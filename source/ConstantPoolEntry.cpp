# include "../include/ConstantPoolEntry.hpp"

using namespace std;

ConstantPoolEntry::ConstantPoolEntry(unsigned int newTag)
	:tag(newTag)
{
	
}

ConstantMethodRef::ConstantMethodRef(unsigned int tag, ifstream &openFile)
    :ConstantPoolEntry(tag)
{
    class_index = readUnsignedShortFromFile(openFile);
    name_and_type_index = readUnsignedShortFromFile(openFile);
}