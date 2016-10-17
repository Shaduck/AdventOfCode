// Advent_of_code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "2015/Day_01/Day_01_a.h"
#include "2015/Day_02/Day_02.h"
#include "2015/Day_03/Day_03.h"
#include "2015/Day_04/Day_04.h"
#include "2015/Day_05/Day_05.h"
#include "2015/Day_06/Day_06.h"
#include "2015/Day_07/Day_07.h"

#include <sstream>
#include <fstream>

void Day01();
void Day02();
void Day03();
void Day04();
void Day05();

int main()
{
	
	nsDay07::CalcSolution();


	return 0;
}

void Day05()
{
	nsDay05::CalcSolution2();
}

void Day04()
{
	//nsDay04::TestMD5();
	nsDay04::CalcSolution();
}

void Day03()
{
	nsDay03::CalcSolution();
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
