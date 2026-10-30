class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});

        }
        if(n==1){
            return 0;
        }
        
    priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> q;
  vector<vector<int>> d(n, vector<int>(k + 1, INT_MAX));
     q.push({0, 0, 1});

d[0][1] = 0;
      
        while(!q.empty()){
           auto [dis, node, count] = q.top();
q.pop();
            if (dis != d[node][count]) continue;
            char c = labels[node];

            for(auto xx:adj[node]){
               
                int newnode=xx.first;
                int diss=xx.second;
                 int newcount=count;
                char newc=labels[newnode];

                if(newc==c){
                    newcount++;
                }
                else{
                    newcount=1;
                }
                if( newcount<=k && dis+diss<d[newnode][newcount] ){
                    q.push({dis + diss, newnode, newcount});
                    d[newnode][newcount]=diss+dis;
                }
            }

        }
        int ma=INT_MAX;
        for(auto x:d[n-1]){
           ma=min(ma,x);
        }
        if(ma==INT_MAX){
            return -1;
        }
        return ma;
    }
};