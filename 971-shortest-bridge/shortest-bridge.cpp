class Solution {
public:
    void dfs(int n,int m,vector<vector<int>> &grid,int i,int j,vector<vector<int>> &visited,vector<pair<int,int>> &s ){
        if(i>=n || j>=m ||i<0 ||j<0){
            return;
        }
        visited[i][j]=1;
        s.push_back({i,j});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx<n && newy<m && newx>=0 && newy>=0 && !visited[newx][newy] && grid[newx][newy]==1){
                dfs(n,m,grid,newx,newy,visited,s);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> v;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<pair<int,int>> s;
        bool found=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                dfs(n,m,grid,i,j,visited,s);
                found = true;
           
                break;
                }
            }
            if(found){
                break;
            }
        }
        queue<pair<pair<int,int>,int>> q;
        for(auto x:s){
           q.push({x,0});
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                  int newx=i+dx[k];
            int newy=j+dy[k];
            if(newx<n && newy<m && newx>=0 && newy>=0 && grid[newx][newy]==1 && visited[newx][newy]==0){
                return dis;
            }
            if(newx<n && newy<m && newx>=0 && newy>=0 && !visited[newx][newy] && grid[newx][newy]==0){
                visited[newx][newy] = 1;
              q.push({{newx,newy},dis+1});
            }
            }


        }
        return 0;
        

    }
};