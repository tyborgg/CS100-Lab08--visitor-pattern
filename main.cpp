#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;

int main(){
	string input = "3+4-6*2/(rand)";
	Base* op1 = new Op(3);
	Base* op2 = new Op(4);
	Base* add1 = new Add(op1,op2);
	Base* op3 = new Op(6);
        Base* sub1 = new Sub(add1,op3);
	Base* op4 = new Op(2);
	Base* mult1 = new Mult(sub1, op4);
	Base* rand1 = new Rand();
	Base* div1 = new Div(mult1, rand1);
	Base* dummy = new Div(div1, op1);	

	Iterator* it = new PreorderIterator(dummy);
        CountVisitor* visit = new CountVisitor();
        it->first();
        while(!it->is_done())
        {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }

	cout << "Input: " << input << endl << endl;

	cout << "Op count: " << visit->op_count() - 1 << endl;
	cout << "Rand count: " << visit->rand_count() << endl;
	cout << "Add count: " << visit->add_count() << endl;
	cout << "Sub count: " << visit->sub_count() << endl;
	cout << "Mult count: " << visit->mult_count() << endl;
	cout << "Div count: " << visit->div_count() << endl;
	
	return 0;
}
