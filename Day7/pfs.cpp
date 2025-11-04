#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n,q,l,r,plus;
    scanf("%d%d",&n,&q);
    vector<long long> pfs;
    pfs.push_back(0);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&plus);
        pfs.push_back(plus+pfs[i-1]);
    }
    for (int i=0;i<q;++i)
    {
        scanf("%d%d",&l,&r);
        printf("%lld\n",pfs[r]-pfs[l-1]);
    }
    return 0;
}
