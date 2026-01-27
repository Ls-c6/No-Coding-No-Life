#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    int n, coin[5] = {1, 5, 10, 25, 50};
    while (scanf("%d", &n) != EOF)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j <= n; ++j)
                if (j - coin[i] >= 0)
                    dp[j] += dp[j - coin[i]];
        printf("%d\n", dp[n]);
    }
    return 0;
}