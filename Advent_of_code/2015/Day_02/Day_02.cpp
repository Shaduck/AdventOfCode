
#include "Day_02.h"

#include <fstream>
#include <algorithm>

namespace nsDay02
{

_Box::_Box(std::string const &pin)
{
	_ParseInput(pin);

	_CalcAree();
}

_Box::_Box(int pl, int pw, int ph)
// 	:
// 	m_l(pl),
// 	m_w(pw),
// 	m_h(ph)
{
	m_Dimension[0] = pl;
	m_Dimension[1] = pw;
	m_Dimension[2] = ph;

	_CalcAree();
}

int _Box::PaperSize() const
{
	//auto minFace = std::min(std::min(m_Faces[0], m_Faces[1]), m_Faces[2]);

	return m_TotalArea + m_Faces[0];
}

int _Box::RibbonLenght() const
{
	return (2 * m_Dimension[0]) + (2 * m_Dimension[1]) + m_Volume;
}

void _Box::_ParseInput(std::string const &pin)
{
	std::string work(pin);

	auto pos = work.find('x');
	m_Dimension[0] = stoi(work.substr(0, pos));
	work = work.substr(pos + 1);

	pos = work.find('x');
	m_Dimension[1] = stoi(work.substr(0, pos));
	work = work.substr(pos + 1);

	m_Dimension[2] = stoi(work);

	std::sort(m_Dimension.begin(), m_Dimension.end());
}

void _Box::_CalcAree()
{
	m_Faces[0] = m_Dimension[0] * m_Dimension[1];
	m_Faces[1] = m_Dimension[1] * m_Dimension[2];
	m_Faces[2] = m_Dimension[2] * m_Dimension[0];

	std::sort(m_Faces.begin(), m_Faces.end());

	m_Volume = m_Dimension[0] * m_Dimension[1] * m_Dimension[2];

	m_TotalArea = 2 * (m_Faces[0] + m_Faces[1] + m_Faces[2]);
}


//////////////////////////////////////////////////////////////////////////

TD2::TD2()
{
	std::ifstream file("Day2/input.txt");
	if(!file.good())
	{
		throw std::exception("File not found!");
	}
	std::string strline;

	std::getline(file, strline);
	while (file.good())
	{
		m_LBoxes.emplace_back(strline);
		std::getline(file, strline);
	}
}

int TD2::TotPaperSurface() const
{
	int total = 0;
	for(auto const &curr : m_LBoxes)
	{
		total += curr.PaperSize();
	}

	return total;
}

int TD2::TotRibbonLenght() const
{
	int total = 0;
	for(auto const &curr : m_LBoxes)
	{
		total += curr.RibbonLenght();
	}

	return total;
}

}
