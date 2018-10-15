#ifndef TWire_h__
#define TWire_h__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER


#include "TNodes.h"

#include <memory.h>
#include <string>
#include <optional>

namespace nsDay07
{

class TWire
{
private:

	// 			: m_Node(nullptr)
	// 		{}

	TWire(std::string const &pname
		  , std::string const &poper
		  , std::unique_ptr<TNode_Base> &&pnode = nullptr
	)
		: m_Name(pname)
		, m_Operation(poper)
		, m_Node(std::move(pnode))
	{}

public:

	static std::optional<TWire> Create_Wire(std::string pline);

	TWire() = delete;

	TWire(TWire const &) = delete;
	TWire(TWire &&pv) noexcept
		: m_Name(std::move(pv.m_Name))
		, m_Operation(std::move(pv.m_Operation))
		, m_Node(std::move(pv.m_Node))
	{}

	TWire &operator = (TWire const &) = delete;
	TWire &operator = (TWire &&pv) noexcept = default;


	std::string const &Name() const				{ return m_Name; }
//	std::string const &Operation() const		{ return m_Operation; }
	TNode_Base const *Node() const				{ return m_Node.get(); }



	uint16_t Value(int lvl) const noexcept				{ return m_Node->Value(lvl); }

	bool IsInputLinked() const						{ return m_Node->IsInputLinked(); }

	bool CheckLink_Input_Wire(const TWire &pwire);

private:

	void _Set_Node(std::unique_ptr<TNode_Base> &&pptr)		{ m_Node = std::move(pptr); }

	bool _CalcNode();

	std::string m_Name;
	std::string m_Operation;
	std::unique_ptr<TNode_Base> m_Node;
};

}

#endif // TWire_h__