/*
 BOJ 19238
 승객고를때 : 손님까지의 최단거리가 짧은 승객 >> bfs
    여러명일때 열번호가 가장 작은 승객
 
 각각 BFS로 최단거리 손님 구함 >> O(N^2)
 목적지까지 이동, BFS O(N^2)
 이걸 M번 반복
 
 O(M+N^2)
 
 */


#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int, int> ti4;

int map[30][30];
int customerMap[30][30];
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};
int y,x;
int N,M,F;
pair<int, int> findCustomer(vector<ti4> customer) {
    bool chk[30][30];
    fill(&chk[0][0], &chk[29][30], -0);
    fill(&customerMap[0][0], &customerMap[29][30], -1);
    for(int i=0; i<customer.size(); i++) {
        int a,b,c,d; tie(a,b,c,d) = customer[i];
        customerMap[a][b] =i;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    chk[y][x] = 1;
    int cnt=0;
    while(!q.empty()) {
        cnt++;
        int qsize = q.size();
        while(qsize--) {
            auto eq = q.front(); q.pop();
            int ey = eq.first;
            int ex = eq.second;
            
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny >=0 && ny < N && nx >=0 && nx < N) {
                    if(map[ny][nx] ==1) continue;
                    if(chk[ny][nx]) continue;
                    if(customerMap[ny][nx] != -1) {
                        return make_pair(customerMap[ny][nx],cnt);
                    }
                    chk[ny][nx]=1;
                    q.push(make_pair(ny, nx));
                    
                }
            }
        }
        
        
    }
    return make_pair(-1, -1);
}

int chkDistance(vector<ti4> customer) {
    bool chk[30][30];
    fill(&chk[0][0], &chk[29][30], -0);
    fill(&customerMap[0][0], &customerMap[29][30], -1);
    for(int i=0; i<customer.size(); i++) {
        int a,b,c,d; tie(a,b,c,d) = customer[i];
        customerMap[c][d] =i;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    chk[y][x] = 1;
    int cnt=0;
    while(!q.empty()) {
        cnt++;
        int qsize = q.size();
        while(qsize--) {
            auto eq = q.front(); q.pop();
            int ey = eq.first;
            int ex = eq.second;
            
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny >=0 && ny < N && nx >=0 && nx < N) {
                    if(map[ny][nx] ==1) continue;
                    if(chk[ny][nx]) continue;
                    if(customerMap[ny][nx] != -1) {
                        return cnt;
                    }
                    chk[ny][nx]=1;
                    q.push(make_pair(ny, nx));
                    
                }
            }
        }
        
        
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> F;
    
    
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            cin >> map[j][i];
        }
    }
    
    cin >> y >>x;
    y--; x--;
    vector<ti4> customer;
    for(int i=0; i<M; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        customer.push_back(make_tuple(a-1,b-1,c-1,d-1));
    }
    int complete=0;
    while(complete != M) {
        // 최단거리 구하기
        pair<int, int> es =findCustomer(customer);
        int ei = es.first;
        int ecnt = es.second;
        
        // 갔다 치고 기름 소비
        // 이떄 기름 0보다 작으면 종료
        F -= ecnt;
        if(F<0) return -1;
        
        vector<ti4> alonecustomer;
        alonecustomer.push_back(customer[ei]);
        int a,b,c,d; tie(a,b,c,d) = customer[ei];
        y=a;
        x=b;

        int ns = chkDistance(alonecustomer);
        F -= ns;
        if(F<0) return -1;
        else F+= ns * 2;
        
        
        y = c;
        x = d;
        
        // 다끝나고 현재손님 없애기
        customer.erase(customer.begin()+ei);
        complete++;
    }
    
    
    cout << F << '\n';
    
    
    
    
    return 0;
}

