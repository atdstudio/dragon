#include <string>
#include <vector>
#include <stdexcept>
#include "covany.h"
namespace dragon
{
	typedef double Number;
	typedef bool Boolean;
	typedef std::string String;
	typedef cov::any(*NLI) (std::vector < cov::any > &);
	class Types
	{
		public:
		static constexpr int Null=-1;
		static constexpr int Number=0;
		static constexpr int Boolean=1;
		static constexpr int String=2;
		static constexpr int Variable=3;
		static constexpr int Function=4;
		static constexpr int Nli=5;
	};
	class Variable
	{
		protected:
		const bool mConst=false;
		const bool mStatic=false;
		const int mType=Types::Null;
		cov::any mVar;
		public:
		Variable():mVar(0.0){}
		Variable(int Type,bool Const=false,bool Static=false):mType(Type),mConst(Const),mStatic(Static){
			if(mConst)
				throw std::logic_error("Constant object is not initialized.");
		}
		template<typename T>Variable(T);
		template<typename T>Variable(T,bool,bool);
	};
	
	template<> Variable::Variable<Number>(Number num):
	mType(Types::Number),mVar(num){}
	template<> Variable::Variable<Number>(Number num,bool Const,bool Static):
	mConst(Const),mStatic(Static),mType(Types::Number),mVar(num){}
	
	template<> Variable::Variable<Boolean>(Boolean val):
	mType(Types::Boolean),mVar(val){}
	template<> Variable::Variable<Boolean>(Boolean val,bool Const,bool Static):
	mConst(Const),mStatic(Static),mType(Types::Boolean),mVar(val){}
	
	template<> Variable::Variable<String>(String val):
	mType(Types::String),mVar(val){}
	template<> Variable::Variable<String>(String val,bool Const,bool Static):
	mConst(Const),mStatic(Static),mType(Types::String),mVar(val){}
	
	template<> Variable::Variable<cov::any>(cov::any val):
	mType(Types::Variable),mVar(val){}
	template<> Variable::Variable<cov::any>(cov::any val,bool Const,bool Static):
	mConst(Const),mStatic(Static),mType(Types::Variable),mVar(val){}
	
	template<> Variable::Variable<NLI>(NLI val):
	mType(Types::Nli),mVar(val){}
	template<> Variable::Variable<NLI>(NLI val,bool Const,bool Static):
	mConst(Const),mStatic(Static),mType(Types::Nli),mVar(val){}
}