/*
    将 X 的第 Y 位设定为 1
*/
void setbit(int& x, int& y) {
    x |= (1 << y);
}

/*
    将 X 的第 Y 位设定为 0
*/
void clrbit(int& x, int& y) {
    x &= ~(1 << y);
}