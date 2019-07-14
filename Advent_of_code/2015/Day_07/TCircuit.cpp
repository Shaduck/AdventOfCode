#include "TCircuit.h"

//#include <boost/algorithm/string.hpp>
//#include <boost/tokenizer.hpp>

namespace nsDay07
{


TCircuit::TCircuit()
//	: m_ListFirstUnlinked (m_WiresList.end())
{

}

//void TCircuit::AddLine(const std::string pstr)
bool TCircuit::AddWire(std::unique_ptr<BWire> &&pwire)
{
//	auto currwire = TWire::Create_Wire(pstr);

// 	for(const auto &curr: m_UnlinkedWires)
// 	{
// 		if(curr.Name() == pwire.Name())
// 		{
// 			return false;
// 		}
// 	}

	for (const auto &curr : m_WiresList)
	{
		if (curr->Name() == pwire->Name())
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

	return true;
}


bool TCircuit::ReplaceWire(std::unique_ptr<BWire> &&pwire)
{
	auto found = false;

	for (const auto &curr : m_WiresList)
	{
		if (curr->Name() == pwire->Name())
		{
			found = true;
		}
	}

	if(!found)
	{
		return false;
	}

	_RemoveWire(pwire->Name());

	_InsertWire(std::move(pwire));
	
	for (auto &curr : m_WiresList)
	{
		curr->ForceRecalc();
	}

	return true;
}

uint16_t TCircuit::Value(std::string const &pwire)
{
	const auto res = _FindWire(pwire);
	if (res == nullptr
		 || !res->IsLinked())		//  Node() == nullptr)
	{
		return 0;
	}

//	return res->Node()->Value(1);
	return res->Value(1);
}

const BWire *TCircuit::_FindWire(std::string const &pname)
{
	auto res = std::find_if(m_WiresList.begin(), m_WiresList.end(),
									[&pname](const std::unique_ptr<nsDay07::BWire> &pa) { return (pa->Name() == pname); });
	if (res == m_WiresList.end())
	{
		return nullptr;
	}

	return res->get();
}

// void TCircuit::_FindWorkingWires()
// {
// //	auto iter = m_UnlinkedWires.begin();
// 	auto iter = m_ListFirstUnlinked;
// 
// //	while( iter != m_UnlinkedWires.end())
// 	while( iter != m_WiresList.end())
// 	{
// 		if(iter->IsInputLinked())
// 		{
// //			m_WiresList.push_back(std::move(*iter));
// 			std::swap(*m_ListFirstUnlinked, *iter);
// //			iter = m_UnlinkedWires.erase(iter);
// //			iter = m_WiresList.erase(iter);
// 			++ m_ListFirstUnlinked;
// 		}
// //		else
// //		{
// 			++iter;
// //		}
// 	}
// }

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


void TCircuit::_InsertWire(std::unique_ptr<BWire> &&pwire)
{

	for (auto &curr : m_WiresList)
	{
		pwire->CheckLink_Input_Node(curr.get());

		if (!curr->IsLinked())
		{
			curr->CheckLink_Input_Node(pwire.get());
		}
	}

	m_WiresList.push_back(std::move(pwire));

	_SortWireList();


// 	for (auto curr = m_ListFirstUnlinked; curr != m_WiresList.end(); ++curr)
// 	{
// 		curr->CheckLink_Input_Wire(pwire);
// 	}
// 
// 	for (const auto &curr : m_WiresList)
// 	{
// 		pwire.CheckLink_Input_Wire(curr);
// 	}
// 
// 	m_WiresList.push_back(std::move(pwire));
// 
// 	if(m_WiresList.size() == 1)
// 	{
// 		m_ListFirstUnlinked = m_WiresList.begin();
// 	}
// 
// 	_FindWorkingWires();

}


void TCircuit::_RemoveWire(const std::string &pwname)
{
	auto wfind = std::find_if(m_WiresList.begin(), m_WiresList.end()
				 , [pwname](const TWirePtr &pv) { return (pv->Name() == pwname); });

	_RemoveWire(wfind);
}

void TCircuit::_RemoveWire(const TWiresVector::const_iterator &piter)
{
	if (piter == m_WiresList.end())
	{
		return;
	}

	const auto wireptr	= (*piter).get();
	
	for (auto &curr : m_WiresList)
	{
		curr->Unlink(wireptr);
	}

	m_WiresList.erase(piter);

	_SortWireList();
}

void TCircuit::_SortWireList()
{
	std::sort(m_WiresList.begin(), m_WiresList.end()
			  , [](const std::unique_ptr<BWire> &p1, const std::unique_ptr<BWire> &p2)
			  {
				  return (p1->Level() < p2->Level());
			  }
			);
}

}
