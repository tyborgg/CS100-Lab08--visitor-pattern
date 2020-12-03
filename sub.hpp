#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "visitor.hpp"
//class Iterator;

class Sub : public Base
{
	public:
		double result;
		Base* arg1;
		Base* arg2;
		std::string str1;
		std::string str2;
		Sub(Base* n1, Base* n2) : Base()
		{
			this->arg1 = n1;
			this->arg2 = n2;
			this->str1 = arg1->stringify();
			this->str2 = arg2->stringify();
			this->result = (arg1->evaluate() - arg2->evaluate());
		}
		virtual double evaluate()
		{
			return this->result;
		}
		virtual std::string stringify()
		{
			return str1 + " - " + str2;
		}
	        virtual Base* get_left()
        	{
                	return arg1;
        	}
        	virtual Base* get_right()
        	{
                	return arg2;
        	}
	        virtual Iterator* create_iterator()
        	{
			Iterator* it1 = new BinaryIterator(this);
			return it1;
                //needs to return a binary iterator
        	}
		virtual void accept(CountVisitor* v1)
		{
			v1->visit_sub();
		}

};

#endif //__SUB_HPP__
