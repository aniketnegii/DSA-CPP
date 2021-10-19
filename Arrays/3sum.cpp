
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int i,j,lo,hi,n=nums.size(),sum;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-2;i++){
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                lo=i+1; hi=n-1; sum=0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        vector<int> temp(3,0);
                        temp[0]=nums[i]; temp[1]=nums[lo]; temp[2]=nums[hi];
                        ans.push_back(temp);
                        while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                        lo++; hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum) lo++;
                    else hi--;
                }
            }
        }
        return ans;
    }
};
