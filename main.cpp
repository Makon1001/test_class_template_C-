//
//  main.cpp
//  test_class_template
//
//  Created by Manuel Konrath on 23/01/2020.
//  Copyright © 2020 Manuel Konrath. All rights reserved.
//

#include <iostream>
#include <cstdint>
#include "TOperand.hpp"
#include <float.h>


using namespace std;

int main(int argc, const char * argv[]) {
   /* Operand<class Operand8> operand(12);
    cout << operand.toString();
    cout << endl;
    cout << endl;
    
    Operand<class Operand8> operand1(1);
    cout << operand1.toString();
    cout << endl;
    cout << endl;
    
    IOperand* results(0);
    results = operand + operand1;
    cout << results->toString();
    cout << endl;
    cout << endl;

*/
   Operand<typename::int8_t> operand(9);
    cout << operand.toString();
    cout << endl;
    cout << endl;
    Operand<typename::int8_t> operand1(8);
    cout << operand1.toString();
    cout << endl;
    cout << endl;
    
    IOperand* results(0);
    results = operand % operand1;
    cout << results->toString();
    cout << endl;
    cout << endl;
    
    Operand<typename::int32_t> operand2(4000);
    cout << operand2.toString();
    cout << endl;
    cout << endl;
    

    Operand<float> operand3(0.1);
    cout << operand3.toString();
    cout << endl;
    cout << endl;
    
    IOperand* results1(0);
    results1 = operand2 / operand3;
    cout << results1->toString();
    cout << endl;
    cout << endl;
    

    return 0;
}

