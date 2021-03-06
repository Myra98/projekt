#include <iostream>
#include <iomanip>
#include <stdlib.h> //rand
#include <ctime>
#include "functions.h"

using namespace std;

// Zmienne globalne

int n;                   // Liczba wierzcholkow
char ** A;               // Macierz sasiedztwa
bool * visited;          // Tablica odwiedzin
int mapa[40][20] = {};

// **********************
// *** PROGRAM GLOWNY ***
// **********************

int main()
{
    srand(time(NULL));
    
    generateMap(mapa);
    draw(mapa);
    
    system("PAUSE");
	
	int m, i, j, v1, v2;
    
	int n = 25;                    // Liczba wszystkich kwadratów                   
    int lw = 11;                   // Liczba bialych pol
    A = new char *[n];    // Tworzymy tablice wskaznikow
    visited = new bool[n]; // Tworzymy tablice odwiedzin

    for (i = 0; i < n; i++)
        A[i] = new char[n];  // Tworzymy wiersze

    // Macierz wypelniamy zerami

    for (i = 0; i < n; i++)
    {
        visited[i] = true;  // Wypelniamy tablice odwiedzin
        for (j = 0; j < n; j++) A[i][j] = 0;
    }

    // Odczytujemy kolejne definicje krawedzi
    //  visited[2]=false;
    //  visited[4]=false;
    //  visited[5]=false;
    //   visited[8]=false;
    int tab[] = { 3, 7, 8, 11, 12, 14, 15, 17, 18, 19, 23 };
    for (int f = 0; f<lw; f++)
        visited[tab[f]] = false;

    for (int k = 0; k<lw; k++){
        for (int j = 0; j<lw; j++){
            if (tab[k] - tab[j] == 5){
                A[tab[j]][tab[k]] = 1;
                A[tab[k]][tab[j]] = 1;
            }
            if ((tab[k] - tab[j] == 1) && ((tab[k] % 5) != 1)){
                A[tab[j]][tab[k]] = 1;
                A[tab[k]][tab[j]] = 1;
            }
        }
    }

    cout << endl;

    // Przechodzimy graf wszerz

    BFS(12); // ustawiamy punkt początkowy

    // Usuwamy macierz

    for (i = 0; i < n; i++) delete A[i];
    delete[] A;
    delete[] visited;

    cout << endl;

    return 0;
}
