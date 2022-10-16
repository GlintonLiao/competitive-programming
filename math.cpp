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
