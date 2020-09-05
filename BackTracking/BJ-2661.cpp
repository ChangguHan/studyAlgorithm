// 3^N * N/2 * N/2
// N^3  >> 1e6

#include <iostream>
#include <vector>

using namespace std;

int N;
// int map[90];
vector<int> v;
void dfs(int dep) {
    if(dep == N) {
        for (int x : v ) cout << x;
        cout <<'\n';
        exit(0);
    }
    for(int i=1; i<=3; i++) {
        v.push_back(i);
        if(v.size()==0) dfs(dep+1);
        // 개수
        // 1이면 0번, 2이면 1번, 3이면 1번, 4이면 2번, 5이면 2번, 6이면 3번, ...
        bool sw = false;
        for(int j=1; j<=v.size()/2; j++) {
            bool sw2 = false;
            for(int k=0; k<j; k++) {
                int a = v.size()-1-k;
                int b = v.size()-1-k-j;
            
                if(v[a] !=v[b]) sw2=true;
                // if(sw) break;

            }
            // 모든 쌍이 같을경우, break;
            if(!sw2) {
                sw = true;
                break;
            }
            

        }
        // 모두 달랐다면
        if(!sw) dfs(dep+1);
        
        v.pop_back();
        

    }
}
int main() {
    cin  >> N;
    dfs(0);



    return 0;
}