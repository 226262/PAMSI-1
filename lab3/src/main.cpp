#include "../inc/iRunable.hpp"
#include "../inc/Stack.hpp"
#include "../inc/List.hpp"
// #include "../inc/Queue.hpp"
#include "../inc/iStack.hpp"
#include "../inc/iList.hpp"
#include "../inc/iQueue.hpp"
#include<iostream>
using namespace std;

void proba(iRunable &x){
	for(int i=0; i<10; i++){
		x.add(i);
	}
	x.print();
	cout<< "jestem " << x.type()<<endl;

}
int main(){
	// List l;
	Stack s;
	// proba(l);
	proba(s);
}
