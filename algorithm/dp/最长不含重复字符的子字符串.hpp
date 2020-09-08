/*
题目：请从字符串中找出一个最长的不包含重复字符的子字符串，
计算该最长子字符串的长度
解法：然后尽量向右移动尾指针来拓展窗口，并更新窗口的最大长度。
如果尾指针指向的元素重复，则将头指针直接移动到窗口中重复元素的右侧
tail 指针向末尾方向移动;
如果尾指针指向的元素存在于哈希表中：
    head 指针跳跃到重复字符的下一位
更新哈希表和窗口长度
*/
#include <string>
#include <map>
#include <math.h>
using namespace std;
int lengthOfLongestSubstring(string s) 
{
    map<char, int> m;
    int ret = 0, l = 0, r = 0;
    while (r < s.size()) {
        if (m.find(s[r]) != m.end()) {
            l = max(l, m[s[r]] + 1);
        }
        m[s[r++]] = r;
        ret = max(r - l, ret);
    }
    return ret;
}
