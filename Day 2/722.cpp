#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int bfs(int &r,int &c,vector<vector<int>> &Map)
{
    int n=Map.size(),m=Map[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int total=1;
    vis[r][c]=1;
    queue<pair<int,int>> q; q.push({r,c});
    while (!q.empty())
    {
        int x=q.front().first,y=q.front().second; q.pop();
        for (int i=0;i<4;i++)
        {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx>=0 && cx<n && cy>=0 && cy<m && !Map[cx][cy])
            {
                if (vis[cx][cy]++==0)
                {
                    total++;
                    q.push({cx,cy});
                }
            }
        }
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,r,c;
    string s;
    cin>>t;
    while (t--)
    {
        cin>>r>>c;
        cin.ignore();
        r--; c--;
        vector<vector<int>> Map;
        while (getline(cin,s))
        {
            if (s.empty()) break;
            vector<int> tmp;
            for (char &c:s) tmp.push_back(c-'0');
            Map.push_back(tmp);
        }
        cout<<bfs(r,c,Map)<<"\n";
        if (t) cout<<"\n";
    }
    return 0;
}
