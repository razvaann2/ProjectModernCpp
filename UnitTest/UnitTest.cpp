#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectModernCpp/DataBase.h"
#include"../ProjectModernCpp/Movie.h"
#include "sqlite_orm/sqlite_orm.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
	
		TEST_METHOD(TestingDatabaseG)
		{
			Movie* m = new Movie();
			m->SetCast("Leonardo Dicaprio");
			std::string s = "Leonardo Dicaprio";
			Assert::AreEqual(s, m->GetCast());
		}
	};
}
