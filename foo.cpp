#include "foo.h"

#include <string>

 void foo::setter_name(std::string n){
	name = n;
}

 void foo::setter_initial(std::string i){
	initial = i;
}

 void foo::setter_final(std::string f){
	final = f;
}

std::string foo::get_name(){
	return name;
}

std::string foo::get_initial(){
	return initial;
}

std::string foo::get_final(){
	return final;
}
