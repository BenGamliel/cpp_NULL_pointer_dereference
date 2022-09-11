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
testClass* GetMYTrueObject(){
    testClass* temp = new testClass(3000);
    return temp;
}
testClass* GetMYNullObject(){
    testClass temp = testClass(3);
    return nullptr;
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
    if (testClass* testObject10 = GetMYTrueObject()){
        std::cout << "10" << std::endl;
        testObject10->someFunc2();
    }
    if (testClass* testObject11 = GetMYNullObject()){
        std::cout << "11" << std::endl;
        (*testObject11).someFunc();
    }
    if (auto* testObject60 = GetMYTrueObject()){
        std::cout << "60" << std::endl;
        testObject60->someFunc2();
    }
    if (auto* testObject61 = getNullPtr(false)){// FP
        std::cout << "61" << std::endl;
        testObject61->someFunc2();
    }
    if (auto* testObject62 = getNullPtr(true)){ // TP
        std::cout << "62" << std::endl;
        testObject62->someFunc2();
    }
    if (testClass* const testObject80 = GetMYTrueObject()){
        std::cout << "80" << std::endl;
        testObject80->someFunc2();
    }
    if (testClass* const testObject81 = getNullPtr(false)){// FP
        std::cout << "81" << std::endl;
        testObject81->someFunc2();
    }
    if (testClass* const testObject82 = getNullPtr(true)){ // TP
        std::cout << "82" << std::endl;
        testObject82->someFunc2();
    }
    if (auto* const testObject70 = GetMYTrueObject()){
        std::cout << "70" << std::endl;
        testObject70->someFunc2();
    }
    if (auto* const testObject71 = getNullPtr(false)){// FP
        std::cout << "71" << std::endl;
        testObject71->someFunc2();
    }
    if (auto* const testObject72 = getNullPtr(true)){ // TP
        std::cout << "72" << std::endl;
        testObject72->someFunc2();
    }

    if(testClass* testObject32 = getNullPtr(true); false){
        std::cout << "3.2" << std::endl << (*testObject32).someFunc();//NOT a result
    }
    else{
        std::cout << "3.3" << std::endl;
        std::cout << (*testObject32).someFunc() << endl;//RESULT
    }
    testClass* testObject4 = getNullPtr(false);
    if(testObject4){
        std::cout << "4" << std::endl << (*testObject4).someFunc() << endl;// NOT a Result
    }
    testClass* testObject5 = getNullPtr(true);
    if(testObject5){
        std::cout << "5" << std::endl << (*testObject5).someFunc() << endl;// NOT a Result
    }
    if (testClass* testObject60 = GetMYTrueObject()){
        std::cout << "60" << std::endl;
        testObject60->someFunc2();
    }
    if (testClass* testObject61 = GetMYNullObject()){
        std::cout << "61" << std::endl;
        (*testObject61).someFunc();
    }
    if(testClass* testObject3 = getNullPtr(true); true){
        std::cout << "3" << std::endl << (*testObject3).someFunc();//RESULT
    }
    else{
        std::cout << "3.1" << std::endl << (*testObject3).someFunc() << endl;// NOT a Result
    }
    return 0;
}

