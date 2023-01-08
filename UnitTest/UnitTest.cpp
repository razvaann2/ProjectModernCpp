#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectModernCpp/DataBase.h"
#include"../ProjectModernCpp/Movie.h"
#include"../ProjectModernCpp/Movie.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
	
		TEST_METHOD(TestingSettersandGetters)
		{
			Movie* m = new Movie();
			m->SetCast("Leonardo Dicaprio");
			std::string s = "Leonardo Dicaprio";
			Assert::AreEqual(s, m->GetCast());
		}
	};
}
 