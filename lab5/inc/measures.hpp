#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "tab.hpp"
#include "timer.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"

void measures(tab &t, char option){ 
  tab pomiary(20);
  timer<microseconds> clock;
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
    clock.begin();
    merge_sort(t,0, t.get_length()-1);
    clock.stop();
    pomiary[i]=clock.duration();
    if(!is_sorted(t)){
      cout << "not sorted :c"<< endl;	
    }
  }

  /*
  cout <<"  pivot: poczatek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
  for(int i=0; i<pomiary.get_length()-1; i++){
    t.fill(option);
    clock.begin();
    merge_sort(t,0, t.get_length()-1);
    clock.stop();
    pomiary[i]=clock.duration();
    if(!is_sorted(t)){
      cout << "not sorted :c"<< endl;	
    }
  }
  cout <<"  pivot: srodek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
  for(int i=0; i<pomiary.get_length()-1; i++){
    t.fill(option);
    clock.begin();
    merge_sort(t,0, t.get_length()-1);
    clock.stop();
    pomiary[i]=clock.duration();
    if(!is_sorted(t)){
      cout << "not sorted :c"<< endl;	
    }
  } */
  cout <<"  czas sortowania: " << pomiary.mean() << " mikrosekund" << endl;
 	
}
#endif
