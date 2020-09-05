#include <iostream>

#define MAX 20
using namespace std;

int N,S;
int gd[MAX];
int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i=0; i<N; i++) cin >> gd[i];

    for(int i=1; i<(1<<N); i++) {
        int tmp = i;
        int rs=0;
        for (int j=0; j<N; j++) {
            if(tmp%2==1) rs+=gd[j];
            tmp /= 2;
        }
        if(rs == S) cnt++;
    }

    cout << cnt;

    return 0;
}