#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define N 100000

int visited[N+1];
typedef struct move{
	int n;
	int step;
} Move;
int find = 0;
queue<Move *> q;

Move *new_move(int n, int step)
{
	Move *temp = (Move *)malloc(sizeof(Move));
	temp->n = n;
	temp->step = step;
	return temp;
}

void bfs(int n, int k)
{
	Move *temp = new_move(n, 0);
	q.push(temp);
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		n = temp->n;
		if (n == k) {
			printf("%d\n", temp->step);
			return;
		}
		for (int i = 0; i < 3; ++i) {
			int next;
			switch(i) {
				case 0:
					next = n * 2;
					break;
				case 1:
					next = n + 1;
					break;
				case 2:
					next = n - 1;
			}
			if (next < 0 || next > N -1) continue;
			if (visited[next]) continue;
			
			q.push(new_move(next, temp->step+1));
			visited[next] = 1;
		}
		free(temp);
	}
}

void release_space()
{
	while (!q.empty()){
		free(q.front());
		q.pop();
	}
}

int main()
{
	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		memset(visited, 0, sizeof(visited));
		bfs(n, k);
		release_space();
	}
}
