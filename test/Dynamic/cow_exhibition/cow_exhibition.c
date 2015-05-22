#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 200001
#define N 101
#define BIAS 100000
#define max(a, b) ((a) > (b) ? (a) : (b))

int smartness[N];
int funness[N];

int dp[M+1];

int main()
{
	int n;
	scanf("%d", &n);
	int i, j, end = BIAS;
	for (i = 0; i < n; ++i) {
		scanf("%d %d", &smartness[i], &funness[i]);
		if (smartness[i] > 0) end += smartness[i];
	}
	
	for (j = 0; j < M; ++j) {
		dp[j] = -M;
	}

	dp[BIAS] = 0;
	for (i = 0; i < n; ++i) {
		if (smartness[i] < 0) {
			for (j = 0; j <= end; ++j) {
				dp[j] = max(dp[j], dp[j-smartness[i]]+funness[i]);
			}
		} else {
			for (j = end; j >= smartness[i]; --j) {
				dp[j] = max(dp[j], dp[j-smartness[i]]+funness[i]);
			}
		}
	}

	int max_sum = 0;
	for (j = BIAS; j <= end; ++j) {
		printf("%d ", dp[j]);
		if (dp[j] >= 0) {
			max_sum = max(max_sum, j-BIAS+dp[j]);	
		}
	}
	printf("%d\n", max_sum);

	return 0;
}
