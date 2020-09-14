/*
题目：输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

*/
#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> vec;
    vector<int> res;
    int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
    for (int x = 1; x <= limit; ++x) {
        long long delta = 1 - 4 * (x - 1ll * x * x - 2 * target);
        if (delta < 0) continue;
        int delta_sqrt = (int)sqrt(delta + 0.5);
        if (1ll * delta_sqrt * delta_sqrt == delta && (delta_sqrt - 1) % 2 == 0){
            int y = (-1 + delta_sqrt) / 2; // 另一个解(-1-delta_sqrt)/2必然小于0，不用考虑
            if (x < y) {
                res.clear();
                for (int i = x; i <= y; ++i) res.emplace_back(i);
                vec.emplace_back(res);
            }
        }
    }
    return vec;
}
vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>>vec;
    vector<int> res;
    for (int l = 1, r = 2; l < r;){
        int sum = (l + r) * (r - l + 1) / 2;
        if (sum == target){
            res.clear();
            for (int i = l; i <= r; ++i) res.emplace_back(i);
            vec.emplace_back(res);
            l++;
        }
        else if (sum < target) r++;
        else l++;
    }
    return vec;
}
