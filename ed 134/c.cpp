#include <bits/stdc++.h>
using namespace std;

void findMinMax(vector<int>& a, vector<int>& b, int n){

    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({a[i], i});
    }

    multiset<int> s;
    for(int i : b)
        s.insert(i);
    
    for(int i = 0; i < n; i++)
        cout << *s.lower_bound(a[i]) - a[i] << " ";
    cout << "\n";

    vector<int> maxi(n);
    for(int i = n-1; i >= 0; i--){
        int element = *s.rbegin();
        maxi[i] = element - a[i];
        s.erase(s.lower_bound(a[i])); 
    }
    for(int i : maxi)
        cout << i << " ";
    cout << endl;

    return;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for(int i = 0; i < n; i++)
            cin >> b[i];

        findMinMax(a, b, n);
    }
    return 0;
}