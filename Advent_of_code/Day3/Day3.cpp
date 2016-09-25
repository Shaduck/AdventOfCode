#include "Day3.h"

#include <xutility>


namespace nsDay03
{
T2DMap::T2DMap(std::istream &pstr)
{
	
	//std::string strline;

	//std::getline(file, strline);
	
	_ParseStream(pstr);
}


void T2DMap::_ParseStream(std::istream &pstr)
{
	char ch;
	_Coord workCoord;
	workCoord.x = 0;
	workCoord.y = 0;

	m_OldPos.push_back(workCoord);

	pstr.get(ch);

	int DelID = 0;

	while(pstr.good())
	{
		m_LSanta[DelID].Move(ch);
		auto find = std::find(m_OldPos.begin(), m_OldPos.end(), m_LSanta[DelID].Position());

		if(find == m_OldPos.end())
		{
			m_OldPos.push_back(m_LSanta[DelID].Position());
		}

		++DelID;
		if(DelID >= N_DELIVERERS)
		{
			DelID = 0;
		}
		pstr.get(ch);
	}
}

bool operator==(_Coord const &pa, _Coord const &pb)
{
	return ((pa.x == pb.x) && (pa.y == pb.y));
}

void _Deliverer::Move(char pdir)
{
	switch(pdir)
	{
	case '^':
	{
		++m_Position.y;
		break;
	}
	case '>':
	{
		++m_Position.x;
		break;
	}
	case 'v':
	{
		--m_Position.y;
		break;
	}
	case '<':
	{
		--m_Position.x;
		break;
	}
	default:
	{
		int a = 0;
	}
	}
}

}
