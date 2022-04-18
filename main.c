#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "pivoter.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: ./main <filename>\n");
		return 0;
	}
	freopen(argv[1], "r", stdin);
	//freopen("as-skitter.txt", "r", stdin);
	//freopen("result.txt", "w", stdout);

	fprintf(stderr, "Reading data......");

	int n, m;
	scanf("%d%d", &n, &m);

	Graph *g = init_graph(n, m << 1);
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		++u; ++v;
		add_edge_no_weight(g, u, v);
		add_edge_no_weight(g, v, u);
	}

	fprintf(stderr, "\rReading data......Done\n");

	fprintf(stderr, "Running PIVOTER......");

	double *C = (double *)calloc(n + 1, sizeof(double));

	pivoter(g, C);

	fprintf(stderr, "\rRunning PIVOTER......Done\nResult:\n");

	for (int i = 0; i <= n; ++i)
		if (C[i]) {
			printf("C(%d) = %.0lf\n", i, C[i]);
		}

	free_graph(g);
	free(C);

	return 0;
}