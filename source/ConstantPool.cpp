# include "../include/ConstantPool.hpp"

// Constant Pool Method 

using namespace std;

// Public Interface

ConstantPool::ConstantPool(unsigned int poolSize, ifstream &openFile)
	:ConstantPoolEntries(), size(poolSize)
{
	createConstantPoolFromStream(poolSize, openFile);
}

string ConstantPool::toString()
{
	string res = "";
	for (auto p : ConstantPoolEntries)
		res += p->toString() + "\n";
	return res;
}

ConstantPool::~ConstantPool()
{
	for (auto p : ConstantPoolEntries)
		delete p;
}

// Private Implementation

void ConstantPool::createConstantPoolFromStream(unsigned int poolSize, ifstream &openFile)
{
	ConstantPoolEntry * cp_entry = nullptr;
    unsigned char c = 0;
	char d = 0;

	for (unsigned int i = 0; i < poolSize - 1; ++i)
	{
		openFile.read(&d, 1);
		c = d;
		printf("%02X\n", c);
		switch (c)
		{
			case CONSTANT_METHOD_REF:
				cout << "ConstantMethodRef" << endl;
				ConstantPoolEntries.push_back(new ConstantMethodRef(CONSTANT_METHOD_REF, openFile));
				break;
			case CONSTANT_FIELD_REF:
				cout << "ConstantFieldRef" << endl;
				ConstantPoolEntries.push_back(new ConstantFieldRef(CONSTANT_FIELD_REF, openFile));
				break;
			case CONSTANT_CLASS:
				cout << "ConstantClass" << endl;
				ConstantPoolEntries.push_back(new ConstantClass(CONSTANT_CLASS, openFile));
				break;
			case CONSTANT_UTF_8:
				cout << "ConstantUtf8" << endl;
				ConstantPoolEntries.push_back(new ConstantUtf8(CONSTANT_UTF_8, openFile));
				break;
			case CONSTANT_NAME_AND_TYPE:
				cout << "Constant Name and Type" << endl;
				ConstantPoolEntries.push_back(new ConstantNameAndType(CONSTANT_NAME_AND_TYPE, openFile));
				break;
			default:
				cout << "Pool tag not found" << endl;
				return;
				//exit(1);

		}
	}
}