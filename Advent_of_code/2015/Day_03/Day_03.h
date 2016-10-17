
#ifndef Day3_h__
#define Day3_h__

#include <string>
#include <vector>
#include <array>

namespace nsDay03
{

struct _Coord
{
	int x;
	int y;
};

bool operator == (_Coord const &pa, _Coord const &pb);

class _Deliverer
{
public:

	_Coord const &Position() const			{ return m_Position; }
	void Move(char pdir);

private:

	_Coord m_Position;

};

class T2DMap
{
public:

	static const int N_DELIVERERS = 2;

	T2DMap(std::istream &pstr);

	unsigned int NHouses() const			{ return m_OldPos.size(); }

private:

	void _ParseStream(std::istream &pstr);

	std::vector<_Coord> m_OldPos;

	std::array<_Deliverer, N_DELIVERERS> m_LSanta;
};

void CalcSolution();

}

#endif // Day2_h__

