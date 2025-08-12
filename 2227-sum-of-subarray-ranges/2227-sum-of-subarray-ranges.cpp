class Solution {
public:
    vector<int>findnse(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop(); 
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findnle(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nle(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop(); 
            }
            nle[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nle;
    }
    vector<int>findpsee(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>psee(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop(); 
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    vector<int>findplee(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>plee(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop(); 
            }
            plee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return plee;
    }
    long long sosmin(vector<int>&nums){
        int n=nums.size();
        long long ans=0;
        vector<int>nse=findnse(nums);
        vector<int>psee=findpsee(nums);
        for(int i=0;i<n;i++){
            long long left=i-psee[i];
            long long right=nse[i]-i;
            ans+=left*right*(long long)nums[i];
        }
        return ans;
    }
    long long sosmax(vector<int>&nums){
        int n=nums.size();
        long long ans=0;
        vector<int>nle=findnle(nums);
        vector<int>plee=findplee(nums);
        for(int i=0;i<n;i++){
            long long left=i-plee[i];
            long long right=nle[i]-i;
            ans+=left*right*(long long)nums[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sosmax(nums)-sosmin(nums);
    }
};