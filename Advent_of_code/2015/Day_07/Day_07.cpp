#include "Day_07.h"

//#include <vector>

namespace nsDay07
{



//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////

std::string ExtractToken(std::string &pstr, std::string const &delim)
{
	auto pos = pstr.find(delim);
	std::string ret = pstr.substr(0, pos);
	pstr = pstr.substr(pos + delim.size());

	return ret;
}


void ParseLine(std::string pline, TGrid_Int &pgrid)
{
	enum class ecmd
	{
		NONE,
		SET_ON,
		SET_OFF,
		TOGGLE
	};

	ecmd operation = ecmd::NONE;

	// turn on 489,959 through 759,964
	std::string delim(" ");

	std::string work = ExtractToken(pline, delim);

	if(work == "turn")
	{
		work = ExtractToken(pline, delim);
		if(work == "on")
		{
			operation = ecmd::SET_ON;
		}
		else if(work == "off")
		{
			operation = ecmd::SET_OFF;
		}
	}
	else if(work == "toggle")
	{
		operation = ecmd::TOGGLE;
	}

	_Coord startcoord;
	work = ExtractToken(pline, delim);
	startcoord.x = std::stoi(ExtractToken(work, ","));
	startcoord.y = std::stoi(ExtractToken(work, ","));

	work = ExtractToken(pline, delim);
	if(work != "through")
	{
		int error = 0;
	}

	_Coord endcoord;
	work = ExtractToken(pline, delim);
	endcoord.x = std::stoi(ExtractToken(work, ","));
	endcoord.y = std::stoi(ExtractToken(work, ","));

	switch(operation)
	{
	case ecmd::SET_ON:
		pgrid.Set(startcoord, endcoord, true);
		break;
	case ecmd::SET_OFF:
		pgrid.Set(startcoord, endcoord, false);
		break;
	case ecmd::TOGGLE:
		pgrid.Toggle(startcoord, endcoord);
		break;

	case ecmd::NONE:
	default:
		int error = 0;
		break;
	}

}

void CalcSolution()
{
	std::string str;
	int nice = 0;

	std::string teststr(
						"123->x\n"
						"456->y\n"
						"x AND y->d\n"
						"x OR y->e\n"
						"x LSHIFT 2->f\n"
						"y RSHIFT 2->g\n"
						"NOT x->h\n"
						"NOT y->i\n"
						);



	std::ifstream file("2015/Day_07/input.txt");
	while(file.good())
	{
		std::getline(file, str);


	}
	
	int a = 0;

}


}
