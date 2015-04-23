#include <stdio.h>
#include <stdlib.h>

#define N 32

char parenthesis[2*N];
int P[N];
int W[N];

int main()
{
	int t, n;
	scanf("%d", &t);
	int i, j, k;
	for (i = 0; i < t; ++i) {
		scanf("%d", &n);
		for (j = 0; j < n; ++j) {
			scanf("%d", &P[j]);
		}

		// construct parenthesis
		int s = 0, e;
		for (j = 0; j < n; ++j) {
			e = P[j] + j;
			for (k = s; k < e; ++k) {
				parenthesis[k] = '(';
			}	
			parenthesis[e++] = ')';
			s = e;
		}
		parenthesis[e] = '\0';
		printf ("%s\n", parenthesis);

		for (j = 0; j < n; ++j) {
			e = P[j] + j; // ')' pos
			int count = 1;
			int total_count = 0;

			for (k = e-1; k >= 0; --k) {
				if (parenthesis[k] == ')') {
					count++;
				}
				else if (parenthesis[k] == '(') {
					total_count++;
					count--;	
					if (count == 0) {
						W[j] = total_count;	
						break;
					}
				}
			}
		}
		for (j = 0; j < n-1; ++j) {
			printf ("%d ", W[j]);	
		}
		printf ("%d\n", W[j]);	
	}
			
	return 0;
}
