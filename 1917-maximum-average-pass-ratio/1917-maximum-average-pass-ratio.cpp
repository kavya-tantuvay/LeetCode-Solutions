using pp=pair<double,int>;
class Solution {
public:
    double passratio(int a,int b){
        return static_cast<double>(a) / static_cast<double>(b);
    }
    double gain(int a,int b){
         return (static_cast<double>(a + 1) / static_cast<double>(b + 1)) 
         - (static_cast<double>(a) / static_cast<double>(b));
    }
    double maxAverageRatio(vector<vector<int>>& classes, int k) {
        int n=classes.size();
        double ans;
        double sum=0;
        priority_queue<pp>maxh;
        for(int i=0;i<n;i++){
            double pr=gain(classes[i][0],classes[i][1]);
            maxh.push({pr,i});
        }
        for(int i=0;i<k;i++){
            auto it=maxh.top();
            maxh.pop();
            double req=gain(++classes[it.second][0],++classes[it.second][1]);
            maxh.push({req,it.second});
        }
        for(int i=0;i<n;i++){
            sum+=passratio(classes[i][0],classes[i][1]);
        }
       
        ans=sum/(double)n;
        return ans;
    }
};