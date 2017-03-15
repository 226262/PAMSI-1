#include <iostream>
using namespace std;
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <time.h>

class tab
{
	int length;
	double * tablica;
public:
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
// 
struct clock_
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
		pomiar.enlarge(2*(pomiar.length));
		t.stop();
		wyniki_x2[i]=t.duration();
		// cout<< t.duration();
	}

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
	double x;
	cin >> x;
	int y;
	cin >> y;
	measures(x, y);

	return 0;
}

// std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
// std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

// std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() <<std::endl;
// std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() <<std::endl;

 