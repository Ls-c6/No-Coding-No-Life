#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,n,e,t,m,a,b,w;
vector<vector<int>> maze;

void Floyd()
{
    for (int mid=1;mid<=n;++mid) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) maze[i][j]=min(maze[i][j],maze[i][mid]+maze[mid][j]);
    return;
}

int main()
{
    scanf("%d",&N);
    while (N--)
    {
        int ans=0;
        scanf("%d%d%d%d",&n,&e,&t,&m);
        maze.assign(n+1,vector<int>(n+1,1e9));
        for (int i=1;i<=n;++i) maze[i][i]=0;
        while (m--)
        {
            scanf("%d%d%d",&a,&b,&w);
            maze[a][b]=min(maze[a][b],w);
        }
        Floyd();
        for (int i=1;i<=n;++i) if (maze[i][e]<=t) ++ans;
        printf("%d\n",ans);
        if (N) printf("\n");
    }
    return 0;
}