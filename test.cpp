#include "utils.hpp"
#include <iostream>
#include <string>
using namespace std;

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

int main(){
    cout << "hello world" << endl;
    //test_lower();
    //test_getline();
    //test_cin_int_string();
    //str_to_int();
    //test_is_number("1_000_000.22");
    //if(nullptr) cout<<"ggggggggggg"<<endl; //test nullptr as bool value
    test_string_concatenation();
    return 0;
}