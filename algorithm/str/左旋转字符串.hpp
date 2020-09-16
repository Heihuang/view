/*
题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab
解法：
反转区间为前n的子串
反转区间为n到末尾的子串
反转整个字符串
*/
#include <string>
using namespace std;

string reverse(string &s,int i,int j) {
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
string reverseLeftWords(string s, int n) {
    int size = (int)s.size();
    if (size <= 1) return s;
    reverse(s, 0, n-1);
    reverse(s, n, size-1);
    reverse(s, 0, size-1);
    return s;
}
