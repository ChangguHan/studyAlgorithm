#include <iostream>
#include <string>

#define MAX 50
using namespace std;

int N,M;
char map[MAX+1][MAX+1];
int rs = MAX*MAX;

int check(int y, int x) {
    int cnt=0;
    char fc = map[y][x];
    char sc;
    if(fc == 'W') sc = 'B';
    else sc='W';
    
    for(int j=0; j<8; j++) {
        for (int i=0; i<8; i++) {
            char ec;
            if((j+i)%2 == 0) ec = fc;
            else ec = sc;

            if(map[j+y][i+x] != ec) cnt++;
        }
    }
    return min(64-cnt,cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string input;
    for (int j=0; j<N; j++) {
        cin >> map[j];
    }

    for (int j=0; j<=N-8; j++) {
        for (int i=0; i<=M-8; i++) {
            rs = min(rs, check(j,i));
        }
    }

    
    cout << rs << '\n';
    

    return 0;
}