/*
题目：在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
解法1：
统计所有数字的次数，采用key ： value的方式存在哈希表中
扫描哈希表，找出只出现一次的那个数字
解法2:
值得注意的是：如果某个数字出现3次，那么这个3个数字的和肯定能被3整除，则其对应二进制位的每一位的和也能被3整除
统计数组中每个数字的二进制中每一位的和，判断该和是否能被3整除。
若可以，则只出现一次的数字的二进制数中那一位为0，否则为1
*/
#include <vector>
#include <unordered_map>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int n : nums) mp[n] ++;
    int ans;
    for(auto pr : mp){
        if(pr.second == 1){
            ans = pr.first;
            break;
        }
    }
    return ans;
}

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < 32; ++i){
        int cnt = 0;
        for(int n : nums){
            // n & 1 << i 的值大于0即为真
            if(n & (1 << i)) cnt++;
        }
        // 构造只出现一次的那个数字，采用异或的方法生成二进制中的每一位
        if(cnt % 3 == 1) ans ^= (1 << i);
    }
    return ans;
}
