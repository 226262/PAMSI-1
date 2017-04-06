#include <iostream>
using namespace std;
#include <cstdlib>


int** stworz_tablice(int wymiar_x, int wymiar_y)
{
	int ** tablica = new int * [wymiar_x];
	for(int i=0; i<wymiar_x; i++)
		tablica[i] = new int[wymiar_y];
	return tablica;
}

void usun_tablice(int** tablica, int wymiar_x)
{
	for(int i=0; i<wymiar_x; i++)
		delete [] tablica[i];
}

void wypelnij_tablice(int** tablica, int wymiar_x,int wymiar_y)
{
	for(int i=0; i<wymiar_x; i++)
			for(int j=0; j<wymiar_y; j++)
				tablica[i][j]=rand() % 10;
}

void wyswietl_tablice(int** tablica, int wymiar_x, int wymiar_y)
{
	for(int i=0; i<wymiar_x; i++){
		for(int j=0; j<wymiar_y; j++){
			cout << tablica[i][j]<<" ";
		}
		cout << endl;
	}
	
}

int znajdz_najw(int** tablica, int wymiar_x, int wymiar_y)
{
	int tmp;
	tmp=tablica[0][0];
	for(int i=0; i<wymiar_x; i++)
		for(int j=0; j<wymiar_y; j++)
			if (tablica[i][j]>tmp)
				tmp=tablica[i][j];
	return tmp;
}
	int main()
	{
		int x,y;
		cout<<"x";
		cin>>x;
		cout<<"y";
		cin>> y;
		int ** tablica = stworz_tablice(x,y);
		wypelnij_tablice(tablica, x, y);
		wyswietl_tablice(tablica, x, y);
		cout << "Biggest: " << znajdz_najw(tablica, x, y) << endl;

	}

			
			

