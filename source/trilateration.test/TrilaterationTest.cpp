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

// Consider an epsilon as below.
const double EPSILON = 1e-6;

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

   // TODO: add more unit tests.
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
    // workers and beacons
    Trilateration worker;
    PosAndDistance2dVec beacons;
    Pos2d location;
    
    beacons.push_back(PosAndDistance2d(Pos2d(0, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, 1), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(2, 0), 1));
    
    worker.CalculateLocation2d(beacons, location);

    // Expected location (1, 0)
    CPPUNIT_ASSERT(std::fabs(location[0] - 1) < EPSILON);
    CPPUNIT_ASSERT(std::fabs(location[1]) < EPSILON);
}

void 
TrilaterationTest::Test3PositionHasApporxSolution()
{
    // workers and beacons
    Trilateration worker;
    PosAndDistance2dVec beacons;
    Pos2d location;
    
    beacons.push_back(PosAndDistance2d(Pos2d(0, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, 1), 2));
    beacons.push_back(PosAndDistance2d(Pos2d(2, 0), 1));
    
    worker.CalculateLocation2d(beacons, location);

    // Expected location (1, -1.5)
    CPPUNIT_ASSERT(std::fabs(location[0] - 1) < EPSILON);
    CPPUNIT_ASSERT(std::fabs(location[1] - -1.5) < EPSILON);
}

void 
TrilaterationTest::Test4PositionHasExactSolution()
{
    // workers and beacons
    Trilateration worker;
    PosAndDistance2dVec beacons;
    Pos2d location;
    
    beacons.push_back(PosAndDistance2d(Pos2d(0, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, 1), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(2, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, -1), 1));
    
    worker.CalculateLocation2d(beacons, location);

    // Expected location (1, 0)
    CPPUNIT_ASSERT(std::fabs(location[0] - 1) < EPSILON);
    CPPUNIT_ASSERT(std::fabs(location[1]) < EPSILON);
}

void 
TrilaterationTest::Test4PositionHasApporxSolution()
{
    // workers and beacons
    Trilateration worker;
    PosAndDistance2dVec beacons;
    Pos2d location;
    
    beacons.push_back(PosAndDistance2d(Pos2d(0, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, 1), 1.5));
    beacons.push_back(PosAndDistance2d(Pos2d(2, 0), 1));
    beacons.push_back(PosAndDistance2d(Pos2d(1, -1), 1.5));
    
    worker.CalculateLocation2d(beacons, location);

    // Expected location (1, 0)
    CPPUNIT_ASSERT(std::fabs(location[0] - 1) < EPSILON);
    CPPUNIT_ASSERT(std::fabs(location[1]) < EPSILON);
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