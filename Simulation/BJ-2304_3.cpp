/**
 BOJ 2304
 컨테이너문제
 - 최대값 구한다음에, 최대값까지 왼쪽에서부터 값 추가
 - 오른쪽에서부터 최대값 이전까지 최대값 추가
 */

#include <iostream>

using namespace std;

int map[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int maxv = -1;
    int maxi = -1;
    for(int i=0; i<N; i++) {
        int a,b; cin >> a >> b;
        map[a] = b;
        if(map[a] > maxv) {
            maxv = map[a];
            maxi = a;
        }
    }
    int rs=0;
    int mv = -1;
    for(int i=0; i<=maxi; i++) {
        if(map[i] > mv) mv = map[i];
        rs += mv;
    }
    mv = -1;
    for(int i=1000; i>maxi; i--) {
        if(map[i] > mv) mv = map[i];
        rs += mv;
    }
    
    cout << rs << '\n';
    return 0;
}
