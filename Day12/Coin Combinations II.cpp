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
    for (int i=0;i<n;++i) for (int j=1;j<=x;++j) if (j-c[i]>=0) dp[j]=(dp[j]+dp[j-c[i]])%1000000007;
    printf("%d\n",dp[x]);
    return 0;
}