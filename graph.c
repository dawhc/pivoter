#include <string.h>
#include <stdlib.h>

#include "graph.h"


void clear_graph(Graph *g) {
	g->e_cnt = g->max_in_deg = g->max_out_deg = 0;
	memset(g->first, -1, sizeof(int) * (g->v_num + 1));
	memset(g->in_deg, 0, sizeof(int) * (g->v_num + 1));
	memset(g->out_deg, 0, sizeof(int) * (g->v_num + 1));
}

Graph *init_graph(int vertex_num, int edge_num) {
	Graph *g = (Graph *)malloc(sizeof(Graph));
	g->e_num = edge_num;
	g->v_num = vertex_num;
	g->first = (int *)malloc(sizeof(int) * (vertex_num + 1));
	g->e = (Edge *)malloc(sizeof(Edge) * (edge_num + 10));
	g->in_deg = (int *)malloc(sizeof(int) * (vertex_num + 1));
	g->out_deg = (int *)malloc(sizeof(int) * (vertex_num + 1));
	clear_graph(g);
	return g;
}

void free_graph(Graph *g) {
	free(g->first);
	free(g->e);
	free(g->in_deg);
	free(g->out_deg);
	free(g);
}

void add_edge(Graph *g, int src, int dst, int w) {
	g->e[++g->e_cnt] = (Edge) {src, dst, w, g->first[src]};
	g->first[src] = g->e_cnt;	
	g->in_deg[dst]++;
	g->out_deg[src]++;
	g->max_in_deg = max(g->in_deg[dst], g->max_in_deg);
	g->max_out_deg = max(g->out_deg[src], g->max_out_deg);
}

void add_edge_no_weight(Graph *g, int src, int dst) {
	add_edge(g, src, dst, 0);
}