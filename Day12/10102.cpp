#include <queue>
#include <vector>
#include <utility>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
vector<vector<char>> Map;

int bfs(int s)
{
    vector<int> vis(n*n,1);
    --vis[s];
    queue<pair<int,int>> q; q.push({s,0});
    while (!q.empty())
    {
        auto[now,cnt]=q.front(); q.pop();
        for (int i=0;i<4;++i)
        {
            int x=now/n+dx[i],y=now%n+dy[i];
            if (x>=0 && x<n && y>=0 && y<n) if (vis[x*n+y]-->0)
            {
                if (Map[x][y]=='3') return cnt+1;
                q.push({x*n+y,cnt+1});
            }
        }
    }
    return 0;
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int ans=0;
        vector<int> st;
        char *s=new char[n+1];
        Map.assign(n,vector<char>(n));
        for (int i=0;i<n;++i)
        {
            scanf("%s",s);
            for (int j=0;j<n;++j)
            {
                Map[i][j]=s[j];
                if (s[j]=='1') st.push_back(i*n+j);
            }
        }
        delete[] s;
        for (int &i:st) ans=max(ans,bfs(i));
        printf("%d\n",ans);
    }
    return 0;
}
