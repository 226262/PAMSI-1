#ifndef iQueue_HPP
#define iQueue_HPP
#include <iostream>
using namespace std;

class iQueue
{
	iQueue(){}
	virtual ~iQueue(){}
// 
	virtual void add(int a)=0;
	virtual int get()const=0;
	virtual int Size()const=0;
	// virtual Queue find(Queue a)const=0;
// 
	virtual int end()const=0;	
	virtual void push(int a)=0;
	virtual int pop()=0;	
};
#endif