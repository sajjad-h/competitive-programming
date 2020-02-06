#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int inf = 1e9 + 9;
int grid[27][27];
int dp[N][27];
int n;
string s;

int solve(int at, int p)
{
    if (at == n) {
        return 0;
    }
    if (dp[at][p] != -1) {
        return dp[at][p];
    }
    int x = s[at] - 'a' + 1;
    int res;
    if (grid[p][x] == 1) {
        res = 1 + solve(at + 1, p);
    }
    else {
        res = solve(at + 1, x);
        res = min(res, 1 + solve(at + 1, p));
    }
    dp[at][p] = res;
    return res;
}

int main( )
{
    cin >> s;
    n = (int) s.size();
    int i, j, k;
    string ss;
    cin >> k;
    cin.ignore();
    while (k--) {
        cin >> ss;
        i = ss[0] - 'a' + 1;
        j = ss[1] - 'a' + 1;
        grid[i][j] = 1;
        grid[j][i] = 1;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
    return 0;
}
