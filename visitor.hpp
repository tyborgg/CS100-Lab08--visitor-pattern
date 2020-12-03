#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

#include "base.hpp"
//#include "op.hpp"
//#include "rand.hpp"
//#include "mult.hpp"
//#include "div.hpp"
//#include "add.hpp"
//#include "sub.hpp"
//#include "pow.hpp"

class Base;

class CountVisitor{
    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;

    public:
        CountVisitor();
        void visit_op();
        int op_count();
        void visit_rand();
        int rand_count();
        void visit_mult();
        int mult_count();
        void visit_div();
        int div_count();
        void visit_add();
        int add_count();
        void visit_sub();
        int sub_count();
        void visit_pow();
        int pow_count();

};

#endif //__COUNT_VISITOR_HPP__
