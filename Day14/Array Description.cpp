#include <vector>
#include <stdio.h>
using namespace std;

int main ()
{
    int n,m,ans=0;
    scanf("%d%d",&n,&m);
    vector<int> a(n+1);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    int tmp=a[1];
    if (!tmp) for (int i=1;i<=m;++i) dp[1][i]=1;
    else dp[1][tmp]=1;
    for (int i=2;i<=n;++i)
    {
        if (!a[i]) for (int j=1;j<=m;++j)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000007;
            if (j>1) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%1000000007;
            if (j<m) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%1000000007;
        }
        else
        {
            tmp=a[i];
            for (int j=1;j<=m;++j) dp[i][j]=0;
            dp[i][tmp]=(dp[i][tmp]+dp[i-1][tmp])%1000000007;
            if (tmp>1) dp[i][tmp]=(dp[i][tmp]+dp[i-1][tmp-1])%1000000007;
            if (tmp<m) dp[i][tmp]=(dp[i][tmp]+dp[i-1][tmp+1])%1000000007;
        }
    }
    for (int i=1;i<=m;++i) ans=(ans+dp[n][i])%1000000007;
    printf("%d\n",ans);
    return 0;
}