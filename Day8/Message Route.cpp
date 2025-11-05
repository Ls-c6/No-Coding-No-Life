#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,a,b;
vector<int> fa,vis,line;
vector<vector<int>> com;

bool bfs()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        for (int &i:com[now])
        {
            if (i==n)
            {
                fa[n]=now;
                return true;
            }
            if (vis[i]-->0)
            {
                fa[i]=now;
                q.push(i);
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    fa.assign(n+1,0);
    vis.assign(n+1,1);
    com.assign(n+1,vector<int>());
    vis[1]=0;
    line.push_back(n);
    for (int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        com[a].push_back(b);
        com[b].push_back(a);
    }
    if (bfs())
    {
        int tmp=n;
        while(tmp!=1)
        {
            tmp=fa[tmp];
            line.push_back(tmp);
        }
        reverse(line.begin(),line.end());
         printf("%d\n",line.size());
         for (int &i:line) printf("%d ",i);
         printf("\n");
    }
    else printf("IMPOSSIBLE\n");
    return 0;
}
