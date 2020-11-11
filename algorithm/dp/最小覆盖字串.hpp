/*
题目：你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，
则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案
解法：
在滑动窗口类型的问题中都会有两个指针。一个用于「延伸」现有窗口的r指针，
和一个用于「收缩」窗口的l指针。在任意时刻，只有一个指针运动，而另一个保持静止。
我们在s上滑动窗口，通过移动r指针不断扩张窗口。当窗口包含t全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
如何判断当前的窗口包含所有 t所需的字符呢？我们可以用一个哈希表表示 
t中所有的字符以及它们的个数，用一个哈希表动态维护窗口中所有的字符以及它们的个数，如果这个动态表中包含 
t的哈希表中的所有字符，并且对应的个数都不小于t的哈希表中各个字符的个数，那么当前的窗口是「可行」的
*/
class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};
