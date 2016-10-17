
#ifndef Day7_h__
#define Day7_h__

#include <string>
#include <fstream>
#include <vector>
// #include <array>

namespace nsDay07
{

class INode_Base
{
public:

	virtual ~INode_Base() = 0								{}

	virtual uint16_t Value() = 0;

};

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

class TCircuit
{
public:

	TCircuit()												{}


	uint16_t Value(std::string const &pwire) const;

private:

	uint32_t m_Width;
	uint32_t m_Height;

	std::vector<std::vector<unsigned int>> m_Grid;
};

//////////////////////////////////////////////////////////////////////////

void ParseLine(std::string pline, TGrid_Int &pgrid);

void CalcSolution();

}

#endif // Day2_h__

