#include <tuple>
#include <queue>
#include <vector>
#include <stdio.h>
#include <climits>
using namespace std;
using ll = long long;
vector<vector<ll>> val;
vector<vector<pair<ll, int>>> Map;

void dijkstra(int s)
{
    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> pq;
    pq.push({0, s, false});
    while (!pq.empty())
    {
        auto [w, v, use] = pq.top();
        pq.pop();
        if (w > val[use][v])
            continue;
        for (auto [nw, nv] : Map[v])
        {
            // 不用折扣
            if (val[use][nv] > w + nw)
            {
                val[use][nv] = w + nw;
                pq.push({val[use][nv], nv, use});
            }
            // 用折扣
            if (!use)
            {
                ll nval = w + nw / 2;
                if (val[1][nv] > nval)
                {
                    val[1][nv] = nval;
                    pq.push({nval, nv, true});
                }
            }
        }
    }
    return;
}

int main()
{
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    Map.assign(n + 1, {});
    val.assign(2, vector<ll>(n + 1, LLONG_MAX));
    val[0][1] = 0;
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        Map[a].push_back({c, b});
    }
    dijkstra(1);
    printf("%lld\n", val[1][n]);
    return 0;
}
