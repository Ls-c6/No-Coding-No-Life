#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    vector<int> c(n),dp(x+1,0);
    dp[0]=1;
    for (int i=0;i<n;++i) scanf("%d",&c[i]);
    for (int i=1;i<=x;++i) for (int j=0;j<n;++j) if (i-c[j]>=0) dp[i]=(dp[i]+dp[i-c[j]])%1000000007;
    printf("%d\n",dp[x]);
    return 0;
}