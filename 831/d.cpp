#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int k, vector<int>& cards){
    
    int spacesLeft = n*m - 2;
    int toMove = k;

    vector<int> visited(k+1, 0);
    for(int i = 0; i < k; i++){
        visited[cards[i]] = 1;
        if(cards[i] == toMove){
            if(spacesLeft >= 2){
                toMove--;
                while(visited[toMove]){
                    toMove--;
                    spacesLeft++;
                }
            }
            else{
                cout << "TIDAK" << "\n";
                return;
            }
        }
        else{
            spacesLeft--;
        }
    }
    cout << "YA" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> cards(k);
        for(int i = 0; i < k; i++)
            cin >> cards[i];
        solve(n, m, k, cards);
    }
    return 0;
}