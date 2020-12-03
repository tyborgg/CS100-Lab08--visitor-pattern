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

TEST(VisitorTest, Preorder)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Div(op1,op2);
        Base* dummy = new Mult(temp,op2);

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
        EXPECT_EQ(visit->div_count(),1);
        EXPECT_EQ(visit->mult_count(),0);


}

TEST(VisitorTest, Preorder2)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Pow(op1,op2);
        Base* dummy = new Add(temp,op2);
	Base* op3 = new Op(4);
	Base* dummy2 = new Sub(dummy, op3);

        Iterator* it = new PreorderIterator(dummy2);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(),4);
        EXPECT_EQ(visit->pow_count(),1);
        EXPECT_EQ(visit->add_count(),1);
	EXPECT_EQ(visit->sub_count(),0);
}

TEST(VisitorTest, Preorder3)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Pow(op1,op2);
        Base* dummy = new Add(temp,op2);
        Base* op3 = new Op(4);
        Base* dummy2 = new Sub(dummy, op3);
	Base* op4 = new Op(5);
	Base* op5 = new Op(9);
	Base* temp2 = new Mult(op4, op5);
	Base* dummy3 = new Add(dummy2, temp2);

        Iterator* it = new PreorderIterator(dummy3);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(),6);
        EXPECT_EQ(visit->pow_count(),1);
        EXPECT_EQ(visit->add_count(),1);
        EXPECT_EQ(visit->sub_count(),1);
	EXPECT_EQ(visit->mult_count(),1);
}

TEST(VisitorTest, Preorder4)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Pow(op1,op2);
        Base* dummy = new Add(temp,op2);
        Base* op3 = new Op(4);
        Base* dummy2 = new Sub(dummy, op3);
        Base* rand1 = new Rand();
        Base* op5 = new Op(9);
        Base* temp2 = new Mult(rand1, op5);
        Base* dummy3 = new Add(dummy2, temp2);
	Base* rand2 = new Rand();
	Base* dummy4 = new Div(dummy3, rand2);

        Iterator* it = new PreorderIterator(dummy4);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(),5);
        EXPECT_EQ(visit->pow_count(),1);
        EXPECT_EQ(visit->add_count(),2);
        EXPECT_EQ(visit->sub_count(),1);
        EXPECT_EQ(visit->mult_count(),1);
	EXPECT_EQ(visit->rand_count(),2);
	EXPECT_EQ(visit->div_count(),0);	
}

TEST(VisitorTest, Preorder5)
{
        Base* op1 = new Op(3);
        Base* op2 = new Op(7);
        Base* temp = new Pow(op1,op2);
        Base* dummy = new Add(temp,op2);
        Base* op3 = new Op(4);
        Base* dummy2 = new Sub(dummy, op3);
        Base* rand1 = new Rand();
        Base* op4 = new Op(9);
        Base* temp2 = new Mult(rand1, op4);
        Base* dummy3 = new Add(dummy2, temp2);
        Base* rand2 = new Rand();
        Base* dummy4 = new Div(dummy3, rand2);
	Base* op5 = new Op(23);
	Base* rand3 = new Rand();
	Base* temp3 = new Add(op5, rand3);
	Base* dummy5 = new Pow(dummy4, temp3);

        Iterator* it = new PreorderIterator(dummy5);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

        EXPECT_EQ(visit->op_count(),6);
        EXPECT_EQ(visit->pow_count(),1);
        EXPECT_EQ(visit->add_count(),3);
        EXPECT_EQ(visit->sub_count(),1);
        EXPECT_EQ(visit->mult_count(),1);
        EXPECT_EQ(visit->rand_count(),3);
        EXPECT_EQ(visit->div_count(),1);
}

#endif //__VISITOR_TEST_HPP__
