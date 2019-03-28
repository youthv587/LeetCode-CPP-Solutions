bool isSubsequence(char* s, char* t) {
    int flag = 1;
    int i, j;
    i = j = 0;
    for ( ; s[i] != '\0'; i++) {
        if(flag) {
            flag = 0;
            while (t[j] && (s[i] != t[j])) j++;
            if (t[j++]) flag = 1;
            else return false;
        }
    }
  return true;
}