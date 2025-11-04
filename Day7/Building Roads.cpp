#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> p,vis;
vector<vector<int>> town;

void bfs(int now)
{
    p.push_back(now);
    queue<int> q;
    q.push(now);
    while (!q.empty())
    {
        int c=q.front();
        q.pop();
        for (int &i:town[c]) if (vis[i]-->0) q.push(i);
    }
    return;
}

int main()
{
    int n,m,a,b,group=0;
    scanf("%d%d",&n,&m);
    vis.assign(n+1,1);
    town.assign(n+1,vector<int>());
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        town[a].push_back(b);
        town[b].push_back(a);
    }
    for (int i=1;i<=n;++i) if (vis[i]-->0)
    {
        ++group;
        bfs(i);
    }
    printf("%d\n",group-1);
    for (int i=0;i<group-1;++i) printf("%d %d\n",p[i],p[i+1]);
    return 0;
}