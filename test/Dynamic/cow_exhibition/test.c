#include<stdio.h>  
#include<string.h>  
#define maxn 210000  
#define max(a, b) ((a) > (b) ? (a) : (b))
#define BIAS 100000
int dp[maxn];  
int main()  
{  
	int i,n,S[105],F[105],j,sum;  
	while(scanf("%d",&n)!=EOF)  
	{  
		for(i=0;i<maxn;i++)  
			dp[i]=-maxn;  
		dp[BIAS]=0;  
		sum=BIAS;  
		for(i=0;i<n;i++)  
		{  
			scanf("%d%d",&S[i],&F[i]);  
			if(S[i]>0)  
				sum+=S[i];      //sum为背包的最大容量  
		}  
		for(i=0;i<n;i++)  
		{  
			if(S[i]>=0)  
			{  
				for(j=sum;j>=S[i];j--)  
				{  
					dp[j]=max(dp[j],dp[j-S[i]]+F[i]);  
				}  
			}  
			else  
			{  
				for(j=0;j<=sum;j++)  
				{  
					dp[j]=max(dp[j],dp[j-S[i]]+F[i]);  
				}  
			}  
		}  
		int maxx=0;  
	//	for(i=BIAS;i<=sum;i++)  
	//	{  
	//		if(dp[i]>=0&&maxx<dp[i]+i-100000)  
	//		{  
	//			maxx=dp[i]+i-100000;  
	//		}  
	//	}  
		for (j = BIAS; j <= sum; ++j) {
			printf("%d ", dp[j]);
			if (dp[j] >= 0) {
				maxx = max(maxx, j-BIAS+dp[j]);	
			}
		}
		printf("%d\n",maxx);  
	}  
	return 0;  
}  
