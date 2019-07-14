#ifndef TWire_h__
#define TWire_h__

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER


//#include "TNodes.h"

#include <memory>
#include <string>
#include <optional>
#include <algorithm>

namespace nsDay07
{

class BWire
{
protected:

	class _TWireIn
	{
	public:
		//		_TNodeIn();
		_TWireIn(const std::string &pid)
			: m_NameInput(pid)
			, m_FixedVal(0)
			, m_Link(nullptr)

			, m_IsCashed (false)
			, m_CachedValue (0)

			, m_WatchLoop(-1)
		{
			_CheckString();
		}
		_TWireIn(std::string &&pid)
			: m_NameInput(std::move(pid))
			, m_FixedVal(0)
			, m_Link(nullptr)

			, m_IsCashed (false)
			, m_CachedValue (0)

			, m_WatchLoop(-1)
		{
			_CheckString();
		}

		//		_TNodeIn(uint16_t pval) : m_NameInput(""), m_FixedVal(pval), m_Link(nullptr)		{}

		// 		void Set_ID(const std::string &pid)						{ m_NameID = pid; }
		// 		void Set_ID(std::string &&pid)							{ m_NameID = std::move(pid); }

		void CheckSet_Link(BWire const *pwire)
		{
			if (!m_NameInput.empty() && pwire->Name() == m_NameInput)
			{
				m_Link = pwire;
//				return true;
			}

//			return false;
		}

		void Unlink(BWire const *pwire)
		{
			if (!m_NameInput.empty() && pwire->Name() == m_NameInput)
			{
				if (m_Link != pwire)
				{
					int a = 0;
				}
				m_Link = nullptr;

				m_IsCashed = false;
				m_CachedValue = 0;
			}
		}

		bool Is_Linked() const { return (m_Link != nullptr) || (m_NameInput.empty()); }

		//void Set_Link(TNode_Base const *pnode)					{ m_Link = pnode; }

		uint16_t Value(int lvl) const
		{
			if (m_FixedVal == 1674)
			{
				int a = 0;
			}

			if (m_WatchLoop >= 0 && m_WatchLoop < lvl)
			{
				int a = 0;
			}

			if (!m_IsCashed)
			{
				m_WatchLoop = lvl;
				m_CachedValue = m_NameInput.empty() ? m_FixedVal : m_Link->Value(lvl);
				m_IsCashed = true;

				m_WatchLoop = -1;
			}

			return m_CachedValue;
		}

		int Level() const
		{
			if (m_NameInput.empty())
			{
				return 0;
			}

			if (m_Link)
			{
				return m_Link->Level() + 1;
			}
			else
			{
				return -1;
			}
		}

		void ForceRecalc()
		{
			m_IsCashed = false;
			m_CachedValue = 0;

			m_WatchLoop = -1;
		}

	private:

		void _CheckString()
		{
			if (m_NameInput.find_first_not_of("0123456789") == std::string::npos)
			{
				m_FixedVal = static_cast<uint16_t>(std::stoul(m_NameInput));
				m_NameInput.clear();
			}
		}

	private:

		std::string m_NameInput;
		uint16_t m_FixedVal;
		BWire const *m_Link;

		mutable bool m_IsCashed;
		mutable uint16_t m_CachedValue;

		mutable int m_WatchLoop;
	};

	// 			: m_Node(nullptr)
	// 		{}

	BWire(std::string const &pname
// 		  , std::string const &poper
// 		  , std::unique_ptr<TNode_Base> &&pnode = nullptr
	)
		: m_Name(pname)
//		, m_Operation(poper)
//		, m_Node(std::move(pnode))
		, m_Linked {false}
		, m_Level {0}
	{}

public:

//	static std::optional<TWire> Create_Wire(std::string pline);
	static std::unique_ptr<BWire> Create_Wire(std::string pline);

	BWire() = delete;

	BWire(BWire const &) = delete;
	BWire(BWire &&pv) noexcept
		: m_Name(std::move(pv.m_Name))
		, m_Linked (std::move(pv.m_Linked))
		, m_Level (std::move(pv.m_Level))
	{}

	BWire &operator = (BWire const &) = delete;
	BWire &operator = (BWire &&pv) noexcept = default;


	std::string const &Name() const				{ return m_Name; }
//	std::string const &Operation() const		{ return m_Operation; }
//	TNode_Base const *Node() const				{ return m_Node.get(); }

	bool IsLinked() const							{ return m_Linked; }

	int Level() const									{ return m_Level; }

	virtual uint16_t Value(int lvl) const = 0;

// 	virtual bool IsLinked() const = 0;
// 
// 	virtual int Level() const = 0;

