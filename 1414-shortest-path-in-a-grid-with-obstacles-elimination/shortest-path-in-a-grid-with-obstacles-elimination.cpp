class Solution {
public:
    int ans;
    vector<vector<vector<int>>> dp;

    void solve(int i,int j,int n,int m,vector<vector<int>> &grid,int k,int steps){
        if(i>=n || i<0 || j<0 || j>=m){
            return;
        }

        if(steps + (n-1-i) + (m-1-j) >= ans){
            return;
        }

        if(steps >= dp[i][j][k]){
            return;
        }

        dp[i][j][k] = steps;

        if(i==n-1 && j==m-1){
            ans = steps;
            return;
        }

        int nk;

        if(j<m-1){
            nk = k;
            if(grid[i][j+1]==1) nk--;
            if(nk>=0)
                solve(i,j+1,n,m,grid,nk,steps+1);
        }

        if(j>0){
            nk = k;
            if(grid[i][j-1]==1) nk--;
            if(nk>=0)
                solve(i,j-1,n,m,grid,nk,steps+1);
        }

        if(i<n-1){
            nk = k;
            if(grid[i+1][j]==1) nk--;
            if(nk>=0)
                solve(i+1,j,n,m,grid,nk,steps+1);
        }

        if(i>0){
            nk = k;
            if(grid[i-1][j]==1) nk--;
            if(nk>=0)
                solve(i-1,j,n,m,grid,nk,steps+1);
        }
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        ans = INT_MAX;
        dp.assign(n,vector<vector<int>>(m,vector<int>(k+1,INT_MAX)));

        solve(0,0,n,m,grid,k,0);

        return ans==INT_MAX ? -1 : ans;
    }
};