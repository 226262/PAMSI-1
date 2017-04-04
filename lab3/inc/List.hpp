#ifndef List_HPP
#define List_HPP
#include <iostream>
using namespace std;
#include "iList.hpp"
#include "Node.hpp"


class List : public iList
{
	Node *head; //wskaznik na poczatek listy
	Node *tail; //wskaznik na ostatni element tablicy
	int size; //rozmiar listy, 0 oznacza ze lista jest pusta
	string what;
public:
//
	List(){         //konstruktor
		head=NULL;
		tail=NULL;
		size=0;
		what = "List";
	}

	void add(int a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node * new_ = new Node; //stworzenie nowego ogniwa
		if (head==NULL){        //sprawdzenie czy lista jest pusta
			head=new_;          //przypisanie wskaznikow na glowe i ogon do pierwszego dodanego elementu
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
		if(a->prev==NULL){  //jesli a to head
			a->next->prev=NULL;
			head=a->next;
		}
		if(a->prev!=NULL && a->next!=NULL){ //jesli a znajduje sie w srodku listy
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
	Node* find_value(int a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		Node* tmp;
		tmp=head;
		while(tmp!=NULL){ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->value==a){
				return tmp;
			}
			tmp=tmp->next;
		}
		return NULL;
	}
//

	void print(){  //wypisuje po kolei elemety listy
		Node* tmp;
		tmp=head;
		while(tmp->next!=NULL){
			cout<< tmp->value << "\t";
			tmp=tmp->next;
		}
		cout<< tmp->value << "\n";
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
	string type(){
		return what;
	}
};
#endif


