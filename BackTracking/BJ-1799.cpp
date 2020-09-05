// 백트., 마찬가지로 체크

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > v;
int N;
int map[20][20];
int maxv=0;
bool chk(int y, int x) {
    int ny = y;
    int nx = x;
    // 왼쪽 위로
    while(1){
        ny--; nx--;
        if(!(ny>=0 && nx>=0)) break;
        if(map[ny][nx] == 2) return 0;
    }
    ny = y; nx=x;
    while(1){
        ny--; nx++;
        if(!(ny>=0 && nx<N)) break;
        if(map[ny][nx] == 2) return 0;
    }
    return 1;

}
void dfs(int y, int x) {
    maxv = max(maxv, (int)v.size());
    for (int j=y; j<N; j++) {
        for (int i=x+1; i<N; i++) {
            if(map[j][i] == 1) {
                // 놓을수 있으면
                if(chk(j,i)) {
                    v.push_back(make_pair(j,i));
                    map[j][i] = 2;
                }
                else continue;
                dfs(j,i);
                v.pop_back();
                map[j][i] = 1;

            }
            
        }
        x=-1;
    }
    
    return;

    
}
int main() {
    cin >> N;
    for (int j=0; j<N; j++)
        for (int i=0; i<N; i++) cin >> map[j][i];

    dfs(0,-1);
    cout << maxv << '\n';
    return 0;
}