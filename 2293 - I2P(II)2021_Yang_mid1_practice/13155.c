#include <stdio.h>
#include "13155.h"

int main() {
	int n; 
	while(scanf("%d", &n) != EOF) {
		struct Graph *g = createGraph(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; scanf("%d %d", &u, &v);
			addEdge(g, u, v);
		}
		int q; scanf("%d", &q);
		while (q--) {
			int a, b; scanf("%d %d", &a, &b);
			printf("%d %d\n", findMax(g, a, b), findMax(g, b, a));
		}
		freeGraph(g);
	}
	return 0;
}
