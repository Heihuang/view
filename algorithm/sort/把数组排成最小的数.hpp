/*
题目：输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个
解法：
思路描述：首先我们要明白就是
无论这些数字怎么取排列，形成的数字的位数是不变的
那么就是高位的数字肯定是越小越好。
我们先考虑一下怎么排列两个数字，比如 1 和 20，高位越小越好，放 1，组合成 120
我们再看一下三个数的情况，比如 36、38 和 5，首先肯定先放 36，剩下 38 和 5，
然后对这两个数进行排列 385，所以最后的结果为 36385。
由上面的两个例子我们其实就可以知道，放数字的顺序肯定是先放第一位(最左边一位)最小的元素，
如果第一位相等，比较第二位....，以此类推。
我们再思考一下，36 < 38 > 5 ，但是 "36" < "38" < "5"，
也就是我们如果把所有数字转换成字符串再排列，刚好就是我们希望的情况。
注意：我们这里说的排列大小比较和字符串大小有点区别，比如 3 和 30，明显 30 排在前面比较好，
所以我们要重构比较，我们组合 s1 和 s2 ，如果 s1 + s2 > s2 + s1，那么 s1 > s2
*/
#include <string>
#include <vector>
using namespace std;

string minNumber(vector<int>& nums) {
    vector<string>strs;
    string ans;
    for(int i = 0; i < nums.size(); i ++){
        strs.push_back(to_string(nums[i]));
    }
    sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});
    for(int i = 0; i < strs.size(); i ++)
        ans += strs[i];
    return ans;
}

