// Advent_of_code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Day1/Day1_a.h"
#include "Day2/Day2.h"
#include "Day3/Day3.h"
#include "Day4/Day4.h"

#include <sstream>
#include <fstream>

void Day01();
void Day02();
void Day03();
void Day04();


int main()
{
	
	Day04();


	return 0;
}

void Day04()
{
	nsDay04::TestMD5();

}

void Day03()
{
	using namespace	nsDay03;
	T2DMap test0(std::istringstream(std::string(">")));
	int t0 = test0.NHouses();

	T2DMap test1(std::istringstream(std::string("^v")));
	int t1 = test1.NHouses();

	T2DMap test2(std::istringstream(std::string("^>v<")));
	int t2 = test2.NHouses();

	T2DMap test3(std::istringstream(std::string("^v^v^v^v^v")));
	int t3 = test3.NHouses();

	std::ifstream file("Day3/input.txt");
	if(!file.good())
	{
		throw std::exception("File not found!");
	}
	T2DMap test4(file);
	int t4 = test4.NHouses();
}

void Day02()
{
	nsDay02::TD2 tmp;

	nsDay02::_Box debug1(2, 3, 4);
	auto tot1 = debug1.RibbonLenght();

	nsDay02::_Box debug2(1, 1, 10);
	auto tot2 = debug2.RibbonLenght();

	auto result = tmp.TotRibbonLenght();
}

void Day01()
{
	int a = Day1_a::value();
}
