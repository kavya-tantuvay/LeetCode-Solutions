class TaskManager {
public:
    struct cmp{
        bool operator()(const pair<int, int>&a, const pair<int, int>&b)const{
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first <b.first;

        }
    };
    unordered_map<int, pair<int, int>> tasktouser;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> globalheap;
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(auto &t : tasks){
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            tasktouser[taskId] = {userId, priority};
            globalheap.push({priority, taskId});
        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        tasktouser[taskId] = {userId, priority};
        globalheap.push({priority, taskId});
        
    }
    
    void edit(int taskId, int newPriority) {
        int userId = tasktouser[taskId].first;
        tasktouser[taskId] = {userId, newPriority};
        globalheap.push({newPriority, taskId});
        
    }
    
    void rmv(int taskId) {
        tasktouser.erase(taskId);
    }
    
    int execTop() {
        while(!globalheap.empty()){
            auto [priority, taskId] = globalheap.top();
            if(tasktouser.count(taskId) && tasktouser[taskId].second == priority){
                int userId= tasktouser[taskId].first;
                tasktouser.erase(taskId);
                return userId;
            }
            globalheap.pop();
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */