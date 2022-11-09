#include <bits/stdc++.h>
using namespace std;

bool canReach(int n, int m, int sx, int sy, int d){

    int leftBlock = (sy-d <= 1) ? 1 : 0;
    int rightBlock = (sy+d >= m) ? 1 : 0;
    int topBlock = (sx-d <= 1) ? 1 : 0;
    int bottomBlock = (sx+d >= n) ? 1 : 0;

    int blockCount =   topBlock + bottomBlock + 
                        leftBlock + rightBlock;

    if(blockCount >= 3) return false;

    if((leftBlock and topBlock) or (leftBlock and rightBlock) or
        (topBlock and bottomBlock) or (rightBlock and bottomBlock))
        return false;

    return true;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if(canReach(n, m, sx, sy, d))
            cout << n+m-2 << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}