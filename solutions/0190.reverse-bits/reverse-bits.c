uint32_t reverseBits(uint32_t n) {
    int i = 31;
    uint32_t result = 0;
    while (n != 0) {
        result += (n & 1) << i;
        i--;
        n >>= 1;
    }
    return result;
}