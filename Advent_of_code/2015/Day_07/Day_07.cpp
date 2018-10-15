#include "Day_07.h"

//#include <vector>
#include <sstream>

#include <fstream>

// #include <boost/algorithm/string.hpp>
// #include <boost/tokenizer.hpp>

namespace nsDay07
{



//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////

void CalcSolution()
{
	std::string str;
	//	int nice = 0;

	const std::string teststr(
		"NOT y->i\n"
		"x LSHIFT 2->f\n"
		"123->hf\n"
		"y RSHIFT 2->g\n"
		"hf -> x\n"
		"x OR y->e\n"
		"456->y\n"
		"NOT x->h\n"
		"x AND y->d\n"
	);

	TCircuit circuit;

	/**
	std::istringstream stream(teststr);
	/*/
	std::ifstream stream("2015/Day_07/input.txt");
	//*/

	while(stream.good())
	{
		std::getline(stream, str);

		auto currwire = TWire::Create_Wire(str);

		if(currwire)
		{
			circuit.AddWire(std::move(*currwire));
		}
	}

	// Test

	/**
	auto d = circuit.Value("d");
	auto e = circuit.Value("e");
	auto f = circuit.Value("f");
	auto g = circuit.Value("g");
	auto h = circuit.Value("h");
	auto i = circuit.Value("i");
	auto x = circuit.Value("x");
	auto y = circuit.Value("y");


	if( d != 72
	|| e != 507
	|| f != 492
	|| g != 114
	|| h != 65412
	|| i != 65079
	|| x != 123
	|| y != 456
	)
	{
		int a = 0;
	}
	/*/
	
	int result = circuit.Value("a");


	std::string strwire = std::to_string(result) + "->b";

	auto newwire = TWire::Create_Wire(strwire);

	if(newwire)
	{
		circuit.ReplaceWire(std::move(newwire.value()));
	}

	/**/

// 	uint16_t d = 72;
// 	uint16_t e = 507;
// 	uint16_t f = 492;
// 	uint16_t g = 114;
// 	uint16_t h = 65412;
// 	uint16_t i = 65079;
// 	uint16_t x = 123;
// 	uint16_t y = 456;

}

}
