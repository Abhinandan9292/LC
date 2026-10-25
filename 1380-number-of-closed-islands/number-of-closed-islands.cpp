class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int ii,int jj){
        if(ii<0 || jj<0|| jj>grid[0].size()||ii>grid.size()){
            return;
        }
         visited[ii][jj]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int newi=ii+dx[i];
            int newj=jj+dy[i];
            if(newi<grid.size() && newj<grid[0].size() && !visited[newi][newj] && grid[newi][newj]==0){
               
                dfs(grid,visited,newi,newj);
            }

        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
             if(!visited[i][0] && grid[i][0]==0){
                   
                    dfs(grid,visited,i,0);

                }
        }
          for(int i=0;i<n;i++){
             if(!visited[i][m-1] && grid[i][m-1]==0){
                   
                    dfs(grid,visited,i,m-1);

                }
        }
          for(int i=0;i<m;i++){
             if(!visited[0][i] && grid[0][i]==0){
                   
                    dfs(grid,visited,0,i);

                }
        }
         for(int i=0;i<m;i++){
             if(!visited[n-1][i] && grid[n-1][i]==0){
                   
                    dfs(grid,visited,n-1,i);

                }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    ans++;
                    dfs(grid,visited,i,j);

                }
            }
        }
        return ans;
    }
};