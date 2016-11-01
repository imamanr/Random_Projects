//
//  main.cpp
//  RushHour
//
//  Created by Imama Noor on 8/30/16.
//  Copyright © 2016 Imama. All rights reserved.
//
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include "testRushhour.h"

using namespace CppUnit;
using namespace std;

int main()
{
    //Rushhour * rangeObj = new Rushhour;
    CppUnit::TextUi::TestRunner runner;
    
    cout << "Creating Test Suites:" << endl;
    runner.addTest(TestRR::suite());
    
    cout<< "Running the unit tests."<<endl;
    runner.run();
    

}