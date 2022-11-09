#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;

    string name = "Timur";
    sort(name.begin(), name.end());
    unordered_set<string> set;

    do{
        set.insert(name);
    }while(next_permutation(name.begin(), name.end()));

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(set.find(s) != set.end())
            cout << "YES";
        else
            cout << "NO";

        cout << "\n";
    }
    return 0;
}