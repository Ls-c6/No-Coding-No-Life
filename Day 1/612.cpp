#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(pair<string, pair<int,int>> &a,pair<string, pair<int,int>> &b) // 如果反轉數相同，要照輸入順序輸出
{
    if (a.second.first!=b.second.first) return a.second.first<b.second.first;
    return a.second.second<b.second.second;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t,n,m;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        vector<pair<string,pair<int,int>>> s;
        for (int i=0;i<m;i++)
        {
            string temp;
            cin>>temp;
            s.push_back({temp,{0,i}});
        }
        for (int i=0;i<m;i++)
        {
            int times=0;
            string nc=s[i].first;
            for (int j=0;j<n;j++) for (int q=j+1;q<n;q++) if (nc[j]>nc[q]) times++;
            s[i].second.first=times;
        }
        sort(s.begin(),s.end(),f);
        for (auto &print:s) cout<<print.first<<"\n";
        if (t) cout<<"\n"; // 測資間換行(最後一個測資時不換)
    }
    return 0;
}
