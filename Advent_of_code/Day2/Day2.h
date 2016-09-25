
#ifndef Day2_h__
#define Day2_h__

#include <string>
#include <vector>
#include <array>

namespace nsDay02
{

class _Box
{
public:
	_Box() = delete;
	_Box(std::string const &pin);
	_Box(int pl, int pw, int ph);

	int PaperSize() const;
	int RibbonLenght() const;

private:

	void _ParseInput(std::string const &pin);
	void _CalcAree();

	// 	int m_l;
	// 	int m_w;
	// 	int m_h;

	std::array<int, 3> m_Dimension;
	std::array<int, 3> m_Faces;

	int m_Volume;

	int m_TotalArea;
};

class TD2
{
public:

	TD2();

	int TotPaperSurface() const;
	int TotRibbonLenght() const;

private:

	std::vector<_Box> m_LBoxes;
};

}

#endif // Day2_h__

