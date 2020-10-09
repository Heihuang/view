/*
题目：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标
解法：在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。
*/
vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> a;//提供一对一的hash
    vector<int> b(2,-1);//用来承载结果，初始化一个大小为2，值为-1的容器b
    for(int i=0;i<nums.size();i++)
    {
        if(a.count(target-nums[i])>0)
        {
            b[0]=a[target-nums[i]];
            b[1]=i;
            break;
        }
        a[nums[i]]=i;//反过来放入map中，用来获取结果下标
    }
    return b;
};

