class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int ce=0,co=0;
        int n=nums1.size();
        int so=1e9;
        int se=1e9;
        for(auto i:nums1){
            if(i%2==0){
                 ce++;
                 se=min(i,se);
            }
            else {
                co++;
                so=min(i,so);
            }
        }
        if(ce==n || co==n)return true;
        if(so<se)return true;
        return false;
    }
};