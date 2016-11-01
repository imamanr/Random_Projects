//
//  testRushhour.h
//  RushHour
//
//  Created by Imama Noor on 8/31/16.
//  Copyright © 2016 Imama. All rights reserved.
//

#ifndef testRushhour_h
#define testRushhour_h


#endif /* testRushhour_h */
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCase.h>

#include "Rushour.h"

using namespace std;

class TestRR : public CppUnit::TestFixture {
private:
    Rushhour * RushhourObj;
public:
    TestRR() { RushhourObj = new Rushhour;}
    virtual ~TestRR() {
        delete RushhourObj;
    }
    
    static CppUnit::Test *suite() {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestingCombinations");
        
        suiteOfTests->addTest(new CppUnit::TestCaller<TestRR>("Test1 - Add/query Rush hour",
                                                              &TestRR::testRushReal_Process ));
        suiteOfTests->addTest(new CppUnit::TestCaller<TestRR>("Test2 - Add Rush hour",
                                                              &TestRR::testRushHourAQ_Process ));
        
        return suiteOfTests;
    }
    
    /// Setup method
    void setUp() {
        RushhourObj = new Rushhour;
    }
    
    /// Teardown method
    void tearDown() {
        delete RushhourObj;
    }
    
protected:
    void testRushHourAQ_Process() {
        int val = 0;
        int valClass = RushhourObj->AddTimeSpan(3, 4);
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(13, 14);
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(13, 14);
        CPPUNIT_ASSERT( valClass == val );
        
        
        valClass = RushhourObj->AddTimeSpan(3.5, 4.5);
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(3.6, 4.1);
        CPPUNIT_ASSERT( valClass == val );
        bool det = RushhourObj->IsRushHour(4);
        
        CPPUNIT_ASSERT( valClass == val );
        CPPUNIT_ASSERT( det == true );
 
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(14, 12);
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(0.5, 0.01);
        CPPUNIT_ASSERT( valClass == val );
        valClass = RushhourObj->AddTimeSpan(.001, .009);
        CPPUNIT_ASSERT( valClass == val );
        det = RushhourObj->IsRushHour(0);
        
        CPPUNIT_ASSERT( valClass == val );
        CPPUNIT_ASSERT( det == false );
        

    }
    void testRushReal_Process() {
        int val = 0;
        int valClass = RushhourObj->AddTimeSpan(5, 6);
        
        CPPUNIT_ASSERT( valClass == val );
    }
};
