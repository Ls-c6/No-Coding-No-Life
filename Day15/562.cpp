#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    while (n--)
    {
        int tmp, tmps = 0;
        scanf("%d", &m);
        vector<int> coin(m, 0);
        for (int &i : coin)
        {
            scanf("%d", &i);
            tmps += i;
        }
        vector<bool> dp(tmps / 2 + 1, false);
        dp[0] = true;
        for (int &c : coin)
            for (int i = tmps / 2; i >= 0; --i)
            {
                if (i - c >= 0 && dp[i - c])
                    dp[i] = true;
            }
        for (int i = tmps / 2; i >= 0; --i)
        {
            if (dp[i])
            {
                tmp = i * 2;
                break;
            }
        }
        printf("%d\n", tmps - tmp);
    }
    return 0;
}