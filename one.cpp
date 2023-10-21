#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int sum = 0;
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}