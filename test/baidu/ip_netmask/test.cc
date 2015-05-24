#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 1024
#define M 64

using namespace std;

int ip[N][4];
int netmask[M][4];
int address[M];

int get_loc(int temp[], int loc) 
{
	int i, total = 0;
	for (i = 0; i < 4; ++i) {
		total += (temp[i] << (8*i));
	}

	for (i = 0; i < loc; ++i) {
		if (address[i] - total == 0) {
			return i;
		}
	}

	for (i = 0; i < 4; ++i) {
		address[loc] = total;
	}
	return loc+1;
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
			int loc = 0;
			address[0] = -1;
			for (j = 0; j < n; ++j) {
				for (k = 0; k < 4; ++k) {
					temp[k] = netmask[i][k] & ip[j][k];
				}

				if (get_loc(temp, loc) > loc) {
					loc++;
				}
			}
			printf("%d\n", loc);
		}
	}

	return 0;
}
