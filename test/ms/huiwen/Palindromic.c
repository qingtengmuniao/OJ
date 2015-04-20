#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1005
#define FAC 100007

char str[N];
int E[N][N];

void solve(char *s)
{
	int n = strlen(s);
	int i, j, k;
	memset(E, 0, sizeof(E));
	for (i = 0; i < n; ++i) E[i][i] = 1; 
	for (i = 1; i < n; ++i) {
		// i-1 ... 0 
		for (j = i-1; j >= 0; --j) {
			if (s[j] == s[i]) {
				E[j][i] = (E[j+1][i] + E[j][i-1] + 1) % FAC;  
			} else {
				E[j][i] = (E[j+1][i] + E[j][i-1] - E[j+1][i-1]) % FAC;  
			}
		}
	}

	printf("%d\n", E[0][n-1]);
}

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; ++i) {
		scanf("%s", str);
		printf("Case #%d: ", i+1);
		solve(str);
	}
}
