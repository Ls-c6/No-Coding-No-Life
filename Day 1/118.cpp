#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    char to,com[100],To[]={'N','E','S','W'};
    int m,n,N,S,idx,flag=0,Move[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    scanf("%d%d",&m,&n);
    vector<vector<int>> Map(m+1,vector<int>(n+1, 0));
    while (scanf("%d%d %c",&N,&S,&to)!=EOF)
    {
        for (int i=0;i<4;i++) if (To[i]==to) {idx=i; break; }
        scanf("%s",&com);
        for (int i=0;com[i]!='\0';i++)
        {
            flag=0;
            if (com[i]=='F')
            {
                int cx=N+Move[idx][0],cy=S+Move[idx][1];
                if (cx<0 || cx>m || cy<0 || cy>n)
                {
                    if (!Map[N][S])
                    {
                        printf("%d %d %c LOST\n",N,S,To[idx]);
                        Map[N][S]=1;
                        flag=1;
                        break;
                    }
                }
                else
                {
                    N=cx;
                    S=cy;
                }
            }
            else if (com[i]=='R') idx=(idx+1)%4;
            else idx=(idx+3)%4;
        }
        if (!flag) printf("%d %d %c\n",N,S,To[idx]);
    }
    return 0;
}
