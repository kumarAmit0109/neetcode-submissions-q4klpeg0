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

    bool isConnected(int u, int v){
        return findParent(u) == findParent(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // create a dsu of size row*cols + 1 , one extra becoz of dummy node
        // which denotes the safe component node
        DSU dsu(rows * cols + 1);
        vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // use to convert the 2d positions into 1d position which are used in 
        // dsu initialization
        auto index = [&](int r, int c){
            return r * cols + c;
        };

        // now for every border nodes make its union with dummy node, so we can mark it safer one
        // here rows*Cols serves as the dummy node

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                // if value is not equal to 'O' then simply continue
                if(board[r][c] != 'O'){
                    continue;
                }
                // for borders value simply union with dummy node so we can 
                // keep track of cells which are safe during transformation
                if((r == 0 || r == rows-1) || (c == 0 || c == cols-1)){
                    dsu.unionBySize(rows*cols, index(r,c));
                }else{
                    // in other case expolre all directions nd union the every connected
                    // 'O' cells
                    for(auto dir : directions){
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        if(board[nr][nc] == 'O'){
                            dsu.unionBySize(index(r, c), index(nr, nc));
                        }
                    }
                }
            }
        }

        // now traverse the grid again if the cell is 'O' but not connected to
        // dummy node, simply flip it to 'X'
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == 'O'){
                    if(!dsu.isConnected(index(r, c), rows*cols)){
                        board[r][c] = 'X';
                    }
                }
            }
        }
    }
};
