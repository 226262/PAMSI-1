#include "../inc/iRunable.hpp"
#include "../inc/Stack.hpp"
#include "../inc/List.hpp"
#include "../inc/Queue.hpp"
#include "../inc/Timer.hpp"
#include "../inc/tab.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void measures(int a, int b, iRunable &x){ //a- ile elementow, b-ile testow, x obiekt na ktorym bedziemy pracowac
	Timer<microseconds> t;
	int when; //kiedy wrzucic szukana wartosc
	tab<float> results(b);
	when=(rand() & (a/4)) + (a/4);
	for(int j=0; j<b; j++){
		for(int i=0; i<a; i++){
			if(i!=when){
				x.add( ( (rand() & 10000) + 100) ); //wrzuca losowe liczby od 100 do 100+10000
			} else{
				x.add(2); //bo czemu nie
			}
		}
		t.begin();
		x.find_value(2);
		t.stop();
		results[j]=t.duration();
		x.flush();
	}
	cout << "-----------------------------------------------\n";
	cout <<  x.type()<<endl;
	cout <<a << " elementow-";
	cout << results.mean() <<" mikrosekund\n";
	cout << "zrobilem to: " << b << " razy\n";
	cout << "-----------------------------------------------\n";
}


int main(int argc, char* argv[]){
	srand(time(NULL)); //zapewnia losowosc przy kazdym kolejnym odpaleniu programu
	List l;
	Stack s;
	Queue q;
	/*l.add(1);
	if(l.head==l.tail){
	cout << l.head->get_prev() << " " << l.head->get_next() << endl;
	}
	l.add(2);
	if(l.head==l.tail){
	cout << l.head->get_prev() << " " << l.head->get_next() << endl;
	}
	cout << l.size << endl;

	l.remove(l.tail);
	cout << l.size << endl;
	l.remove(l.tail);
	cout << l.size << endl; */	
	if(argc<=2){
		cout<<"za malo argumentow\n";
		return 0;
	}else{
		if(*argv[3]=='l'){
			measures(-atoi(argv[1]), atoi(argv[2]), l);
		}
		if(*argv[3]=='s'){
			measures(-atoi(argv[1]), atoi(argv[2]), s);
		}
		if(*argv[3]=='q'){
			measures(-atoi(argv[1]), atoi(argv[2]), q);
		}
	}

}
