class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> vec(nums.size(),-1);
        
        for(int i=0;i<nums.size();i++)
        {
            if( vec[index[i]] != -1)
            {
                int minuIdx = index[i];
                for(int j=index[i];j<nums.size();++j)
                {
                    if(vec[j] == -1)
                        minuIdx = j;
                }
                
                for(int j=minuIdx;j>index[i];--j)
                    vec[j] = vec[j-1];
            }
            vec[index[i]] = nums[i];
        }
        return vec;
    }
};
