class Solution {
public:
    int dist(int a,int b){
        return a*a+b*b;
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(auto &it : obstacles){
            st.insert(to_string(it[0]) + "," + to_string(it[1]));
        }
       char cur='N';
       int x=0,y=0;
       unordered_map<char, unordered_map<int, char>> mpp;
        mpp['N'][-1] = 'E';
        mpp['E'][-1] = 'S';
        mpp['S'][-1] = 'W';
        mpp['W'][-1] = 'N';
        mpp['N'][-2] = 'W';
        mpp['W'][-2] = 'S';
        mpp['S'][-2] = 'E';
        mpp['E'][-2] = 'N';
        int maxi=0;
        for(int i:commands){
            if(i==-1 || i==-2){
                cur=mpp[cur][i];
            }
            else{
                if(cur=='N'){
                    for(int j=0;j<i;j++){
                        if(st.count(to_string(x) + "," + to_string(y+1)))break;
                        y++;
                        maxi=max(maxi,dist(x,y));
                    }
                }
                if(cur=='E'){
                    for(int j=0;j<i;j++){
                        if(st.count(to_string(x+1) + "," + to_string(y)))break;
                        x++;
                        maxi=max(maxi,dist(x,y));
                    }
                }
                if(cur=='W'){
                    for(int j=0;j<i;j++){
                        if(st.count(to_string(x-1) + "," + to_string(y)))break;
                        x--;
                        maxi=max(maxi,dist(x,y));
                    }
                }
                if(cur=='S'){
                    for(int j=0;j<i;j++){
                        if(st.count(to_string(x) + "," + to_string(y-1)))break;
                        y--;
                        maxi=max(maxi,dist(x,y));
                    }
                }
            }
        }
        return maxi;
    }
};