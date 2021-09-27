#include "istream.h"
#include "statistict.h"


void static_out(Min *min_value ,Max *max_value,  Mean *mean_value= NULL , Std *std_value= NULL, PCT90 *ptc90_value = NULL,PCT90 *ptc95_value = NULL){
	const size_t statistics_count = 1;

		

	std::vector <Update*> statistics;

	statistics.push_back(min_value);
	statistics.push_back(max_value);

	if (mean_value!= NULL && std_value != NULL && ptc90_value !=NULL &&  ptc95_value !=NULL){ 
		statistics.push_back(mean_value);
    	statistics.push_back(std_value);
    	statistics.push_back(ptc90_value);
		statistics.push_back(ptc95_value);
	}

	for ( Update* i : statistics ) std::cout << i->name() << "\t" <<i->eval() << std::endl;
	}


int main() {

	printf ("Выберети какая будет последовательнось:\n");
	std::vector <const char*> _const = {"1 - int\n", "2 - double\n","3 - char\n"};
    for (const char* type: _const) std ::cout << type;
	
    int _input{0};

	std::cin >> _input;
  	std::cin.clear();
    std::cin.ignore();
	printf ("Введите последовательность :\n");
	switch (_input)
	{
    vectpor vector;
	case 1:{
		
		Interger vector_int;
		Base* _interger(&vector_int);
		std::cin>> vector_int;

		
		Min min_value;
		min_value.Vector_int= vector.int_vector;
		Max max_value ;
		max_value.Vector_int = vector.int_vector;
		Mean mean_value;
		mean_value.Vector_int =vector.int_vector;
        Std std_value;
		std_value.Vector_int =vector.int_vector;
        PCT90 pct90_value(0.90);
        pct90_value.Vector_int  = vector.int_vector;

		PCT90 pct95_value(0.95);
        pct95_value.Vector_int  = vector.int_vector;

		static_out(&min_value, &max_value, &mean_value,&std_value, &pct90_value, &pct95_value);

		break;
	}

	case 2:{
		Double vector_double;
		Base* _double(&vector_double);
		std::cin>> vector_double;


		Min min_value;
		min_value.Vector_double= vector.double_vector;

		Max max_value ;
		max_value.Vector_double= vector.double_vector;

		Mean mean_value;
		mean_value.Vector_double= vector.double_vector;
		
        Std std_value;
		std_value.Vector_double = vector.double_vector;

		PCT90 pct90_value(0.90);
        pct90_value.Vector_double  = vector.double_vector;

		PCT90 pct95_value(0.95);
        pct95_value.Vector_double  = vector.double_vector;

		static_out(&min_value, &max_value, &mean_value,&std_value, &pct90_value, &pct95_value);

		break;
	}

	case 3:{
		Char vector_char;
		Base* _double(&vector_char);
		std::cin>> vector_char;

		Min min_value;
		min_value.Vector_char= vector.char_vector;

		Max max_value ;
		max_value.Vector_char= vector.char_vector;
		break;	
		static_out(&min_value, &max_value);
	}	
	
	default:
	  	return 0;
	}
		return 0;
} 

