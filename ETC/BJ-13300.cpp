// 학년, 남,여 수 채운다음 더해주면될듯

#include <iostream>

using namespace std;

int stud[6][2];
int N,K;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    while(N--) {
        int s,y;
        cin >> s >> y;
        stud[y-1][s]++;
    }
    int rs=0;
    for (int j=0; j<6; j++) {
        for (int i=0; i<2; i++) {
            if(stud[j][i]==0) continue;
            rs += (stud[j][i]-1)/K+1;

        }
    }

    cout << rs << '\n';

    return 0;
}