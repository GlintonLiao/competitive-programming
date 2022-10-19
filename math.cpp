/*
    需要使用 long long 的情况：
    数据取到 10^9 级别，同时涉及到数据的 add or multiply
    2^31 ~= 10^9
*/
typedef long long LL;


/*
  MOD
*/
(a + b) % MOD = ((a % MOD) + (b % MOD)) % MOD;
(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD;


/*
    Reverse a number
    123 -> 321
*/
int reverse(int num) {
    int res = 0;
    while (num) {
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res;
}


/*
    Get every prime factor of number n

    A number n will only have at most 1 prime factor
    which is greater than √n
*/
vector<int> getPrimeFactor(int n) {
    vector<int> res;
    for (int i = 2; i <= n % i; i++)
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res.push_back(i);
        }
    if (n > 1) res.push_back(n);
    return res;
}


/*
    Get prime cnt of 1 - n
    O(n)
*/
void get_primes(){
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    cout << cnt << endl;
}

/*
    Get every factor of n
*/
vector<int> getFactor(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }
    return res;
}

/*
    Given a1, a2, ... an
    return the factor number of (a1 * a2 * ... * an)
*/
int getFactor(vector<int>& nums) {
    unordered_map<int, int> primes;
    int MOD = 1e9 + 7;
    for (auto& n : nums) {
        for (int i = 2; i <= n / i; i++) {
            while (n % i == 0) {
                n /= i;
                primes[i]++;
            }
        }
        if (n > 1) primes[n]++;
    }
    long long res = 1;
    for (auto& p : primes) {
        res = res * (p.second + 1) % MOD;
    }
    return res;
}
