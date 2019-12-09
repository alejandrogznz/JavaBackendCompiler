# include "./../include/Instruction.hpp"

using namespace std;

Value::Value(int value)
	:value(value)
{

}

string Value::getString()
{
	return string(to_string(value));
}

AbstractVariable::AbstractVariable(unsigned int value)
	:Value(value)
{

}

StackVariable::StackVariable(unsigned int index)
	:AbstractVariable(index)
{

}

string StackVariable::getString()
{
	return string("stack" + to_string(value));
}

LocalVariable::LocalVariable(unsigned int index)
	:AbstractVariable(index)
{

}

string LocalVariable::getString()
{
	return string("local" + to_string(value));
}
//// Instructions ////

Instruction::Instruction(unsigned int opcode)
	:opcode(opcode)
{

}

MoveInstruction::MoveInstruction(unsigned char opcode, Value * op1, Value * op2)
	:Instruction(opcode), op1(op1), op2(op2)
{
	
}

std::string MoveInstruction::getString()
{
	return std::string("MOV " + op1->getString() + ", " + op2->getString());
}