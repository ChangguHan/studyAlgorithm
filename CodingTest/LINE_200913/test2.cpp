
// 모두 다 한번씩 돌면 10^10
// 너무 많으니까, 중간에 짜르는걸로 한번 해보자

#include <iostream>
#include <fstream>

using namespace std;

int map[20][20];
bool chk[20];
int N, rs;
int minv;
void dfs(int dep, int st)
{
    if (dep == N)
    {
        minv = min(rs, minv);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (chk[i])
            continue;
        if (st == i)
            continue;
        chk[i] = 1;
        rs += map[st][i];
        if (rs <= minv)
            dfs(dep + 1, i);
        rs -= map[st][i];
        chk[i] = 0;
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // // cin >> N;
    // ifstream in("in.txt");
    // in >> N;
    // minv=1e8;

    // for(int j=0; j<N; j++) {
    //     for(int i=0; i<N; i++) {
    //         // cin >> map[j][i];
    //         in >> map[j][i];
    //     }
    // }
    // for(int i=0; i<N; i++) {
    //     rs = 0;
    //     fill(chk, chk+N+1, false);
    //     dfs(0,i);
    // }
    cout << 1 << '\n';
    cout << 1 << '\n';
    // ifstream in("in.txt");
    // in >> N;
    // cout << N << '\n';
    cout << 1 << '\n';
    cout << 1 << '\n';

    return 0;
}