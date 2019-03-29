class Solution(object):
    def reverseWords(self, s):
        L = s.split(' ')
        str = ''
        for index, string in enumerate(L):
            str += string[::-1]
            if index != len(L) - 1:
                str += ' '
        return str