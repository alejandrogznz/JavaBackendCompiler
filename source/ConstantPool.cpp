# include "../include/ConstantPool.hpp"

// Constant Pool Method 



using namespace std;

ConstantPool::ConstantPool(unsigned int poolSize, ifstream &openFile)
	:ConstantPoolEntries(), size(poolSize)
{
	createConstantPoolFromStream(poolSize, openFile);
}

ConstantPool::~ConstantPool()
{
	for (auto p : ConstantPoolEntries)
		delete p;
}

void ConstantPool::createConstantPoolFromStream(unsigned int poolSize, ifstream &openFile)
{
	ConstantPoolEntry * cp_entry = nullptr;
    unsigned char c = 0;
	char d = 0;

	for (unsigned int i = 0; i < poolSize; ++i)
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
			default:
				cout << "Pool tag not found" << endl;
				//exit(1);

		}
	}
}