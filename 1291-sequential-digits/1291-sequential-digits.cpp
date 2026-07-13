class Solution {
public:
    int digit(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    bool valid(int n){
        int prev=n%10;
            n/=10;
            while(n>0){
                int d=n%10;
                if(d!=prev-1)return false;
                prev=d;
                n/=10;
            }
            return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        int d1=digit(low);
        int d2=digit(high);
        if(d1==9){
            if(low<=123456789 && high>=123456789)return {123456789};
            else return {};
        }
        if(d1>9)return {};
        if(d2==2 && high<12)return {};
        if(high>123456789){
            high=123456789;
            d2=9;
        }
        
        vector<int>ans;
        unordered_map<int,pair<int,int>>mpp;
        mpp[2]={12,89};
        mpp[3]={123,789};
        mpp[4]={1234,6789};
        mpp[5]={12345,56789};
        mpp[6]={123456,456789};
        mpp[7]={1234567,3456789};
        mpp[8]={12345678,23456789};
        mpp[9]={123456789,123456789};
        int l,h;
        l=mpp[d1].first;
        int cnt1;
        if(d1>2)cnt1=mpp[d1].first-mpp[d1-1].first;
        if(d1==2)cnt1=11;
        while(l<low){
            l+=cnt1;
            if(l>mpp[d1].second)break;
        }
        if(l==mpp[d1].first || valid(l))low=l;
        else low=mpp[d1+1].first;
        h=mpp[d2].second;
        int cnt2;
        if(d2>2)cnt2=mpp[d2].first-mpp[d2-1].first;
        if(d2==2)cnt2=11;
        while(h>high){
            h-=cnt2;
        }
        if(h==mpp[d2].first || valid(h))high=h;
        else high=mpp[d2-1].second;
        if(d2==9 && high<123456789)high=mpp[8].second;
        int dd=digit(low);
        int cnt3;
        while(low<=high){
            ans.push_back(low);
            if(dd==2)cnt3=11;
            else cnt3=mpp[dd].first-mpp[dd-1].first;
            if(low+cnt3<=mpp[dd].second)low+=cnt3;
            else{
                dd+=1;
                low=dd<=9?mpp[dd].first:1e9+1;
            }
        }
        return ans;
    }
};