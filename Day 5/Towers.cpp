#include <set>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    multiset<int> s;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int tower;
        scanf("%d",&tower);
        auto it=s.upper_bound(tower);
        if (it==s.end()) s.insert(tower);
        else
        {
            s.erase(it);
            s.insert(tower);
        }
    }
    printf("%d\n",s.size());
    return 0;
}
