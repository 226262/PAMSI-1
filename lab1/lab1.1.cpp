#include <iostream>
using namespace std;
#include <cstdlib>
#include <chrono>
#include <ctime>

class tab
{
	int length;
	double * tablica;
	void enlarge(int);
public:
	//konstruktory, metody 
	tab(int);
	~tab();
	void input();
	void fill_rand(int);
	void output();
	int size();
	void size_out();	
	friend void measures(int, int);
	double mean();
	//przeciazenia
	double & operator[](int element) {return tablica[element];}
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

struct clock_
{
	chrono::time_point<chrono::system_clock> start, end;
	chrono::duration<double> elapsed_seconds = end-start;
	// 
    void begin(){
    	start = chrono::system_clock::now();
    }
    // 
    void stop(){
    	end = chrono::system_clock::now();
    }
    // 
	void duration_out(){ 
    	cout<< "czas trwania: " << elapsed_seconds.count();
	}
	double duration(){
		return elapsed_seconds.count();
	}
	//
	friend void measures(int);
};
// 
void measures(int x, int y){ //x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	clock_ t;
	tab oryginal(x);
	tab pomiar(x);
	oryginal.fill_rand(100);
	tab wyniki_add1(y);
	tab wyniki_x2(y);
	for(int i=0; i<y; i++){
		pomiar=oryginal;
		t.begin();
		pomiar.enlarge(pomiar.length+1);
		t.stop();
		wyniki_add1[i]=t.duration();
	}
	for(int i=0; i<20; i++){
		pomiar=oryginal;
		t.begin();
		pomiar.enlarge(2*pomiar.length);
		t.stop();
		wyniki_x2[i]=t.duration();
		cout<< t.duration();
	}
	pomiar.output();

	cout<< "wyniki dla " << y << " elementow." << endl;
	cout<< "+1" << endl; 
	wyniki_add1.output();
	cout<< "srednia: " << wyniki_add1.mean();
	cout<< "x2" << endl; 
	wyniki_x2.output();
	cout<< "srednia: " << wyniki_x2.mean();
}
// 
int main(){
	int x;
	int y;
	cout<<"ilosc elementow: ";
	cin>> x;
	cout<<"ilosc powtorzen: ";
	cin>> y;
	measures(x, y);
	return 0;
}