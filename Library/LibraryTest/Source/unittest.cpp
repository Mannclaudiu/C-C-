#include "stdafx.h"
#include "CppUnitTest.h"
#include "Library.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LibraryTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestAuthorClassInitialize)
		{
			Author * bookAuthor = new Author();

			Assert::IsNotNull(bookAuthor);
			delete bookAuthor;
		}

		TEST_METHOD(TestBookClassInitialize)
		{
			Book * aBook = new Book();

			Assert::IsNotNull(aBook);
			delete aBook;
		}

		TEST_METHOD(TestLibraryClassInitialize)
		{
			Library * publicLibrary = new Library();

			Assert::IsNotNull(publicLibrary);
			delete publicLibrary;
		}

		// TBD further tests for the library application.

	};
}