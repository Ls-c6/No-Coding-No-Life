#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string ans,to="URDL";
vector<vector<int>> vis;
vector<vector<char>> Map,Move;
int n,m,s,e,cnt,dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void bfs()
{
    vis[s/m][s%m]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        int x=now/m,y=now%m;
        if (now==e)
        {
            cnt=vis[x][y];
            break;
        }
        for (int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if (nx>=0 && nx<n && ny>=0 && ny<m && Map[nx][ny]!='#') if (vis[nx][ny]==-1)
            {
                Move[nx][ny]=to[i],vis[nx][ny]=vis[x][y]+1;
                q.push(nx*m+ny);
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tx,ty,flag_1=0,flag_2=0;
    cin>>n>>m;
    vis.assign(n,vector<int>(m,-1));
    Map.assign(n,vector<char>(m));
    Move=Map;
    for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin>>Map[i][j];
    for (int i=0;i<n;++i) for (int j=0;j<m;++j)
    {
        if (Map[i][j]=='A') s=i*m+j,flag_1=1;
        else if (Map[i][j]=='B') tx=i,ty=j,e=i*m+j,flag_2=1;
    }
    bfs();
    if (!flag_1 || !flag_2 || vis[tx][ty]==-1) cout<<"NO\n";
    else if (flag_1 && flag_2)
    {
        while (tx*m+ty!=s)
        {
            ans.push_back(Move[tx][ty]);
            if (Move[tx][ty]=='U') tx++;
            else if (Move[tx][ty]=='R') ty--;
            else if (Move[tx][ty]=='D') tx--;
            else ty++;
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES\n"<<cnt<<"\n"<<ans<<"\n";
    }
    return 0;
}