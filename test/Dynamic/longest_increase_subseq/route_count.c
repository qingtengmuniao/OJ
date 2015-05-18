#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 10
int L[N];
int a[N];

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	// caculate the L vector
	for (i = 0; i < n; ++i) {
		L[i] = 1;
		for (j = 0; j < i; ++j) {
			// if j is the predecessor
			if (a[j] < a[i]) {
				if (L[j] + 1 > L[i]) {
					L[i] = L[j] + 1;
				}
			}
		}
	}
	int max_num = 0, max_pos;
	for (i = 0; i < n; ++i) {
		if (max_num < L[i]) {
			max_num = L[i];
		}
	}
	printf("%d\n", max_num);

	return 0;
}

