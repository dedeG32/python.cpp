#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

void line(){
    cout<<endl;
}
void test_lower(){
    string str = "HELLO MR.DeYYYYYeeee";
    cout<<str<<endl;
    str = Utils::lower(str);
    cout<<str<<endl;
    cout<<endl;
}

void test_getline(){
    string test;
    getline(cin, test);
    cout<<test<<endl;
    cout<<endl;
}

//if we pass a string to an int  the function is skipped and int gets 0.  
void test_cin_int_string(){
    int nb;
    string str;
    cin>> nb;
    cout<<nb<<endl;
    cout<<endl;
    cout<<"\033[33mstr time \033[0m"<<str<<endl; 
    cin>> str;
    cout<<str<<endl;
}

void str_to_int(){
    string str ;
    getline(cin,str);

    cout<< "str = "<< str<<endl;

    int nb = stoi(str);
    cout << nb<< endl;

}

void test_is_number(string nbr){
    cout<< nbr <<" is a number : "<< Utils::isNumber(nbr)<< endl;
}

void test_string_concatenation(){
    string h = "hello";
    h += 'g';
    cout<<h<<endl;
}

void test_int_overflow_limit(){
    line();
    int test = 1;
    while (test>0){
        test++;
    }
    cout<<test--<< " and "<< test <<endl;
    
}
void test_usigned_int_overflow_limit(){
    line();
    unsigned int test = 1;
    while (test>0){
        test++;
    }
    cout<<test--<< " and "<< test <<endl;
}

void test_long_overflow_limit(){
    line();
    long test = 1;
    while (test>0){
        test++;
    }
    cout<<test--<< " and "<< test <<endl;
    
}

void test_unsigned_long_overflow_limit(){
    line();
    unsigned long test = 1;
    while (test>0){
        test++;
    }
    cout<<test--<< " and "<< test <<endl;
    
}

//don't try that
void test_longlong_overflow_limit(){
    line();
    long long test = 1;
    while (test>0){
        test+= 1000000;
        if (test%1000000000000 == 0) cout<<test<<endl;
    }
    line();
    cout<<test--<< " and "<< test <<endl;
    
}

void test_unsigned_longlong_overflow_limit(){
    line();
    unsigned long long test = 1;
    while (test>0){
        test+= 1000000;
        if (test%1000000000000 == 0) cout<<test<<endl;
    }
    cout<<test--<< " and "<< test <<endl;

    
}

// void test_remoce_dash(){
//     line();
//     cout<< Utils::remove_dash("_p_l_a_y_ _OP")<< endl;
// }
//irelevant
// void test_to_pyfloat(){
//     line();
//     double x = Utils::to_py_float("1.2");
//     double y = Utils::to_py_float("11.3");
//     cout<<x+y<<endl;
// }
// void test_to_pyint(){
//     line();
//     long  x = Utils::to_py_float("100"); //Note: even if it returns long long. long is enough to be accepted (no compiler error)
//     long long y = Utils::to_py_float("1_23_0");
//     cout<<x+y<<endl;
// }

void limit_of_long_long(){
    unsigned long long x = 0;
    x--;
    long long y = x/2;
    cout << "unsigned "<<x<< endl;
    cout<< "signed :" << y<< endl;
    for(int i=0; i<100; i++){
        cout<< ++y<< endl;
    }
}

void test_fix_number(){
    line();
    unsigned int dot_idx = 0;
    long long sign= 0;
    cout<< Utils::fix_number("-1_000_000.1", sign, dot_idx)<< endl;
    cout<< "sign = "<< sign<< endl;
    cout<< "dot_idx = "<< dot_idx<< endl;
}
int main(){
    cout << "hello world" << endl;
    //test_lower();
    //test_getline();
    //test_cin_int_string();
    //str_to_int();
    //test_is_number("-.");
    //if(nullptr) cout<<"ggggggggggg"<<endl; //test nullptr as bool value
    //test_string_concatenation();

        //test_int_overflow_limit();
        //test_usigned_int_overflow_limit();
        //test_long_overflow_limit();
        //test_unsigned_long_overflow_limit();
        //test_longlong_overflow_limit();
        //test_unsigned_longlong_overflow_limit();

    //test_remoce_dash();
    //test_to_pyfloat();
    //test_to_pyint();

    //limit_of_long_long();

    test_fix_number();


    return 0;
}