#include <stdio.h>
#include <vector>
using namespace std;
vector<int> vis,color;
vector<vector<int>> Map;

void draw(int s)
{
    vis[s]--;
    for (int &i:Map[s]) if (vis[i])
    {
        color[i]=(color[s]+1)%2; // �W���P�C��
        draw(i);
    }
    return;
}

bool dfs(int s)
{
    vis[s]--;
    for (int &i:Map[s])
    {
        if (color[i]==color[s]) return false; // �@���C�����
        if (vis[i]) if (!(dfs(i))) return false; // �S���L�N�� ����false�N����
    }
    return true;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (!n) break;
        int m;
        scanf("%d",&m);
        vis.assign(n,1);
        color.assign(n,0);
        Map.assign(n,{});
        while (m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            Map[a].push_back(b);
            Map[b].push_back(a);
        }
        draw(0);
        vis.assign(n,1);
        printf(dfs(0)?"BICOLORABLE.\n":"NOT BICOLORABLE.\n");
    }
    return 0;
}
