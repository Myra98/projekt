#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern int n;                   // Liczba wierzchoĹ‚kĂłw
extern char ** A;               // Macierz sÄ…siedztwa
extern bool * visited;          // Tablica odwiedzin
//int mapa[40][20] = {};;

void BFS(int);
void draw(int[40][20]);
void drawMap(char);
void generateMap(int[40][20]);

#endif