	virtual void CheckLink_Input_Node(const BWire *pnode) = 0;

	virtual void Unlink(const BWire *pnode) = 0;

	virtual void Update() = 0;

	virtual void ForceRecalc() = 0;

// 	uint16_t Value(int lvl) const noexcept				{ return m_Node->Value(lvl); }
// 
// 	bool IsInputLinked() const						{ return m_Node->IsInputLinked(); }
// 
// 	bool CheckLink_Input_Wire(const BWire &pwire);

private:

//	void _Set_Node(std::unique_ptr<TNode_Base> &&pptr)		{ m_Node = std::move(pptr); }

	static std::unique_ptr<BWire> _CalcWire(const std::string &pname, const std::string &poper);

	std::string m_Name;

protected:

	bool m_Linked;
	int m_Level;
//	std::string m_Operation;
//	std::unique_ptr<BWire> m_Node;
};



//////////////////////////////////////////////////////////////////////////

class TWire_Link : public BWire
{
public:

	TWire_Link(const std::string &pname
				  , const std::string &pnamein
	)
		: BWire(pname)
		, m_Input(pnamein)
	{}

	// 	TNode_Link(std::string const &pname
	// 					 , uint16_t pv
	// 	)
	// 		: TNode_Base(pname)		//, 0)
	// 		, m_Input(pv)
	// 	{}

	virtual uint16_t Value(int lvl) const override		{ return m_Input.Value(lvl + 1); }


// 	virtual bool IsLinked() const override					{ return m_Input.Is_Linked(); }
// 
// 	virtual int Level() const override						{ return m_Input.Level(); }

	virtual void CheckLink_Input_Node(const BWire *pnode) override
	{
		m_Input.CheckSet_Link(pnode);

		Update();
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input.Unlink(pnode);
		Update();
	}

	virtual void Update() override
	{
		m_Linked = m_Input.Is_Linked();

		m_Level = m_Input.Level();
	}

	virtual void ForceRecalc() override
	{
		m_Input.ForceRecalc();
	}

private:

	BWire::_TWireIn m_Input;
};

//////////////////////////////////////////////////////////////////////////

class TWire_NOT : public BWire				//<1>
{
public:

	TWire_NOT(std::string const &pname
				 , std::string const &pnamein
	)
		: BWire(pname)
		, m_Input(pnamein)
	{
		//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override { return ~m_Input.Value(lvl + 1); }

//	virtual bool IsInputLinked() const override { return m_Input.Is_Linked(); }

	virtual void CheckLink_Input_Node(BWire const *pnode) override 
	{
		m_Input.CheckSet_Link(pnode);
		Update(); 
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input.Unlink(pnode);
		Update();
	}

//	virtual int Level() const override { return m_Input.Level(); }

	virtual void Update() override
	{
		m_Linked = m_Input.Is_Linked();

		m_Level = m_Input.Level();
	}

	virtual void ForceRecalc() override
	{
		m_Input.ForceRecalc();
	}

private:

	BWire::_TWireIn m_Input;
	//TNode_Base const *m_Parent;
};

//////////////////////////////////////////////////////////////////////////

class TWire_AND : public BWire				//<2>
{
public:

	TWire_AND(std::string const &pname
				 , std::string const &pnamein1
				 , std::string const &pnamein2
	)
		: BWire(pname)
		, m_Input_1(pnamein1)
		, m_Input_2(pnamein2)
	{
		// 		m_Inputs[0].Set_ID(pidparent1);
		// 		m_Inputs[1].Set_ID(pidparent2);
	}

	virtual uint16_t Value(int lvl) const override	{ return (m_Input_1.Value(lvl + 1) & m_Input_2.Value(lvl + 1)); }

// 	virtual bool IsInputLinked() const override		{ return (m_Input_1.Is_Linked() && m_Input_2.Is_Linked()); }
// 
// 	virtual int Level() const override					
// 	{
// 		if(m_Input_1.Level() == 0 || m_Input_2.Level() == 0)
// 		{
// 			return 0;
// 		}
// 
// 		return (std::max(m_Input_1.Level(),m_Input_2.Level()) + 1);
// 	
// 	}

	virtual void CheckLink_Input_Node(BWire const *pnode) override 
	{
		m_Input_1.CheckSet_Link(pnode);
		m_Input_2.CheckSet_Link(pnode);

		Update();
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input_1.Unlink(pnode);
		m_Input_2.Unlink(pnode);
		Update();
	}

