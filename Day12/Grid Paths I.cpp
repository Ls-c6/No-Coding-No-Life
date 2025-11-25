#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n,flag=1;
    scanf("%d",&n);
    char *s=new char[n+1];
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0]=1;
    vector<vector<char>> Map(n,vector<char>(n));
    for (int i=0;i<n;++i)
    {
        scanf("%s",s);
        for (int j=0;j<n;++j) Map[i][j]=s[j];
    }
    delete[] s;
    if (Map[0][0]=='*')
    {
        flag=0;
        printf("%d\n",0);
    }
    if (flag)
    {
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) if (Map[i][j]!='*')
        {
            if (i) dp[i][j]=(dp[i][j]+dp[i-1][j])%1000000007;
            if (j) dp[i][j]=(dp[i][j]+dp[i][j-1])%1000000007;
        }
        printf("%d\n",dp[n-1][n-1]);
    }
    return 0;               
}