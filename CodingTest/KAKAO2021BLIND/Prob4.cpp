#include <iostream>


#include <string>
#include <vector>

using namespace std;


// s-a + s-b, s-a-b, s-b-a 세개 최소값 구하면 될듯
//O(N^3)
const int inf = 3e7;
int map[210][210];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    fill(&map[0][0], &map[209][210], inf);
    for(auto x : fares) {
        int a = x[0];
        int b = x[1];
        int c = x[2];
        map[a][b] = c;
        map[b][a] = c;
    }
    for(int i=0; i<=n; i++) map[i][i] = 0;
    for(int k=1; k<=n; k++) {
        for(int j=1; j<=n; j++) {
            for(int i=1; i<=n; i++) {
                if(map[j][i] > map[j][k] + map[k][i]) {
                    map[j][i] = map[j][k] + map[k][i];
                }
            }
        }
    }
    //들려서 가는것
    int minv = inf;
    for(int k=1; k<=n; k++) {
        minv = min(minv, map[s][k] + map[k][a] + map[k][b]);
    }

    
    return minv;
}



int main() {


    int n=6;
    int s=4;
    int a=6;
    int b=2;
    vector<vector<int>> fares;
    vector<int> e;

    e.clear();
    e.push_back(4);
    e.push_back(1);
    e.push_back(10);
    fares.push_back(e);
    e.clear();
    e.push_back(3);
    e.push_back(5);
    e.push_back(24);
    fares.push_back(e);
    e.clear();

    e.push_back(5);
    e.push_back(6);
    e.push_back(2);
    fares.push_back(e);
    

    e.clear();
    e.push_back(3);
    e.push_back(1);
    e.push_back(41);
    fares.push_back(e);
    
    e.clear();
    e.push_back(5);
    e.push_back(1);
    e.push_back(24);
    fares.push_back(e);
    e.clear();
    e.push_back(4);
    e.push_back(6);
    e.push_back(50);
    fares.push_back(e);
    
    e.clear();
    e.push_back(2);
    e.push_back(4);
    e.push_back(66);
    fares.push_back(e);
    e.clear();
    e.push_back(2);
    e.push_back(3);
    e.push_back(22);
    fares.push_back(e);
        
    e.clear();
    e.push_back(1);
    e.push_back(6);
    e.push_back(25);
    fares.push_back(e);
    


    cout << solution(n,s,a,b,fares) << '\n';

    return 0;
}