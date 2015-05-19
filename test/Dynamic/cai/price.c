#include <stdio.h>
#include <string.h>

#define N 10001
#define max(a, b) ((a) > (b) ? (a) : (b))

int balance[N];
int price[N];

void swap(int v[], int a, int b)
{
	int temp = v[a];
	v[a] = v[b];
	v[b] = temp;
}
void mysort(int v[], int left, int right)
{
	int i, last;

	if (left >= right) return;

	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i <= right; ++i) {
		if (v[i] < v[left])
			swap(v, ++last, i);
	}
	swap(v, last, left);

	mysort(v, left, last-1);
	mysort(v, last+1, right);
}

int solve(int n, int m)
{
	int i, j;
	for (i = 0; i < n-1; ++i) {
		for (j = m-5; j >= price[i]; --j) {
			balance[j] = max(balance[j], balance[j-price[i]]+price[i]);
		}
	}
	return balance[m-5];
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int i, m;
		for (i = 0; i < n; ++i){
			scanf("%d", &price[i]);
		}	
		scanf("%d", &m);

		if (m < 5) {
			printf("%d\n", m);
			continue;
		}
		mysort(price, 0, n-1);
		memset(balance, 0, N);
		int left = m - solve(n, m);
		printf("%d\n", left-price[n-1]);
	}

	return 0;
}
