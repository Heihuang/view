/*
题目：给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串
*/
/*
哈希计数
*/
bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> mp;
        for(char c : s1) {
            mp[c]++;
        }
        for(char c : s2) {
            mp[c]--;
        }
        for(int i = 0; i < 26; i++) {
            char c = i + 'a';
            if(mp[c] != 0) {
                return false;
            }
        }
        return true;
    }
/*
解法2：排序
*/
bool CheckPermutation(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
