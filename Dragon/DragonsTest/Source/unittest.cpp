#include "stdafx.h"
#include "CppUnitTest.h"
#include "Dragons.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace DragonsTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestDragonsClassInitialize)
		{
			Dragon * dragon = new Dragon();
			
			Assert::IsNotNull(dragon);
		}

		TEST_METHOD(TestFly){
			Dragon *dragon = new Dragon("Andrei", 5, 100, 20, 15);
			Dragon *dragon2 = new Dragon("Alin", 5, 80, 30, 13, 4);

			int initialPosition = dragon->getPosition();
			dragon->fly(10);
			int afterPosition = dragon->getPosition();
			Assert::IsFalse(initialPosition != afterPosition);

			delete dragon;
			delete dragon2;
		}
		TEST_METHOD(TestHidraClassInitialize)
		{
			Hidra * hidra = new Hidra();
			
			Assert::IsNotNull(hidra);
		}

		TEST_METHOD(TestLibraryClassInitialize)
		{
		}

		// TBD further tests for the library application.

	};
}