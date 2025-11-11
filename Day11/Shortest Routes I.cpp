#include <queue>
#include <vector>
#include <stdio.h>
#include <climits>
using namespace std;
vector<long long> val;
vector<vector<pair<int,int>>> Map;

void dijkstra(int s)
{
    val.assign(Map.size(),LLONG_MAX);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq; //greater(升冪)
    val[s]=0;
    pq.push({0,s}); // 排序根據看第一個元素，所以前面放距離
    while (!pq.empty())
    {
        auto [w,v]=pq.top();
        pq.pop();
        if (w>val[v]) continue; //點可能重複進去很多次，所以可能不同
        for (auto [nw,nv]:Map[v]) if (val[nv]>val[v]+nw)
        {
            val[nv]=val[v]+nw;
            pq.push({val[nv],nv});
        }
    }
}

int main()
{
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    Map.assign(n+1,{});
    val.assign(Map.size(),LLONG_MAX);
    while (m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        Map[a].push_back({c,b}); // (權重，點)
    }
    dijkstra(1);
    for (int i=1;i<=n;++i) printf("%lld ",val[i]);
    return 0;
}