	virtual void Update() override
	{
		m_Linked = (m_Input_1.Is_Linked() && m_Input_2.Is_Linked());

		if (m_Input_1.Level() < 0 || m_Input_2.Level() < 0)
		{
			m_Level = -1;
		}
		else
		{
			m_Level = std::max(m_Input_1.Level(),m_Input_2.Level());
		}
	}

	virtual void ForceRecalc() override
	{
		m_Input_1.ForceRecalc();
		m_Input_2.ForceRecalc();
	}

private:

	BWire::_TWireIn m_Input_1;
	BWire::_TWireIn m_Input_2;

	//TNode_Base const *m_ParentA;
	//TNode_Base const *m_ParentB;
};

//////////////////////////////////////////////////////////////////////////

class TWire_OR : public BWire				//<2>
{
public:

	TWire_OR(std::string const &pname
				, std::string const &pnamein1
				, std::string const &pnamein2
	)
		: BWire(pname)
		, m_Input_1(pnamein1)
		, m_Input_2(pnamein2)
	{
		// 		m_Inputs[0].Set_ID(pidparent1);
		// 		m_Inputs[1].Set_ID(pidparent2);
	}

	virtual uint16_t Value(int lvl) const override { return (m_Input_1.Value(lvl + 1) | m_Input_2.Value(lvl + 1)); }

//	virtual bool IsInputLinked() const override { return (m_Input_1.Is_Linked() && m_Input_2.Is_Linked()); }

	virtual void CheckLink_Input_Node(BWire const *pnode) override
	{
		m_Input_1.CheckSet_Link(pnode);
		m_Input_2.CheckSet_Link(pnode);

		Update();
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input_1.Unlink(pnode);
		m_Input_2.Unlink(pnode);
		Update();
	}

	virtual void Update() override
	{
		m_Linked = m_Input_1.Is_Linked() && m_Input_2.Is_Linked();

		if (m_Input_1.Level() < 0 || m_Input_2.Level() < 0)
		{
			m_Level = -1;
		}
		else
		{
			m_Level = std::max(m_Input_1.Level(),m_Input_2.Level());
		}
	}

	virtual void ForceRecalc() override
	{
		m_Input_1.ForceRecalc();
		m_Input_2.ForceRecalc();
	}

private:

	BWire::_TWireIn m_Input_1;
	BWire::_TWireIn m_Input_2;

	// 	TNode_Base const *m_ParentA;
	// 	TNode_Base const *m_ParentB;
};

//////////////////////////////////////////////////////////////////////////

class TWire_LSHIFT : public BWire
{
public:

	TWire_LSHIFT(const std::string &pname
					 , const std::string &pnamein
					 , int poffset
	)
		: BWire(pname)
		, m_Input(pnamein)
		, m_Offset(poffset)
	{
		//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override { return (m_Input.Value(lvl + 1) << m_Offset); }

//	virtual bool IsInputLinked() const override { return m_Input.Is_Linked(); }

	virtual void CheckLink_Input_Node(BWire const *pnode) override 
	{	
		m_Input.CheckSet_Link(pnode); 
		Update(); 
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input.Unlink(pnode);
		Update();
	}

	virtual void Update() override
	{
		m_Linked = m_Input.Is_Linked();

		m_Level = m_Input.Level();
	}

	virtual void ForceRecalc() override
	{
		m_Input.ForceRecalc();
	}

private:

	//	TNode_Base const *m_Parent;
	BWire::_TWireIn m_Input;
	int m_Offset;
};

//////////////////////////////////////////////////////////////////////////

class TWire_RSHIFT : public BWire
{
public:

	TWire_RSHIFT(const std::string &pname
					 , const std::string &pnamein
					 , int poffset
	)
		: BWire(pname)
		, m_Input(pnamein)
		, m_Offset(poffset)
	{
		//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override { return (m_Input.Value(lvl + 1) >> m_Offset); }

//	virtual bool IsInputLinked() const override { return m_Input.Is_Linked(); }

	virtual void CheckLink_Input_Node(BWire const *pnode) override 
	{ 
		m_Input.CheckSet_Link(pnode); 
		Update();
	}

	virtual void Unlink(const BWire *pnode) override
	{
		m_Input.Unlink(pnode);
		Update();
	}

	virtual void Update() override
	{
		m_Linked = m_Input.Is_Linked();

		m_Level = m_Input.Level();
	}

	virtual void ForceRecalc() override
	{
		m_Input.ForceRecalc();
	}

private:

	//	TNode_Base const *m_Parent;
	BWire::_TWireIn m_Input;
	int m_Offset;
};



}

#endif // TWire_h__