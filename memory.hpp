// started at 4:13am 05/10/2026 by Deyae Eddine Barga
//Used to preprocess python.cpp code
//The purpose of the processor is to identify the validity of the code
//Check for syntax and indentation errors before interpretation of the code
//The code also include imports in one file and calculate total number of lines

//Memory can be organized in two ways each have cons and pros:
////Array: according to the len of variable chosen we can store it in an array of lenght n. 
        // The issue with this approch is that it would allocate mempry to variables that we won't be using. Wasting memory space.
        // Pros, we will have O(1) access to data.
////Tree (choosen): This allow storage of only the data we need. No need to allocate space to non existing data.
                // Cons, More complicated data structure to set up. Takes some time to traverse the tree if no reordering system is set up. 
                // 
////Map: Thought about it late. It provides quick access to variables. And doesn't preallocate memory space. It is a library so it shouldn't take much effort to implement.
// DATA TYPE : To handle python property of not requirig data type at a variable specification we use any.
// FUNCTION CALL : To simulate function stack we use vectors. After each function call we can pushback variable to memory. Those variables get poped after function return. 


//TODO:
//balance the tree after insertion
//function stack handling in store


#ifndef MEMORY_HPP
#define MEMORY_HPP

// To implement python specificity to store any type of variable
#include <vector>
#include <any>
#include <typeinfo>
//////////////////
#include "utils.hpp"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Node{
    //types that are saved 
    //int   : for integers and booleon
    //double: for dooble and floats
    //vector: for python list
    
    public:
    vector<any> data;
    unsigned int address;
    Node* left  = nullptr;
    Node* right = nullptr;
    

    Node(unsigned int address, any data){
        this->address = address;
        this->data.push_back(data);
    }

    void setRight(Node* right){
        this->right = right;
    }
    void setleft(Node* left){
        this->left = left;
    }    
};

class Memory{
    //string min_valid_variabble_name = "a";
    string max_valid_variabble_name = "zzzzzzzzzzz";
    unsigned int max_valid;//, min_valid;
    Node* root = nullptr;
    vector<vector<int>> function_stack;
    enum valid_type{py_int, py_float, py_string ,py_list}; 

public:
    Memory()
    {
        this->max_valid = hash(this->max_valid_variabble_name);
        //this->min_valid = hash(this->min_valid_variabble_name);
    }

    void store(string address, any data){
        int int_address = hash(address);
        ////////
        //error handling / / / / ////   /  // / / / // // / / / // /// / / / /// /////// / /////// / // / / / // / / / / / / / / / / //
        //////////
        if(max_valid && ! valid_address(int_address)){ //check max lenght. can be disabled by setting max_valid_variable_name = "0"
            cout<< "\033[33m variable name execeded maximum lenght of \033[0m" << max_valid_variabble_name<< endl;
            return;
        }
        if(root == nullptr){ //set root
            root = new Node(int_address, data);
        }
        else{  //NOT YET IMPLEMENTED: should handle function stack by appending data instead of replacing it
            Node* node = find(int_address, root);
            if(node == nullptr)  node->address = int_address;
            node->data.back() = data;
        }
    }

    //helper methode for print(Node) recurcive
    void print(){
        print(root);
    }
    
private:
    void add(unsigned int address,any data){}
    //uses a 36 number system (36 = 26 letters (a-z) + 10 numbers (0-9)). 
    //Memory is not case sensitive. Example: MyVariable == myvariable; both are stored in the same address.
    //max_valid and min_valid represent the max variable lenght. min_valid_variable_name = "a", it implies that min_variable = 10. Numbers are not 
    int hash(string address){
        unsigned int result = 0;
        address = Utils::lower(address);
        for(int exponent= 0; exponent<address.size() ; exponent++ )
            result += char_hash_idx(address[exponent]) * pow(35, exponent);
        return result;
    }
    
    string unhash(unsigned int address){
        unsigned int i= 1;
        string result = "";
        for(;i*35<address; i*=35);
        for(unsigned int expo = 1 ; i>1 ; i%=35){
            expo = address / i;
            address %= i;
            result += char_hash_idx(expo);
        }
        cout<<"unhash result is: "<< result<<endl;
        return result;

    }

    int char_hash_idx(char input){
        if(Utils::isNumber(input))
            return input - '0';
        return input - 'a' + 10;
    }
    //reverse hashing
    char char_hash_idx(unsigned int input){
        if(input<10) return '0'+ input;
        return 'a' +input - 10 ;
        cout
    }

    //
    bool valid_address(int address){
        return address < this->max_valid;
    }

    Node* find(int address, Node* node){
        if(node == nullptr) return node;

        if( address > node->address)
            return find(address, node->right);
        if( address < node->address)
            return find(address, node->left);
        if(address == node->address){ //value already exists
            return node;
        }
        return node;
        
    }

    void print(const Node* node){
        if(node->left)
            print(node->left);
        if(node->right)
            print(node->right);

        cout<< unhash(node->address) << endl;//" = "<<node->data << endl;
    }
        //supports 4 types
    
    static valid_type type_check(any data){
        if (data.type() == typeid(int)) return py_int;
        if (data.type() == typeid(float) || data.type() == typeid(double)) return 0x0010;
        if (data.type() == typeid(string)) return 0x0001;

            
    }

};

#endif