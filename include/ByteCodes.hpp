# ifndef JAVABACKENDCOMPILER_BYTECODES_H
# define JAVABACKENDCOMPILER_BYTECODES_H

/* iconst_<i> */

#define ICONST_0 0x03
#define ICONST_1 0x04
#define ICONST_2 0x05
#define ICONST_3 0x06
#define ICONST_4 0x07
#define ICONST_5 0x08

/* iload_<i> */

#define ILOAD_0 0x1a
#define ILOAD_1 0x1b
#define ILOAD_2 0x1c
#define ILOAD_3 0x1d

/* istore <i> */

#define ISTORE_0 0x3b
#define ISTORE_1 0x3c
#define ISTORE_2 0x3d
#define ISTORE_3 0x3e

/* Arithmetic */

#define IADD 0x60
#define IINC 0x84
#define ISUB 0x64
#define IMUL 0x68
#define ISHL 0x78
#define ISHR 0x7a

/* Control Transfer */

#define IF_ICMPEQ	0x9f
#define IF_ICMPNE	0xa0
#define IF_ICMPLT	0xa1
#define IF_ICMPGE	0xa2
#define IF_ICMPGT	0xa3
#define IF_ICMPLE	0xa4
#define IFEQ		0x99
#define IFNE		0x9a
#define IFGT		0x9d
#define IFGE		0x9c
#define IFLT		0x9b
#define IFLE		0x9e

#define GOTO		0xa7

#define BIPUSH		0x10

#define INVOKESTATIC	0xB8
#define GETSTATIC		0xb2
#define INVOKEVIRTUAL 	0xb6//println

#define RETURN			0xb1
#define IRETURN			0xac

#endif // JAVABACKENDCOMPIILER_BYTECODES_H