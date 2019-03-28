char findTheDifference(char* s, char* t) {
    int sum_s, sum_t;
    sum_s = sum_t = 0;
    for (int i = 0; s[i] != '\0'; i++) sum_s += s[i];
    for (int j = 0; t[j] != '\0'; j++) sum_t += t[j];
    return (sum_t - sum_s);
}