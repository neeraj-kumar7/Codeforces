#include <bits/stdc++.h>
using namespace std;

int numOfOperations(vector<int> &p, int n, int k){
    int count = 0;

    for(int i = 0; i < k; i++){
        if(p[i] > k)
            count++;
    }
    return count;
}


int main(){
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> p(n,0);
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            p[i] = num;
        }

        ans.push_back(numOfOperations(p, n, k));
    }
    for(int i : ans)
        cout << i << endl;

    return 0;
}