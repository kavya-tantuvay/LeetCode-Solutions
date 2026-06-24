#define ll long long int
typedef  vector<vector<ll>> matrix;

class Solution {
public:
    const int N=1e9+7;
    matrix mul(matrix a,matrix b){
        matrix res=matrix (a.size(),vector<ll>(b[0].size()));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b[0].size();j++){
                res[i][j]=0;
                for(int k=0;k<a.size();k++){
                    res[i][j]+=(a[i][k]*1LL * b[k][j])%N;
                    res[i][j]%=N;
                }
            }
        }
        return res;
    }
    matrix mat_power(matrix a,ll p){
        matrix res=matrix(a.size(),vector<ll>(a.size(),0));
        for(int i=0;i<a.size();i++)res[i][i]=1;
        while(p){
            if(p&1)
                res=mul(res,a);
            a=mul(a,a);
            p/=2;
        }
        return res;

    }
    int zigZagArrays(int n, int l, int r) {
        matrix base(r+1, vector<ll>(1,0));
        for(int i=l;i<=r;i++)base[i][0]=1;
        matrix inc(r+1, vector<ll>(r+1, 0));
        matrix dec(r+1, vector<ll>(r+1, 0));
        for(int i=l;i<=r;i++){
            for(int j=l;j<i;j++)
                inc[i][j]=1;
            for(int j=i+1;j<=r;j++)
                dec[i][j]=1;
        }
        n--;
        matrix inc_dec = mul(inc, dec);
        matrix dec_inc = mul(dec, inc); 
        matrix res1 = mul(mat_power(inc_dec, n/2), base);
        matrix res2 = mul(mat_power(dec_inc, n/2), base);
        if(n&1){
            res1 = mul(dec, res1);
            res2 = mul(inc, res2);
        }
        ll ans=0;
        for(int i=l;i<=r;i++){
            ans = (ans + res1[i][0])%N;
            ans = (ans + res2[i][0])%N;
        }
        return ans;

    }
};