#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,t;
    while (scanf("%d%d",&n,&t)!=EOF)
    {
        vector<int> ans,song(t);
        vector<vector<int>> dp(t+1,vector<int>(n+1,0));
        for (int &i:song) scanf("%d",&i);
        for (int i=1;i<=t;++i)
        {
            int ns=song[i-1];
            for (int j=0;j<=n;++j)
            {
                dp[i][j]=dp[i-1][j];
                if (j>=ns) dp[i][j]=max(dp[i][j],dp[i-1][j-ns]+ns);
            }
        }
        int j=n;
        for (int i=t;i>0;--i) if (dp[i][j]!=dp[i-1][j])
        {
            ans.push_back(song[i-1]);
            j-=song[i-1];
        }
        reverse(ans.begin(),ans.end());
        for (int &i:ans) printf("%d ",i);
        printf("sum:%d\n",dp[t][n]);
    }
    return 0;
}