#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int s,n,m,num=0,dx[2][4]={{-1,0,1,0},{0,0,1,0}},dy[4]={0,1,0,-1};
vector<vector<int>> M,ans;

void bfs(int go)
{
    vector<int> vis(n*m,1);
    vis[go]--;
    queue<pair<int,int>> q; q.push({go,2});
    while (!q.empty())
    {
        auto [now,h]=q.front(); q.pop();
        for (int i=0;i<4;i++)
        {
            int cx=now/m+dx[s-1][i],cy=now%m+dy[i];
            if (cx>=0 && cx<n && cy>=0 && cy<m && M[cx][cy])
            {
                if (vis[cx*m+cy]-->0)
                {
                    ans[cx][cy]+=h;
                    q.push({cx*m+cy,h+1});
                }
            }
        }
    }
    return;
}

int main()
{
    while (scanf("%d",&s)!=EOF)
    {
        printf("Case %d:\n",++num);
        scanf("%d%d",&n,&m);
        M.assign(n,vector<int>(m,0));
        ans=M;
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&M[i][j]);
        for (int i=0;i<m;i++)
        {
            if (M[0][i])
            {
                ans[0][i]=1;
                bfs(i);
                break;
            }
        }
        for (auto &r:ans)
        {
            for (int &c:r) printf("%d ",c);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
