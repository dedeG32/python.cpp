// Not sure of usefulness of that. I created the file as a reminder for potentially implementing those if I see fit.
// this would be all the potential variable types (py_int -> long long), (py_float -> double), (py_list -> vector), (py_string -> string)
// for now all of them are cpp handled so no fancy class needs to be inmplemented 
// I will try to code the rest of the programme in sort to handle a change If I decide to use classes for types

//This can be useful for applying methodes like .append(), .toint(), etc...

// class Py_int{};
//would implement logic to avoid overflow

// class Py_float{};
//maybe mix between Py_int and Py_float using scientific notation to optimize storage. 
//This would allow to use both int and double as the same type allowing less type checks for operations and 

// class Py_string{};
//useless cpp already handles it.
//unless 

// class Py_list{};

#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

constexpr unsigned long long MAX_long_size_fct(){
    unsigned long long x = 0;
    return --x;
}

const unsigned long long    MAX_LONG_SIZE = MAX_long_size_fct(); //euh 05/25/2026 3:57AM. Lord bless me this is out of my knowledge zone.
                                                     // This serves to reconstitute a number after overflows or underflows (no really)
                                                     // The purpuse is to make Py_number an infinite lenght number. (almost) {well far from almost} [exactly of size : size of long long * (size of long long/2) (hopefully)]
constexpr int MAX_long_lenght_fct(){
    int i=0; 
    unsigned long long test_max_size = MAX_LONG_SIZE;
    while(test_max_size!=0){
        test_max_size /= 10;
        i++;
    }
    return i;
}
const  int          MAX_LONG_LENGHT=MAX_long_lenght_fct();                                                  
//combines int and double 
class Py_number{
    unsigned long long  data = 0;
    long long ou_flow= 0; //under or overflow times. can be used to know if number is negative or positive
    unsigned int decimal= 0;      //track '.' place if the number is decimal
    //bool negative = false;  //outdated //allows the use of the full 64 bites in data 

    public:
        Py_number(unsigned long long  data, long long ou_flow, unsigned int decimal){
            this->data = data;
            this->ou_flow = ou_flow;
            this->decimal = decimal;
        }

        Py_number(string nbr){
            nbr = Utils::fix_number(nbr, this->ou_flow, this->decimal);
            interprete_number(nbr);
        }

        void interprete_number(string input){

        }

        static string reconstitute_number(string input, const long long& sign, const unsigned int& dot_idx, bool with_sign = true, bool with_dot = true){

        }

        private:
        bool overflow(unsigned long long nbr)(
            return this->data + nbr < nbr;
        )
        bool underflow(unsigned long long nbr)(
            return this->data - nbr > this->data;
        )
};

