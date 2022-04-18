#ifndef PIVOTER_H
#define PIVOTER_H

#include "graph.h"

double comb[200][200];

void comb_init(int n);
Graph *core_decomposition(Graph *g);
void S_init(int *S, int *S_p, int vertex_num);
void S_insert(int *S, int *S_p, int vertex);
void S_delete(int *S, int *S_p, int vertex);

void pivoter_dfs(int *S, int *S_p, int **S_nbr, double *C, int c_cnt, int p_cnt);
void pivoter(Graph *g, double *C);

#endif // PIVOTER_H