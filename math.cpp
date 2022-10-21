/*
    需要使用 long long 的情况：
    数据取到 10^9 级别，同时涉及到数据的 add or multiply
    2^31 ~= 10^9
*/
typedef long long LL;


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
    for (int i = 2; i <= n / i; i++)
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


/*
    Roman numbers combinations < 4000
*/
string c[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};


/*
    Given a number n, from 1 to n
    return how many numbers and n are prime to each other
    (gcd(n1, n2) == 1)

    6 -> 1, 2, 3, 4, 5, 6
    1, 5 meets requirements
    return 2
*/
int phi(int n) {
    int res = n;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    return res;
}


/*
    Exponentiation by squaring
    return (a^b) mod p
*/
LL qmi(int a, int b, int p) {
    LL res = 1 % p;
    while (b) {
        if (b & 1) res = res * a % p;
        b >>= 1;
        a = a * (LL)a % p;
    }
    return res;
}

/*
    a / b % p == a * a^p-2 % p
    when p is prime
    return a^p-2 % p
*/
LL getReversePower(int a, int b, int p) {
    return qmi(a, p - 2, p);
}
