/*
*题目：给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值
*/
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;    //用来存结果的vector
    deque<int> tem;     
    
    for(int i=0; i<nums.size(); ++i)
    {
        while(!tem.empty() && nums[i]>nums[tem.back()])
        {   //while这步操作是为了让当前窗口最大值的索引值放到tem的队头
            tem.pop_back();
        }
        if(!tem.empty() && tem.front()<i-k+1) tem.pop_front();
        //这里的if判断条件中的第二个是为了判断队头是否过期，也就是说队头的索引是否小于当前索引                  //往左走k步，+1是因为索引是从0开始，若当前滑窗索引便把它清理掉。
        tem.push_back(i);

        if(i>=k-1)  res.push_back(nums[tem.front()]);
    }
    return res;
}
