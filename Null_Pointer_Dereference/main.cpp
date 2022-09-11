#include <iostream>
#include "testClass.h"
using namespace std;
testClass * getNullPtr(bool x){
    cout << " in getNullPtr " << endl;
   testClass temp = testClass(5);
   cout << "address of temp: "  << std::dec<< (&temp) << endl;
   if(x){
       return nullptr;
   }
    return &temp;
}

int main() {
    if(testClass* testObject0 = getNullPtr(false)){
        std::cout << "0" << std::endl << (*testObject0).someFunc() << endl;//NOT a Result
    }
    if(testClass* testObject1 = getNullPtr(false); testObject1){
        std::cout << "1" << std::endl << (*testObject1).someFunc() << endl;//NOT a Result
    }
    if(testClass* testObject2 = getNullPtr(true)){
        std::cout << "2" << std::endl << (*testObject2).someFunc();// NOT a Result
    }
    if(testClass* testObject3 = getNullPtr(true); true){
        std::cout << "3" << std::endl << (*testObject3).someFunc();//RESULT
    }
    else{
        std::cout << "3.1" << std::endl << (*testObject3).someFunc() << endl;// NOT a Result
    }
    if(testClass* testObject32 = getNullPtr(true); false){
        std::cout << "3.2" << std::endl << (*testObject32).someFunc();//NOT a result
    }
    else{
        std::cout << "3.3" << std::endl << (*testObject32).someFunc() << endl;//RESULT
    }
    testClass* testObject4 = getNullPtr(false);
    if(testObject4){
        std::cout << "4" << std::endl << (*testObject4).someFunc() << endl;// NOT a Result
    }
    testClass* testObject5 = getNullPtr(true);
    if(testObject5){
        std::cout << "5" << std::endl << (*testObject5).someFunc() << endl;// NOT a Result
    }
    return 0;
}

