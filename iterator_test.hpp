#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include <string>
#include "base.hpp"
#include "add.hpp"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "rand.hpp"
#include "pow.hpp"

using namespace std;

TEST(IteratorTest, AddTest)
{
	Base* op1 = new Op(7);
	Base* op2 = new Op(3);

	Base* add1 = new Add(op1,op2);
	Iterator* b1 = add1->create_iterator();
	
	EXPECT_EQ(op1,b1->current());
	b1->next();
	EXPECT_EQ(op2,b1->current());
}
TEST(IteratorTest, RandTest)
{
        Base* rand1 = new Rand();
        Iterator* b1 = rand1->create_iterator();	

        EXPECT_EQ(NULL,b1->current());
	b1->next();
	EXPECT_EQ(NULL,b1->current());
}
TEST(IteratorTest, OpTest)
{
        Base* op1 = new Op(7);

        Iterator* b1 = op1->create_iterator();

        EXPECT_EQ(NULL,b1->current());
        b1->next();
        EXPECT_EQ(NULL,b1->current());
}

TEST(IteratorTest, MultTest)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(3);

        Base* mult1 = new Mult(op1,op2);
        Iterator* b1 = mult1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());
}
TEST(IteratorTest, DivTest)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(3);

        Base* div1 = new Div(op1,op2);
        Iterator* b1 = div1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());
}
TEST(IteratorTest, SubTest)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(3);

        Base* sub1 = new Sub(op1,op2);
        Iterator* b1 = sub1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());
}
TEST(IteratorTest, PowTest)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(2);

        Base* pow1 = new Pow(op1,op2);
        Iterator* b1 = pow1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());
}

TEST(IteratorTest, BigTest)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(2);

        Base* mult1 = new Mult(op1,op2);
        Iterator* b1 = mult1->create_iterator();

	Base* op3 = new Op(5);
	Base* add1 = new Add(mult1, op3);

	Iterator* b2 = add1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());

	EXPECT_EQ(mult1,b2->current());
        b2->next();
        EXPECT_EQ(op3,b2->current());
}

TEST(IteratorTest, BigTest2)
{
        Base* op1 = new Op(7);
        Base* op2 = new Op(2);

        Base* div1 = new Div(op1,op2);
        Iterator* b1 = div1->create_iterator();

        Base* op3 = new Op(5);
        Base* sub1 = new Sub(div1, op3);

        Iterator* b2 = sub1->create_iterator();

        EXPECT_EQ(op1,b1->current());
        b1->next();
        EXPECT_EQ(op2,b1->current());

        EXPECT_EQ(div1,b2->current());
        b2->next();
        EXPECT_EQ(op3,b2->current());
}

#endif
