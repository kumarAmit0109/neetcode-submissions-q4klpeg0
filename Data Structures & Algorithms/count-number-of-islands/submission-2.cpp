class DSU {
    vector<int> Parent;
    vector<int> Size;
public :
    DSU(int n){
        Parent.resize(n + 1);
        Size.resize(n + 1);

        for(int i = 0; i <= n; i++){
            // initially every one is parent of itself and having size 1
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int findParent(int node){
        if(node != Parent[node]){
            Parent[node] = findParent(Parent[node]);
        }
        return Parent[node];
    }

    bool unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        // if both belongs to same parent then union not possible
        if(pu == pv){
            return false;
        }

        if(Size[pu] < Size[pv]){
            Size[pv] += Size[pu];
            Parent[pu] = pv;
        }else{
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // use union by size to solve this problem
        // initially all the '1' refers to single island if so if we found
        // any '1' so we increase the island count, but if they are mergeable
        // so we have to decrease island count 

        vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int islandsCount = 0;
        // initialize dsu with row*cols nodes
        DSU dsu(rows*cols);

        // use to convert the 2d positions into 1d position which are used in 
        // dsu initialization
        auto index = [&](int r, int c){
            return r * cols + c;
        };

        // strt the dsu algo now
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    islandsCount++;
                    // explore int all direction nd call dsu if the new position
                    // is within range + nd contain '1'
                    for(auto dir : directions){
                        int nr = i + dir.first;
                        int nc = j + dir.second;
                        if((nr >=0 && nr < rows) && (nc >= 0 && nc < cols) && (grid[nr][nc] == '1')){
                            if(dsu.unionBySize(index(i,j), index(nr, nc))){
                                islandsCount--;
                            }
                        }
                    }
                }
            }
        }

        return islandsCount;
    }
};
