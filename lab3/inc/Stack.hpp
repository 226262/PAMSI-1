#ifndef Stack_HPP
#define Stack_HPP
#include <iostream>
using namespace std;
#include "iStack.hpp"
#include "Node.hpp"

class Stack : public iStack
{
	Node* tail; //wskaznik na ostatni element stosu
	int size;
	string what; //czym jestem
public:
	Stack(){       //konstruktor
		tail=NULL;
		size=0;
		what="Stack";
	}
//
	void add(int a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node * new_ = new Node; //stworzenie nowego ogniwa
		if (tail==NULL){        //sprawdzenie czy stos jest pusty
			tail=new_;
			new_->prev=NULL;     //przypisanie wlasciwych wskznikow do ogniwa
			new_->next=NULL;
		} else{
			tail->next=new_;
			new_->prev=tail;
			tail=new_;
			new_->next=NULL;
		}
		new_->value=a;
		size++;
	}
//
	void remove(Node *a){
		if(a->prev==NULL){  //jesli a jest na spodzie stosu
			a->next->prev=NULL;
		}
		if(a->prev!=NULL && a->next!=NULL){ //jesli a znajduje sie w srodku stosu
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==NULL){  //jesli a to tail
			a->prev->next=NULL;
			tail=a->prev;
		}
		size--; //rozmiar sie zmniejsza
		delete a; //zwolnienie pamieci
	
	}
//
	void push(int a){ //dodanie nowego elementu na gore stosu
		add(a);
	}
//
	void pop(){ //wyrzuca ostatni element ze stosu
			if(is_empty()){
			cout << "Nie ma nic do wyrzucenia\n";
		} else{
			remove(tail);
		}
		size--;
	}
//
	int top(){//zwraca wartosc ostatniego elementu
		return tail->value;
	}
//
	Node* find_value(int a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		while(size){
			if(tail->value==a){
				return tail;
			} 
			pop();
		}
		return NULL;
	}
//
	int get_size(){   //zwraca rozmiar
		return size;
	}
//
	int get(){ //zwraca wartosc ostatniego elementu
		return tail->value;
	}
//
	int get(Node *a){ //zwraca wartosc podanego elementu
		return a->value;
	}
//
	bool is_empty(){	//sprawdza czy jest pusty
		if(!size){
			return true;
		} else{
			return false;
		}
	}
//
	void print(){
		Node* tmp;
		tmp=tail;
		for(int i=size; i>0; i--){
			cout << tmp->value << "\t";
			tmp=tmp->prev;
		}
	}
//
	string type(){
		return what;
	}
};
#endif