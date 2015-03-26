#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 1000

unsigned char state[N+1];
typedef struct Point{
	int x;
	int y;
} Point;
Point islands[N+1];

typedef struct Segment{
	double x1;
	double x2;
} Segment;
Segment cross_points[N+1];

void swap(Segment v[], int i, int j)
{
	Segment temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort1(Segment v[], int left, int right) 
{
	int i, last;

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; ++i)
		if (v[i].x1 < v[left].x1)
			swap(v, ++last, i);
	swap(v, left, last);

	qsort1(v, left, last-1);
	qsort1(v, last+1, right);
}


int main()
{
	int n, d, case_count = 0;		

	while (scanf("%d %d", &n, &d) == 2) {

		if (n == 0 && d == 0) return 0;
		++case_count;

		int i = 0;
		// read all the data
		for (i = 0; i < n; ++i){
			scanf("%d %d", &islands[i].x, &islands[i].y);
		}

		// if d is valid
		if (d <= 0) {
			printf("Case %d: -1\n", case_count);
			continue;
		}

		// calculate the cross_points
		int flag = 0;
		for (i = 0; i < n; ++i) {
			double dis2 = d*d - islands[i].y * islands[i].y; 
			if (dis2 < 0) {
				flag = 1;
				break;
			}
			double dis = sqrt(dis2);
			cross_points[i].x1 = islands[i].x - dis;
			cross_points[i].x2 = islands[i].x + dis;
		}
		if (flag) {
			printf("Case %d: -1\n", case_count);
			continue;
		}
		qsort1(cross_points, 0, n-1);

		int radar_count = 0;
		// warning!!! not memset(state, sizeof(state), 0);
		memset(state, 0, sizeof(state));
		int now_island = 0;
		state[now_island] = 1;
		double now_end = cross_points[now_island].x2; 
		while (1){
			++radar_count;
			// label the covered island 
			for (i = 0; i < n; ++i) {
				// will affect the result if not pass 
				if (state[i]) 
					continue;
				if (cross_points[i].x1 < now_end || fabs(cross_points[i].x1 - now_end) < 0.0001){	
					state[i] = 1;
					// forget this for the first time
					now_end = now_end > cross_points[i].x2 ? cross_points[i].x2 : now_end;
				}
			}
			// select next island  
			int over = 1;
			for (i = now_island+1; i < n; ++i){
				if (!state[i]) {
					now_island = i;
					state[now_island] = 1;
					now_end = cross_points[now_island].x2; 
					over = 0;
					break;
				}
			}
			if (over) {
				printf("Case %d: %d\n", case_count, radar_count);
				break;
			}
		}
	}
}
