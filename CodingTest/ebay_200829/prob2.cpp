// DP로 하면 될것같은데
// Sn = min(Sn-x[0], Sn-x[1],...)+1
// O(N*N*X)
// 1e10
#include <iostream>

#include <vector>
using namespace std;

int solution(int num, vector<int> cards) {
    int dp[10010];
    fill(dp, dp+10010, -1);
    for(int i=1; i<=num; i++) {
        bool sw = false;
        for(int x : cards) {
            if(x==i) {
                sw = true;
                dp[i] = 1;
                break;
            }
        }
        if(sw) continue;

        int minv = 10010;
        for (int x : cards) {
            if(i-x<=0) break;
            if(dp[i-x]<0) continue;
            minv = min(minv, dp[i-x]+1);
        }
        if(minv!=10010) dp[i] = minv;

    }
    return dp[num];
}

int main() {
    // vector<int> ip;
    // ip.push_back(1);
    // ip.push_back(2);
    // ip.push_back(5);

    vector<int> ip;
    ip.push_back(3);
    // ip.push_back(2);
    // ip.push_back(5);

    cout << solution(4,ip) << '\n';
    return 0;
}