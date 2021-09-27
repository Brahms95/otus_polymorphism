#pragma once
#include <iostream>
#include <vector>

#include <iostream>
#include <string>

#include <iostream>
 
struct vectpor
{
static inline std::vector<int>int_vector;
static inline std::vector<double> double_vector;
static inline std::vector< char*> char_vector;
};
 
namespace detail {
 
    template <typename TL> void _set     (TL ar) {}
    template <>            void _set<int>(int value) { vectpor vector; vector.int_vector.push_back(value);}
    template <>            void _set<double>(double value) {  vectpor vector; vector.double_vector.push_back(value); }
    template <>            void _set<char* >(char* value) {  vectpor vector; 
    /*Прошу тут помощи , я знаю что передаю адрес ,и записывают алрес,и поэтому все значения меняются, но не хочу менять шаблон 
     /*std::vector<char*>::const_iterator it = vector.char_vector.begin(); */ 
     vector.char_vector.push_back(value); }
}


class Base {
  public:
    enum class CheckResult {
	    Ok = 0,
	    Error = 1
    };
 virtual CheckResult readSelfFrom(std::istream& in) =0;
 template <typename TL> void _set(TL position) {
    
        detail::_set<TL>(position);
    }

};

std::istream& operator>> (std::istream& in, Base& student) 
{
    student.readSelfFrom(in);
    return in;
}

class Double :public Base{

    public:
        CheckResult readSelfFrom(std::istream& in) override  {
            while( in>> val1){  _set(val1);  }

            if (!in.eof() && !in.good()) {
		        std::cerr << "Invalid input data\n";
		        return CheckResult::Error;
	        }
        return CheckResult::Ok;
        }
    private:
        double val1;
};

class Interger :public Base{
    public:
   
    CheckResult readSelfFrom(std::istream& in) override{
        while( in>> val){  _set(val); }

        if (!in.eof() && !in.good()) {
            std::cerr << "Invalid input data\n";
            return CheckResult::Error;
	    }
        return CheckResult::Ok;
    }
	
    private:
        int  val;

};

class Char :public Base{
    public:
   
        CheckResult readSelfFrom(std::istream& in) override{
//не работае запись в ветор char
            while( in>> strtmp){
                const char*  val;
                val = strtmp.c_str(); 
                std::vector< char> char_vector;
                char* val_char = const_cast<char* >(val);
              
                 _set(val_char); }

            if (!in.eof() && !in.good()) {
                std::cerr << "Invalid input data\n";  
                return CheckResult::Error; 
	        }
            return CheckResult::Ok;
        }   
	
    private:
        std::string strtmp;
};
