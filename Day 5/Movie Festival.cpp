#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (vector<int> &a,vector<int> &b) {return a[1]<b[1];}

int main()
{
    int n,sum=1;
    scanf("%d",&n);
    vector<vector<int>> time(n,vector<int>(2));
    for (int i=0;i<n;++i) scanf("%d%d",&time[i][0],&time[i][1]);
    sort(time.begin(),time.end(),cmp);
    int r=time[0][1];
    for (int i=1;i<n;i++) if (time[i][0]>=r)
    {
        r=time[i][1];
        ++sum;
    }
    printf("%d\n",sum);
    return 0;
}