#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
class Op : public Base {
    public:
	double result;
        Op(double value) : Base()
	{
		this->result = value;
	}
        virtual double evaluate()
	{
		return result;
	}
        virtual std::string stringify()
	{
		std::string text;
		text = std::to_string(result);
		return text;
	}
	virtual Base* get_right()
	{
		return nullptr;
	}
	virtual Base* get_left()
	{
		return nullptr;
	}
	virtual Iterator* create_iterator()
	{
		Iterator* it1 = new NullIterator(this);
		return it1;
		//needs to return a null iterator
	}
};

#endif //__OP_HPP__
