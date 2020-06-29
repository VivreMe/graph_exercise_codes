#include <stdio.h>
#include "preprocess_constants.h"

/*--------인접연결리스트 구현 함수 파트(시작)--------*/

typedef struct GraphNode {
	int vtx;				//vertex
	struct GraphNode *link;	//refer next node
} GraphNode;

typedef struct GraphType {
	int n;			//the number of vertices
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

//그래프 초기화
void init(GraphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType *g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType *g, int u, int v) {
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프 정점 인덱스 범위 오류");
		return;
	}
	GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vtx = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	GraphNode *node_ = (GraphNode *)malloc(sizeof(GraphNode));
	node_->vtx = u;
	node_->link = g->adj_list[v];
	g->adj_list[v] = node_;
}

void print_adj_list(GraphType *g) {
	for (int i = 0; i < (g->n); i++) {
		GraphNode *p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d ", p->vtx);
			p = p->link;
		}
		printf("\n");
	}
}


void dfs_adj_list(GraphType *g, int v, int *visited) {
	GraphNode *w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v + 1);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vtx])
			dfs_adj_list(g, w->vtx, visited);
}

/*--------인접연결리스트 구현 함수 파트(종료)--------*/