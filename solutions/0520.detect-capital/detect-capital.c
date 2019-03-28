bool detectCapitalUse(char* word)
{
    int i, diff, len = strlen(word);
    char cword[len+1];
    cword[len] = '\0';
    for (i = 0; i < len; ++i) cword[i] = toupper(word[i]);
    diff = word[len-1] - cword[len-1];
    for (i = len - 1; i >= 1; --i)
	if (word[i] - cword[i] != diff) return false;
    if (word[0] - cword[0] != diff && word[0] - 'a' >= 0) return false;
    return true;
}