#include <queue>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,st,ed,flag=1,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
char to[]={'U','R','D','L'};
vector<int> mon;
vector<vector<int>> vis,t_1,t_2;
vector<vector<char>> Map,Move;

void mbfs()
{
    queue<int> q;
    for (int &i:mon)
    {
        q.push(i);
        t_1[i/m][i%m]=0;
    }
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        int x=cur/m,y=cur%m;
        for (int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && Map[nx][ny]=='.')
            {
                if (t_1[nx][ny]>t_1[x][y]+1)
                {
                    t_1[nx][ny]=t_1[x][y]+1;
                    q.push(nx*m+ny);
                }
            }
        }
    }
    return;
}

int pbfs(int now)
{
    vis.assign(n,vector<int>(m,1));
    --vis[now/m][now%m];
    t_2[now/m][now%m]=0;
    queue<int> q;
    q.push(now);
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        int x=cur/m,y=cur%m;
        if (x==0 || x==n-1 || y==0 || y==m-1)
        {
            ed=x*m+y;
            return 1;
        }
        for (int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && Map[nx][ny]=='.') if (vis[nx][ny]-->0)
            {
                if (t_2[x][y]+1<t_1[nx][ny])
                {
                    t_2[nx][ny]=t_2[x][y]+1;
                    Move[nx][ny]=to[i];
                    q.push(nx*m+ny);
                }
            }
        }
    }
    return 0;
}

int main()
{
    string ans;
    scanf("%d%d",&n,&m);
    Map.assign(n,vector<char>(m));
    t_1.assign(n,vector<int>(m,1e9));
    t_2.assign(n,vector<int>(m,1e9));
    Move=Map;
    for (int i=0;i<n;++i) for (int j=0;j<m;++j)
    {
        char tmp;
        scanf(" %c",&tmp);
        if (tmp=='A') st=i*m+j;
        else if (tmp=='M') mon.push_back(i*m+j);
        Map[i][j]=tmp;
    }
    mbfs();
    flag=pbfs(st);
    while (ed!=st)
    {
        int x=ed/m,y=ed%m;
        ans.push_back(Move[x][y]);
        if (Move[x][y]=='U') ++x;
        else if (Move[x][y]=='R') --y;
        else if (Move[x][y]=='D') --x;
        else ++y;
        ed=x*m+y;
    }
    reverse(ans.begin(),ans.end());
    if (flag) printf("YES\n%d\n%s\n",ans.size(),ans.c_str());
    else printf("NO\n");
    return 0;
}
