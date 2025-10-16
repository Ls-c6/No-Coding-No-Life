#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int m,n,dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
vector<vector<int>> vis;
vector<vector<char>> Map;

void bfs(int now)
{
    queue<int> q;
    q.push(now);
    while(!q.empty())
    {
        int x=q.front()/n,y=q.front()%n;
        q.pop();
        for (int i=0;i<8;i++)
        {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx>=0 && cx<m && cy>=0 && cy<n && Map[cx][cy]=='@') if (vis[cx][cy]-->0) q.push(cx*n+cy);
        }
    }
    return;
}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int sum=0;
        if (!m &&!n) break;
        vis.assign(m,vector<int>(n,1));
        Map.assign(m,vector<char>(n));
        for (int i=0;i<m;i++)
        {
            char c[101];
            scanf("%s",c);
            for (int j=0;j<n;j++) Map[i][j]=c[j];
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (Map[i][j]=='@') if (vis[i][j]-->0)
                {
                    sum++;
                    bfs(i*n+j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}