1. 注意数字和字符和行列的对应关系不要弄反，关键点在于坐标原点要一致。例如都选在左下角，用表格形式可能很自然的会选在左上角，这样计算的坐标的时候却很容易选在左下角，容易造成混淆。
A2B2C2A1B1C1
坐标转换为字符的时候：
result[pos] = 'A' + x;
result[pos+1] = '1' + y;
判断是否越界的时候：
return (x >= 0 && x < q) && (y >= 0 && y < p) && (!chessboard[x][y]);

2. 由于要求字典序，所以step那八个点要有顺序，从左到右优先（A-B），然后是从下到上（1-2）
int step[8][2] = {
	-2, -1,
	-2, 1,
	-1, -2,
	-1, 2,
	1, -2,
	1, 2,
	2, -1,
	2, 1
};
	3. 回溯的精华在于，将这一步的行为抹掉，字符串自然就会被覆盖，所以剩下的工作就是讲访问数据置零。
void dfs(int x, int y, int n)
{
	if (flag) return;
	int pos = 2 * (n - 1);
	result[pos] = 'A' + x;
	result[pos+1] = '1' + y;
	chessboard[x][y] = 1;

	if (n == p*q) {
		result[pos+2] = '\0';
		printf("%s\n\n", result);
		flag = 1;
		return;
	}

	int i;
	for (i = 0; i < 8; ++i) {
		int new_x = x+step[i][0];
		int new_y = y+step[i][1];

		if (can_move(new_x, new_y)) {
			dfs(new_x, new_y, n+1);
		}
	}

	chessboard[x][y] = 0;
}
4. 深度搜索在于，没有用队列，闷着头往下走啊，能走就走，一直到==p*q的情况。


还有一个疑点，就是看讨论说从A1走就行了，但是这充分必要条件是，只要有路径就一定是闭合路径。这点我没能证明。如果不成立的话，就需要像我这样写：
for (j = 0; j < q; ++j) {
	for (k = 0; k < p; ++k) {
		if (flag) break;
		dfs(k, j, 1);
	}
	if (flag) break;
}



