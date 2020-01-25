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
    
   Operand<class Int16> operand2(9);
    cout << operand2.toString();
    cout << endl;
    cout << endl;
    Operand<class Int8> operand3(8);
    cout << operand3.toString();
    cout << endl;
    cout << endl;
    
    IOperand* results(0);
    results = operand2 + operand3;
    cout << results->toString();
    cout << endl;
    cout << endl;
    
    Operand<class Int32> operand4(4000);
    cout << operand4.toString();
    cout << endl;
    cout << endl;
    
    
    results = operand3 + operand4;
    cout << results->toString();
    
    return 0;
}

