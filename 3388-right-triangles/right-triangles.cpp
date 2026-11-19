class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      
        long long ans=0;
        vector<int> row(n);
        vector<int> col(m);
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    val++;
                }

            }
            row[i]=val;
        }
          for(int i=0;i<m;i++){
            int val=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    val++;
                }

            }
            col[i]=val;
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( grid[i][j]==1){
                    ans+=(col[j]-1)*(row[i]-1);
                }
            }
        }
        return ans;
        
    }
};