/*
 * Interpreter
 * Author: reimen
 * Date: Oct.6.2014
 * Ginven a language, define a represention for its grammar along with
 * aninterpreter that uses the representation to interpret
 * sentences in the language.
 */
#include <iostream>
#include <cstdlib>
#include <list>
using std::cout;
using std::endl;
using std::list;

class AbstractExpression
{
public:
  virtual ~AbstractExpression() {}
  virtual int interpret() = 0;
};

class TerminalExpression : public AbstractExpression
{
  int _num;
public:
  TerminalExpression(int num) : _num(num) {}
  virtual ~TerminalExpression() {}
  virtual int interpret()
  {
    return _num;
  }
};

class NonterminalExpression : public AbstractExpression
{
  AbstractExpression*  _left_expression;
  AbstractExpression*  _right_expression;
public:
  NonterminalExpression(AbstractExpression* left_expression, AbstractExpression* right_expression)
    : _left_expression(left_expression), _right_expression(right_expression) {}
  virtual ~NonterminalExpression()
  {
    if(_left_expression != NULL)
      delete _left_expression;
    if(_right_expression != NULL)
      delete _right_expression;
  }
  virtual int interpret()
  {
    int left_num = _left_expression -> interpret();
    int right_num = _right_expression -> interpret();
    return left_num + right_num;
  }
};

int addFour(int a, int b, int c, int d)
{
  int ans;
  AbstractExpression *pa, *pb, *pc, *pd;
  AbstractExpression *pA, *pB, *pC;
  pa = new TerminalExpression(a);
  pb = new TerminalExpression(b);
  pc = new TerminalExpression(c);
  pd = new TerminalExpression(d);
  pC = new NonterminalExpression(pc, pd);
  pB = new NonterminalExpression(pb, pC);
  pA = new NonterminalExpression(pa, pB);
  ans = pA->interpret();
  delete pA;
  return ans;
}

int main()
{
  cout << addFour(1,2,3,4) << endl;
  return EXIT_SUCCESS;
}
