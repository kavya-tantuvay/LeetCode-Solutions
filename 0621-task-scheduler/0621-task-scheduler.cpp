class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int>maxh;
        for(auto it : mpp){
            maxh.push(it.second);
        }
        int gaps=maxh.top()-1;
        int idle=gaps*n;
        maxh.pop();
        while(!maxh.empty()){
            int f=maxh.top();
            maxh.pop();
            idle-=min(f,gaps);
        }
        if(idle<0)idle=0;
        return tasks.size()+idle;
    }
};