bool canConstruct(char* ransomNote, char* magazine) {
    int *s = (int *)calloc(26, sizeof(int));
	for (int i = 0; magazine[i] != '\0'; ++i) ++s[magazine[i]-'a'];
	for (int i = 0; ransomNote[i] != '\0'; ++i) --s[ransomNote[i]-'a'];
	for (int i = 0; i < 26; ++i)
		if (s[i] < 0) return false;
	return true;
}