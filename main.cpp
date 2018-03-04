#include <iostream>
#include <iomanip>
#include <stdlib.h> //Necessary to use rand
#include <ctime>

using namespace std;

// Typ elementów listy dla kolejki

struct slistEl
{
    slistEl * next;
    int data;
};

int segment_A[5][5] = { { 1, 1, 0, 1, 1 }, { 1, 0, 0, 1, 1 }, { 0, 0, 1, 0, 0 }, { 1, 0, 0, 0, 1 }, { 1, 1, 0, 1, 1 } };
int segment_B[5][5] = { { 1, 1, 0, 0, 1 }, { 0, 1, 1, 0, 1 }, { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 1 }, { 1, 1, 0, 0, 1 } };
int segment_C[5][5] = { { 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 1, 0 }, { 1, 0, 1, 1, 1 }, { 1, 0, 0, 0, 0 } };
int segment_D[5][5] = { { 1, 1, 0, 0, 0 }, { 1, 0, 0, 1, 0 }, { 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 1 }, { 1, 0, 0, 1, 1 } };
int segment_E[5][5] = { { 0, 0, 0, 1, 1 }, { 1, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0 }, { 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 1 } };
int segment_F[5][5] = { { 1, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1 }, { 0, 0, 0, 0, 0 }, { 1, 1, 0, 1, 1 }, { 1, 1, 0, 1, 1 } };

/* Prototypy funkcji */
void draw(int[40][20]);
void drawMap(char);
void generateMap(int[40][20]);

void BFS(int);

// Zmienne globalne

int n;                   // Liczba wierzchołków
char ** A;               // Macierz sąsiedztwa
bool * visited;          // Tablica odwiedzin

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
    srand(time(NULL)); //To randomize rand
    int m, i, j, v1, v2;
    /*
    drawSegment('A');
    drawSegment('B');
    drawSegment('C');
    drawSegment('D');
    drawSegment('E');
    drawSegment('F');
    */
    int mapa[40][20] = {};
    generateMap(mapa);
    draw(mapa);

    system("PAUSE");
    int n = 25;                    // Liczba wszystkich kwadratów                   
    int lw = 11;                   // Liczba białych pól
    A = new char *[n];    // Tworzymy tablicę wskaźników
    visited = new bool[n]; // Tworzymy tablicę odwiedzin

    for (i = 0; i < n; i++)
        A[i] = new char[n];  // Tworzymy wiersze

    // Macierz wypełniamy zerami

    for (i = 0; i < n; i++)
    {
        visited[i] = true;  // Wypełniamy tablicę odwiedzin
        for (j = 0; j < n; j++) A[i][j] = 0;
    }

    // Odczytujemy kolejne definicje krawędzi
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


/* Funkcje */
void BFS(int v)
{
    int i;
    slistEl *q, *head, *tail; // Kolejka

    q = new slistEl;        // W kolejce umieszczamy v
    q->next = NULL;
    q->data = v;
    head = tail = q;

    visited[v] = true;      // Wierzchołek v oznaczamy jako odwiedzony

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
            q = new slistEl; // W kolejce umieszczamy nieodwiedzonych sąsiadów
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
            if (seg[i][j] == 1)
                cout << char(219);
            else cout << " ";
        }
        cout << std::endl;
    }
}
/*
void drawSegment(char S){
    switch (S)
    {
        case 'A': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_A);
        break;
        case 'B': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_B);
        break;
        case 'C': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_C);
        break;
        case 'D': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_D);
        break;
        case 'E': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_E);
        break;
        case 'F': std::cout<<"Drawing segment "<<S<<std::endl;
        draw(segment_F);
        break;
        default: std::cout<<"Unknown char";
    }
}
*/
void generateMap(int mapa[40][20])
{
    int segment[5][5];
    int w = 0, k = 0;

    //Generuj map� segment�w
    printf("____________________________UPROSZCZONA MAPA____________________________\n");
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

    //Rozwi� map� segment�w
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

    //Generuj du�� map� z mapy segment�w
    printf("____________________________DU�A MAPA____________________________\n");
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
}

