#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectModernCpp/DataBase.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestingCheckDatabaseFunction)
		{
			DataBase bazaDeDate;
			bazaDeDate.m_db.sync_schema();
			bool result = bazaDeDate.Checkdatabase("DoNotUse");
			Assert::AreEqual(result, true);
		}
	};
}
