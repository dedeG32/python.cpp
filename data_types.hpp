// Not sure of usefulness of that. I created the file as a reminder for potentially implementing those if I see fit.
// this would be all the potential variable types (py_int -> long long), (py_float -> double), (py_list -> vector), (py_string -> string)
// for now all of them are cpp handled so no fancy class needs to be inmplemented 
// I will try to code the rest of the programme in sort to handle a change If I decide to use classes for types

//This can be useful for applying methodes like .append(), .toint(), etc...

//obselete comments start with __
//__class Py_int{};
//__would implement logic to avoid overflow

// __class Py_float{};
//__maybe mix between Py_int and Py_float using scientific notation to optimize storage. 
//__This would allow to use both int and double as the same type allowing less type checks for operations and 

//class Py_number{};
//handle all sort of numerical value in a 

// class Py_string{};
//useless cpp already handles it.
//unless 

// class Py_list{};

#include <iostream>
#include <string>
#include "utils.hpp"
#include <cmath>
#include <algorithm>
using namespace std;

/*
constexpr unsigned long long MAX_long_size_fct(){
    unsigned long long x = 0;
    return --x;
}

const unsigned long long    MAX_LONG = MAX_long_size_fct(); //euh 05/25/2026 3:57AM. Lord bless me this is out of my knowledge zone.
                                                     // This serves to reconstitute a number after overflows or underflows (no really)
                                                     // The purpuse is to make Py_number an infinite lenght number. (almost) {well far from almost} [exactly of size : size of long long * (size of long long/2) (hopefully)]
constexpr int MAX_long_lenght_fct(){
    int i=0; 
    unsigned long long test_max_size = MAX_LONG;
    while(test_max_size!=0){
        test_max_size /= 10;
        i++;
    }
    return i;
}
const  int          MAX_LONG_LENGHT=MAX_long_lenght_fct();  
//got stuck in interprete number. cannot figure out for to translate a big number (overflow size) to the supported format (ou_flow: how many time it does overflow. And data: the remainder after all overflows)                                                
//combines int and double 
class Py_number{
    unsigned long long  data = 0;
    long long ou_flow= 0; //under or overflow times. can be used to know if number is negative or positive
    int decimal= 0;      //track '.' place if the number is decimal. for scientific notayion
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
            int input_size = input.size();
            if(input_size< MAX_LONG_LENGHT || (input_size== MAX_LONG_LENGHT && less_eq_max_long(input))){
            this->data = stoll(input);
            return
           }
           
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
        bool less_eq_max_long(string input){
            int i = 1;
            for(nbr : input){
                if(stoi(nbr)> slot_nbr(i++))
                    return false;
            }
            return true;
        }
        int slot_nbr(int slot){
            return MAX_LONG / pow(10,MAX_LONG_LENGHT-i) - MAX_LONG / pow(10,MAX_LONG_LENGHT-i+1);
        }
}
*/



class Py_number{
    public:
    string data= "0";
    unsigned long long decimal = 0;
    bool negative = false;
    
    Py_number(){}
    Py_number(string nbr){
        if(! Utils::isNumber(nbr))
        {
            cout<< "\033[33m cannot convert string to Py_number in Py_number(string nbr)\033[0m"<< endl;
            exit(0); 
        }
        else
            this->data = Utils::fix_number(nbr, this->negative, this->decimal);
    }
    Py_number(string data, unsigned long long decimal,bool negative){
        this->data = data;
        this->decimal= decimal;
        this->negative= negative;
    }

    // operators ////
    bool operator==(const Py_number& other) const{
        return ((negative && other.negative) || (!negative && !other.negative)) && equal(equilibrate(*this, other), equilibrate(other, *this)); //same sign and equal
    }

    bool operator<(const Py_number& other) const{
        if((negative && !other.negative) || (!negative && other.negative)) return !negative; //opposite signs
        bool big= bigger(equilibrate(*this, other), equilibrate(other, *this));
        return (negative && !big) || (!negative && big);
    }

    bool operator<=(const Py_number& other) const{
        return (*this)<other || (*this) == other;
    }

    bool operator>(const Py_number& other) const{
        return !((*this)<=other);
    }

    bool operator>=(const Py_number& other) const{
        return !((*this)<other);
    }

