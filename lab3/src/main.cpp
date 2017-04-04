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
	}
	cout << "zajelo mi to srednio: " << results.mean() <<" mikrosekund\n";
	cout << "a sprawdzalem to na kontenerze typu "<< x.type()<<endl;
	cout << "dla " << a << " elementow\n";
}


int main(){
	srand(time(NULL)); //zapewnia losowosc przy kazdym kolejnym odpaleniu programu
	List l;
	Stack s;
	Queue q;
	// measures(100, 10, l);
	// measures(100, 10, s);
	measures(100, 10, q);
}
