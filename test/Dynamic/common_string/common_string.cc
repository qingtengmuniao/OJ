#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

#define N 101

using namespace std;

char a_words[N][64];
char b_words[N][64];
int common_len[N][N]; 
int p[N][N]; 
stack<int> result; 

void print_strings(int direction[][N], int i, int j)
{
	if (i == 0 || j == 0) {
		return;
	}

	if (direction[i][j] == 0) {
		result.push(i);
		print_strings(direction, i-1, j-1);
	} else if (direction[i][j] == -1) {
		print_strings(direction, i-1, j);
	} else {
		print_strings(direction, i, j-1);
	}
}

int main()
{
	char temp[64];
	int i, len_a, len_b;
	for (i = 0; i < 101; ++i) {
		common_len[0][i] = 0;
		common_len[i][0] = 0;
	}
	while (1) {
		i = 1;
		while (scanf("%s", a_words[i]) != EOF && strcmp(a_words[i], "#")) {
			++i;
		}
		if (i == 1) break;
		len_a = i-1;

		i = 1;
		while (scanf("%s", b_words[i]) && strcmp(b_words[i], "#")) {
			++i;
		}
		len_b = i-1;

		int j;
		for (i = 1; i <= len_a; ++i) {
			for(j = 1; j <= len_b; ++j) {
				if (strcmp(a_words[i], b_words[j]) == 0) {
					common_len[i][j] = common_len[i-1][j-1] + 1;
					p[i][j] = 0;
				} else if (common_len[i-1][j] >= common_len[i][j-1]){
					common_len[i][j] = common_len[i-1][j];
					p[i][j] = -1;
				} else {
					common_len[i][j] = common_len[i][j-1];
					p[i][j] = 1;
				}
			}
		}

		//printf("%d\n", common_len[len_a][len_b]);
		print_strings(p, len_a, len_b);
		while (1) {
			if (result.empty()) {
				break;
			} else {
				printf("%s", a_words[result.top()]);
				result.pop();
				if (result.empty()) {
					printf("\n");
				} else {
					printf(" ");
				}
			}	
		}
	}

	return 0;
}
