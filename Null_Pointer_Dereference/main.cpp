#include <iostream>
#include "testClass.h"
using namespace std;
testClass * getNullPtr(bool x){
//    cout << " in getNullPtr " << endl;
   testClass* temp = new testClass(5);
//   cout << "address of temp: "  << std::dec<< (&temp) << endl;
   if(x){
       return nullptr;
   }
    return temp;
}
testClass* GetMYTrueObject(){
    testClass* temp = new testClass(3000);
    return temp;
}
testClass* GetMYNullObject(){
    return nullptr;
}


int main() {


    std::cout << endl;
    if (auto* const testObject70 = GetMYTrueObject()){ //SAST result // FP
        std::cout << "70" << std::endl;
        testObject70->someFunc2();
    }
    if (auto* const testObject71 = getNullPtr(false)){ //SAST result // FP
        std::cout << "71" << std::endl;
        testObject71->someFunc2();
    }
    if (auto* const testObject72 = getNullPtr(true)){ //SAST result // FP
        std::cout << "72" << std::endl;
        testObject72->someFunc2();
    }
    auto* const testObject90 = GetMYTrueObject();
    if(testObject90){
        std::cout << "90" << std::endl;
        testObject90->someFunc2();
    }
    auto* const testObject91 = getNullPtr(false);
    if(testObject91){
        std::cout << "91" << std::endl;
        testObject91->someFunc2();
    }
    auto* const testObject92 = getNullPtr(true);
    if(testObject92){
        std::cout << "92" << std::endl;
        testObject92->someFunc2();
    }
    std::cout << endl;
    if (testClass* const testObject80 = GetMYTrueObject()){ //SAST result // FP
        std::cout << "80" << std::endl;
        testObject80->someFunc2();
    }
    if (testClass* const testObject81 = getNullPtr(false)){ //SAST result // FP
        std::cout << "81" << std::endl;
        testObject81->someFunc2();
    }
    if (testClass* const testObject82 = getNullPtr(true)){ //SAST result // FP
        std::cout << "82" << std::endl;
        testObject82->someFunc2();
    }
    std::cout << endl;

    /*
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
 */
    /*
     *     if(testClass* testObject3 = getNullPtr(true); true){
        std::cout << "3" << std::endl << (*testObject3).someFunc();//RESULT
    }
    else{
        std::cout << "3.1" << std::endl << (*testObject3).someFunc() << endl;// NOT a Result
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
    if (auto* testObject60 = GetMYTrueObject()){ // NOT a result
        std::cout << "60" << std::endl;
        testObject60->someFunc2();
        std::cout << endl;

    }
    if (auto* testObject61 = getNullPtr(false)){ // NOT a result
        std::cout << "61" << std::endl;
        testObject61->someFunc2();
    }
    if (auto* testObject62 = getNullPtr(true)){ // NOT a result
        std::cout << "62" << std::endl;
        testObject62->someFunc2();
    }
     */
    return 0;
}

