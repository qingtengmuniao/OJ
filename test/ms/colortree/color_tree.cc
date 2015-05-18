#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int t, n, count;

	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d:\n", i);
		scanf("%d", &n);
		vector<vector<int> > edges(n+1);
		vector<int> colors(n+1);

		for (int j = 0; j < n-1; ++j) {
			int x, y;
			scanf("%d %d", &x, &y);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}

		int q, branches = 1;
		scanf("%d", &q);
		for (int j = 0; j < q; ++j){
			int op;
			scanf("%d", &op);
			if (op == 1) {
				printf("%d\n", branches);
			} else if (op == 2) {
				int point, color;	
				scanf("%d %d", &point, &color);
				int old_color = colors[point];
				if (color == old_color) {
					continue;
				}
				colors[point] = color;
				for (int k = 0; k < edges[point].size(); ++k) {
					if (colors[edges[point][k]] == old_color) {
						branches++;
					}	
				}
			}
		}
	}
	return 0;
}
