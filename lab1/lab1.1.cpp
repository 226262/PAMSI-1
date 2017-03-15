#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

class tab              //
{
	int length;        //dlugosc tblicy
	double * tablica;  //dynamiczna tablica
	void enlarge(int); //funkcja powiekszania, przyjmowany argument mowi do ilu ziwekszyc tablice
	int amor;          //wolne miejsce w tablicy
public:
	//konstruktory, metody 
	tab(int);
	void input();      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
	~tab(); 
	void fill_rand(int);//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres randomowych liczb
	void output();      //wypisuje wartosci tablicy
	int size();         //zwraca rozmiar tablicy
	void size_out();	//wypisuje rozmiar tablicy
	int get_amor();    //zwraca dlugosc amora
	friend void measures(int, int); //zaprzyjazniona funkcja sluzaca do pomiarow
	double mean(); //funkcja zwracajaca srednia wszystkich elementow tablicy 
	//przeciazenia
	double & operator[](int element) {return tablica[element];} //przeciazenie operatora []
};
// 
tab::tab(int x){
	length=x;
	amor =x;
	tablica = new  double [length];

}
//
tab::~tab(){
	delete [] tablica;
} 
// 
void tab::input(){
	int tmp;
	for (int i=0; i<length; i++){
		cout << "podaj element nr " << i+1 << ": ";
		cin >> tmp;
		tablica[i]=tmp;
	}
	amor=0;
}
//
void tab::fill_rand(int range){
	for (int i=0; i<length; i++){
		tablica[i]=rand() % range;
	}
	amor=0;
}
// 
void tab::output(){
	for(int i=0; i<length; i++){
		cout << tablica[i]<<" ";
	}
	cout << endl << "thats all" << endl;
}
// 
void tab::size_out(){
	cout<< endl << "ilosc elementow " << length << endl;
}
// 
int tab::size(){
	return length;
}
//
int tab::get_amor(){
	return amor;
}
// 
void tab::enlarge(int new_length){
	double * tmp = new double [new_length];
	for (int i=0; i<length; i++){
		tmp[i]=tablica[i];
	}
	// delete [] tablica;
	tablica=tmp;
	amor=new_length-(length-amor);
	length=new_length;
}
// 
double tab::mean(){
	double x;
	x=0;
	for(int i=0; i<length; i++){
		x=x+tablica[i];
	}
	return x/length;
}
// 
class clock_
{
	double start, end;
	double duration_; 
    void begin(){
    	start = clock();
    }
    // 
    void stop(){
    	end = clock();
    }
    // 
	void duration_out(){
		duration_ = end-start; 
    	cout<< "czas trwania: " << duration_ << endl;
	}
	double duration(){
		duration_ = end-start;
		return duration_;
	}
	//
	friend void measures(int, int);
};
//

void measures(int x, int y){ //funckja wykonujaca pomiary czasu, x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	clock_ t;
	tab pomiar_add1(1); //inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania o 1
	tab pomiar_x2(1);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
	tab wyniki_add1(y); //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania o 1
	tab wyniki_x2(y);   //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania razy dwa
	for(int i=0; i<y; i++){
		t.begin();       //rozpoczecie mierzenia czasu
		for(int j=0; j<x; j++){
			
			if(!pomiar_add1.amor){ 							 //jesli nie ma miejsca tablica zostanie powiekszona o 1
				pomiar_add1.enlarge((pomiar_add1.length)+1); //powiekszenie tablicy o 1 
				j--; 					 //zmniejszenie licznika petli w celu nie wyjscia poza zaalokowana pamiec dla tablicy
			}
			else{
				pomiar_add1[j]=rand (); // w przypadku wolnego miejsca, dopisana zostaje randomowa wartosc
				pomiar_add1.amor--;     // ilosc miejsc wolnych zmniejszaz sie o 1
			}
		}
		t.stop();        //koniec pomiaru czasu
		wyniki_add1[i]=t.duration(); //wpisanie wyniku do tablicy
	}
	for(int i=0; i<y; i++){
		t.begin();
		for(int j=0; j<x; j++){
			if(!pomiar_x2.amor){
				pomiar_x2.enlarge(2*(pomiar_x2.length)); //powiekszenie tablicy dwukrotnie 
				j--;
			}
			else{
				pomiar_x2[j]=rand ();
				pomiar_x2.amor--;
			}
		}
		t.stop();
		wyniki_x2[i]=t.duration();
	}

	cout<< "wyniki dla " << x << " elementow." << endl;
	cout<< "+1" << endl; 
	wyniki_add1.output();
	cout<< "srednia: " << wyniki_add1.mean();
	cout << endl;
	cout<< "x2" << endl; 
	wyniki_x2.output();
	cout<< "srednia: " << wyniki_x2.mean();
	cout << endl;
}
// 
int main(){
	double x=10;
	int y=20;
	for (int i=0; i<1; i++){
		cout << "*************" << endl;
		measures(x, y);
		cout << "-*************" << endl;
		x=x*10;
	}	
	return 0;
}


