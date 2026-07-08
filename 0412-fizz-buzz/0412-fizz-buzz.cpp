class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            int r=i+1;
            if(r%3==0 && r%5==0)ans[i]="FizzBuzz";
            else if(r%3==0)ans[i]="Fizz";
            else if(r%5==0)ans[i]="Buzz";
            else ans[i]=to_string(r);
        }
        return ans;
    }
};