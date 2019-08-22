# include "../include/ConstantPool.hpp"

using namespace std;

ConstantPool::ConstantPool(unsigned int poolSize, ifstream &openFile)
	:ConstantPoolEntries(), size(poolSize)
{
	ConstantPoolEntry * poolEntry;

	for (int i = 0; i < poolSize; ++i)
	{
		cout << i << endl;
	}

}