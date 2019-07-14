
#ifndef TNodes_h__
#define TNodes_h__

#pragma once

#error "*** Included file: 'TNodes.h' ***"

//#include <array>
#include <vector>
#include <string>

//const int N_INPUTS = 2;

// class INode_Base
// {
// public:
// 	virtual uint16_t Value() const = 0;
// 
// 	virtual bool CheckLink_Node(INode_Base const *pnode) = 0;
// };

//template <int N_INPUTS>
class TNode_Base			//: public INode_Base
{

// 	class _TNodeOut
// 	{
// 	public:
// 		_TNodeOut() = delete;
// 		_TNodeOut(std::string const &pid)	: m_NameID(pid)						{}
// 		_TNodeOut(std::string &&pid)		: m_NameID(std::move(pid))			{}
// 
// 		std::string const &ID() const								{ return m_NameID; }
// 
// 	private:
// 
// 		std::string m_NameID;
// 		//TNode_Base *m_Link;
// 
// 	};

protected:

	class _TNodeIn
	{
	public:
//		_TNodeIn();
		_TNodeIn(const std::string &pid) 
			: m_NameInput(pid)
			, m_FixedVal(0)
			, m_Link(nullptr)

			, m_IsCashed (false)
			, m_CachedValue (0)

			, m_WatchLoop(-1)
		{
			_CheckString();
		}
		_TNodeIn(std::string &&pid)
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

		bool CheckSet_Link(TNode_Base const *pnode)					
		{
			if(!m_NameInput.empty() && pnode->ID() == m_NameInput)
			{
				m_Link = pnode; 
				return true;
			}

			return false;
		}

		bool Is_Linked() const									{ return (m_Link != nullptr) || (m_NameInput.empty()); }

		//void Set_Link(TNode_Base const *pnode)					{ m_Link = pnode; }

		uint16_t Value(int lvl) const
		{
			if(m_FixedVal == 1674)
			{
				int a = 0;
			}

			if( m_WatchLoop >= 0 && m_WatchLoop < lvl)
			{
				int a = 0;
			}

			if(!m_IsCashed)
			{
				m_WatchLoop = lvl;
				m_CachedValue = m_NameInput.empty()? m_FixedVal : m_Link->Value(lvl);
				m_IsCashed = true;

				m_WatchLoop = -1;
			}

			return m_CachedValue;
		}

		int Level() const
		{
			if(m_NameInput.empty())
			{
				return 1;
			}

			if(m_Link)
			{
				m_Link->Level() + 1;
			}
			else
			{
				return 0;
			}
		}

	private:

		void _CheckString()
		{
			if(m_NameInput.find_first_not_of("0123456789") == std::string::npos)
			{
				m_FixedVal = static_cast<uint16_t>(std::stoul(m_NameInput));
				m_NameInput.clear();
			}
		}

	private:

		std::string m_NameInput;
		uint16_t m_FixedVal;
		TNode_Base const *m_Link;

		mutable bool m_IsCashed;
		mutable uint16_t m_CachedValue;

		mutable int m_WatchLoop;
	};

public:

	TNode_Base() = delete;
//	TNode_Base(std::string const &pname) : m_NameID(pname)					{}

protected:

	TNode_Base(std::string const &pname)		//, unsigned int pninputs)
		: m_NameID(pname)
//		, m_Inputs(pninputs)
	{}

public:

	virtual ~TNode_Base() = default;

//	virtual int NParents() const								{ return 0; }

	std::string const &ID() const								{ return m_NameID; }

	virtual uint16_t Value(int lvl) const = 0;

	virtual bool IsInputLinked() const = 0;

	virtual int Level() const = 0;

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) = 0;

protected:

	std::string m_NameID;

	//_TNodeOut m_Output;

//	std::vector<_TNodeIn> m_Inputs;

//	static std::string MID_NULL;
};

