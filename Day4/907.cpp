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
        while (l<r) // �۵��ɬ�����
        {
            ll sum=0,day=1,m=l+((r-l)>>1);
            for (ll &i:camp)
            {
                sum+=i;
                if (sum>m)
                {
                    day++;
                    sum=i; // ����W�L���[�^��
                }
            }
            if (day<=k) r=m; // �����֤�(�S��W��)�A��֤@�ѯਫ���q(���]�i��w�g�O���שҥH��-1)
            else l=m+1; // �����h��(�W�L�W��)�A�W�[�@�ѯਫ���q
        }
        printf("%d\n",l);
    }
    return 0;
}
