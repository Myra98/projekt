#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern int n;                   // Liczba wierzchoĹ‚kĂłw
extern char ** A;               // Macierz sÄ…siedztwa
extern bool * visited;          // Tablica odwiedzin

void BFS(int);
void draw(int[40][20]);
void generateMap(int[40][20]);

#endif
