// 올라갈때 cnt ++ 비교
// 내려갈때, cnt-2

#include <iostream>
#include <algorithm>

using namespace std;

int N,L;
int map[100][101];
int map2[100][101];
int cnt=0;

void cal(int calMap[100][101]) {
    
    for (int j=0; j<N; j++) {
        int ec = 1;
        for (int i=1; i<N; i++) {
            if(calMap[j][i] == calMap[j][i-1]+1) {
                if(ec >= L) {
                    ec=1;
                } else  break;
            } else if (calMap[j][i] == calMap[j][i-1]-1) {
                if(ec>=0) ec = -L+1;
                else break;
            } else if (calMap[j][i] == calMap[j][i-1]) {
                ec++;
            } else break;
            if(i==N-1 && ec>=0) cnt++;
        }
        
    }
}

int main() {
    fill(&map[0][0], &map[99][101], -1);
    fill(&map2[0][0], &map2[99][101], -1);
    cin >> N >> L;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
            map2[i][j] = map[j][i];
        }
    }

    cal(map);
    cal(map2);

    cout << cnt << '\n';

    return 0;
}
