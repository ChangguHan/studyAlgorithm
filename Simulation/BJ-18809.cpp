// 백트래킹으로 조합구해서
// 각각 해보는 수밖에

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M,G,R;
int map[60][60];
int mapb[60][60];
vector<pair<int, int> > v;
int rs=0;
vector<pair<int, int> > rv;
vector<pair<int, int> > gv;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void flower() {
    int cnt=0;
    // 각 꽃 심기
    queue<pair<int, int> > rq;
    queue<pair<int, int> > gq;
    for (int j=0; j<N; j++) for (int i=0; i<M; i++) mapb[j][i] = map[j][i];
    for(auto x : rv) {
        mapb[x.first][x.second] = 4;
        rq.push(x);
    }
    for(auto x : gv) {
        mapb[x.first][x.second] = 3;
        gq.push(x);
    }
    
    
    while(!(rq.empty() && gq.empty())) {
        int gqsize = gq.size();
        while(gqsize--) {
            auto egq = gq.front(); gq.pop();
            int egy = egq.first;
            int egx = egq.second;
            if(mapb[egy][egx] == 8) continue;
            for (int k=0; k<4; k++) {
                int ngy = egy + dy[k];
                int ngx = egx + dx[k];
                if(ngy>=0 && ngy<N && ngx>=0 && ngy<M) {
                    if(mapb[ngy][ngx] == 1 || mapb[ngy][ngx] == 2) {
                        mapb[ngy][ngx] = 9;
                        // gv.push_back(make_pair(ngy, ngx));
                        gq.push(make_pair(ngy, ngx));
                    }

                }
            }
        }
        int rqsize = rq.size();
        while(rqsize--) {
            auto erq = rq.front(); rq.pop();
            int ery = erq.first;
            int erx = erq.second;
            for (int k=0; k<4; k++) {
                int nry = ery + dy[k];
                int nrx = erx + dx[k];
                if(nry>=0 && nry<N && nrx>=0 && nry<M) {
                    if(mapb[nry][nrx] == 9) {
                        cnt++;
                        mapb[nry][nrx] = 8;
                    }
                    else if(mapb[nry][nrx] == 1 || mapb[nry][nrx] == 2) {
                        mapb[nry][nrx] = 4;
                        rq.push(make_pair(nry, nrx));
                    }

                }
            }
        }
        for (int j=0; j<N; j++) {
            for (int i=0; i<M; i++) {
                if(mapb[j][i] == 9) mapb[j][i] = 3;
            }
        }

    }
    rs = max(rs, cnt);
    
}


void cal() {
    if(rv.size() == R) {
        gv.clear();
        for (auto x : v) {
            vector<pair<int,int> >::iterator it = find(rv.begin(), rv.end(), x);
            if(it==rv.end()) gv.push_back(x);
        }
        flower();
        return;
    }
    int idx=-1;
    if(rv.size() !=0) {
        auto x = rv.back();
        for (int i=0; i<v.size(); i++) {
            if(v[i] == x) {
                idx = i;
                break;
            }
        }
    }
    
    // v중에서 조합으로 뽑기
    for (int i= idx+1; i<v.size(); i++) {
        rv.push_back(v[i]);
        cal();
        rv.pop_back();
    }

}

void dfs(int y, int x) {
    // 먼저 심는칸 경우 구하고, 그 안에 들어가서 빨강이냐, 초록이냐 나누자
    if(v.size() == G+R) {
        cal();
        return;
    }
    
    for (int j=y; j<N; j++) {
        for (int i=x; i<M; i++) {
            if(map[j][i] == 2) {
                v.push_back(make_pair(j,i));
                dfs(j,i+1);
                v.pop_back();
            }
        }
        x=0;
    }



}

int main() {
    cin >> N >> M >> G >> R;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            cin >> map[j][i];
            mapb[j][i] = map[j][i];
        }
    }


    dfs(0,0);


    cout << rs << '\n';
    return 0;
}