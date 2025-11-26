#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> price(n),page(n),dp(x+1,0);
    dp[0]=0;
    for (int i=0;i<n;++i) scanf("%d",&price[i]);
    for (int i=0;i<n;++i) scanf("%d",&page[i]);
    for (int i=0;i<n;++i) for (int j=x;j>0;--j) if (j-price[i]>=0) dp[j]=max(dp[j],dp[j-price[i]]+page[i]);
    printf("%d\n",dp[x]);
    return 0;
}