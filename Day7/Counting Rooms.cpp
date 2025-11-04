#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;
int n,m,room=0,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
vector<vector<int>> vis;
vector<vector<char>> Map;

void bfs(int now)
{
    queue<int> q;
    q.push(now);
    while (!q.empty())
    {
        int x=q.front()/m,y=q.front()%m;
        q.pop();
        for (int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && Map[nx][ny]=='.') if (vis[nx][ny]-->0) q.push(nx*m+ny);
        }
    }
    return;
}

int main()
{
    scanf("%d%d",&n,&m);
    Map.assign(n,vector<char>(m));
    vis.assign(n,vector<int>(m,1));
    for (int i=0;i<n;++i)
    {
        char c[1001];
        scanf("%s",c);
        for (int j=0;j<m;++j) Map[i][j]=c[j];
    }
    for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (Map[i][j]=='.' && vis[i][j]-->0)
    {
       ++room;
       bfs(i*m+j);
    }
    printf("%d\n",room);
    return 0;
}