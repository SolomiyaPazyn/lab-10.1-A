#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 10.1A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(4, calc_n(1000)); // Number 1000 has 4 digits
			Assert::AreEqual(1, calc_n(5));    // Number 5 has 1 digit
			Assert::AreEqual(3, calc_n(123));  // Number 123 has 3 digits
		}
	};
}
