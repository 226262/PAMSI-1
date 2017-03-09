#include <iostream>
using namespace std;


class tab
{
	int wymiar_x;
	int wymiar_y;
	int ** tablica;
	public:
	void enlarge( int new_wymiar_x, int new_wymiar_y);
	tab(int, int);
	~tab();
	void input();
	void output();
	int size_kolumny();
	int size_wiersze();
	void size_out();
};
// 
tab::tab(int x, int y){
	wymiar_x=x;
	wymiar_y=y;
	tablica = new  int * [wymiar_x];
	for (int i=0; i<wymiar_x; i++){
		tablica[i]= new int[wymiar_y];
	}
}
//
tab::~tab(){
	for (int i=0; i<wymiar_x; i++){
		delete [] tablica[i];
	}
	delete [] tablica;
} 
// 
void tab::input(){
	int tmp;
	for (int i=0; i<wymiar_y; i++){
		for (int j=0; j<wymiar_x; j++){
			cout << "wiersz: " << i+1 << " kolumna: "  << j+1  << endl <<"wartość: ";
			cin >> tmp;
			tablica[j][i]=tmp;
			cout << endl;
		}
	}
}
// 
void tab::output(){
	for(int i=0; i<wymiar_y; i++){
		for(int j=0; j<wymiar_x; j++){
			cout << tablica[j][i]<<" ";
		}
		cout << endl;
	}
}
// 
void tab::size_out(){
	cout<< endl << "ilosc wierszy: " << wymiar_y << endl << "ilosc kolumn: " << wymiar_x << endl;
}
// 
int tab::size_kolumny(){
	return wymiar_x;
}
// 
int tab::size_wiersze(){
	return wymiar_y;
}
// 
void tab::enlarge(int new_wymiar_x, int new_wymiar_y){
	int ** tmp = new int * [new_wymiar_x];
	for (int i=0; i<new_wymiar_x; i++){
		tmp[i]= new int[new_wymiar_y];
	}
	for (int i=0; i<wymiar_y; i++){
		for (int j=0; j<wymiar_x; j++){
			tmp[i][j]=tablica[i][j];
			cout << endl;
		}
	}
	tablica=tmp;
	wymiar_x=new_wymiar_x;
	wymiar_y=new_wymiar_y;
}
int main(){
	int x,y;
		cout<<"ilosc kolumn: ";
		cin>> x;
		cout<<"ilosc wierszy: ";
		cin>> y;
		tab tablica(x, y);
		tablica.input();
		tablica.output();
		tablica.size_out();
		tablica.enlarge(x+1,y+1);
		tablica.output();
		tablica.size_out();
	return 0;
}