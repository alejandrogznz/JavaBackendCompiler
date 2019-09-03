# include <iostream>
# include <fstream>

# include "include/ClassFile.hpp"

using namespace std;

int 
main(int argc, char * argv[])
{
    ClassFile cf("Test.class");
    cout << cf.toString();
}