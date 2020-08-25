class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> out(nums.size());
        /*for(size_t i=0;i<nums.size();++i)
        {
            for(size_t j=0;j<nums.size();++j)
            {
                if(nums[j]<nums[i])
                    ++out[i];
            }
        }*/
        
        size_t len = nums.size();
        vector<int> sortedInd(nums.size());
        
        for(size_t i=0;i<len;++i)
        {
            sortedInd[i] = i;
        }
        
        sort(sortedInd.begin(),sortedInd.end(),[&nums](int a,int b){
           if(nums[a]<nums[b])
               return true;
            return false;
        });
        
        out[sortedInd[0]] = 0; 
        
        for(size_t i=1;i<len;++i)
        {
            if(nums[sortedInd[i]] == nums[sortedInd[i-1]])
                out[sortedInd[i]] = out[sortedInd[i-1]];
            else
                out[sortedInd[i]] = i;
        }
        
        return out;
    }
};
