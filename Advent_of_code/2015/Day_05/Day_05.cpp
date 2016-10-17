#include "Day_05.h"

#include <vector>

namespace nsDay05
{

bool IsVowel(char const &pchar)
{
	static char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
	for(int i = 0; i < 5; ++i)
	{
		if(pchar == vowel[i])
		{
			return true;
		}
	}

	return false;
}

bool TestLine(std::string const &pstr)
{
	

	bool double_char = false;

	static char bad[4][2] =	{ { 'a', 'b'}
						, { 'c', 'd'}
						, { 'p', 'q'}
						, { 'x', 'y'}
						};

	int nvowel = 0;

	char prec = pstr[0];

	if(IsVowel(prec))
	{
		++nvowel;
	}

	for(auto cc = 1u; cc < pstr.size(); ++cc)
	{
		if(IsVowel(pstr[cc]))
		{
			++nvowel;
		}

		if(prec == pstr[cc])
		{
			double_char = true;
		}

		for(int i = 0; i < 4; ++i)
		{
			if(prec == bad[i][0] && pstr[cc] == bad[i][1])
			{
				return false;
			}
		}

		prec = pstr[cc];
	}

	if(nvowel >= 3 && double_char)
	{
		return true;
	}

	return false;
}

void CalcSolution()
{
	if(TestLine("ugknbfddgicrmopn") != true)
	{
		int a = 0;
	}

	if(TestLine("aaa") != true)
	{
		int a = 0;
	}

	if(TestLine("jchzalrnumimnmhp") != false)
	{
		int a = 0;
	}

	if(TestLine("haegwjzuvuyypxyu") != false)
	{
		int a = 0;
	}

	if(TestLine("dvszwmarrgswjxmb") != false)
	{
		int a = 0;
	}

	std::string str;
	int nice = 0;

	std::ifstream file("2015/Day_05/input.txt");
	while(file.good())
	{
		std::getline(file, str);

		if(TestLine(str))
		{
			++nice;
		}
	}
	
	int a = 0;

}

bool TestLine2(std::string const &pstr)
{
	// Test 1
	if(pstr.size() < 4)
	{
		return false;
	}

	bool found = false;

	for(auto i = 1u; i < pstr.size() && !found; ++i)
	{
		for(auto j = i + 2u; j < pstr.size() && !found; ++j)
		{
			if(pstr[i - 1] == pstr[j - 1]
			   && pstr[i] == pstr[j])
			{
				found = true;
			}
		}
	}

	if(!found)
	{
		return false;
	}

	for(auto i = 2u; i < pstr.size(); ++i)
	{
		if(pstr[i] == pstr[i - 2])
		{
			return true;
		}
	}

	return false;

}

void CalcSolution2()
{
	if(TestLine2("qjhvhtzxzqqjkmpb") != true)
	{
		int a = 0;
	}

	if(TestLine2("xxyxx") != true)
	{
		int a = 0;
	}

	if(TestLine2("uurcxstgmygtbstg") != false)
	{
		int a = 0;
	}

	if(TestLine2("ieodomkazucvgmuy") != false)
	{
		int a = 0;
	}

	std::string str;
	int nice = 0;

	std::ifstream file("2015/Day_05/input.txt");
	while(file.good())
	{
		std::getline(file, str);

		if(TestLine2(str))
		{
			++nice;
		}
	}

	int a = 0;

}

}
