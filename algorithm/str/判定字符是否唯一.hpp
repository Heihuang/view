/*
题目：实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
解法：哈希表

*/
 bool isUnique(string s) {
    unordered_map<char, int> mp;
    for(char c : s) {
        if(mp[c] > 0) {
            return false;
        } else {
            mp[c] = 1;
        }
    }
    return true;
}

/*
解法2：由于一共有26种字符，所以我们用一个0-1串记录所有字符出现的次数，
某一个字符出现过，则将其所在位的值置1，若再次出现，且该位已经为1，则返回false；
*/
bool isUnique(string s) {
    int x = 0;
    for(char c : s) {
        if(x & (1 << (c - 'a'))) {	// c - 'a'：将字符转换为0-25的数字
            return false;
        } else {
            x |= 1 << (c - 'a');
        }
    }
    return true;
}