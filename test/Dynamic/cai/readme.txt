这是第一次集训的B题，当时没想出来。

1. 怎么变成01背包呢，这么想问题，将余额m减去5之后，作为背包容量，将饭菜的价格先取出最贵的那道作为宝石，其价值v和权重w都是饭菜价格。这样就变成，求该背包使劲装，能最多装多少，当然装满最好。
2. 该背包递推式子：
balance[j] = max(balance[j], balance[j-price[i]]+price[i]);
这时候想清楚了为什么是从右往坐算，因为用到了上次balance[j-price[i]]，它在j小的位置，在计算后面的时候不能被覆盖，所以先算后边。
3. 几个优化点：
a.for (j = m-5; j >= price[i]; --j) {
	balance[j] = max(balance[j], balance[j-price[i]]+price[i]);
}
j >= price[i]因为如果背包容量小于price[i]，那么该宝石肯定放不下，自然就不用更新。
b.if (m < 5) {
	printf("%d\n", m);
	continue;
}
当然，这也是一个边界。后面就不用算了。

最后感谢杨炫越（YangXuanyue）同学，虽然他并不知情，因为参考了他的代码。

