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

// DATA TYPE : To handle python property of not requirig data type at a variable specification we use any.
// FUNCTION CALL : To simulate function stack we use vectors. After each function call we can pushback variable to memory. Those variables get poped after function return. 


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


class Memory{
    string min_valid_variabble_name = "a";
    string max_valid_variabble_name = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    int max_valid, min_valid;
    Node* root = nullptr;

public:
    Memory()
    {
        this->max_valid = hash(this->max_valid_variabble_name);
        this->min_valid = hash(this->min_valid_variabble_name);
    }

    void store(string adress, any data){
        address = hash(address);
        if(root == nullptr){ //set root
            root = node(adress, data);
        }
        else{
            if(address == )
        }
    }
    
private:
    void add(int address,any data){}
    
    //uses a 36 number system (36 = 26 letters (a-z) + 10 numbers (0-9)). 
    //Memory is not case sensitive. Example: MyVariable == myvariable; both are stored in the same address.
    //max_valid and min_valid represent the max variable lenght. min_valid_variable_name = "a", it implies that min_variable = 11. Numbers are not 
    int hash(string address){
        result = 0;
        address = Utils::lower(address);
        for(int exponent= 0; i<address.size() ; exponent++ )
            result += char_hash_idx(address[i]) * pow(36, exponent);
        return result;
    }

    int char_hash_idx(char input){
        if(Utils::isNumber(input))
            return input - '0'
        return input - 'a' + 10 
    }

    //
    bool valid_address(){

    }



}
class Node{
    vector<any> data;
    int adress;
    Node* left  = nullptr;
    Node* right = nullptr;
    
public:
    Node(int adress, any data){
        this->adress = adress;
        this->data.pushback(data);
    }

    void setRight(Node& right){
        this->right = right;
    }
    void setleft(Node& left){
        this->left = left;
    }    
}
#endif