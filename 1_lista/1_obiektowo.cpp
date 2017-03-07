#include <iostream>
using namespace std;
#include <cstdlib>


struct tab
{
	int x;
	int y;
	int** tablica;
	// metody, konstruktory
	tab(int X, int Y);
	void wypelnij();
	void wyswietl();
	int znajdz_najw();
	void usun();
};

tab::tab(int X, int Y)
{
	x=X;
	y=Y;
	tablica = new int * [x];
	for(int i=0; i<x; i++)
		tablica[i] = new int[y];
}

void tab::wypelnij()
{
	for(int i=0; i<x; i++){
			for(int j=0; j<y; j++)
				tablica[i][j]=rand() % 10;
	}
}

void tab::wyswietl()
{
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			cout << tablica[i][j]<<" ";
		}
		cout << endl;
	}
}

int tab::znajdz_najw()
{
	int tmp;
	tmp=tablica[0][0];
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			if (tablica[i][j]>tmp)
				tmp=tablica[i][j];
	return tmp;
}

void tab::usun()
{
	for(int i=0; i<x; i++)
		delete [] tablica[i];
}



	int main()
	{
		int x,y;
		cout<<"x";
		cin>> x;
		cout<<"y";
		cin>> y;
		tab tablica(x, y);
		tablica.wypelnij();
		tablica.wyswietl();
		cout << "Biggest: " << tablica.znajdz_najw() << endl;
		tablica.usun();

	}

			
			

