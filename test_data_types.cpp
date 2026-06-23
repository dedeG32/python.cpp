#include <iostream>
#include "data_types.hpp"
using namespace std;


int main(){
    Py_number nbr0 = Py_number("0");
    Py_number nbr1 = Py_number("1000");
    Py_number nbr2 = Py_number("234");
    Py_number nbr3 = nbr1+nbr2+nbr0;
    cout<< "HI " <<nbr0<<endl;
    cout<< "HI " <<nbr1<<endl;
    cout<< "HI " <<nbr2<<endl;
    cout<< "HI " <<nbr3<<endl;
    return 0;
}