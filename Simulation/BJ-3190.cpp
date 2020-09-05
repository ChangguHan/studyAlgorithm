// while 으로 게임 끝나는 조건, cnt 세기

#include <iostream>
#include <deque>

using namespace std;

char map[100][101];
char direc[10001];

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int d = 0;
int t=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K, L;
    deque< pair<int, int> > q;
    q.push_back(make_pair(0,0));

    cin >> N >> K;
    fill(&map[0][0], &map[99][101], '.');
    map[0][0] = 's';
    while(K--) {
        int x,y;
        cin >> y >> x;
        map[y-1][x-1] = 'a';
    }
    cin >> L;
    while (L--) {
        int t;
        char ed;
        cin >> t >> ed;
        direc[t] = ed;
    }

    while (1) {
        t++;
        
        int qsize = q.size();
        

        int fy = q.front().first;
        int fx = q.front().second;
        int fny = fy + dy[d];
        int fnx = fx + dx[d];
        if(fny<0 || fny>=N || fnx<0 || fnx>=N) break;
        if(map[fny][fnx] == 's') break;
        
        if(map[fny][fnx] != 'a') {
            map[q.back().first][q.back().second] = '.';
            q.pop_back();
        }
        q.push_front(make_pair(fny,fnx));
        map[fny][fnx] = 's';
        
        if(direc[t] == 'L') {
            if(d==0) d=3;
            else d--;
        }
        else if(direc[t] == 'D') {
            if(d==3) d=0;
            else d++;
        }

    }

    cout << t;



    return 0;
}