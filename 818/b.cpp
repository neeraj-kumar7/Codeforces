#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& table, int n, int k, int r, int c, 
        unordered_set<int>& rowVisit, unordered_set<int>& colVisit){
    
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    vector<int> dr = {-k, k, 0, 0};
    vector<int> dc = {0, 0, -k, k};

    q.push({r, c});
    visited[r][c] = 1;
    table[r][c] = 'X';
    rowVisit.insert(r);
    colVisit.insert(c);

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int row = p.first;
        int col = p.second;
        for(int dir = 0; dir < 4; dir++){
            int newRow = row + dr[dir];
            int newCol = col + dc[dir];
            if(newRow >= 0 and newRow < n and newCol >= 0 and newCol < n){
                if(!visited[newRow][newCol]){

                    rowVisit.insert(newRow);
                    colVisit.insert(newCol);
                    visited[newRow][newCol] = 1;
                    table[newRow][newCol] = 'X';
                    q.push({newRow, newCol});
                }
            }
        }

    }

    return;
    
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, r, c;
        cin >> n >> k >> r >> c;

        vector<vector<char>> table(n, vector<char> (n, '.'));
        unordered_set<int> rowVisit, colVisit;
        bfs(table, n, k, r-1, c-1, rowVisit, colVisit);

        for(int i = 0; i < n; i++){
            if(rowVisit.find(i) == rowVisit.end()){
                for(int j = 0; j < n; j++){
                    if(colVisit.find(j) == colVisit.end()){
                        bfs(table, n, k, i, j, rowVisit, colVisit);
                        break;
                    }
                }
            }
        }

        for(auto i : table){
            for(char c : i)
                cout << c;
            cout << "\n";
        }
    }
    return 0;
}