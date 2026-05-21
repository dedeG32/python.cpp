#include "memory.hpp"
#include <iostream>

using namespace std;

int main(){
    Memory memory = Memory();

    memory.store("hello", 10);

    memory.print();
    return 0;
}