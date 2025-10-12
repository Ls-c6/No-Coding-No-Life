#include <stdio.h>
#include <vector>
using ll=long long;
using namespace std;

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        k++;
        ll l=-1,r=0;
        vector<ll> camp(++n);
        for (int i=0;i<n;i++) scanf("%d",&camp[i]);
        for (ll &i:camp)
        {
            if (l<i) l=i;
            r+=i;
        }
        while (l<r) // 相等時為答案
        {
            ll sum=0,day=1,m=l+((r-l)>>1);
            for (ll &i:camp)
            {
                sum+=i;
                if (sum>m)
                {
                    day++;
                    sum=i; // 把剛剛超過的加回來
                }
            }
            if (day<=k) r=m; // 花比較少天(沒到上限)，減少一天能走的量(但也可能已經是答案所以不-1)
            else l=m+1; // 花比較多天(超過上限)，增加一天能走的量
        }
        printf("%d\n",l);
    }
    return 0;
}
