//
//  Trilateration.cpp
//
//  Created by waynewang on 17/5/14.
//  Copyright (c) 2014 waynewang. All rights reserved.
//
#pragma warning(push)
#pragma warning(disable : 4267)
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#pragma warning(pop)
#include "Trilateration.h"

class TrilaterationTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( TrilaterationTest );
  CPPUNIT_TEST( Test3PositionHasExactSolution );
  CPPUNIT_TEST( Test3PositionHasApporxSolution );
  CPPUNIT_TEST( Test4PositionHasExactSolution );
  CPPUNIT_TEST( Test4PositionHasApporxSolution );
  CPPUNIT_TEST_SUITE_END();
  
public:
   void setUp();
   void tearDown();

   void Test3PositionHasExactSolution();
   void Test3PositionHasApporxSolution();
   void Test4PositionHasExactSolution();
   void Test4PositionHasApporxSolution();
};

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TrilaterationTest );

void
TrilaterationTest::setUp()
{
   // set up
}

void 
TrilaterationTest::tearDown()
{
   // tear down
}

void 
TrilaterationTest::Test3PositionHasExactSolution()
{
   Trilateration worker;
   worker;
   CPPUNIT_FAIL( "not implemented" );
}

void 
TrilaterationTest::Test3PositionHasApporxSolution()
{
   Trilateration worker;
   worker;
   CPPUNIT_FAIL( "not implemented" );
}

void 
TrilaterationTest::Test4PositionHasExactSolution()
{
   Trilateration worker;
   worker; 
   CPPUNIT_FAIL( "not implemented" );
}

void 
TrilaterationTest::Test4PositionHasApporxSolution()
{
   Trilateration worker;
   worker;
   CPPUNIT_FAIL( "not implemented" );
}

///////////////////////////////////////////////////////////////////////////////

// the main function
int
main(int argc, char* argv[])
{
  // Get the top level suite from the registry
  CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest( suite );

  // Change the default outputter to a compiler error format outputter
  //runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(), std::cerr ) );
  // Run the tests.
  bool wasSucessful = runner.run();

  // Wait user input to finish
  std::cout << "Press <ENTER> to finish" << std::endl;
  std::cin.get();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}