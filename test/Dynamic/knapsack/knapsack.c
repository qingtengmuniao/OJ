#include <stdio.h>
#include <stdlib.h>

#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))
int weight[N];
int value[N];

int main()
{
	int i, n, W;
	scanf("%d", &n);
	scanf("%d", &W);
	for (i = 0; i < n; ++i) {
		scanf("%d", &weight[i]);
	}
	for (i = 0; i < n; ++i) {
		scanf("%d", &value[i]);
	}

	int K[N];
	K[0] = 0;
	int w = 1;
	for (w = 1; w <= W; ++w) {
		int max_val = 0;
		for (i = 0; i < n; ++i) {
			if (weight[i] <= w) {
				int temp_val = K[w-weight[i]] + value[i];
				max_val = max(max_val, temp_val);
			}
		}	
		K[w] = max_val;
	}

	printf("%d\n", K[W]);
	return 0;
}
