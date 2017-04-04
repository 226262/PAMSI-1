#ifndef Node_HPP
#define Node_HPP
#include <iostream>

class Node 
{
	Node *prev; //wskaznik na poprzednie ogniwo
	Node *next; //wskaznik na nastepne ogniwo
	int value;  //zawartosc ogniwa
public:
	Node(){        //konstruktor
		prev=NULL;
		next=NULL;
		value=0;
	}
// 
	int get_value(){   //zwraca wartosc ogniwa
		return value;
	}
// 
	friend class List; //zaprzyjaznienie klasy lista by miala dostep do private
	friend class Queue;//--||-- 
	friend class Stack;//--||--
};

#endif
