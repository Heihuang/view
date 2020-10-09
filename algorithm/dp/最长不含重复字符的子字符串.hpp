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
#include <unordered_set>
#include <math.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            // 左指针向右移动一格，移除一个字符
            occ.erase(s[i - 1]);
        }
        while (rk + 1 < n && !occ.count(s[rk + 1])) {
            // 不断地移动右指针
            occ.insert(s[rk + 1]);
            ++rk;
        }
        // 第 i 到 rk 个字符是一个极长的无重复字符子串
        ans = max(ans, rk - i + 1);
    }
    return ans;
}
