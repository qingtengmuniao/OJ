#include<stdio.h>
#include<string.h>
#include<math.h>
double dp[10010];
int main()
{
	int i,j,t,p[110],n,sum,mark;
	double s,c[110];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%d",&s,&n);
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%lf",&p[i],&c[i]);
			sum+=p[i];
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1.0;
		for(i=1;i<=n;i++)
		{
			for(j=sum;j>=p[i];j--)
			{
				dp[j]=((dp[j]>dp[j-p[i]]*(1-c[i]))?dp[j]:dp[j-p[i]]*(1-c[i]));

			}
		}
		mark=0;
		for(i=sum;i>=1;i--)
			if(dp[i]>=1-s)
			{
				mark=i;
				break;
			}
		printf("%d\n",mark);
	}
	return 0;
}
