#ifndef quicksort_HPP
#define quicksort_HPP
#include <iostream>
using namespace std;
#include "tab.hpp"



int partition(tab<int> &a, int p, int r){
	int x=a[r];
	int i=(p-1);
	for(int j=p; j<=(r-1); j++){
		if(a[j]<=x){
			i++;
			a.change_place(i, j);
		}
	}
	a.change_place((i+1), r);
	return i+1;
}




void quick_sort(tab<int> &a, int p, int r){
	if(p<r){
		int q=partition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}
#endif