#include "funcy.h"

std::vector<int> translator(std::vector<int> &vec) {

  std::vector<char> result{};

  for (int y = 0; y < vec.size(); y++) {
    
    result.push_back(static_cast<char>(vec[y]));
  }

  return element_parser(vec);
}


std::vector<int> vector_clear(std::vector<int> &vec) {

  vec.clear();

  return vec;
}


void scrambler(std::vector<int> &vec) {

  srand(time(0));

  int min = 33;
  int max = 126;

  for (int x = 0; x < vec.size(); x++) {

    int rand_num = min + rand() % (max - min + 1);
    vec[x] = rand_num;
    
  }
  
}


std::vector<int> special_character_parser(std::vector<int> &vec) {
  int flag = 0;

  for (int p = 0; p < vec.size(); p++) {

    if ((vec[p] >= 65 && vec[p] <= 90) || (vec[p] >= 97 && vec[p] <= 122))
      flag = flag + 0;
    else if ((vec[p] >= 33 && vec[p] <= 47) || (vec[p] >= 58 && vec[p] <= 64) ||
             (vec[p] >= 91 && vec[p] <= 96) ||
             (vec[p] >= 123 && vec[p] <= 127)) {
      flag++;
    }
  }

  if (flag == 0) {
    vec.push_back('#');
  }

  return numeral_character_parser(vec);
}


void converter(std::vector<int> &vec, std::string user_input) {

  for (int i = 0; i < user_input.length(); i++) {
// makes int decimal values out of the the userinput loads them into the vector

  
    vec.push_back(static_cast<int>(user_input[i]));
  }


  scrambler(vec);
}


std::vector<int> numeral_character_parser(std::vector<int> &vec) {
  int flag = 0;

  for (int p = 0; p < vec.size(); p++) {

    if ((vec[p] >= 33 && vec[p] <= 47) || (vec[p] >= 58 && vec[p] <= 126)) {
      flag = flag + 0;

    } else if (vec[p] >= 48 && vec[p] <= 57) {
      flag++;
    }
  }
  if (flag == 0) {
    int min = 48;
    int max = 57;

    int rand_num = min + rand() % (max - min + 1);
    char Randchar = rand_num;

    vec.push_back(Randchar);
}

  return capitalization_parser(vec);
}


std::vector<int> random_num(std::vector<int> &vec) {

  srand(time(0));

  int min = 33;
  int max = 126;

  int rand_num = min + rand() % (max - min + 1);
  char Randchar = rand_num;
  vec.push_back(Randchar);

  return vec;
}


std::vector<int> element_parser(std::vector<int> &vec) {
  
  if (vec.size() < 12) {
    for (int i = 12; vec.size() < 12; i--) {

      random_num(vec); // is producing the same random ascii code
                       // till theres 8 elements in side the vector
    }
  }

  scrambler(vec);

  return special_character_parser(vec);
}


std::vector<int> capitalization_parser(std::vector<int> &vec) { 

 int flag = 0;

  for (int p = 0; p < vec.size(); p++) {

    if ((vec[p] >= 33 && vec[p] <= 64) || (vec[p] >= 91 && vec[p] <= 126)) {
      flag = flag + 0;


    } else if (vec[p] >= 65 && vec[p] <= 90) {
      flag++;
  

    }
  }
  if (flag == 0) {
    int min = 65;
    int max = 90;


    int rand_num = min + rand() % (max - min + 1);
    char Randchar = rand_num;
    vec.push_back(Randchar);
  }  

    for (int t = 0; t < vec.size(); t++) {
    std::cout << static_cast<char>(vec[t]);
  }
  std::cout << "\n";

  return vec; 
}



