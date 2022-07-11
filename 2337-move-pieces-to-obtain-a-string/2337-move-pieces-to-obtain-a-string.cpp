class Solution {

public:
    bool canChange(string s, string t) {
    int i = 0, j = 0, n = s.size();
    for (; i < n || j < n; ++i, ++j) {
        while (i < n && s[i] == '_')
            ++i;
        while (j < n && t[j] == '_')
            ++j;
        if (i == n || j == n || s[i] != t[j] || (s[i] == 'L' && i < j) || (s[i] == 'R' && i > j))
            break;
    }
    return i == n && j == n;
}
};