    bool operator!=(const Py_number& other) const{
        return !((*this)==other);
    }

    
    Py_number operator+(const Py_number& other) const{
        string first = equilibrate(*this, other);
        string second= equilibrate(other, *this);
        //reverse(first.begin() , first.end());
        //reverse(second.begin(), second.end());
        string result;
        unsigned long long decimal = this->decimal>other.decimal ? this->decimal : other.decimal;
        bool negative;
 
        
        if(this->negative == other.negative){
            negative = this->negative;
            result = add(first, second);
        } 
        else if(absolute_value()> other.absolute_value()){
            negative = this->negative;
            result = substact(first, second);
        }
        else{
            negative = other.negative;
            result = substact(second,first);
        }

        reverse(result.begin() , result.end());
        result = Utils::remove_zeros_from_ends(result, decimal);
        return Py_number(result, decimal ,negative);
    }
    friend std::ostream& operator<<(std::ostream& os, const Py_number& nbr);

    private:
    string equilibrate(const Py_number& first,const Py_number& second)const{//put them in apropriate format for operations
        unsigned long long back_nbr_zeros = first.decimal < second.decimal?  second.decimal - first.decimal : 0;
        unsigned long long front_nbr_zeros = first.data.size() - first.decimal < second.data.size() - second.decimal ? first.data.size() - first.decimal - second.data.size() + second.decimal: 0;
        return Utils::add_zeros_to_ends(first.data, front_nbr_zeros, back_nbr_zeros);
    }
    Py_number absolute_value()const{
        return Py_number(data, decimal, false);
    }
    bool bigger(const string& first, const string& second)const{
        for(int i =0; i<first.size();i++){
            if(first[i]>second[i]) return true;
        }
        return false;
    }
    bool equal(const string& first, const string& second)const{
        for(int i =0; i<first.size();i++){
            if(first[i] != second[i]) return false;
        }
        return true;
    }
    //two ways to do addition 
    // first : stoi(), turning every char from each strings to int add them if bigger than 9 add 1 to next 2 character addition. to avoid int overflow we will treat each character independently (not transforming the whole to int then adding).
    // second: char addition. using th efollowing equation: first[i] + second[i] - '0'. if this bigger than '9' we substact '9' and add 1 to next addition
    //I will type both of them and comment one out
    //I realized after completing that that for the for loop we can start from the end to the front of string so we won't need use reverse (will possibly be introduced in later updates)
    /*string add(const string& first, const string& second)const{
        result = "";
        bool carry = false;
        int test= 0; //just to save operations in loop
        for(int i =0; i<first.size(); i++){
            test = stoi(first[i]) + stoi(second[i]) + carry;
            carry = false;
            if(test>9){
                test -= 10;
                carry = true;
            }
            result += to_string(test);
        }
        if(carry) result += '1';
        return result;
    }*/
    //char variant (with reverse alternative)
    string add(const string& first, const string& second)const{
        string result = "";
        bool carry = false;
        char test; //just to save operations in loop
        for(int i = first.size()-1 ; i>=0; i--){
            test = first[i] + second[i] + carry - '0'; // (-'0') is to balance out one of the char because we are adding 
            carry = false;
            if(test>'9'){
                test -= 10;
                carry = true;
            }
            result += test;
        }
        if(carry) result += '1';
        return result;
    }
    
    string substact(const string& first, const string& second)const{
        string result = "";
        bool carry = false;
        char test; //just to save operations in loop
        for(int i = first.size()-1 ; i>=0; i--){
            test = first[i] - second[i] - carry - '0'; // (-'0') is to balance out one of the char because we are adding 
            carry = false;
            if(test<'0'){
                test += 10;
                carry = true;
            }
            result += test;
        }
        //if(carry) result += '1';
        return result;
    }
};

ostream& operator<<(ostream& os, const Py_number& nbr) {
    if(nbr.negative) os<< '-';
    unsigned long long i = 0;
    for(;i<nbr.data.size();i++){
        os<< nbr.data[i];
        if(i==nbr.decimal) os<<'.';
    }
    return os; // Returns stream reference to allow chaining (e.g., cout << a << b;)
}

//where did i leave last (note to self to know where to pick up)
//-Just fimished the adding
