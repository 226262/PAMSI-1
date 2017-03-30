#ifndef iList_HPP
#define iList_HPP
#include <iostream>
using namespace std;


class iList 
{
public:
	iList(){};
	virtual ~iList(){};
// 
	virtual void add(int a)=0;
	virtual int get()const=0;
	virtual int Size()const=0;
	// virtual List find(List a)const=0;
// 
};
#endif 