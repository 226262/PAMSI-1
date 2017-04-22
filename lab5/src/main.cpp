#include "../inc/tab.hpp"
#include "../inc/timer.hpp"
#include "../inc/quicksort.hpp"
#include "../inc/mergesort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include<iostream>

using namespace std;


int main(int argc, char* argv[]){

  
  srand(time(NULL));
  tab a(atoi(argv[1]));
  measures(a, *argv[2]);


  /*
  tab tablica(100);

  tablica.fill('l');

  // tablica.output();
  merge_sort(tablica,0,99);
  cout << "\n";
  //tablica.output();
  if(!is_sorted(tablica)){
    cout << "not sorted :c"<< endl;	
  }
  */
  
  return 0;

}
