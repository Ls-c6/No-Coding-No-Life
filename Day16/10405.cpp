#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    while (1)
    {
        getline(cin, a);
        if (a == "")
            break;
        getline(cin, b);
        int al = a.size(), bl = b.size();
        vector<vector<int>> dp(al + 1, vector<int>(bl + 1, 0));
        for (int i = 1; i <= al; ++i)
            for (int j = 1; j <= bl; ++j)
                a[i - 1] == b[j - 1] ? dp[i][j] = dp[i - 1][j - 1] + 1 : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        cout << dp[al][bl] << "\n";
    }
    return 0;
}