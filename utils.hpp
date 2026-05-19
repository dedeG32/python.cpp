// started at 4:52am 05/09/2026 by Deyae Eddine Barga
//Used to execute python.cpp code

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

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
    // Skips '_' like in python (example: 1_000_000 == 1000000)
    static bool isNumber(string input){
        bool dot_used = false; //keep track of fractional part for float an double
        for (char nbr : input){ 
            if(!isNumber(nbr) && nbr == '.' && dot_used){
                if(nbr!='_')
                    return false;
            }
            if(nbr == '.') 
                dot_used = true;
        }
        return true;
    }
};

#endif