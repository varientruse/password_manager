#ifndef _FOO_H_
#define _FOO_H_ 
#include <iostream>
#include <string>

class foo{

private:
    
  std::string name;
  std::string initial;
  std::string final;
  
public:
 
  void setter_name(std::string n);

  void setter_initial(std::string i);

  void setter_final(std::string f);
  
  std::string get_name();

  std::string get_initial();

  std::string get_final();

  /*
  foo::foo (std::string x, std::string y, std::string z) 
      : name{x}, initial{y}, final{z} {
      std::cout << "constructor called" << std::endl;
  }*/
  
};

#endif
