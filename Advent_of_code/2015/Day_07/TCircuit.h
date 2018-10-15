#ifndef TCircuit_h__
#define TCircuit_h__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER


#include "TWire.h"

#include <optional>

namespace nsDay07
{

class TCircuit
{


public:

	TCircuit()												{}

//	void AddLine(std::string pstr);
	bool AddWire(TWire &&pwire);
	bool ReplaceWire(TWire &&pwire);

	uint16_t Value(std::string const &pwire);

private:

	TWire *_Find(std::string const &pname);

//	bool _ParseWire(std::string pline);

	void _FindWorkingWires();

	void _InsertWire(TWire &&pwire);

//	void _CalcNode(TWire &pwire);

private:

	std::vector<TWire> m_UnlinkedWires;

	std::vector<TWire> m_WorkingWires;
};

}

#endif // TCircuit_h__