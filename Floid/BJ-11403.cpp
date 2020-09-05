// floid로 풀어보고
// 그래프 탐색으로도 풀어보자

#include <iostream>

using namespace std;

int map[110][110];
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int j=0; j<N; j++)
        for (int i=0; i<N; i++ ) {
            cin >> map[j][i];
        }

    for (int k=0; k<N; k++) {
        for (int j=0; j<N; j++ ) {
            for (int i=0; i<N; i++) {
                if(map[j][k]==1 && map[k][i] == 1) map[j][i] =1;
            }
        }
    }

    for (int j=0; j<N; j++ ) {
        for (int i=0; i<N; i++) {
            cout << map[j][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}