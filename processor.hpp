// started at 4:13am 05/10/2026 by Deyae Eddine Barga
//Used to preprocess python.cpp code
//The purpose of the processor is to identify the validity of the code
//Check for syntax and indentation errors before interpretation of the code
//The code also include imports in one file and calculate total number of lines

#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <string>
#include <iostream>

using namespace std;


class Processor{
    string keyWords[6] = {"if", "def", "else", "elif", "for", "while"}
    int line_nb = 0;
public:
    Processor()
    {
        for(string line_written = ""; line_written != "end";){
            line_nb ++;
            tokanize

        }
        
    }

    bool valid_syntax(string line){

        return true;
    }
    



}

#endif