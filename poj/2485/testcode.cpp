#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 500
using namespace std;

int father[MAX];    //用来存储各个节点的父节点
int cmax;   //用来存储最小生成树上面边的最大权值

struct edge
{
	int x,y;
	int w;
}e[MAX * MAX / 2];  //用来存储各个边的信息，x点至y点的权值为w

bool cmp(edge a,edge b)     //非降序排序排序函数
{
	return a.w < b.w;
}

int find_set(int a)     //查找x所在的集合，回溯时顺便压缩路径
{
	if(a != father[a])
	{
		father[a] = find_set(father[a]);
	}
	return father[a];
}

void Union(int x,int y,int w)   //合并两个集合，并在合并集合的过程当中不断地更新生成树里面的最大权值，记录到cmax里面
{
	if(x == y)  return ;
	father[y] = x;
	if(w > cmax) cmax = w;
}

int main()
{
	int t,n,i,j,k;
	int temp;
	scanf("%d",&t);
	while(t--)
	{
		k = 0;
		cmax = 0;
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			father[i] = i;  //初始化集合
			for(j = 0;j < n;j++)
			{
				/*因为是无向图，输入的时候只输入右上方三角的信息就可以了*/
				if(i < j)
				{
					e[k].x = i;
					e[k].y = j;
					scanf("%d",&e[k].w);
					k++;
				}
				else
					scanf("%d",&temp);
			}
		}
		sort(e,e + k,cmp);  //排序
		for(i = 0;i < k;i++)
		{
			Union(find_set(e[i].x),find_set(e[i].y),e[i].w);
		}
		cout << cmax << endl;   //输出结果
	}
	return 0;
}
