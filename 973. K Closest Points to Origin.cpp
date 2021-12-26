//Optimal Solution
class Solution {
public:
    //TC O(nlogk)
    //SC O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> ans;
        priority_queue<vector<int>> pq; //{dist,x,y}
        for(auto& p: points){
            int x=p[0], y=p[1];
            int curr=pow(x,2)+pow(y,2);
            if(pq.size()<k){
                pq.push({curr,x,y});
            }
            else if(pq.top()[0]>curr){
                pq.pop();
                pq.push({curr,x,y});
            }
        }
        
        while(!pq.empty()){
            auto tp=pq.top();pq.pop();
            ans.push_back({tp[1], tp[2]});
        }
        return ans;
    }
};

//Method 2
class Solution {
public:
    //TC O(nlogn)
    //SC O(1)
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
            return squaredDistance(a) < squaredDistance(b);
        });
        
        // Return the first k elements of the sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

//Method 3
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> ans;
        vector<vector<int>> dist;
        for(int i=0;i<n;i++){
            int curr=pow(points[i][0],2)+pow(points[i][1],2);
            dist.push_back({curr,points[i][0],points[i][1]});
        }
        sort(dist.begin(),dist.end());
        for(int i=0;i<k;i++){
            ans.push_back({dist[i][1],dist[i][2]});
        }
        return ans;
    }
};
