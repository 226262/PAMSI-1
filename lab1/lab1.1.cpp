#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

class tab              //
{
	int length;        //dlugosc tblicy
	double * tablica;  //dynamiczna tablica
	void enlarge(int); //funkcja powiekszania, przyjmowany argument mowi do ilu ziwekszyc tablice
public:
	//konstruktory, metody 
	tab(int);
	~tab();
	void input();      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
	void fill_rand(int);//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres randomowych liczb
	void output();      //wypisuje wartosci tablicy
	int size();         //zwraca rozmiar tablicy
	void size_out();	//wypisuje rozmiar tablicy
	friend void measures(int, int); //zaprzyjazniona funkcja sluzaca do pomiarow
	double mean(); //funkcja zwracajaca srednia wszystkich elementow tablicy
	//przeciazenia
	double & operator[](int element) {return tablica[element];} //przeciazenie operatora [] 
};
// 
tab::tab(int x){
	length=x;
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
}
//
void tab::fill_rand(int range){
	for (int i=0; i<length; i++){
		tablica[i]=rand() % range;
	}
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
void tab::enlarge(int new_length){
	double * tmp = new double [new_length];
	for (int i=0; i<length; i++){
		tmp[i]=tablica[i];
	}
	tablica=tmp;
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
	tab oryginal(x); //inicjalizacja tablicy oryginalnej 
	tab pomiar(x);   //inicjalizacja tablicy na ktorej wykonane zzostana pomiary
	oryginal.fill_rand(100); //wypelnienie tablicy oryginalnej randomowymi wartosciami od 0 do 100
	tab wyniki_add1(y); //inicjalizacja tablicy do ktorej zapisane zostana pomiary dla powiekszania o 1
	tab wyniki_x2(y);   //inicjalizacja tablicy do ktorej zapisane zostana pomiary dla powiekszania razy dwa
	for(int i=0; i<y; i++){
		pomiar=oryginal; //tablica pomiarowa jest taka sama jak oryginal
		t.begin();       //rozpoczecie mierzenia czasu
		pomiar.enlarge((pomiar.length)+1); //powiekszenie tablicy o 1 
		t.stop();        //koniec pomiaru czasu
		wyniki_add1[i]=t.duration(); //wpisanie wyniku do tablicy
	}
	for(int i=0; i<20; i++){
		pomiar=oryginal;
		t.begin();
		pomiar.enlarge(2*(pomiar.length)); //powiekszenie tablicy dwukrotnie
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
	double x;
	int y;
	cout << "ilosc elementow tablicy: ";
	cin >> x;
	cout << "ilosc powtorzen obliczen: ";
	cin >> y;
	cout << "*************" << endl;
	measures(x, y);
	return 0;
}


 