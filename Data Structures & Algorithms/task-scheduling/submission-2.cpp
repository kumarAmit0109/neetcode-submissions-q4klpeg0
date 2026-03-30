class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // maintain the freq map
        vector<int>count(26, 0);
        for(char task : tasks){
            count[task - 'A']++;
        }

        // create a task list which stores the <freq,indx> of the tasks
        vector<pair<int,int>>arr;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                //emplace_back adds a new element at the end of the vector, but it 
                // constructs the element directly inside the vector instead of creating 
                // it first and then copying it.
                // arr.push_back(make_pair(count[i], i));
                // in this make_pair(count[i], i) creates a pair object. and then 
                // That object is copied or moved into the vector. 
                arr.emplace_back(count[i], i);
            }
        }

        // intitially time is 0 , and processed track what task executed at 
        // each unit of time
        int time = 0;
        vector<int>processed;
        while(!arr.empty()){
            // maxi will store the index of the best task in arr
            int maxi = -1;
            for(int i = 0; i < arr.size(); i++){
                bool ok = true;
                for(int j = max(0, time - n); j < time; j++){
                    // checks whether the task was executed in the last n time units.
                    if(j < processed.size() && processed[j] == arr[i].second){
                        ok = false;
                        break;
                    }
                }
                // If the task is cooling down → skip it and check the next task.
                if(!ok){
                    continue;
                }
                // choose the task with the largest remaining count
                if(maxi == -1 || arr[maxi].first < arr[i].first){
                    maxi = i;
                }
            }
            time++;
            // curr stores the task executed at this time
            int curr = -1;
            // if task exists then execute it by reducing count, adding to 
            // processed list , if count reduces to zero then remove it from arr list
            if(maxi != -1){
                curr = arr[maxi].second;
                arr[maxi].first--;
                if(arr[maxi].first == 0){
                    arr.erase(arr.begin() + maxi);
                }
            }
            processed.push_back(curr);
        }
        return time;
    }
};
