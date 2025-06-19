#ifndef _FUNCY_H_
#define _FUNCY_H_
#include <vector>
#include <string>
#include <ctime>
#include <iostream>


void scrambler(std::vector<int> &vec);

void converter(std::vector<int> &vec, std::string user_input);

std::vector<int> vector_clear(std::vector<int> &vec);

std::vector<int>translator(std::vector<int> &vec);

std::vector<int> special_character_parser(std::vector<int> &vec);

std::vector<int> numeral_character_parser(std::vector<int> &vec);

std::vector<int> element_parser(std::vector<int> &vec);

std::vector<int> capitalization_parser(std::vector<int> &vec);

std::vector<int> random_num(std::vector<int> &vec);

std::vector<int> lower_case_parser(std::vector<int> &vec);

//void menu ();


#endif // !DEBUGdef _FUNCY_H_
