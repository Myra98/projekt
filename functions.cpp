#include <iostream>
#include <iomanip>
#include <stdlib.h> //Necessary to use rand
#include <ctime>
#include "functions.h"

using namespace std;

int segment_A[5][5] = { { 1, 1, 0, 1, 1 }, { 1, 0, 0, 1, 1 }, { 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 1 }, { 1, 1, 0, 1, 1 } };
int segment_B[5][5] = { { 1, 1, 0, 0, 1 }, { 0, 1, 1, 0, 1 }, { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 1 }, { 1, 1, 0, 0, 1 } };
int segment_C[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 1, 0, 1, 1, 1 }, { 1, 0, 0, 0, 0 } };
int segment_D[5][5] = { { 1, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 1 }, { 1, 0, 0, 1, 1 } };
int segment_E[5][5] = { { 0, 0, 0, 1, 1 }, { 1, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1 } };
int segment_F[5][5] = { { 1, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1 } };

struct slistEl
{
    slistEl * next;
    int data;
};

void BFS(int v)
{
    int i;
    slistEl *q, *head, *tail; // Kolejka

    q = new slistEl;        // W kolejce umieszczamy v
    q->next = NULL;
    q->data = v;
    head = tail = q;

    visited[v] = true;      // WierzchoÅ‚ek v oznaczamy jako odwiedzony

    while (head)
    {
        v = head->data;       // Odczytujemy v z kolejki

        q = head;             // Usuwamy z kolejki odczytane v
        head = head->next;
        if (!head) tail = NULL;
        delete q;
        cout << setw(3) << v;
        for (i = 0; i < n; i++)
        if ((A[v][i] == 1) && !visited[i])
        {
            q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sÄ…siadÃ³w
            q->next = NULL;
            q->data = i;
            if (!tail) head = q;
            else tail->next = q;
            tail = q;
            visited[i] = true; // i oznaczamy ich jako odwiedzonych
        }
    }
}

void draw(int seg[40][20]){
    for (int i = 0; i<40; i++)
    {
        for (int j = 0; j<20; j++)
        {
        	switch(seg[i][j])
        	{
        		case 1: cout<<char(219);
        				break;
        		case 2: cout<<"A";
        				break;
        		case 3: cout<<"B";
        				break;
        		default: cout<<" ";
        	}
        }
        cout << std::endl;
    }
}

void generateMap(int mapa[40][20])
{
    int segment[5][5];
    int w = 0, k = 0;

    //Generuj mape segmentow
    char mapa_segmenty[8][4];
    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<4; j++)
        {
            mapa_segmenty[i][j] = char(rand() % 6 + 65);
            cout << mapa_segmenty[i][j];
        }
        cout << std::endl;
    }

    //Rozwiñ mape segmentow
    char mapa_segmenty_extended[40][4];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            mapa_segmenty_extended[(5 * i)][j] = mapa_segmenty[i][j];
            mapa_segmenty_extended[(5 * i)+1][j] = mapa_segmenty[i][j];
            mapa_segmenty_extended[(5 * i)+2][j] = mapa_segmenty[i][j];
            mapa_segmenty_extended[(5 * i)+3][j] = mapa_segmenty[i][j];
            mapa_segmenty_extended[(5 * i)+4][j] = mapa_segmenty[i][j];
        }
    }

    //Generuj duza mape
    for (int i = 0; i<40; i++)
    {
        for (int j = 0; j<4; j++)
        {
            switch (mapa_segmenty_extended[i][j]) //Ustalanie segmentu
            {
            case 'A':
                mapa[i][(5 * j)] = segment_A[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_A[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_A[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_A[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_A[i % 5][4];
                break;
            case 'B':
                mapa[i][(5 * j)] = segment_B[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_B[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_B[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_B[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_B[i % 5][4];
                break;
            case 'C':
                mapa[i][(5 * j)] = segment_C[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_C[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_C[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_C[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_C[i % 5][4];
                break;
            case 'D':
                mapa[i][(5 * j)] = segment_D[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_D[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_D[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_D[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_D[i % 5][4];
                break;
            case 'E':
                mapa[i][(5 * j)] = segment_E[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_E[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_E[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_E[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_E[i % 5][4];
                break;
            case 'F':
                mapa[i][(5 * j)] = segment_F[i % 5][0];
                mapa[i][(5 * j) + 1] = segment_F[i % 5][1];
                mapa[i][(5 * j) + 2] = segment_F[i % 5][2];
                mapa[i][(5 * j) + 3] = segment_F[i % 5][3];
                mapa[i][(5 * j) + 4] = segment_F[i % 5][4];
                break;
            default: cout << "ERROR";
                exit(1);
            }
        }
    }
    
    //Wylosuj punkt startowy i koñcowy
    int a=(rand() % 20), b=(rand() % 40), c=(rand() % 40),d=(rand() % 20);
	while (mapa[a][b]!=0)
	{
		a=(rand() % 40);
		b=(rand() % 20);
	}
	
	mapa[a][b] = 2;

	while (mapa[c][d]!=0)
	{
		c=(rand() % 40);
		d=(rand() % 20);
	}

	mapa[c][d] = 3;
	
	cout << endl << "Wylosowane punkty: " << endl << "A=" << a << ":" << b << endl << "B=" << c << ":" << d << endl << endl;
	
}
