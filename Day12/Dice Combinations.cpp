#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> dp(n+1,0);
    dp[0]=1;
    for (int i=1;i<=n;++i) for (int j=1;j<=6;++j) if (i-j>=0) dp[i]=(dp[i]+dp[i-j])%1000000007;
    printf("%d\n",dp[n]);
    return 0;
}