#pragma once
#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 
#include "istream.h"
#include <sstream>

class Update {
	public:

	virtual  const char*  eval()=0;
	virtual const char * name() const =0;

    std::vector<int>Vector_int; 
    std::vector<double>Vector_double; 
	std::vector< char*> Vector_char;
		
};

//==============================================================================
class Min : public Update {
public:

	using Update::Vector_int;
	using Update::Vector_double;
	using Update:: Vector_char;

	const char*  eval() override {

		std::stringstream s;
		if (!Vector_int.empty()){
			std::vector<int>::iterator it; // объявляем итератор
			it = min_element(Vector_int.begin(), Vector_int.end());
			int min_ =Vector_int[std::distance( Vector_int.begin(), min_element(Vector_int.begin(), Vector_int.end()))];
			s << min_;
			m_min = s.str().c_str();
		}
	else if (!Vector_double.empty()){
		std::vector<double>::iterator it; // объявляем итератор
		it = min_element(Vector_double.begin(), Vector_double.end());
		double min_ =Vector_double[std::distance( Vector_double.begin(), min_element(Vector_double.begin(), Vector_double.end()))];
		s << min_;
		m_min = s.str().c_str();
	}
	else {
		std::vector<char*> Vector_char_default {"q", "w", "e","r","t"};
	
		// for (std::vector<char*>::iterator it = Vector_char.begin() ; it!=Vector_char.end() ; ++it)
		char* min_ =Vector_char[std::distance( Vector_char_default.begin(), min_element(Vector_char_default.begin(), Vector_char_default.end()))];
		s << min_;
		m_min = s.str().c_str();
	}
	return  m_min;		
	}

	const char * name() const override {
		return "min";
	}

    private:
	const char* m_min;

};

//=========================================================================
class Max : public Update {
	public:
	using Update::Vector_int;
	using Update::Vector_double;
		// Max() 
		//  	:m_max(std::numeric_limits<double>::min())

const char*  eval() override {
	
    char return_char ;
	std::stringstream s;
	
		if (!Vector_int.empty()){

			 std::vector<int>::iterator it; // объявляем итератор
    
			 it = max_element(Vector_int.begin(), Vector_int.end());

            int max_vector =Vector_int[std::distance( Vector_int.begin(), max_element(Vector_int.begin(), Vector_int.end()))];
	        s << max_vector;
			m_max = s.str().c_str();
		
        }
		else if (!Vector_double.empty())	
	
	{
		std::vector<double>::iterator it; // объявляем итератор
    
			 it = max_element(Vector_double.begin(), Vector_double.end());

			double max_vector =Vector_double[std::distance( Vector_double.begin(), max_element(Vector_double.begin(), Vector_double.end()))];
 			s << max_vector;
			m_max = s.str().c_str();
		
	}
	else {
		std::vector<char*> Vector_char_default {"q", "w", "e","r","t"};
	
		// for (std::vector<char*>::iterator it = Vector_char.begin() ; it!=Vector_char.end() ; ++it)
		char* max_ =Vector_char[std::distance( Vector_char_default.begin(), max_element(Vector_char_default.begin(), Vector_char_default.end()))];
		s << max_;
		m_max = s.str().c_str();
	}
	return  m_max;		
	}
	
		const char* name() const  override {
			return "max";
		
		}
	private:
		const char* m_max;	

};

//====================================================
class Mean :public Update{
	public:

	using Update::Vector_int;
	using Update::Vector_double;
	const char*  eval()  override{
	std::stringstream s;
	if (!Vector_int.empty()){
		double sum = 0;

	for ( int i : Vector_int ) sum += i;
	s << sum / Vector_int.size();
	str_ = s.str().c_str();
    }
    else{
        double sum = 0;

	for ( int i : Vector_double ) sum += i;
	

	s << sum / Vector_double.size();
	str_ = s.str().c_str();

	
    }
	return str_;		
	}
	const char* name() const  override {
			return "mean";
		}
	private:
	const char* str_;

};
//==================================================================
class Std :public Update{
	public:
	
	using Update::Vector_int;
	using Update::Vector_double;
	const char*  eval()  override{
			double sum = 0;
			std::stringstream s;
		if (!Vector_int.empty()){
			
			for ( double i : Vector_int ) sum += i;

			sum= sum / Vector_int.size();		
		
			double var = 0;
			for ( double i : Vector_int ) {
			var += (i- sum) * (i - sum);
			}
			var /= Vector_int.size();
			s << sqrt(var);
			sqrt_ = s.str().c_str();
		}else{
		
			for ( double i : Vector_double ) sum += i;

			sum= sum / Vector_double.size();		
		
			double var = 0;
			for ( double i : Vector_double ) {
			var += (i- sum) * (i - sum);
			}
			var /= Vector_double.size();
			s << sqrt(var);
			sqrt_ = s.str().c_str();
		}	
		
return sqrt_;
	}

	const char* name() const  override {
			return "std";
		}
private:
const char* sqrt_;

};


class PCT90 :public Update{
	public:

    PCT90(double pct) :_pct(pct){};
	using Update::Vector_int;
    using Update::Vector_double;

