#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectModernCpp/DataBase.h"
#include"../ProjectModernCpp/Movie.h"
#include"../ProjectModernCpp/Movie.cpp"
#include <wrl/client.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
	
		TEST_METHOD(TestingSetCast)
		{
			Movie* m = new Movie();
			m->SetCast("Leonardo Dicaprio");
			std::string s = "Leonardo Dicaprio";
			Assert::AreEqual(s, m->GetCast());
		}
		TEST_METHOD(TestingSetCountry)
		{
			Movie* m = new Movie();
			m->SetCountry("Romania");
			std::string s = "Romania";
			Assert::AreEqual(s, m->GetCountry());
		}
		TEST_METHOD(TestingSet)
		{
			Movie* m = new Movie();
			m->SetDateAdded("01.01.2000");
			std::string s = "01.01.2000";
			Assert::AreEqual(s, m->GetDateAdded());
		}
		TEST_METHOD(TestingSetDescription)
		{
			Movie* m = new Movie();
			m->SetDescription("New movie");
			std::string s = "New movie";
			Assert::AreEqual(s, m->GetDescription());
		}
		TEST_METHOD(TestingSetDuration)
		{
			Movie* m = new Movie();
			m->SetDuration("2:22");
			std::string s = "2:22";
			Assert::AreEqual(s, m->GetDuration());
		}
		TEST_METHOD(TestingSetDirector)
		{
			Movie* m = new Movie();
			m->SetDirector("TimBurton");
			std::string s = "TimBurton";
			Assert::AreEqual(s, m->GetDirector());
		}
		TEST_METHOD(TestingSetTitle)
		{
			Movie* m = new Movie();
			m->SetTitle("Wednesday");
			std::string s = "Wednesday";
			Assert::AreEqual(s, m->GetTitle());
		}
		TEST_METHOD(TestStrings)
		{
			Movie* m = new Movie();
			std::string s = "Oare,,Care,,Cine,,When";
			int poz1, poz2;
			poz1 = s.find(",");
			poz2 = s.find(',', poz1 + 1);
			std::string sub;
			m->MovieGetNewString(poz1, poz2, s);
			sub = m->MovieGetNewString(poz1, poz2, s);
			std::string verifier = "Care";
			Assert::AreEqual(verifier, sub);
		}
	};
}
 