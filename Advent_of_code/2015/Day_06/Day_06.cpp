#include "Day_06.h"

#include <vector>

namespace nsDay06
{

void TGrid_Bool::Set(_Coord const &pstart, _Coord const &pend, bool pval)
{
	for(auto i = pstart.y; i <= pend.y; ++i)
	{
		for(auto j = pstart.x; j <= pend.x; ++j)
		{
			m_Grid[i][j] = pval;
		}
	}
}

void TGrid_Bool::Toggle(_Coord const &pstart, _Coord const &pend)
{
	for(auto i = pstart.y; i <= pend.y; ++i)
	{
		for(auto j = pstart.x; j <= pend.x; ++j)
		{
			m_Grid[i][j] = !m_Grid[i][j];
		}
	}
}

unsigned int TGrid_Bool::CountOn() const
{
	auto count = 0u;

	for(auto i = 0u; i < m_Height; ++i)
	{
		for(auto j = 0u; j < m_Width; ++j)
		{
			if(m_Grid[i][j])
			{
				++count;
			}
		}
	}

	return count;
}

void TGrid_Bool::_InitGrid()
{
	m_Grid.reserve(m_Height);

	for(auto i = 0u; i < m_Height; ++i)
	{
		m_Grid.emplace_back(m_Width, false);
	}
}

//////////////////////////////////////////////////////////////////////////

void TGrid_Int::Set(_Coord const &pstart, _Coord const &pend, bool pval)
{
	for(auto i = pstart.y; i <= pend.y; ++i)
	{
		for(auto j = pstart.x; j <= pend.x; ++j)
		{
			if(pval)
			{
				++m_Grid[i][j];
			}
			else
			{
				if(m_Grid[i][j] > 0)
				{
					--m_Grid[i][j];
				}
			}
		}
	}
}

void TGrid_Int::Toggle(_Coord const &pstart, _Coord const &pend)
{
	for(auto i = pstart.y; i <= pend.y; ++i)
	{
		for(auto j = pstart.x; j <= pend.x; ++j)
		{
			m_Grid[i][j] += 2;
		}
	}
}

unsigned int TGrid_Int::CountOn() const
{
	auto count = 0u;

	for(auto i = 0u; i < m_Height; ++i)
	{
		for(auto j = 0u; j < m_Width; ++j)
		{
			count += m_Grid[i][j];
		}
	}

	return count;
}

void TGrid_Int::_InitGrid()
{
	m_Grid.reserve(m_Height);

	for(auto i = 0u; i < m_Height; ++i)
	{
		m_Grid.emplace_back(m_Width, 0u);
	}
}

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

	TGrid_Int griglia(1000, 1000);


// 	griglia.Set(_Coord(0,0), _Coord(999, 999), true);
// 	auto tmpcnt = griglia.CountOn();

// 	griglia.Set(_Coord(499, 499), _Coord(500, 500), true);
// 	auto tmpcnt = griglia.CountOn();

// 	griglia.Set(_Coord(0,0), _Coord(0,0), true);
// 	auto tmpcnt = griglia.CountOn();

// 	griglia.Toggle(_Coord(0,0), _Coord(999, 999));
// 	auto tmpcnt = griglia.CountOn();

	if(griglia.CountOn() != 0u)
	{
		int a = 0;
	}

	std::ifstream file("2015/Day_06/input.txt");
	while(file.good())
	{
		std::getline(file, str);

		ParseLine(str, griglia);
	}
	
	auto nlon = griglia.CountOn();
	int a = 0;

}


}
