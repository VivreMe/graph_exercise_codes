#include <stdio.h>
#include <stdlib.h>

#include "arr_OR_ajd_list__OnOff_switch.h"

#if (SWTCH == ON)
	#include "dfs_graph_arr.h"
#elif	(SWTCH == OFF)
	#include "dfs_graph_adj_list.h"
#endif

int visited[MAX_VERTICES];

int main(void) {
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);

	int num_of_vertices;		//���� ����
	int num_of_edges;			//���� ����
	int where_start_vtx_num;	//Ž�� ������ ���� ��ȣ

	//���� ����, ���� ����, Ž�� ������ ���� ��ȣ
	scanf("%d %d %d", 
		&num_of_vertices, &num_of_edges, &where_start_vtx_num);

	for (int i = 0; i < num_of_vertices; i++)
		insert_vertex(g, i);

	//���� ������ŭ, ���� �Է� �ݺ�
	for (int i = 0; i < num_of_edges; i++) {
		int v1, v2;		//�� ���� ��
		scanf("%d %d", &v1, &v2);
		insert_edge(g, v1 - 1, v2 - 1);
	}

	printf("���� �켱 Ž��\n");
	dfs_adj_list(g, where_start_vtx_num - 1, visited);
	printf("\n");
	free(g);
	return 0;
}