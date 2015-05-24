#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 1024
#define MAX 100000
#define M 64

using namespace std;

int ip[N][4];
int netmask[M][4];
bool hash_vector[MAX];

int get_hash_code(int a[])
{
	int i;
	int temp = 0;
	for (i = 0; i < 4; ++i) {
		temp += ((a[i] << (8*i)) % MAX);
	}
	return temp % (MAX);
}

int main()
{
	int t, tt;
	scanf("%d", &t);
	tt = t;
	while (t--) {
		int n, m;
		int i, j, k;
		scanf("%d %d", &n, &m);
		
		for (i = 0; i < n; ++i) {
			scanf("%d.%d.%d.%d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
		}

		for (i = 0; i < m; ++i) {
			scanf("%d.%d.%d.%d", &netmask[i][0], &netmask[i][1], &netmask[i][2], &netmask[i][3]);
		}

		int temp[4];
		printf("Case #%d:\n", tt-t);
		for (i = 0; i < m; ++i) {
			memset(hash_vector, 0, sizeof(hash_vector));
			int count = 0;
			for (j = 0; j < n; ++j) {

				for (k = 0; k < 4; ++k) {
					temp[k] = netmask[i][k] & ip[j][k];
				}

				int loc = get_hash_code(temp);
				if (!hash_vector[loc]) {
					count++;
					hash_vector[loc] = true;
				}
			}
			printf("%d\n", count);
		}
	}

	return 0;
}