// class TNode_SingleParent_Base: public TNode_Base
// {
// public:
// 
// 	TNode_SingleParent_Base() = delete;
// 	TNode_SingleParent_Base(std::string const &pname
// 							, std::string const &pidparent)
// 						: TNode_Base(pname)		
// 						, m_IDParent1(pidparent)
// 						{}
// 
// 	virtual ~TNode_SingleParent_Base() = 0									{}
// 
// //	virtual int NParents() const								{ return 1; }
// 
// protected:
// 
// 	std::string m_IDParent1;
// 
// };
// class TNode_DoubleParent_Base : public TNode_SingleParent_Base
// {
// public:
// 
// 	TNode_DoubleParent_Base() = delete;
// 	TNode_DoubleParent_Base(std::string const &pname
// 							, std::string const &pidparent1
// 							, std::string const &pidparent2
// 							)
// 		: TNode_SingleParent_Base(pname
// 								, pidparent1
// 								)
// 		, m_IDParent2(pidparent2)
// 	{}
// 
// 	virtual ~TNode_DoubleParent_Base() = 0									{}
// 
// //	virtual int NParents() const								{ return 2; }
// 
// protected:
// 
// 	std::string m_IDParent2;
// 
// };

//////////////////////////////////////////////////////////////////////////

// class TNode_Direct : public TNode_Base		//<0>
// {
// public:
// 
// 	TNode_Direct(std::string const &pname
// 				 , uint16_t pv
// 				)
// 		: TNode_Base(pname)		//, 0)
// 		, m_Value(pv)
// 	{}
// 
// 	virtual uint16_t Value() const override					{ return m_Value; }
// 
// 
// 	//std::string TNode_Base::MID_NULL ("***NULL***");
// 
// 	// bool TNode_Base::CheckAddLink_Node(TNode_Base const *pnode)
// 	// {
// 	// 	return false;
// 	// }
// 	
// 	virtual bool IsInputLinked() const override										{ return true; }
// 
// 	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override		{ return false; }
// 
// private:
// 
// 	uint16_t m_Value;
// };

//////////////////////////////////////////////////////////////////////////

class TNode_Link : public TNode_Base			//<1>
{
public:

	TNode_Link(const std::string &pname
				  , const std::string &pnamein
				 ) 
		: TNode_Base(pname)		//, 1)
		, m_Input(pnamein)
	{}

// 	TNode_Link(std::string const &pname
// 					 , uint16_t pv
// 	)
// 		: TNode_Base(pname)		//, 0)
// 		, m_Input(pv)
// 	{}

	virtual uint16_t Value(int lvl) const override			{ return m_Input.Value(lvl + 1); }


	virtual bool IsInputLinked() const override				{ return m_Input.Is_Linked(); }

	virtual int Level() const override							{ return m_Input.Level(); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override		
																			{ return m_Input.CheckSet_Link(pnode); }

private:

	TNode_Base::_TNodeIn m_Input;
};

//////////////////////////////////////////////////////////////////////////

class TNode_NOT : public TNode_Base				//<1>
{
public:

	TNode_NOT(std::string const &pname
			  , std::string const &pnamein
			)
		: TNode_Base(pname)		//, 1)
		, m_Input(pnamein)
//		, m_Parent(nullptr)

