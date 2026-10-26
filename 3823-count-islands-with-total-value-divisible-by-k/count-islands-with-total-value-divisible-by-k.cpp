class Solution {
public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &visited,int ii,int jj,long long &val){
        if(ii<0 || jj<0|| jj>=grid[0].size()||ii>=grid.size()){
            return; 
        }
        val+=grid[ii][jj];
        
         visited[ii][jj]=1;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int newi=ii+dx[i];
            int newj=jj+dy[i];
            if(newi<grid.size() && newj<grid[0].size() && !visited[newi][newj] && grid[newi][newj]!=0){
                
                dfs(grid,visited,newi,newj,val);
            }

        }
 
    }
    int countIslands(vector<vector<int>>& grid, int k) {
          int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        int a=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           
            for(int j=0;j<m;j++){
                 long long val=0;
             if(!visited[i][j] && grid[i][j]!=0){
                   
                    dfs(grid,visited,i,j,val);
                    if(val%k==0){
                        a++;
                    }
                }
            }
        }
        return a;
        
    }
};