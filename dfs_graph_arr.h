#include <stdio.h>
#include "preprocess_constants.h"

/*--------인접배열 구현 함수 파트(시작)--------*/

//인접배열용 구조체 선언
typedef struct GraphType {
	int n;		//정점의 개수
	int adj_mtrx[MAX_VERTICES][MAX_VERTICES];
} GraphType;

//그래프 초기화
void init(GraphType *g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mtrx[r][c] = 0;
}

//정점 삽입 연산
void insert_vertex(GraphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType *g, int start, int end) {
	if (start >= (g->n) || end >= (g->n)) {
		fprintf(stderr, "그래프 정점 인덱스 범위 오류");
		return;
	}
	g->adj_mtrx[start][end] = 1;
	g->adj_mtrx[end][start] = 1;
}

//인접 행렬로 표현된 그래프에 대한 DFS
void dfs_mtrx(GraphType *g, int v, int *visited_) {
	//printf("dfs_mtrx(g, %d) start!\n", v);
	int w;		//for문 반복용 변수
	visited_[v] = TRUE;	//정점 v의 방문 표시

	printf("정점 %d -> ", v + 1);
	for (w = 0; w < (g->n); w++) {
		if (g->adj_mtrx[v][w] && !visited_[w])
			dfs_mtrx(g, w, visited_);		//정점 w에서 DFS 새로 시작
	}
}

/*--------인접배열 구현 함수 파트(종료)--------*/