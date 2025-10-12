#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int l,r,c,ans,s[]={0,0,0},e[]={0,0,0},dx[]={-1,0,1,0,0,0},dy[]={0,1,0,-1,0,0},dz[]={0,0,0,0,1,-1};
vector<vector<vector<char>>> M;

int bfs(int z,int x,int y)
{
    vector<vector<vector<int>>> vis(l,vector<vector<int>>(r,vector<int>(c,1)));
    vis[z][x][y]--;
    queue<pair<tuple<int,int,int>,int>> q; q.push({{z,x,y},0});
    while (!q.empty())
    {
        auto [nz,nx,ny]=q.front().first;
        int cnt=q.front().second;
        q.pop();
        if (nz==e[0] && nx==e[1] && ny==e[2]) return cnt;
        for (int i=0;i<6;i++)
        {
            int cz=nz+dz[i],cx=nx+dx[i],cy=ny+dy[i];
            if (cz>=0 && cz<l && cx>=0 && cx<r && cy>=0 && cy<c && M[cz][cx][cy]!='#') if (vis[cz][cx][cy]-->0) q.push({{cz,cx,cy},cnt+1});
        }
    }
    return -1;
}

int main()
{
    while (scanf("%d%d%d",&l,&r,&c)!=EOF)
    {
        if (!l &&!r && !c) break;
        M.assign(l,vector<vector<char>>(r,vector<char>(c)));
        for (int i=0;i<l;i++)
        {
            for (int j=0;j<r;j++)
            {
                char tmp[30];
                scanf("%s",tmp);
                for (int q=0;q<c;q++)
                {
                    if (tmp[q]=='S') s[0]=i,s[1]=j,s[2]=q;
                    else if (tmp[q]=='E') e[0]=i,e[1]=j,e[2]=q;
                    M[i][j][q]=tmp[q];
                }
            }
        }
        ans=bfs(s[0],s[1],s[2]);
        if (ans>0) printf("Escaped in %d minute(s).\n",ans);
        else printf("Trapped!\n");
    }
    return 0;
}
