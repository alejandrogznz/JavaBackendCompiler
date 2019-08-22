# ifndef JAVABACKENDCOMPILER_CONSTANTPOOLENTRIES_H_
# define JAVABACKENDCOMPILER_CONSTANTPOOLENTRIES_H_S

class ConstantPoolEntry
{
protected:

	unsigned int tag; 	// Describes the type of the ConstantPoolEntry

public:

	ConstantPoolEntry(unsigned int newTag);

};

class ConstantClass;

class ConstantFieldRef;

class ConstantMethodRef;

class ConstantInterfaceMethodRef;

class ConstantString;

class ConstantInteger;

class ConstantFloat;

class ConstantLong;

class ConstantNameAndType;

class ConstantUtf8;

class ConstantMethodHandle;

class ConstantMethodType;

class ConstantInvokeDynamic;

# endif // JAVABACKENDCOMPILER_CONSTANTpOOLeNTRIES_H_S 
