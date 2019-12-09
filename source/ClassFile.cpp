# include "../include/ClassFile.hpp"

using namespace std;

ClassFile::ClassFile()
    :fileName("")
{}

ClassFile::ClassFile(const char * filename)
{
    fileName = string(filename);
    buildClassFileFromFile();
}

ClassFile::ClassFile(std::string filename)
{
    fileName = filename;
    buildClassFileFromFile();
}

std::string ClassFile::generateMachineCode()
{
    buildInstructionList(); // Convert From ByteCodes to assembly instructions
    // TODO generateSSA
    // TODO Optimize
    // TODO buildx86
    // TODO Done
    return string();
}

string ClassFile::toString()
{
    stringstream outString;
    outString << "ClassFile: " << fileName << endl;
    outString << "Magic Number: 0x" << hex << magicNumber << endl;
    outString << "Minor Version: 0x" << hex << minorVersion << endl;
    outString << "Major Version: 0x" << hex << majorVersion << endl;
	outString << "Access Flags: 0x" << hex << accessFlags << endl;
	outString << "This Class: 0x" << hex << thisClass << endl;
	outString << "Super Class: 0x" << hex << superClass << endl;
	outString << "Interface Count: 0x" << hex << interfaceCount << endl;
	outString << "Fields Count: 0x" << hex << fieldsCount << endl;
	outString << "Mehtods Count: 0x" << hex << methodsCount << endl;
	outString << "Attributes Count: 0x" << hex << attributesCount << endl;
    outString << "Constant Pool Count: 0x" << hex << constantPoolCount << endl;
	outString << "Constant Pool Members\n" << endl;
	for (auto m : methods)
	{
		outString << m->toString() << endl;
	}
	// TODO outString << constantPool->toString();

    return string(outString.str());
}

// Implementation

void ClassFile::buildClassFileFromFile()
{
    // Open the file and begin reading the contents into the 
    // class. If the file does not exist, throw and exception
    // TODO throw an exception if there is no 0xCAFEBABE in the first 4 bytes
    unsigned int magic_num = 0xCAFEBABE;
    char c;
	unsigned char d;
    ifstream readfile(fileName.c_str(), ios::in | ios::binary);

    // Assignment
    magicNumber = readUnsignedWordFromFile(readfile);
    minorVersion = readUnsignedShortFromFile(readfile);
    majorVersion = readUnsignedShortFromFile(readfile);
    constantPoolCount = readUnsignedShortFromFile(readfile);
	constantPool = new ConstantPool(constantPoolCount, readfile);
	accessFlags = readUnsignedShortFromFile(readfile);
	thisClass = readUnsignedShortFromFile(readfile);
	superClass = readUnsignedShortFromFile(readfile);
	interfaceCount = readUnsignedShortFromFile(readfile);
	// TODO There are no interfaces in this project, so for now we'll skip over them
	fieldsCount = readUnsignedShortFromFile(readfile);
	// TODO There are also no fields in this assignment, so skip over this too
	methodsCount = readUnsignedShortFromFile(readfile);
	readMethodsFromFile(readfile);

	while (readfile.good())
	{
		readfile.read(&c, 1);
		d = c;
		printf("%02X", d);
	}
    
	printf("\n");
    readfile.close();
}

void ClassFile::readMethodsFromFile(ifstream &openFile)
{
	Method * m = nullptr;
	for (int i = 0; i < methodsCount; ++i)
	{
		m = new Method(openFile);
		methods.push_back(m);
		m = nullptr;
	}
}

unsigned short int ClassFile::readUnsignedShortFromFile(ifstream &openFile)
{
    unsigned short int res = 0;
    char * buf = new char[2];
    openFile.read(buf, 2);
    void * v_char = reinterpret_cast<void *>(buf);
    unsigned short int  * i_char = reinterpret_cast<unsigned short int  *>(v_char);
    res = *i_char;
    delete [] buf;
    return htons(res);
}

