//
// Created by Ben Gamliel on 22/08/2022.
//

#ifndef UNTITLED_TESTCLASS_H
#define UNTITLED_TESTCLASS_H
#include <string>
#include <iostream>
using namespace std;
class testClass {

int _param = 0;
public:
    //default constractor
    testClass(){
        std::cout << "default constractor" << std::endl;
    }
    //value contractor
    testClass(int _val){
        this->_param=_val;
        std::cout << "value constractor" << std::endl;
    }
    //default copy constractor
    testClass(const testClass& testclass){
        std::cout << "copy constractor" << std::endl;
    }
    //default destractor
    ~testClass()=default;

    std::string someFunc(){
        std::cout << this->_param << endl;
        return "somefunc in action";
    }

};


#endif //UNTITLED_TESTCLASS_H
