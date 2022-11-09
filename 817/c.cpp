#include <bits/stdc++.h>
using namespace std;

vector<int> findPoints(vector<vector<string>>& words, 
                        unordered_map<string, int>& freqMap, int n){

    vector<int> points(3, 0);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){

            int frequency = freqMap[words[i][j]];
            if(frequency == 2)
                points[i] += 1;
            else if(frequency == 3)
                points[i] += 0;
            else
                points[i] += 3;
        }
    }

    
    return points;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<string>> words;
        unordered_map<string,int> freqMap;
        for(int i = 0; i < 3; i++){
            vector<string> v;
            for(int j = 0; j < n; j++){
                string s;
                cin >> s;
                
                v.push_back(s);
                freqMap[s]++;
            }
            words.push_back(v);
        }
            
        vector<int> points = findPoints(words, freqMap, n);

        for(int i : points)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}