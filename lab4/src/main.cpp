#include "../inc/tab.hpp"
#include "../inc/timer.hpp"
#include "../inc/quicksort.hpp"
#include <cstdlib>
#include<iostream>
using namespace std;
//option: r- rosnacy, m-malejacy, 
void mierz_mnie_kurwo(tab &t, char option){ 
	tab pomiary(5);
	timer<milliseconds> clock;
	string what;
	switch(option){
		case 'r':
			what ="Rosnaca tablica";
		break;

		case 'm':
			what ="Malejaca tablica";
		break;

		case 'l':
			what ="Losowa tablica";
		break;
	}
			cout<< what << endl;
			cout<<"ilosc elementow: " <<t.get_length() << endl;
				for(int i=0; i<pomiary.get_length(); i++){
				t.fill(option);
				t.output();
				clock.begin();
				quick_sort(t, 0, t.get_length(),'f');
				clock.stop();
				pomiary[i]=clock.duration();
				t.output();
				}
			cout <<"  pivot: poczatek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
				for(int i=0; i<pomiary.get_length(); i++){
				t.fill(option);
				t.output();
				clock.begin();
				quick_sort(t, 0, t.get_length(),'m');
				clock.stop();
				t.output();
				pomiary[i]=clock.duration();
				// t.output();
				}
			cout <<"  pivot: srodek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
				for(int i=0; i<pomiary.get_length(); i++){
				t.fill(option);
				t.output();
				clock.begin();
				quick_sort(t, 0, t.get_length(), 'l');
				clock.stop();
				t.output();
				pomiary[i]=clock.duration();
				// t.output();
				}
			cout <<"  pivot: koniec \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
		
}

// 
int main(int argc, char* argv[]){
	srand(time(NULL));
	tab a(atoi(argv[1]));
	mierz_mnie_kurwo(a, *argv[2]);
	return 0;
}
