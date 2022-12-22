#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <queue>
using namespace std;

queue<int>q;
void BFS(int s, int n, int* vis, int** G) {
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        printf("%d ", s);
        for (int i = 0; i < n; i++)
        {
            if (G[s][i] == 1 && vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, i = 0;
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    printf("Введите количество вершин для матрицы: ");
    scanf_s("%d", &n);
    int** G = new int* [n];
    int* vis = new int[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = new int[n];
        vis[i] = 0;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                G[i][j] = 0;
            }
            else if (i != j)
            {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }

    printf("Матрица смежности:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }

    printf("Введите номер стартовой вершины: ");
    scanf_s("%d", &m);
    BFS(m, n, &vis[0], &(&G)[0][0]);

}