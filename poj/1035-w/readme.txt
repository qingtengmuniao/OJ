1. 重新练了一遍edit distance这个动态规划。
	for i = 0, 1, 2, . . . ,m:
		E(i, 0) = i
	for j = 1, 2, . . . , n:
		E(0, j) = j
	for i = 1; 2; : : : ;m:
		for j = 1; 2; : : : ; n:
			E(i, j) = min{E(i-1, j) + 1, E(i, j-1) + 1, E(i - 1, j - 1) + diff(i, j)}
	return E(m, n)

	注意点有三：
	1) 初始化的时候，不是初始化两条边界不是初始化为0；
	2) 递归的时候，注意去对应delete, insert, repalce这三种情况，其中diff(i, j)可以表述为
	word1[i]!= word2[j] 而非 word1[i]== word2[j] 3) 这里的word1[i],word2[j]都是从1开始存储的。
2. 先是暴力，然后各种优化。优化点有三：
	1) 将字典中的每个单词长度存在该字符串最后，反正其最大长度才有15，用char存足矣。因为其大量被使用，所以优化比较多。
	2) 每次比对两个单词（待检测单词和字典中单词），不直接计算edit_dis，而是先看其len的差距范围。
	3) 计算edit_dis的时候，加上这句判断if (i == j && dis[i][j] > 2) return dis[i][j];以便在不匹配早期就返回。

起初都是超时，加上第三点后就AC了。

