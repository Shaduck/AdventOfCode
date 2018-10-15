#include "TCircuit.h"

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

namespace nsDay07
{


//void TCircuit::AddLine(const std::string pstr)
bool TCircuit::AddWire(TWire &&pwire)
{
//	auto currwire = TWire::Create_Wire(pstr);

	for(const auto &curr: m_UnlinkedWires)
	{
		if(curr.Name() == pwire.Name())
		{
			return false;
		}
	}

	for (const auto &curr : m_WorkingWires)
	{
		if (curr.Name() == pwire.Name())
		{
			return false;
		}
	}

// 	if(currwire)
// 	{
	_InsertWire(std::move(pwire));		//		currwire.value()));
//	}


// 	if (_ParseWire(pstr))
// 	{
// 		_UpdateWires();
// 	}
}


bool TCircuit::ReplaceWire(TWire &&pwire)
{
	auto found = false;

	for (const auto &curr : m_WorkingWires)
	{
		if (curr.Name() == pwire.Name())
		{
			return false;
		}
	}

	for (const auto &curr : m_UnlinkedWires)
	{
		if (curr.Name() == pwire.Name())
		{
					
		}
	}

	return false;
}

uint16_t TCircuit::Value(std::string const &pwire)
{
	const auto res = _Find(pwire);
	if (res == nullptr
		 || res->Node() == nullptr)
	{
		return 0;
	}

	return res->Node()->Value(1);
}

TWire *TCircuit::_Find(std::string const &pname)
{
	auto res = std::find_if(m_WorkingWires.begin(), m_WorkingWires.end(),
									[&pname](nsDay07::TWire const &pa) { return (pa.Name() == pname); });
	if (res == m_WorkingWires.end())
	{
		return nullptr;
	}

	return res.operator->();
}

void TCircuit::_FindWorkingWires()
{
	auto iter = m_UnlinkedWires.begin();

	while( iter != m_UnlinkedWires.end())
	{
		if(iter->IsInputLinked())
		{
			m_WorkingWires.push_back(std::move(*iter));
			iter = m_UnlinkedWires.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

// std::string ExtractToken(std::string &pstr, std::string const &delim)
// {
// 	auto pos = pstr.find(delim);
// 	std::string ret = pstr.substr(0, pos);
// 	pstr = pstr.substr(pos + delim.size());
// 
// 	return ret;
// }


// std::optional<TWire> TCircuit::_ParseWire(std::string pline)
// {
// 	const auto posarrow = pline.find("->");
// 
// 	if (posarrow == std::string::npos)
// 	{
// 		// Invalid row
// //		return false;
// 		return std::optional<TWire>();
// 	}
// 
// 	// 	_Wire locwire;
// 	// 	locwire.Name = pline.substr(posarrow + 2);
// 	// 	locwire.Operation = pline.substr(0, posarrow);
// 	// 
// 	// 	boost::trim(locwire.Name);
// 	// 	boost::trim(locwire.Operation);
// 
// 	TWire locwire(boost::trim_copy(pline.substr(posarrow + 2))
// 					  , boost::trim_copy(pline.substr(0, posarrow)));
// 
// 
// 	m_UnlinkedWires.push_back(std::move(locwire));
// 
// 	return true;
// }

void TCircuit::_InsertWire(TWire &&pwire)
{
	for (auto &curr : m_UnlinkedWires)
	{
		pwire.CheckLink_Input_Wire(curr);
		curr.CheckLink_Input_Wire(pwire);
		//_CalcNode(curr);
	}

	for (const auto &curr : m_WorkingWires)
	{
		pwire.CheckLink_Input_Wire(curr);
	}

	m_UnlinkedWires.push_back(std::move(pwire));

	_FindWorkingWires();

// 	for (auto &curr : m_Circuit)
// 	{
// 		if (curr.Node() == nullptr)
// 		{
// 			_CalcNode(curr);
// 		}
// 	}
}


}
