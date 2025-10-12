#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    int n,m,ans=999999999;
    scanf("%d%d",&n,&m);
    vector<int> a(n),b(m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<m;i++) scanf("%d",&b[i]);
    if (n==1 && m==1) printf("%d\n",abs(a[0]-b[0]));
    else
    {
        sort(b.begin(),b.end());
        for (int &now:a)
        {
            int mid,left=0,right=m-1;
            while (left<=right)
            {
                mid=left+(right-left)/2;
                if (b[mid]==now)
                {
                    ans=0;
                    break;
                }
                else if (b[mid]>now) right=mid-1;
                else left=mid+1;
            }
            if (!ans) break;
            if (right>-1) ans=min(ans,abs(b[right]-now));
            if (left<m) ans=min(ans,abs(b[left]-now));
        }
        printf("%d\n",ans);
    }
    return 0;
}
