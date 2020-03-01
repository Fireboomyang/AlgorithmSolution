class Solution {
public:
    //memo[i]��ʾ��������nums[i...n)���ܻ�õ��������
    vector<int> memo;

    //��������nums[index...nums.size())�����Χ�����еķ���
    int tryRob(vector<int> &nums, int index){
        if(index>=nums.size())
            return 0;
        if(memo[index]!=-1)
            return memo[index];
        int res=0;
        for(int i=index; i<nums.size(); i++){
            res=max(res, nums[i]+tryRob(nums, i+2));
        }
        return memo[index]=res;
    }

    int rob(vector<int>& nums) {
        memo=vector<int>(nums.size(), -1);
        return tryRob(nums, 0);
    }
};
