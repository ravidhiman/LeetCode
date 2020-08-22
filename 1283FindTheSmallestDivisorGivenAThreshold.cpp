class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int max_elem = *max_element(nums.begin(),nums.end());
        
        int s = 1;
        int e = max_elem;
        int ans = e;
        
        while(s<=e)
        {
            int mid = (s+e)/2;
            
            int sum = 0;
            for(int i=0;i<nums.size();i++)
            {
                sum += ceil(((float(nums[i])/mid)));
            }
            
            if(sum > threshold)
            {
                s = mid+1;

            }
            else
            {
                ans = mid;
                e = mid-1;
            }
        }
        return ans;
    }
};
