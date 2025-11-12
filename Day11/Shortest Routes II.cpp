#include <vector>
#include <climits>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,q,a,b,c,s,e;
    scanf("%d%d%d",&n,&m,&q);
    vector<vector<long long>> dis(n+1,vector<long long>(n+1,LLONG_MAX/2));
    while (m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        dis[a][b]=min((long long)c,dis[a][b]);
        dis[b][a]=min((long long)c,dis[b][a]);
    }
    for (int i=1;i<=n;++i) dis[i][i]=0;
    for (int mid=1;mid<=n;++mid) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
    while (q--)
    {
        scanf("%d%d",&s,&e);
        printf("%lld\n",dis[s][e]!=LLONG_MAX/2?dis[s][e]:-1);
    }
    return 0;
}