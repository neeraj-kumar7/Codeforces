#include <bits/stdc++.h>
using namespace std;

string Lshapes(vector<vector<int>>& grid, int n, int m){

    
    vector<vector<int>> visited(n, vector<int> (m, 0));
    vector<int> dx = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<int> dy = {0, 0, -1, 1, -1, -1, 1, 1};
    int islands = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] or !grid[i][j])
                continue;
            
            int islandSize = 1;
            queue<pair<int, int>> q;
            q.push({i, j});
            visited[i][j] = 1;

            while(!q.empty()){
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for(int dir = 0; dir < 8; dir++){
                    int newx = x + dx[dir], newy = y + dy[dir];
                    
                    if(newx >= 0 and newx < n and newy >= 0 and newy < m){
                        if(!visited[newx][newy] and grid[newx][newy]){
                            
                            visited[newx][newy] = 1;
                            islandSize++;
                            q.push({newx, newy});
                        }
                    } 
                    
                }

            }

            if(islandSize == 3)
                islands++;
            else
                return "NO";
        }
    }
    //cout << islands << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!grid[i][j])
                continue;
            
            if((i-1 >= 0) and (j-1 >= 0) and (grid[i-1][j] + grid[i][j-1] == 2))
                islands--;
            if((i-1 >= 0) and (j+1 < m) and (grid[i-1][j] + grid[i][j+1] == 2))
                islands--;
            if((j-1 >= 0) and (i+1 < n) and (grid[i][j-1] + grid[i+1][j] == 2))
                islands--;
            if((j+1 < m) and (i+1 < n) and (grid[i][j+1] + grid[i+1][j] == 2))
                islands--;
        }
    }

    return (islands == 0) ? "YES" : "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                if(c == '*')
                    grid[i][j] = 1;
            }
        }
        
        cout << Lshapes(grid, n, m) << "\n";
    }
    return 0;
}