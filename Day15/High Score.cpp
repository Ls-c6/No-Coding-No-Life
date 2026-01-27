#include <vector>
#include <stdio.h>
#include <climits>
using namespace std;
int n, m;
vector<long long> val;
vector<vector<pair<int, int>>> Map;

bool bellman()
{
    bool flag = true;
    for (int v = 1; v <= n; ++v)
        if (val[v] != -LLONG_MAX) // 只從可達節點更新
            for (auto [nv, w] : Map[v])
                if (val[nv] < val[v] + w)
                {
                    flag = false;
                    val[nv] = val[v] + w;
                }
    return flag;
}

int main()
{
    int a, b, c;
    scanf("%d%d", &n, &m);
    Map.assign(n + 1, {});
    val.assign(n + 1, -LLONG_MAX);
    vector<bool> re(n + 1, false);
    val[1] = 0;
    while (m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        Map[a].push_back({b, c});
    }
    for (int i = 0; i < n - 1; ++i)
        if (bellman())
            break;
    // 因為bellman做n-1次必為答案，所以多做一次判斷是不是有循環(分數重複加)
    for (int v = 1; v <= n; ++v)
        if (val[v] != -LLONG_MAX)
            for (auto [nv, w] : Map[v])
                if (val[nv] < val[v] + w)
                {
                    val[nv] = val[v] + w;
                    re[nv] = true;
                }
    // 因為終點可能不再循環上，所以要傳遞標記
    for (int i = 0; i < n; ++i) // 傳遞n次標記，保證標記傳到終點
        for (int v = 1; v <= n; ++v)
            if (re[v])
                for (auto [nv, w] : Map[v])
                    re[nv] = true;
    printf("%lld\n", re[n] ? -1 : val[n]);
    return 0;
}