unsigned int ClassFile::readUnsignedWordFromFile(ifstream &openFile)
{
    unsigned int res = 0;
    char * buf = new char[4];
    openFile.read(buf, 4);
    void * v_char = reinterpret_cast<void *>(buf);
    unsigned int  * i_char = reinterpret_cast<unsigned int  *>(v_char);
    res = *i_char;
    delete [] buf;
    return htonl(res);
}

// Machine Code Generation

void ClassFile::buildInstructionList()
{
    // Iterate through the static methods, not including A[0]
    unsigned int sz = methods.size();
    CodeAttribute * codeAttribute = nullptr;
	unsigned int length = 0;
	unsigned char * code = nullptr;
	
	// Read the instructions of the bytecode
    for (int i = 1; i < sz; ++i)
    {
		codeAttribute = methods[i]->getCodeAttribute();
		code = codeAttribute->getCode();
		length = codeAttribute->getCodeLength();
		readByteCode(code, length);
    }
}

void ClassFile::readByteCode(unsigned char * code, unsigned int length)
{
	Instruction * temp = nullptr;
	vector<Instruction *> instr;

	unsigned char op1 = 0;
	unsigned char op2 = 0;
	int stackSize     = 0;
	int i = 0;
	while (i < length)
	{
		cout << hex <<(int)code[i] << endl;


		switch((int)code[i])
		{
			// Move Instruction
			case ICONST_0:
				op1 = 0;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			case ICONST_1:
				op1 = 1;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			case ICONST_2:
				op1 = 2;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			case ICONST_3:
				op1 = 3;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			case ICONST_4:
				op1 = 4;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			case ICONST_5:
				op1 = 5;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				break;

			// Move Instruction
			case ILOAD_0:
				op1 = 0;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new LocalVariable(op1));
				instr.push_back(temp);
				break;
			case ILOAD_1:
				op1 = 1;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new LocalVariable(op1));
				instr.push_back(temp);
				break;

			case ILOAD_2:
				op1 = 2;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new LocalVariable(op1));
				instr.push_back(temp);
				break;

			case ILOAD_3:
				op1 = 3;
				temp = new MoveInstruction((unsigned char)code[i], new StackVariable(stackSize++), new LocalVariable(op1));
				instr.push_back(temp);
				break;

			// Move Instruction
			case ISTORE_0:
				op1 = 0;
				temp = new MoveInstruction((unsigned char)code[i], new LocalVariable(op1), new StackVariable(--stackSize));
				instr.push_back(temp);
				break;
			case ISTORE_1:
				op1 = 1;
				temp = new MoveInstruction((unsigned char)code[i], new LocalVariable(op1), new StackVariable(--stackSize));
				instr.push_back(temp);
				break;
			case ISTORE_2:
				op1 = 2;
				temp = new MoveInstruction((unsigned char)code[i], new LocalVariable(op1), new StackVariable(--stackSize));
				instr.push_back(temp);
				break;
			case ISTORE_3:
				op1 = 3;
				temp = new MoveInstruction((unsigned char)code[i], new LocalVariable(op1), new StackVariable(--stackSize));
				instr.push_back(temp);
				break;

			// Aritmetic
			case IADD:
				
			case IINC:
			case ISUB:
			case IMUL:
			case ISHL:
			case ISHR:
				cout << "Arithmentic instruction" << endl;
				break;

			// Control Transfer
			case IF_ICMPEQ:
			case IF_ICMPNE:
			case IF_ICMPLT:
			case IF_ICMPGE:
			case IF_ICMPGT:
			case IF_ICMPLE:
			
			case IFEQ:
			case IFNE:
			case IFGT:
			case IFGE:
			case IFLT:
			case IFLE:

			case GOTO:

			case BIPUSH:
				op1 = code[i + 1];
				temp = new MoveInstruction((unsigned char) code[i], new StackVariable(stackSize++), new Value(op1));
				instr.push_back(temp);
				++i;
				break;

			case INVOKESTATIC:
			case GETSTATIC:
			case INVOKEVIRTUAL:

			case RETURN:
			case IRETURN:

			default:
				break;
		}

		++i;
	}
	for (auto e : instr) {
		cout << e->getString() << endl;
	}
}

