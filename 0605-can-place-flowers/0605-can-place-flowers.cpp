class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        if(m==1)return flowerbed[0]==0&&(n==1 ||n==0) || flowerbed[0]==1&&n==0;
        int cnt=0;
        if(m>=2)if(flowerbed[0]==0 &&flowerbed[1]==0){flowerbed[0]=1;cnt++;}
        for(int i=1;i<m-1;i++){
            if(flowerbed[i]==0 && flowerbed[i+1]!=1 && flowerbed[i-1]!=1){
                flowerbed[i]=1;
                cnt++;   
                }
        }
        if (flowerbed[m-1]==0 && flowerbed[m-2]!=1)cnt++;
        return cnt>=n;
    }
};