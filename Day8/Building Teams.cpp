#include <vector>
#include <stdio.h>
using namespace std;
int n,m,a,b,flag=1;
vector<int> vis,Std;
vector<vector<int>> Class;

void c(int now)
{
    --vis[now];
    for (int &i:Class[now]) if (vis[i])
    {
        Std[i]=Std[now]==1?2:1;
        c(i);
    }
    return;
}

bool dfs(int now)
{
    --vis[now];
    for (int &i:Class[now])
    {
        if (Std[now]==Std[i]) return false;
        if (vis[i]) if (!dfs(i)) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    vis.assign(n+1,1);
    Std.assign(n+1,0);
    Class.assign(n+1,vector<int>());
    while (m--)
    {
        scanf("%d%d",&a,&b);
        Class[a].push_back(b);
        Class[b].push_back(a);
    }
    for (int i=1;i<=n;++i) if (vis[i])
    {
        Std[i]=1;
        c(i);
    }
    vis.assign(n+1,1);
    for (int i=1;i<=n;++i) if (vis[i]) if(!dfs(i)) flag=0;
    if (flag)
    {
        for (int i=1;i<=n;++i) printf("%d ",Std[i]);
        printf("\n");
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}