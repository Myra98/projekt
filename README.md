#include <iostream>
#include <iomanip>

using namespace std;

// Typ elementów listy dla kolejki

struct slistEl
{
  slistEl * next;
  int data;
};

// Zmienne globalne

int n;                   // Liczba wierzchołków
char ** A;               // Macierz sąsiedztwa
bool * visited;          // Tablica odwiedzin

// Procedura przejścia wszerz
//---------------------------
void BFS(int v)
{
  int i;
  slistEl *q,*head,*tail; // Kolejka

  q = new slistEl;        // W kolejce umieszczamy v
  q->next = NULL;
  q->data = v;
  head = tail = q;

  visited[v] = true;      // Wierzchołek v oznaczamy jako odwiedzony

  while(head)
  {
    v = head->data;       // Odczytujemy v z kolejki

    q = head;             // Usuwamy z kolejki odczytane v
    head = head->next;
    if(!head) tail = NULL;
    delete q;
    cout << setw(3) << v;
    for(i = 0; i < n; i++)
      if((A[v][i] == 1) && !visited[i])
      {
        q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sąsiadów
        q->next = NULL;
        q->data = i;
        if(!tail) head = q;
        else tail->next = q;
        tail = q;
        visited[i] = true; // i oznaczamy ich jako odwiedzonych
      }
  }
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
  int m,i,j,v1,v2,lw;

n=25;                    // Liczba wszystkich kwadratów                   
lw=11;                   // Liczba białych pól
  A = new char * [n];    // Tworzymy tablicę wskaźników
  visited = new bool[n]; // Tworzymy tablicę odwiedzin

  for(i = 0; i < n; i++)
    A[i] = new char[n];  // Tworzymy wiersze

  // Macierz wypełniamy zerami

  for(i = 0; i < n; i++)
  {
    visited[i] = true;  // Wypełniamy tablicę odwiedzin
    for(j = 0; j < n; j++) A[i][j] = 0;
  }

  // Odczytujemy kolejne definicje krawędzi
  //  visited[2]=false;
  //  visited[4]=false;
  //  visited[5]=false;
 //   visited[8]=false;
int tab[lw]={3,7,8,11,12,14,15,17,18,19,23};
for (int f=0;f<lw;f++)
    visited[tab[f]]=false;
    
for (int k=0;k<lw;k++){
    for (int j=0;j<lw;j++){
        if(tab[k]-tab[j]==5){
            A[tab[j]][tab[k]]=1;
            A[tab[k]][tab[j]]=1;
            }
        if((tab[k]-tab[j]==1) && ((tab[k] % 5)!=1)){
            A[tab[j]][tab[k]]=1;
            A[tab[k]][tab[j]]=1;
            }
    }
}

  cout << endl;

  // Przechodzimy graf wszerz

  BFS(12); // ustawiamy punkt początkowy

  // Usuwamy macierz

  for(i = 0; i < n; i++) delete A[i];
  delete [] A;
  delete [] visited;

  cout << endl;

  return 0;
} 
