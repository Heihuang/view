/**
 * 题目：给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序

 * 解法：因为单词的长度 len 是固定的，所以可以将一个单词看成一个单元
对单词使用滑动窗口，单元间的步长就是 len
在 0 - len 的范围内，每一个都作为滑动窗口的起点，滑动 len 次，即可覆盖所有字符串的各种组合
*/

vector<int> findSubstring(string s, vector<string>& words) {
    if (words.size() == 0) return {};
    unordered_map<string, int> wordcnt;
    for (auto& w : words) {
        wordcnt[w]++;
    }
    int len = words[0].size();

    vector<int> ans;
    for (int i = 0; i < len; i++) {
        int left = i;
        int right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while (left + words.size() * len <= s.size()) {
            string temp = "";
            while (cnt < words.size()) {
                temp = s.substr(right, len);
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                window[temp]++;
                cnt++;
                right += len;
            }

            if (window == wordcnt) {
                ans.push_back(left);
            }

            if (wordcnt.find(temp) != wordcnt.end()) {
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            }
            else {
                right += len;
                left = right;
                cnt = 0;
                window.clear();
            }
        }
    }
    return ans;
}
