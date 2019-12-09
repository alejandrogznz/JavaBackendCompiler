# ifndef JAVABACKENDCOMPILER_INSTRUCTION_H
# define JAVABACKENDCOMPILER_INSTRUCTION_H

# include <iostream>
# include "Instruction.hpp"

class Value
{
protected:

	int value;

public:

	Value();

	Value(int value);

	virtual std::string getString();

};

class AbstractVariable
	: public Value
{

	bool isStack;

public:

	AbstractVariable();

	AbstractVariable(unsigned int value);
};

class StackVariable
	: public AbstractVariable
{

public:

	StackVariable();

	StackVariable(unsigned int index);

	std::string getString();

};

class LocalVariable
	: public AbstractVariable
{

public:

	LocalVariable();

	LocalVariable(unsigned int index);

	std::string getString();

};

////////////////////////////////////////////////////////
//						Instruction Base Class

class Instruction
{
	unsigned char opcode;

public:

	Instruction();

	Instruction(unsigned int opcode);

	virtual std::string getString() = 0;
};

class MoveInstruction
	: public Instruction
{

	Value * op1;

	Value * op2;

public:

	MoveInstruction();

	MoveInstruction(unsigned char opcode, Value * op1, Value * op2);

	std::string getString();
	
};

class BinaryInstruction
	: public Instruction
{

};

class CmpInstruction
	: public Instruction
{

};

class CondBranchInstruction
	: public Instruction
{

};

class UncondBranchInstruction
	: public Instruction
{

};

class CallInstruction
	: public Instruction
{

};

class ReturnInstruction
	: public Instruction
{

};

class PhiInstruction
	: public Instruction
{

};

# endif //JAVABACKENDCOMPILER_INSTRUCTION_H