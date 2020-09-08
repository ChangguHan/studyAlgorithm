// 간선이 하나야
// 위상정렬인가

// 위상정렬중에, 다른 조건이 들어갔는데
// 이 조건을 어떻게 반영해야할까

// 우선 위상정렬 구현해보자

// 위상정렬 O(V+E)
// 

#include <iostream>


#include <string>
#include <vector>
#include <queue>

using namespace std;

// vector<int > adj[200010];
// bool chk[200010];
// int pre[200010];
// int nxt[200010];

// chk가 있긴 있어야돼

vector<int > adj[200];
bool chk[200];
int pre[200];
int nxt[200];

int preNode[200];

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    
    fill(preNode, preNode+n, -1);
    for(vector<int> x : path) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);

        // tree구조를 따로 만드어줘야하나
        
        preNode[x[1]] = x[0];

    }
    
    fill(pre, pre+n, -1);
    fill(nxt, nxt+n, -1);
    
    for(vector<int> x : order) {
        pre[x[1]] = x[0];
        nxt[x[0]] = x[1];
    }

    // order가 있는경우, 따로 조건을 만들어줘
    queue<int> q;
    q.push(0);
    chk[0]=1;
    vector<int> rs;
    // vector<int> sub;
    int befSize = 0;
    int befNode = 0;
    rs.push_back(0);


    // 다시 돌아오게 하는게 되게 까다롭네
    // 0으로 하면 막혀서 안되고
    // 이전노드로하자니, 그럼 더 이전노드로 돌아가야할수 있으니까


    // 여기서 사이즈가 0이 아닌 이전 노드를 추가해줘야함

    // q.push(preNode[befNode]);
    while(!q.empty()) {
        int eq = q.front(); q.pop();
        
        
        pre[nxt[eq]] = -1;
        
        bool sw = false;
        for(int x : adj[eq]) {
            
            if(pre[x] == -1 && !chk[x]) {
                chk[x]=1;
                q.push(x);
                rs.push_back(x);
                sw=1;
            }
        }
        // 더이상 갈곳없을때ㄴ
        if(!sw && preNode[eq] != -1) q.push(preNode[eq]);
    }

        
        
    
    
    if(rs.size() == n) return 1;
    else return false;

}


int main() {
    int n=9;

    vector<vector<int> > path;
    vector<int> ep;
    ep.push_back(0);
    ep.push_back(1);
    path.push_back(ep);

    ep.clear();
    ep.push_back(0);
    ep.push_back(3);
    path.push_back(ep);


    ep.clear();
    ep.push_back(0);
    ep.push_back(7);
    path.push_back(ep);

    ep.clear();
    ep.push_back(8);
    ep.push_back(1);
    path.push_back(ep);

    ep.clear();
    ep.push_back(3);
    ep.push_back(6);
    path.push_back(ep);

    ep.clear();
    ep.push_back(1);
    ep.push_back(2);
    path.push_back(ep);

    ep.clear();
    ep.push_back(4);
    ep.push_back(7);
    path.push_back(ep);

    ep.clear();
    ep.push_back(7);
    ep.push_back(5);
    path.push_back(ep);

    vector<vector<int> > order;


    ep.clear();
    ep.push_back(8);
    ep.push_back(5);
    order.push_back(ep);



    ep.clear();
    ep.push_back(6);
    ep.push_back(7);
    order.push_back(ep);


    ep.clear();
    ep.push_back(4);
    ep.push_back(1);
    order.push_back(ep);


    cout << solution(n,path, order) << '\n';
    return 0;
}