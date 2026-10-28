class Solution {
public:
    int minn=INT_MAX;
    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>> &visited,int i,int j,int n,int m,int val){
        if(i==n-1&& j==m-1){
            return val;

        }
        if(visited[i][j][val]!=-1){
            return visited[i][j][val];
        }
   
      
        int right=INT_MAX;
        int left=INT_MAX;
        if(i<n-1){
                 int t=val^grid[i+1][j];
         left=solve(grid,visited,i+1,j,n,m,t);
        }
        if(j<m-1){
              int tt=val^grid[i][j+1];
         right=solve(grid,visited,i,j+1,n,m,tt);
        }
        return visited[i][j][val]=min(left,right);
    }
    int minCost(vector<vector<int>>& grid) {
    int maxi = 0;

for (auto &row : grid) {
    for (int x : row) {
        maxi = max(maxi, x);
    }
}

int MAX_XOR = 1;
while (MAX_XOR <= maxi) {
    MAX_XOR *= 2;
}
        int n=grid.size();
        int m=grid[0].size();

      vector<vector<vector<int>>> visited(
    n, vector<vector<int>>(m, vector<int>(MAX_XOR, -1))
);
        int val=grid[0][0];
        int ans=solve(grid,visited,0,0,n,m,val);
        return ans;
    }
};