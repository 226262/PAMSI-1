#ifndef iStack_HPP
#define iStack_HPP
#include <iostream>
using namespace std;
//stos na inty

class iStack 
{
public:
	iStack(){}
	virtual ~iStack(){}
// 
	virtual void add(int a)=0;
	virtual int get()const=0;
	virtual int Size()const=0;
	// virtual Stack find(Stack a)const=0;
// 
	virtual int top()const=0;	
	virtual void push(int a)=0;
// 
	virtual int pop()=0;	
};
#endif