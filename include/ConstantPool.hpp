#ifndef JAVABACKENDCOMPILER_CONSTANTPOOL_H_
#define JAVABACKENDCOMPILER_CONSTANTPOOL_H_

# include <iostream>
# include <string>
# include <vector>
# include <fstream>

# include "ConstantPoolEntry.hpp"

# define CONSTANT_METHOD_REF 0x0A


// Main Constant Pool Class
// Contains a vector of Class Pool Entry

class ConstantPool
{
protected:

	std::vector<ConstantPoolEntry *> ConstantPoolEntries;

	unsigned int size;

public:

	ConstantPool(unsigned int poolSize, std::ifstream &openFile);

    ~ConstantPool();

private:

    void createConstantPoolFromStream(unsigned int poolSize, std::ifstream &openFile);

};

#endif //JAVABACKENDCOMPILER_CONSTANTPOOL_H_