	{
//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override									{ return ~m_Input.Value(lvl + 1); }

	virtual bool IsInputLinked() const override										{ return m_Input.Is_Linked(); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override		{ return m_Input.CheckSet_Link(pnode); }

	virtual int Level() const override													{ return m_Input.Level(); }

private:

	TNode_Base::_TNodeIn m_Input;
	//TNode_Base const *m_Parent;
};

//////////////////////////////////////////////////////////////////////////

class TNode_AND : public TNode_Base				//<2>
{
public:

	TNode_AND(std::string const &pname
			  , std::string const &pnamein1
			  , std::string const &pnamein2
			)
		: TNode_Base(pname)		//, 2)		//, pidparent1, pidparent2)
		, m_Input_1(pnamein1)
		, m_Input_2(pnamein2)
// 		, m_ParentA(nullptr)
// 		, m_ParentB(nullptr)	
	{
// 		m_Inputs[0].Set_ID(pidparent1);
// 		m_Inputs[1].Set_ID(pidparent2);
	}

	virtual uint16_t Value(int lvl) const override			{ return (m_Input_1.Value(lvl + 1) & m_Input_2.Value(lvl + 1)); }

	virtual bool IsInputLinked() const override				{ return (m_Input_1.Is_Linked() && m_Input_2.Is_Linked()); }

	virtual int Level() const override							{ return m_Input.Level(); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override { return (m_Input_1.CheckSet_Link(pnode)
																											|| m_Input_2.CheckSet_Link(pnode)); }

 private:

	 TNode_Base::_TNodeIn m_Input_1;
	 TNode_Base::_TNodeIn m_Input_2;

	//TNode_Base const *m_ParentA;
	//TNode_Base const *m_ParentB;
};

//////////////////////////////////////////////////////////////////////////

class TNode_OR : public TNode_Base				//<2>
{
public:

	TNode_OR(std::string const &pname
			 , std::string const &pnamein1
			 , std::string const &pnamein2
			)
		: TNode_Base(pname)	//, 2)			//, pidparent1, pidparent2)
		, m_Input_1(pnamein1)
		, m_Input_2(pnamein2)
// 		, m_ParentA(nullptr)
// 		, m_ParentB(nullptr)
	{
// 		m_Inputs[0].Set_ID(pidparent1);
// 		m_Inputs[1].Set_ID(pidparent2);
	}

	virtual uint16_t Value(int lvl) const override			{ return (m_Input_1.Value(lvl + 1) | m_Input_2.Value(lvl + 1)); }

	virtual bool IsInputLinked() const override { return (m_Input_1.Is_Linked() && m_Input_2.Is_Linked()); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override
	{
		return (m_Input_1.CheckSet_Link(pnode)
				  || m_Input_2.CheckSet_Link(pnode));
	}

private:

	TNode_Base::_TNodeIn m_Input_1;
	TNode_Base::_TNodeIn m_Input_2;

// 	TNode_Base const *m_ParentA;
// 	TNode_Base const *m_ParentB;
};

//////////////////////////////////////////////////////////////////////////

class TNode_LSHIFT : public TNode_Base			//<1>
{
public:

	TNode_LSHIFT( const std::string &pname
					 , const std::string &pnamein
					 , int poffset
				) 
			: TNode_Base(pname)		//, 1)				//, pidparent1)
//			, m_Parent(nullptr)
			, m_Input(pnamein)
			, m_Offset(poffset)
	{
//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override			{ return (m_Input.Value(lvl + 1) << m_Offset); }

	virtual bool IsInputLinked() const override									{ return m_Input.Is_Linked(); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override	{ return m_Input.CheckSet_Link(pnode); }

private:

//	TNode_Base const *m_Parent;
	TNode_Base::_TNodeIn m_Input;
	int m_Offset;
};

//////////////////////////////////////////////////////////////////////////

class TNode_RSHIFT : public TNode_Base			//<1>
{
public:

	TNode_RSHIFT( const std::string &pname
					 , const std::string &pnamein
					 , int poffset
				)
		: TNode_Base(pname)		//, 1)					//, pidparent1)
//		, m_Parent(nullptr)
		, m_Input(pnamein)
		, m_Offset(poffset)
	{
//		m_Inputs[0].Set_ID(pidparent1);
	}

	virtual uint16_t Value(int lvl) const override			{ return (m_Input.Value(lvl + 1) >> m_Offset); }

	virtual bool IsInputLinked() const override									{ return m_Input.Is_Linked(); }

	virtual bool CheckLink_Input_Node(TNode_Base const *pnode) override	{ return m_Input.CheckSet_Link(pnode); }

private:

//	TNode_Base const *m_Parent;
	TNode_Base::_TNodeIn m_Input;
	int m_Offset;
};



#endif // TNodes_h__


