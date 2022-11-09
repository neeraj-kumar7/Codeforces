#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unordered_map<char, int> hashMap;
        for(int i = 0; i < 4; i++){
            char c;
            cin >> c;
            hashMap[c]++;
        }
        cout <<  hashMap.size()-1 << endl;
    }
    return 0;
}