	const char*  eval()  override{
		
		if (!Vector_int.empty()){
			std::stringstream s;
			const auto n  = Vector_int.size();
			const auto id = (n - 1) * _pct;
			const auto lo = floor(id);
			const auto hi = ceil(id);
			const auto qs = Vector_int[lo];
			const auto h  = (id - lo);
	
	
			s << (1.0 - h) * qs + h * Vector_int[hi];
			pct_ = s.str().c_str();
			  return pct_ ;
		}else{
			std::stringstream s;
			const auto n  = Vector_double.size();
			const auto id = (n - 1) * _pct;
			const auto lo = floor(id);
			const auto hi = ceil(id);
			const auto qs = Vector_double[lo];
			const auto h  = (id - lo);

			s << (1.0 - h) * qs + h * Vector_double[hi];
			pct_ = s.str().c_str();
			  return pct_ ;
		}

	}

	const char* name() const  override {	
		return (_pct==0.90)?"pct90":"pct95";
	}

	private:
	std::vector<double> values_std;
	double _pct;
	const char* pct_;

};

//=======Другая реализация==============
/*
class Base_min {
	public:

	virtual  const char*  _min()=0;
	virtual const char * name_min() const =0;
	virtual  const char*  _max()=0;
	virtual const char * name_max() const =0;


    std::vector<int>Vector_int; 
    std::vector<double>Vector_double; 
		
};

class Medium {
	public:

	virtual  const char*  _mean()=0;
	virtual const char * name_mean() const =0;
	virtual  const char*  _str()=0;
	virtual const char * name_str() const =0;
	virtual  const char*  _pct()=0;
	virtual const char * name_pct() const =0;
	

    std::vector<int>Vector_int; 
    std::vector<double>Vector_double; 
		
};
class Statistict_base :public Base_min{

	using Base::Vector_int;
	using Base::Vector_double;


	const char*  _min() override {

		std::stringstream s;
		if (!Vector_int.empty()){

			 std::vector<int>::iterator it; // объявляем итератор
			it = min_element(Vector_int.begin(), Vector_int.end());
			int min_ =Vector_int[std::distance( Vector_int.begin(), min_element(Vector_int.begin(), Vector_int.end()))];
			s << min_;
			m_min = s.str().c_str();

		}
		else{
			std::vector<double>::iterator it; // объявляем итератор
    		it = min_element(Vector_double.begin(), Vector_double.end());
			double min_ =Vector_double[std::distance( Vector_double.begin(), min_element(Vector_double.begin(), Vector_double.end()))];
			s << min_;
			m_min = s.str().c_str();
		}

		return  m_min;		
	}

	const char * name_min() const override {
		return "min";
	}

	const char*  _max() override {
		char return_char ;
		std::stringstream s;
	
		if (!Vector_int.empty()){

			std::vector<int>::iterator it; // объявляем итератор
    		it = max_element(Vector_int.begin(), Vector_int.end());
            int max_vector =Vector_int[std::distance( Vector_int.begin(), max_element(Vector_int.begin(), Vector_int.end()))];
	        s << max_vector;
			m_max = s.str().c_str();
		
        }
		else{
			std::vector<double>::iterator it; // объявляем итератор
			it = max_element(Vector_double.begin(), Vector_double.end());
			double max_vector =Vector_double[std::distance( Vector_double.begin(), max_element(Vector_double.begin(), Vector_double.end()))];
 			s << max_vector;
			m_max = s.str().c_str();
		
		}
		return  m_max;	

	}
	const char* name_max() const  override { return "max";}

    private:
	const char* m_min;
	const char* m_max;

};

class Statistict_medium :public Medium{
	public:
		Statistict_medium(int pct) :_pct_value(pct){};
		using Medium::Vector_int;
		using Medium::Vector_double;
		const char*  _str()  override{
			double sum = 0;
			std::stringstream s;
			for ( double i : Vector_int ) sum += i;
			sum= sum / Vector_int.size();		
			double var = 0;
			for ( double i : Vector_int ) {
  				var += (i- sum) * (i - sum);
			}
			var /= Vector_int.size();

 			s << sqrt(var);
			sqrt_ = s.str().c_str();
		
		return sqrt_;
		}

		const char* name_str() const  override {
			return "std";
		}
	
		const char*  _pct()  override{
	
    		std::stringstream s;
    		const auto n  = Vector_int.size();
			const auto id = (n - 1) * _pct_value;
			const auto lo = floor(id);
			const auto hi = ceil(id);
			const auto qs = Vector_int[lo];
			const auto h  = (id - lo);
			s << (1.0 - h) * qs + h * Vector_int[hi];
			pct_ = s.str().c_str();
   		return pct_ ;
		}

		const char* name_pct() const  override {
			return "pct90";
		}
	
		const char*  _mean()  override{
			std::stringstream s;
			if (!Vector_int.empty()){
				double sum = 0;

			for ( int i : Vector_int ) sum += i;
			s << sum / Vector_int.size();
			str_ = s.str().c_str();
    	}
    	else{
        	double sum = 0;
			for ( int i : Vector_double ) sum += i;
			s << sum / Vector_double.size();
			str_ = s.str().c_str();
    	}
		return str_;		
	}

	const char* name_mean() const  override {
			return "mean";
		}	

	private:
	std::vector<double> values_std;
    
	int _pct_value;
	const char* pct_;

		const char* sqrt_;
		const char* str_;	
};
*/
