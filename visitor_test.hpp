#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
//#include "div.hpp"
#include "pow.hpp"
//#include "visitor.hpp"
//#include "iterator.hpp"

TEST(VisitorTest, SimpleBinaryTest)
{
	Base* op1 = new Op(3);
	Base* op2 = new Op(7);
	Base* temp = new Pow(op1,op2);
	Base* dummy = new Add(temp,op2);

	Iterator* it = dummy->create_iterator();
	CountVisitor* visit = new CountVisitor();
	it->first();
	while(!it->is_done())
	{
		Base* phase = it->current();
		phase->accept(visit);
		it->next();
	}

	EXPECT_EQ(visit->op_count(),1);
	EXPECT_EQ(visit->pow_count(),1);
	EXPECT_EQ(visit->add_count(),0);


}

TEST(VisitorTest, LastTestButPreorder)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Pow(op1,op2);
        Base* dummy = new Add(temp,op2);

        Iterator* it = new PreorderIterator(dummy);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(),3);
        EXPECT_EQ(visit->pow_count(),1);
        EXPECT_EQ(visit->add_count(),0);


}

#endif //__VISITOR_TEST_HPP__
