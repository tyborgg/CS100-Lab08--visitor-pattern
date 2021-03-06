#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "visitor.hpp"

using namespace std;
//class Iterator;


class Rand : public Base {
    public:
	double random;
        Rand() : Base(){
		random = rand() % 100;
	}
        virtual double evaluate(){
		return random;
	}
        virtual string stringify(){
		string str = "";
		str = to_string(random);
		return str;
	}
	virtual Base* get_left()
	{
		return nullptr;
	}
	virtual Base* get_right()
	{
		return nullptr;
	}
	virtual Iterator* create_iterator()
	{
		Iterator* it1 = new NullIterator(this);
		return it1;
		//needs to return a null iterator.
	}
        virtual void accept(CountVisitor* v1)
        {
                v1->visit_rand();
        }

};

#endif //__RAND_HPP__
