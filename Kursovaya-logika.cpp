#include<iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int** createG(int size) {
	int** G = NULL;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d", G[i][j]);
		}
		printf("\n");
	}
}

void DFS(int** G, int size, int* vis, int s) {
	queue <int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		s = q.front();
		printf("%d ", s + 1);
		q.pop();
		for (int i = 0; i < size; i++) {
			if (G[s][i] == 1 && vis[i] == 0) {
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int** G = NULL;
	int* vis = NULL;
	int size = 5;
	int s = 1;
	printf("Введите колл-во вершин: ");
	scanf_s("%d", &size);
	G = createG(size);
	printG(G, size);
	printf("Введите начальную вершину: ");

	vis = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		vis[i] = 0;
	}

	scanf_s("%d", &s);
	s--;
	printf("Обход графа в ширину: \n");
	DFS(G, size, vis, s);
	scanf_s("%d", s);

	return 0;
}