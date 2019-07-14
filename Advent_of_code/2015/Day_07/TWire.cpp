
#include "TWire.h"

#include <boost/algorithm/string.hpp>


namespace nsDay07
{

//std::optional<nsDay07::TWire> TWire::Create_Wire(std::string pline)
std::unique_ptr<BWire> BWire::Create_Wire(std::string pline)
{
	if(pline.empty())
	{
//		return std::optional<TWire>();
		return nullptr;
	}

	const auto posarrow = pline.find("->");

	if (posarrow != std::string::npos)
	{
		// Invalid row
		//		return false;

// 		TWire workwire(boost::trim_copy(pline.substr(posarrow + 2))
// 							, boost::trim_copy(pline.substr(0, posarrow)));
// 
// 		if(workwire._CalcWire())
// 		{
// 			return workwire;
// 		}

		return _CalcWire(boost::trim_copy(pline.substr(posarrow + 2))
							  , boost::trim_copy(pline.substr(0, posarrow)));

	}

	// 	_Wire locwire;
	// 	locwire.Name = pline.substr(posarrow + 2);
	// 	locwire.Operation = pline.substr(0, posarrow);
	// 
	// 	boost::trim(locwire.Name);
	// 	boost::trim(locwire.Operation);


//	return std::optional<TWire>();
	return nullptr;
}

// bool TWire::CheckLink_Input_Wire(const TWire &pwire)
// {
// 	return m_Node->CheckLink_Input_Node(pwire.m_Node.get());
// }

std::unique_ptr<BWire> BWire::_CalcWire(const std::string &pname
													 , const std::string &poper
													)
{
	auto tmpstr = poper;				//m_Operation;

	auto pos = tmpstr.find(' ');

	if (pos == std::string::npos)
	{
		// Parametro unico, dev'essere una costante o un link
// 		if (tmpstr.find_first_not_of("0123456789") == std::string::npos)
// 		{
// 			// costante
// 			auto value = static_cast<uint16_t>(std::stoul(tmpstr));
// 			m_Node = std::make_unique<TNode_Link>(m_Name, value);
// 		}
// 		else
//		{

		return std::make_unique<TWire_Link>(pname, tmpstr);

// 		auto locnode = std::make_unique<TWire_Link>(pname, tmpstr);
// 		_Set_Node(std::move(locnode));

// 			auto parent = _Find(tmpstr);
// 
// 			if (parent != nullptr
// 					&& parent->Node() != nullptr)
// 			{
// 				auto locnode = std::make_unique<TNode_Link>(parent->Node());
// 				Set_Node(std::move(locnode));
// 			}

//		}

//		return true;
	}

	auto firststr = tmpstr.substr(0, pos);
	tmpstr = tmpstr.substr(pos + 1);

	if(firststr.empty())
	{
		return nullptr;		// false;
	}

	if (firststr == "NOT")
	{
		// Operazione NOT
		return std::make_unique<TWire_NOT>(pname, tmpstr);

// 		auto locnode = std::make_unique<TNode_NOT>(m_Name, tmpstr);
// 		_Set_Node(std::move(locnode));
		
// 		auto parent = _Find(tmpstr);
// 
// 		if (parent != nullptr
// 				&& parent->Node() != nullptr)
// 		{
// 			auto locnode = std::make_unique<TNode_NOT>(parent->Node());
// 			pwire.Set_Node(std::move(locnode));
// 		}

//		return true;
	}

	pos = tmpstr.find(' ');
	auto oper = tmpstr.substr(0, pos);
	auto secondstr = tmpstr.substr(pos + 1);

	if(secondstr.empty())
	{
		return nullptr;		//false;
	}

// 	auto firstparent = _Find(firststr);
// 
// 	if (firstparent == nullptr
// 			|| firstparent->Node() == nullptr
// 			)
// 	{
// 		return;
// 	}

	if (oper == "LSHIFT")
	{
		auto offset = std::stoul(secondstr);
		
//		auto locnode = std::make_unique<TNode_LSHIFT>(firstparent->Node(), offset);
	
		return std::make_unique<TWire_LSHIFT>( pname, firststr, offset);
// 		auto locnode = std::make_unique<TNode_LSHIFT>( m_Name, firststr, offset);
// 		_Set_Node(std::move(locnode));
// 		return true;
	}

	if (oper == "RSHIFT")
	{
		auto offset = std::stoul(secondstr);
//		auto locnode = std::make_unique<TNode_RSHIFT>(firstparent->Node(), offset);

		return std::make_unique<TWire_RSHIFT>(pname, firststr, offset);

// 		auto locnode = std::make_unique<TNode_RSHIFT>(m_Name, firststr, offset);
// 		_Set_Node(std::move(locnode));
// 		return true;
	}

// 	auto secondparent = _Find(secondstr);
// 
// 	if (secondparent == nullptr
// 			|| secondparent->Node() == nullptr
// 			)
// 	{
// 		return;
// 	}

	if (oper == "AND")
	{
//		auto locnode = std::make_unique<TNode_AND>(firstparent->Node(), secondparent->Node());
		return std::make_unique<TWire_AND>(pname, firststr, secondstr);
// 		auto locnode = std::make_unique<TNode_AND>(m_Name, firststr, secondstr);
// 		_Set_Node(std::move(locnode));
// 		return true;
	}
	if (oper == "OR")
	{
//		auto locnode = std::make_unique<TNode_OR>(firstparent->Node(), secondparent->Node());
		return std::make_unique<TWire_OR>(pname, firststr, secondstr);
// 		auto locnode = std::make_unique<TNode_OR>(m_Name, firststr, secondstr);
// 		_Set_Node(std::move(locnode));
// 		return true;
	}

	return nullptr;	// false;
}


}
