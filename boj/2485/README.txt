解这个题我用了Kruskal算法，正好是选最大边。
在对边进行初始化时候，最后不用讲edge_pos--，因为正好最后它代表了edge的个数，而不是最后一个边的下标。
手写qsort的时候犯了一个严重错误，就是记住最左边的下标是left不是0，所以初始的时候last=left
判断两个点是否在一个连通分支里：首先读入的时候可以保证所有的边是从i->j(i<j)，然后利用一个向量previous[]，记下每一个节点的前驱节点。然后利用该数组可以找到每个指定点的root，如果root(A) == root(B)，那么A,B属于同一连通分支。一个优化的点就是如果pos(A)<pos(B)，那么B在向前回溯找根时候，如果发现A，说明A是B的祖先，则直接就可以判定A，B在同一连通分支。
// judge if point i and j in one connected component
int in_one_component(int x, int y)
{
	int root_x, root_y;

	while (y != -1) {
		root_y = y;
		y = previous[y];     
		if (y == x) return 1; // x is the precedence of the y (x < y)
	}

	while (x != -1) {
		root_x = x;
		x = previous[x];     
	}
	return root_x == root_y;
}
咳咳，对于上面的更正。原来这是一种早有耳闻的叫做并查集的思想，利用树形数据结构，来表示互不相交的一些集合。用树根唯一标识这个并查集，两个并查集的合并即将一个树根只向另一个树根（一般是小树）指向大树，这样形成一个棵大树。而上面我的代码的错误根源在于合并的时候，直接将在不在一个集合的边uv，直接令father[u]=v，而不是father[find_set(u)] = find_set(v).
find_set(v) {
	if (v != father[v]) {
		father[v] = find_set(father[v]);
	}
	return father[v];
}
这里涉及到一个小优化，如果v不是树根，那么在找树根（该集合的标识）的过程中，顺手将该点v向上回溯找树根的路径经过的所有点，顺手直接指向树根，如此一来大大缩小了树的深度，从而大大便利了以后找树根的递归深度。

初始化是令father[i]=i，这也容易理解，就是表明开始是有N（节点数）个互不相交的集合，随着不断填边而逐渐联通集合，这就是不断Union的过程。
Union(x, y) {
	if(x == y) return;
	father[x] = y;
}
这也应该有个优化，就是在两棵树合并的时候，谁指向谁的问题（开个脑洞，肯定是大鱼吃小鱼，小鱼吃虾米了）。也就是新树用原来较大的一棵树的树根作为新树树根，这样新树就较为平衡，总体深度不增加或者增一（两树等高）。怎么来实现呢，简单，增加一个向量来记下每个集合的高度就行了，不过叫高度多俗，咱叫秩（rank）。然后代码如下：
Union(x, y,h) {
	x = find_set(x)
		y = find_set(y)
		if(x == y) return;

	if (rank(x) == rank(y)) {
		father[x] = y;
		rank[y] ++;
	} else if (rank[x] > rank[y]) {
		father[y] = x;
	} else {
		father[x] = y;
	}
}
参考：http://dongxicheng.org/structure/union-find-set/
