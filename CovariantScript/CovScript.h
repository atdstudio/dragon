#include <iostream>
#include <string>
#include "covany.h"
namespace Cs
{
	typedef cov::any Var;
	typedef double Num;
	typedef bool Bool;
	typedef std::string String;
	static const char* Endl="\n";
	template < typename T > void print(const T & val)
	{
		std::cout << val;
	}
	template < typename T, typename ... Elements >
	void print(const T & val, const Elements & ... args)
	{
		print(val);
		print(args...);
	}
	template < typename T > void input(T & val)
	{
		std::cin >> val;
	}
	template < typename T, typename...Elements > void input(T & val, Elements & ... args)
	{
		input(val);
		input(args...);
	}
}
int main()
{
	using namespace Cs;
	print("Covariant Script[Dragon] Interpreter v16.50 Beta",Endl);
	print("Please enter your name:");
	String name;
	input(name);
	print("Hello,",name,"!");
	return 0;
}