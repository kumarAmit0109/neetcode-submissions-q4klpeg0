class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>que;
        for(int stone : stones){
            que.push(stone);
        }

        while(que.size()>1){
            int num1 = que.top();
            que.pop();
            int num2 = que.top();
            que.pop();
            if(num1 == num2){
                que.push(0);
            }else{
                que.push(abs(num1 - num2));
            }
        }

        return que.top();
    }
};
