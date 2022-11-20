// 将 X 的第 Y 位设定为 1
void setbit(int& x, int& y) {
    x |= (1 << y);
}

// 将 X 的第 Y 位设定为 0
void clrbit(int& x, int& y) {
    x &= ~(1 << y);
}

// 取得 X 的第 k 位
int getK(int x, int k) {
    return (x >> k) & 1;
}

// 取得 X 的第 0 到 k - 1 位
int getK(int x, int k) {
    return x & ((1 << k) - 1)
}

// 将 X 的第 k 位取反
void xorK(int& x, int& k) {
    x ^ (1 << k);
}
