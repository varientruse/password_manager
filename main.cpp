#include "foo.h"
#include "funcy.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>
#include <vector>
// currently filling out menu features
// must then refact menu to its own cpp file
// each option will be implemented as a function
// add file creation and editing
// then file reading
/*
int LineCounter(); // I dint remeber this;
*/
int main() {

  int menu_selection;

  std::string user_input;
  std::string user_input1;
  std::string output;
  std::vector<int> vec{};
  std::vector<foo> log;
  // refact file_name to a pointer, help reduce memory usage
  char *ptr;
  char Name_of_File[25];
  ptr = Name_of_File;

  do {
    std::cout << "\n";
    std::cout << "M E N U";
    std::cout << "\n";
    std::cout << "1.add password object";
    std::cout << "\n";
    std::cout << "2.display objects";
    std::cout << "\n";
    std::cout << "3.remove object";
    std::cout << "\n";
    std::cout << "4.create file";
    std::cout << "\n";
    std::cout << "5.write to file";
    std::cout << "\n";
    std::cout << "6.read file to object list";
    std::cout << "\n";
    std::cout << "7. encrypt data (tbd)";
    std::cout << "\n";
    std::cout << "8. decrypt data (tdb)";
    std::cout << "\n";
    std::cout << "9.quit";
    std::cout << "\n";
    scanf("%d", &menu_selection);

    switch (menu_selection) {
    case 1: {
      std::cout << "\n";
      std::cout << "enter password name" << std::endl;
      std::cin >> user_input;
      std::cout << "\n";
      std::cout << "enter a string" << std::endl;
      std::cin >> user_input1;
      std::cout << "\n";

      converter(vec, user_input1);

      translator(vec);

      std::string output{vec.begin(), vec.end()};
      foo entry;
      entry.setter_name(user_input);
      entry.setter_initial(user_input1);
      entry.setter_final(output);
      log.push_back(entry);

      vector_clear(vec);

      break;
    }

    case 2: {
      for (int x = 0; x < log.size(); x++) {
        std::cout << "\n";
        std::cout << "Name: " << log.at(x).get_name();
        std::cout << "\n";
        std::cout << "Intial Input: " << log.at(x).get_initial();
        std::cout << "\n";
        std::cout << "Final Output: " << log.at(x).get_final();
        std::cout << "\n";
      }
      break;
    }

    case 3: {

      int deletion_selection;

      std::cout << "\n";
      std::cout << "select a number to delete";
      std::cout << "\n";
      std::cout << "\n";

      for (int y = 0; y < log.size(); y++) {
        std::cout << y + 1 << ":" << log.at(y).get_name() << " ";
      }

      std::cout << "\n";
      std::cout << "\n";
      scanf("%d", &deletion_selection);

      log.erase(log.begin() + (deletion_selection - 1));

      break;
    }

    case 4: {

       char Name_of_File[25] = {0};

      std::cout << "\n";
      std::cout << "name your file: ";
      std::cout << "\n";
      std::cin >> Name_of_File;

      std::ofstream outfile(Name_of_File);
      outfile.close();

      std::cout << "\n";
      std::cout << Name_of_File << " has been created";
      std::cout << "\n";

       //ptr = nullptr;

      break;
    }

    case 5: {
      std::string user_generated_file_name;

      std::cout << "\n";
      std::cout << "write name of file: ";
      std::cout << "\n";
      std::cin >> user_generated_file_name;

      std::ofstream outfile(user_generated_file_name);

      if (outfile.is_open()) {
        for (int z = 0; z < log.size(); z++) {
          outfile << "\n";
          outfile << log.at(z).get_name();
          outfile << "\n";
          outfile << log.at(z).get_initial();
          outfile << "\n";
          outfile << log.at(z).get_final();
          outfile << "\n";
        }

        outfile.close();
         //ptr = nullptr;
      } else {
        std::cerr << "Error opening file" << std::endl;
      }

      break;
    }
    case 6: {
      int line_count = 0;

      std::cout << "\n";
      std::cout << "type name of file";
      std::cout << "\n";
      std::cin >> ptr;

      std::ifstream file(ptr);
        if (!file.is_open()) {
        std::cerr << "Error in opening file" << std::endl;
      }

      std::string line;

      while (std::getline(file, line)) {
        line_count++;

        if (line.empty()) {
          foo entry;
          log.push_back(entry);
        } else if (line_count % 4 == 2) {
          log.back().setter_name(line);
        } else if (line_count % 4 == 3) {
          log.back().setter_initial(line);
        } else if (line_count % 4 == 0) {
          log.back().setter_final(line);
        }
      }
      
      file.close();
       // ptr = nullptr;
      break;
    }
      case 7:{
        std::cout << "under construction" << std::endl;
        break;
      }
      case 8:{
        std::cout << "under construction" << std::endl;
        break;
      }

    case 9: {
      std::cout << "\n";
      std::cout << "closing program";
      std::cout << "\n";

      break;
    }
    }
  } while (menu_selection != 9);

  return 0;
}
