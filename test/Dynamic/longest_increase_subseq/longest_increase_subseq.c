#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define N 10
int L[N];
int previous[N];
int a[N];

void print_route(int pos, int step)
{
	if (pos == previous[pos]) {
		printf("%d ", a[pos]);
		return;
	}
	print_route(previous[pos], step+1);
	if (step == 0) 
		printf("%d\n", a[pos]);
	else 
		printf("%d ", a[pos]);

}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	// init the previous vector
	for (i = 0; i < n; ++i) {
		previous[i] = i;
	}

	// caculate the L vector
	for (i = 0; i < n; ++i) {
		L[i] = 1;
		for (j = 0; j < i; ++j) {
			// if j is the predecessor
			if (a[j] < a[i]) {
				if (L[j] + 1 > L[i]) {
					L[i] = L[j] + 1;
					previous[i] = j;
				}
			}
		}
	}
	int max_num = 0, max_pos;
	for (i = 0; i < n; ++i) {
		if (max_num < L[i]) {
			max_num = L[i];
			max_pos = i;
		}
	}
	printf("%d\n", max_num);
	print_route(max_pos, 0);

	return 0;
}

