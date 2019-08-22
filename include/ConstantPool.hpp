#ifndef JAVABACKENDCOMPILER_CONSTANTPOOL_H_
#define JAVABACKENDCOMPILER_CONSTANTPOOL_H_

# include <iostream>
# include <string>
# include <vector>

# include "ConstantPoolEntry.hpp"

// Main Constant Pool Class
// Contains a vector of Class Pool Entry

class ConstantPool
{
protected:

	std::vector<ConstantPoolEntry *> ConstantPoolEntries;

	unsigned int size;

public:

	ConstantPool(unsigned int poolSize, std::ifstream &openFile);

private:


};

#endif //JAVABACKENDCOMPILER_CONSTANTPOOL_H_