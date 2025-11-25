#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        int now=i;
        while (now>0)
        {
            int num=now%10;
            now/=10;
            if (num) dp[i]=min(dp[i],dp[i-num]+1);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}