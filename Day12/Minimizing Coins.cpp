#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> c(n),dp(x+1,1e9);
    dp[0]=0;
    for (int i=0;i<n;++i) scanf("%d",&c[i]);
    for (int i=1;i<=x;++i) for (int j=0;j<n;++j) if (i-c[j]>=0) dp[i]=min(dp[i],dp[i-c[j]]+1);
    printf("%d\n",dp[x]==1e9?-1:dp[x]);
    return 0;
}