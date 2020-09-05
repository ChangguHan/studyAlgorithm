#include <iostream>
#include <cmath>

using namespace std;

#define MAX 30

int N,M;
int weight[MAX];
int seek[7];
bool rs[MAX+1][MAX*500+1];

void dfs(int cnt, int w) {
    if(cnt > N) return;
    if(rs[cnt][w] == true) return;

    rs[cnt][w] = true;

    dfs(cnt+1, w);
    dfs(cnt+1, w+weight[cnt]);
    dfs(cnt+1, abs(w-weight[cnt]));
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++ ) {
        cin >> weight[i];
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> seek[i];
    }

    dfs(0,0);
    
    for (int i=0; i<M; i++) {
        if(seek[i] > N*500) cout << "N ";
        else if(rs[N][seek[i]]) cout << "Y ";
        else cout << "N ";
        
    }
    cout << endl;


    return 0;
}