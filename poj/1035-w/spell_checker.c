#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10002
#define min(a, b) ((a) > (b) ? (b) : (a))

int out_loc[N]; // store every position of the similar words
char dic_words[N][20];
char check_words[N][16];
int dis[16][16];

int get_edit_dis(const char* a, const char* b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	int i, j;

	for (i = 0; i < 16; ++i) {
		dis[i][0] = i;
		dis[0][i] = i;
	}	

	for (i = 1; i <= len_a; ++i) {
		for (j = 1; j <= len_b; ++j) {
			int del = dis[i-1][j] + 1;
			int insert = dis[i][j-1] + 1;
			int change = dis[i-1][j-1] + (a[i-1] != b[j-1]);
			dis[i][j] = min(min(del, insert), change);
			if (i == j && dis[i][j] > 2) return dis[i][j];
		}
	}

	//printf(" %s and %s == %d\n", a, b, dis[len_a][len_b]);

	return dis[len_a][len_b];
}

int main()
{
	int i = 0;
	while (scanf("%s", dic_words[i]) != EOF && strcmp(dic_words[i], "#")) {
		int len = strlen(dic_words[i]);
		dic_words[i][19] = len;
		++i;	
	}

	int count = i;
	i = 0;
	while (scanf("%s", check_words[i]) != EOF && strcmp(check_words[i], "#")) {
		int j = 0, pos = 0; 
		int len_a = strlen(check_words[i]);
		for (j = 0; j < count; ++j) {
			int len_b = dic_words[j][19];
			if (abs(len_a - len_b) > 1) continue;

			int dis = get_edit_dis(check_words[i], dic_words[j]);
			if (dis == 0) {
				printf("%s is correct\n", check_words[i]);
				break;
			} else if (dis == 1) {
				out_loc[pos++] = j;
			} 
		}
		out_loc[pos] = -1;

		if (j == count) {
			printf("%s:", check_words[i]);	
			j = 0;
			while(out_loc[j] != -1) {
				printf(" %s", dic_words[out_loc[j]]);
				++j;
			}
			printf("\n");
		}
		++i;
	}

	return 0;
}
