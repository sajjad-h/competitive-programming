#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

ll l, r;
ll fact[22];

ll power(ll a, ll b)
{
    ll s = 1;
    while (b--) {
        s = s * a;
    }
    return s;
}

ll f(ll n)
{
    if (n < 10) {
        return n;
    }
    ll d = log10(n * 1.0);
    ll p = power(10, d);
    if (n < p) {
        d--;
        p /= 10;
    }
    ll cnt = 0;
    for (int i = 1; i <= d; i++) {
        cnt = cnt + 9 * power(10, max(0, (i - 2)));
    }
    //cout << "cnt * " << cnt << '\n';

    //cout << "d " << d << '\n';
    //cout << "p " << p << '\n';
    ll num = n % p;
    ll f_d = n / p;
    ll l_d = n % 10;
    //cout << f_d << ' ' << l_d << '\n';
    cnt = cnt + (f_d - 1) * power(10, max(0LL, d - 1));
    //cout << "cnt " << cnt << '\n';
    cnt = cnt + (num / 10 + 1);
    //cout << "cnt " << cnt << '\n';
    num = (n / 10) * 10 + f_d;
    //cout << num << ' ' << n << '\n';
    if (num > n) {
        cnt--;
    }
    //cout << "cnt " << n << ' ' << cnt << '\n';
    return cnt;
}

int main( )
{
    ll i, j, k;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
    return 0;
}
