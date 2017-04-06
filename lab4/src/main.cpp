#include "../inc/tab.hpp"
#include "../inc/timer.hpp"
#include "../inc/quicksort.hpp"
#include <cstdlib>
#include<iostream>
using namespace std;

// 
int main(){
	srand(time(NULL));
	tab<int> a(10);
	timer<nanoseconds> t;
	a.fill_rand(50);
	a.output();
	t.begin();
	quick_sort(a,0,a.get_length());
	t.stop();
	a.output();
	cout << "zajelo mi to: " << t.duration() <<" nanosekund"<< endl;
	return 0;
}
