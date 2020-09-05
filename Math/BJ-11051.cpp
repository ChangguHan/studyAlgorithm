#include <iostream>

using namespace std;

int maps[1020][1020];
int main() {
    int N,K;
    cin >> N >> K;
    if(K==0) {
        cout << 1 << '\n';
        return 0;
    }
    for(int j=1; j<=N; j++) {
        for (int i=1; i<=j; i++) {
            if(j==1) maps[j][i] = 1;
            else if(i==1) maps[j][i] = j%10007;
            else if(j==i) maps[j][i] = 1;
            else maps[j][i] = (maps[j-1][i-1] + maps[j-1][i])%10007;
        }
    }

    cout << maps[N][K] << '\n';

    return 0;
}