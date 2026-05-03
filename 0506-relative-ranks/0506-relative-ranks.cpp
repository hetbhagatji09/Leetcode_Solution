class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n,"");
        int place = 1;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        int key =0;
        while(!pq.empty()){
            key = pq.top().second;

            if(place == 1){
                ans[key] = "Gold Medal";
            } 
            else if (place == 2){
                ans[key] = "Silver Medal";
            }
            else if (place == 3){
                ans[key] = "Bronze Medal";
            }
            else{
                ans[key] = to_string(place);
            }
            place++;
            pq.pop();
            
        }
        return ans;
    }
};