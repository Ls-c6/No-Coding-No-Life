#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int N,C;
    while (scanf("%d%d",&N,&C)!=EOF)
    {
        int k=1;
        vector<int> p,check(N+1,1);
        p.push_back(1);
        printf("%d %d: ",N,C);
        for (int i=2;i<=N;i++)
        {
            if (check[i])
            {
                k++;
                p.push_back(i);
            }
            for (int j=2*i;j<=N;j+=i) check[j]=0;
        }
        if ((k&1 && C*2>=k) || (!(k&1) && C*2-1>=k))
        {
            printf("%d",p[0]);
            for (int i=1;i<k;i++) printf(" %d",p[i]);
        }
        else if (k&1)
        {
            int tmp=(k-(C*2-1))/2;
            printf("%d",p[tmp++]);
            for (int i=tmp;i<tmp+C*2-2;i++) printf(" %d",p[i]);
        }
        else if (!(k&1))
        {
            int tmp=(k-C*2)/2;
            printf("%d",p[tmp++]);
            for (int i=tmp;i<tmp+C*2-1;i++) printf(" %d",p[i]);
        }
        printf("\n\n");
    }
    return 0;
}
