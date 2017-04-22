#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <iostream>

using namespace std;
#include "tab.hpp"



void merge(tab &array, int left, int middle, int right){

  tab temp(right-left+1);
  int i=left, j=middle+1,k=0; 

  while(i<=middle && j<= right){

    if(array[j]<array[i]){
      temp[k]=array[j];
      j++;
    }else{
      temp[k] =array[i];
      i++;
    }
    k++;
  }

  if(i<=middle){

    while(i<=middle){
      temp[k]=array[i];
      i++;
      k++;
    }
  }else{

    while(j<= right){
      temp[k]=array[j];
      j++;
      k++;
    }
  }

  for(i=0; i<=right-left;i++){
    array[left+i]=temp[i];
    
  }
}
  
void merge_sort(tab &array, int left,  int right){

  int middle;

  if(left!=right){
    middle=(left+right)/2;
    merge_sort(array, left, middle);
    merge_sort(array, middle+1,right);
    merge(array,left,middle,right);
  }
  
}


#endif
