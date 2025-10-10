#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    while (n--)
    {
        cin>>m;
        string a,b,c;
        for (int i=0;i<m;i++)
        {
            char x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
        }
        int flag=0;
        for (int i=m-1;i>=0;i--)
        {
            int tmp=a[i]-'0'+b[i]-'0';
            if (flag) tmp++;
            if (tmp>9)
            {
                tmp%=10;
                flag=1;
            }
            else flag=0;
            c.push_back(tmp+'0');
        }
        for (int i=m-1;i>=0;i--) cout<<c[i]; cout<<"\n";
        if (n) cout<<"\n";
    }
    return 0;
}
