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
