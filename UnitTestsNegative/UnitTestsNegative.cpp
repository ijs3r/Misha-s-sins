#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Negative/input_data.cpp"
#include "../Negative/ImageHandler.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsNegative
{
	TEST_CLASS(UnitTestsNegative)
	{
	public:
		inline void WriteFile(const char* nameFile,string str) {
			std::ofstream of(nameFile);
			of << str;
		}
		inline string Generate(int n,int m) {
			string s1, s2;
			s1.resize(n * m); s2.resize(n * m);
			for (int i = 0; i < n * m; ++i) 
				if (rand() % 2)
			{
				s1[i] = 'W';
				s2[i] = 'B';
			}
			else {
				s2[i] = 'W';
				s1[i] = 'B';
			}
			return s1 + s2;
		}
#define INPUT_TEST(error_code) Assert::AreEqual((int)InputHandler(nameFile, img1, img2, n, m), error_code);if(error_code ==NO_ERROR){Assert::AreEqual(n, n1);Assert::AreEqual(m, m1);Assert::AreEqual(mistakes, FindMistakes(img1, img2, n, m));}
		const char* nameFile = "NoMistakes.test";
		Image img1, img2;
		int n, m;
		TEST_METHOD(NoMistakes)
		{
			int n1 = 2, m1 = 2, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BBWBWWBW");
			INPUT_TEST(NO_ERROR)
		}
		TEST_METHOD(HasMistakes)
		{
			int n1 = 2, m1 = 2, mistakes = 1;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BBWBWWBB");
			INPUT_TEST(NO_ERROR)
		}
		TEST_METHOD(N_M_Equal_1)
		{
			int n1 = 1, m1 = 1, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BW");
			INPUT_TEST(NO_ERROR)
		}
		TEST_METHOD(N_M_Equal_100)
		{
			int n1 = 100, m1 = 100,mistakes = 0;
			WriteFile(nameFile, to_string(n1)+' ' + to_string(m1) + ' ' + Generate(n1, m1));
			INPUT_TEST(NO_ERROR)
		}
		TEST_METHOD(N_M_Incorrect_Less_1)
		{
			int n1 = -1, m1 = 100, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BBWBWWBB");
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
		TEST_METHOD(N_M_Incorrect_More_100)
		{
			int n1 = 1, m1 = 101, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BBWBWWBB");
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
		TEST_METHOD(Imgs_Incorrect)
		{
			int n1 = 2, m1 = 2, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BKWBWIBW");
			INPUT_TEST(ERROR_INCORRECT_IMAGE)
		}
		TEST_METHOD(Not_enough_data)
		{
			int n1 = 3, m1 = 3, mistakes = 0;
			WriteFile(nameFile, to_string(n1) + ' ' + to_string(m1) + " BBWBWWBB");
			INPUT_TEST(ERROR_NOT_ENOUGH_DATA)
		}
		TEST_METHOD(Empty_file)
		{
			int n1 = 3, m1 = 3, mistakes = 0;
			WriteFile(nameFile, "");
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
		TEST_METHOD(Not_exist_file)
		{
			Assert::AreEqual((int)InputHandler("not_exist.test", img1, img2, n, m), ERROR_FAILED_TO_OPEN_FILE);
		}
		TEST_METHOD(Overflow_N_M)
		{
			int n1 = 3, m1 = 3, mistakes = 0;
			WriteFile(nameFile, "1000000000 10000000000000000");
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
		TEST_METHOD(Float_N_M)
		{
			int n1 = 3, m1 = 3, mistakes = 0;
			WriteFile(nameFile, "1.2  10.25");
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
		TEST_METHOD(N_M_Before_0)
		{
			int n1 = 5, m1 = 2, mistakes = 0;
			WriteFile(nameFile, "00000000" + to_string(n1) + " 0" + to_string(m1) + ' ' + Generate(n1, m1));
			INPUT_TEST(NO_ERROR)
		}
		TEST_METHOD(N_M_ThroughDot)
		{
			int n1 = 5, m1 = 2, mistakes = 0;
			WriteFile(nameFile,  to_string(n1) + "." + to_string(m1) + ' ' + Generate(n1, m1));
			INPUT_TEST(ERROR_INCORRECT_ARRAY_SIZES)
		}
	};
}