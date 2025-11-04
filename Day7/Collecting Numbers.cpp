#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n,tmp,ans=1;
    scanf("%d",&n);
    vector<int> ck(n+1);
    for (int i=0;i<n;++i) 
    {
        scanf("%d",&tmp);
         ck[tmp]=i;
    }
    for (int i=1;i<n;++i) if (ck[i]>ck[i+1]) ++ans;
    printf("%d\n",ans);
    return 0;
}
