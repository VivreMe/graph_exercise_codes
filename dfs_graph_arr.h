#include <stdio.h>
#include "preprocess_constants.h"

/*--------�����迭 ���� �Լ� ��Ʈ(����)--------*/

//�����迭�� ����ü ����
typedef struct GraphType {
	int n;		//������ ����
	int adj_mtrx[MAX_VERTICES][MAX_VERTICES];
} GraphType;

//�׷��� �ʱ�ȭ
void init(GraphType *g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mtrx[r][c] = 0;
}

//���� ���� ����
void insert_vertex(GraphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "�׷��� ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

//���� ���� ����
void insert_edge(GraphType *g, int start, int end) {
	if (start >= (g->n) || end >= (g->n)) {
		fprintf(stderr, "�׷��� ���� �ε��� ���� ����");
		return;
	}
	g->adj_mtrx[start][end] = 1;
	g->adj_mtrx[end][start] = 1;
}

//���� ��ķ� ǥ���� �׷����� ���� DFS
void dfs_mtrx(GraphType *g, int v, int *visited_) {
	//printf("dfs_mtrx(g, %d) start!\n", v);
	int w;		//for�� �ݺ��� ����
	visited_[v] = TRUE;	//���� v�� �湮 ǥ��

	printf("���� %d -> ", v + 1);
	for (w = 0; w < (g->n); w++) {
		if (g->adj_mtrx[v][w] && !visited_[w])
			dfs_mtrx(g, w, visited_);		//���� w���� DFS ���� ����
	}
}

/*--------�����迭 ���� �Լ� ��Ʈ(����)--------*/