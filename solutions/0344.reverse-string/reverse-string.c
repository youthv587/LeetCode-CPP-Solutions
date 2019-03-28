char* reverseString(char* s) {
    int i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        char c = s[j];
        s[j] = s[i];
        s[i] = c;
    }
    return s;
}