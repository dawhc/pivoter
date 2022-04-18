#ifndef GRAPH_H
#define GRAPH_H

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
	int src, dst, w, nxt;
} Edge; 

typedef struct {
	int e_num, v_num;
	int e_cnt;
	int *first;
	Edge *e;

	int *in_deg, *out_deg;
	int max_in_deg, max_out_deg;
} Graph;


void clear_graph(Graph *g);

Graph *init_graph(int vertex_num, int edge_num);

void free_graph(Graph *g);

void add_edge(Graph *g, int src, int dst, int w);

void add_edge_no_weight(Graph *g, int src, int dst);

#endif // GRAPH_H