#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int maxLimit;
vector<bool> is_prime(maxLimit, true);
void sieve()
{
    int n = maxLimit-1;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void vectPrint(vector<int> &vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}

vector<int> findPrimeFactors(int num)
{
    vector<int> ans;
    while (num % 2 == 0)
    {
        ans.push_back(2);
        num /= 2;
    }

    for (int i = 3; i * i <= num; i += 2)
    {
        while (num % i == 0)
        {
            ans.push_back(i);
            num /= i;
        }
    }

    if (num > 2)
        ans.push_back(num);

    return ans;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        // b % 2 == 1
        if (b & 1)
            res = res * a;
        a = a * a;
        // b /= 2
        b >>= 1;
    }
    return res;
}

ll binpowMod(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

vector<int> findFactors(int n)
{
    vector<int> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i); // i is a factor of n

            if (i != n / i) // n is not a square of i :: n/i and i are different
                factors.push_back(n/i); // (n/i) is also a factor n
        }
    }
}