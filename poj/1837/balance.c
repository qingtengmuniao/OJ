#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21
#define offset  (15 * 20 * 25)

int state[N][2*offset];
int arm[N];
int weight[N];

int main()
{
	int C, G;
	while (scanf("%d %d", &C, &G) == 2) {
		int i, j, k;
		for (i = 0; i < C; ++i)
			scanf("%d", &arm[i]);
		for (i = 0; i < G; ++i)
			scanf("%d", &weight[i]);

		memset(state, 0, sizeof(state));
		state[0][offset] = 1;

		for (i = 1; i <= G; ++i) {
			for (j = 0; j < C; ++j) {
				int pos = arm[j] * weight[i-1];
				for (k = 0; k < 2*offset; ++k) {
					if (state[i-1][k]) {
						state[i][k+pos] += state[i-1][k];
						//printf("state[%d][%d]=%d, pos=%d\n", i, k+pos, state[i][k+pos], pos);
					}	
				}
			}	
		}
		printf("%d\n", state[G][offset]);
	}

	return 0;
}
