// 백트래킹으루 각 경우의수 나열하면 됨

#include <iostream>

using namespace std;

int N;
int eggs[310][5];
int maxv = 0;
void dfs(int depth) {
    if(depth == N) {
        int cnt=0;
        for (int i=0; i<N; i++) if(eggs[i][0] <=0) cnt++;
        maxv = max(maxv, cnt);
        return;
    }
    // 손에 든것이 깨진경우
    if(eggs[depth][0] <=0) dfs(depth+1);
    else {
        bool sw = true;
        for(int i=0; i<N; i++) {
            if(i== depth) continue;
            if(eggs[i][0] >0) {
                sw = false;
                int origindepth = eggs[depth][0];
                int origini = eggs[i][0];
                eggs[depth][0] -= eggs[i][1];
                eggs[i][0] -= eggs[depth][1];
                dfs(depth+1);
                eggs[depth][0] = origindepth;
                eggs[i][0]  = origini;
            }
            
        }
        if(sw) dfs(depth+1);
    }

    


}
int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> eggs[i][0] >> eggs[i][1];
    }

    dfs(0);

    cout << maxv << '\n';

    return 0;
}