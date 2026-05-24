// started at 4:52am 05/09/2026 by Deyae Eddine Barga
//Used to execute python.cpp code

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <any>

using namespace std;

class Utils {
public:
    static string lower(string str) {
        for (int i = 0; i < str.size(); i++) 
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + ('a' - 'A');
        return str;
    }
    
    // usually string would be lowered before checking for letters. More efficeint that checking for bot upper and lower cases
    static bool isLetter_lowered(char input){
        return 'a'<= input && input <= 'z';
    }

    // General fct for checking if char is letter.
    static bool isLetter(char input){
        return ('a'<= input && input <= 'z') || ('A'<= input && input <= 'Z');
    }

    static bool isNumber(char input){
        return '0'<= input && input <= '9';
    }

    // used for multiple digit number. 
    // Handles fractions double and float. 
    // Handles negative values nnn                     
    // Skips '_' like in python (example: 1_000_000 == 1000000)
    static bool isNumber(string input){ //This function discards the info about negation and fraction
        bool x = false;
        bool y = false;
        return isNumber(input, x, y);
    }
    //modify negative and fractionnal to reflect if this is a negative and fractionnal number
    static bool isNumber(string input, bool& negative, bool& fractional){
        fractional = false; //keep track of fractional part for float and double (fractionnal numbers)
        negative   = false; //keep track of negative sign
        bool at_least_one_number = false;

        if(input[0]== '-'){
            negative = true;
            input = input.substr(1,input.length());
        }
        cout<<"input is : "<<input<<endl;
        for (char nbr : input){ 
            if(!isNumber(nbr)){
                cout<<nbr<<endl;
                if(nbr == '.' && !fractional){
                    fractional = true;
                }
                else if(nbr!='_')
                    return false;
            }
            else at_least_one_number = true;
        }
        //if((negative || fractional) && input.size()<1) return false; //number composed 
        return at_least_one_number;
    }
    //removes "_" from number
    static string remove_dash(string input){
        string result= "";
        for (char x : input){
            if(x != '_')
                result += x;
        }
        return result;
    }

    static long long to_py_int(string input){
        input = remove_dash(input);
        return stoll(input);
    }

    static double to_py_float(string input){
        input = remove_dash(input);
        return stod(input);
    }

    static void debug_print(string line, any data){
        return;

    }

};

#endif