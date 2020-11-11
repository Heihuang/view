/*
题目：
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。
说明:
单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/
    string fillWords(vector<string>& words, int bg, int ed, int maxWidth, bool lastLine = false)
    {
        int wordCount = ed - bg + 1;
        int spaceCount = maxWidth + 1 - wordCount;  // 除去每个单词尾部空格， + 1 是最后一个单词的尾部空格的特殊处理
        for (int i = bg; i <= ed; i++)
        {
            spaceCount -= words[i].size();  // 除去所有单词的长度
        }

        int spaceSuffix = 1;    // 词尾空格
        int spaceAvg = (wordCount == 1) ? 1 : spaceCount / (wordCount - 1);     // 额外空格的平均值
        int spaceExtra = (wordCount == 1) ? 0 : spaceCount % (wordCount - 1);   // 额外空格的余数

        string ans;
        for (int i = bg; i < ed; i++)
        {
            ans += words[i];    // 填入单词
            if (lastLine)   // 特殊处理最后一行
            {
                fill_n(back_inserter(ans), 1, ' ');
                continue;
            }
            fill_n(back_inserter(ans), spaceSuffix + spaceAvg + ((i - bg) < spaceExtra), ' ');  // 根据计算结果补上空格
        }
        ans += words[ed];   // 填入最后一个单词
        fill_n(back_inserter(ans), maxWidth - ans.size(), ' '); // 补上这一行最后的空格
        return ans;
    }

vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> ans;
    int cnt = 0;
    int bg = 0;
    for (int i = 0; i < words.size(); i++)
    {
        cnt += words[i].size() + 1;

        if (i + 1 == words.size() || cnt + words[i + 1].size() > maxWidth)
        {   // 如果是最后一个单词，或者加上下一个词就超过长度了，即可凑成一行
            ans.push_back(fillWords(words, bg, i, maxWidth, i + 1 == words.size()));
            bg = i + 1;
            cnt = 0;
        }
    }
    return ans;
}
