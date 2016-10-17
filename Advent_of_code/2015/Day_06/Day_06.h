
#ifndef Day6_h__
#define Day6_h__

#include <string>
#include <fstream>
#include <vector>
// #include <array>

namespace nsDay06
{

struct _Coord
{
	_Coord()															{}
	_Coord(unsigned int px, unsigned int py)	: x(px), y(py)			{}
	unsigned int x;
	unsigned int y;
};

//////////////////////////////////////////////////////////////////////////

class TGrid_Bool
{
public:
	TGrid_Bool() = delete;
	TGrid_Bool(int pwidth, int pheight) : m_Width(pwidth), m_Height(pheight)		{ _InitGrid(); }

	void Set(_Coord const &pstart, _Coord const &pend, bool pval);
	void Toggle(_Coord const &pstart, _Coord const &pend);

	unsigned int CountOn() const;

private:

	void _InitGrid();

	uint32_t m_Width;
	uint32_t m_Height;

	std::vector<std::vector<bool>> m_Grid;
};

//////////////////////////////////////////////////////////////////////////

class TGrid_Int
{
public:
	TGrid_Int() = delete;
	TGrid_Int(int pwidth, int pheight) : m_Width(pwidth), m_Height(pheight)		{ _InitGrid(); }

	void Set(_Coord const &pstart, _Coord const &pend, bool pval);
	void Toggle(_Coord const &pstart, _Coord const &pend);

	unsigned int CountOn() const;

private:

	void _InitGrid();

	uint32_t m_Width;
	uint32_t m_Height;

	std::vector<std::vector<unsigned int>> m_Grid;
};

//////////////////////////////////////////////////////////////////////////

void ParseLine(std::string pline, TGrid_Int &pgrid);

void CalcSolution();

}

#endif // Day2_h__

