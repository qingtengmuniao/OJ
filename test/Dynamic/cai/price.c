#include <stdio.h>

#define N 10001

int balance[N];
int price[N];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int i, b;
		for (i = 0; i < n; ++i){
			scanf("%d", &price[i]);
		}	
		scanf("%d", &b);
	}
}
