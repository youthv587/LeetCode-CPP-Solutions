int rangeBitwiseAnd(int m, int n) {
    int32_t result = m;
    if (m == n) return m;
    while (m < n) {
        if (result == 0) return 0;
        result = result & (++m);
    }
    return result;
}