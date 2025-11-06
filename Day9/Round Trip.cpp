#include <vector>
#include <stdio.h>
using namespace std;
int n,m,a,b,st,ed;
vector<int> fa,vis,ans;
vector<vector<int>> road;

int dfs(int now,int fat)
{
    vis[now]=0;
    for (int &i:road[now])
    {
        if (i==fat) continue; // 不走回父節點（父子相連不算環）
        if (vis[i])
        {
            fa[i]=now;
            if (dfs(i,now)) return 1; // 一找到環直接停止搜尋
        }
        else // 找到環：i->now為回邊 （不為父節點，且已經拜訪過代表為回邊）
        {
            st=i;
            ed=now;
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf( "%d%d",&n,&m);
    fa.assign(n+1,0);
    vis.assign(n+1,1);
    road.assign(n+1,{});
    for (int i=0;i<m;++i)
   {
        scanf("%d%d",&a,&b);
        road[a].push_back(b);
        road[b].push_back(a);
    }
    for (int i=1;i<=n;++i) if (vis[i] && dfs(i,0)) break; // 因為一開始的丟進去的父節點沒有父節點，所以用0假裝它有，這樣也不會卡其他節點
    if (!st) printf("IMPOSSIBLE\n");
    else
    {
        for (int i=ed;i!=st;i=fa[i]) ans.push_back(i);
        printf("%d\n%d ",ans.size()+2,st);
        for (int &i:ans) printf("%d ",i);
        printf("%d\n",st);
    }
    return 0;
}
