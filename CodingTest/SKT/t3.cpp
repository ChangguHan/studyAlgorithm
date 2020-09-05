#include <iostream>
#include <string>
#include <vector>
using namespace std;
int rs=0;
int aMax=0;
vector<char> v[3];
// int bnum[] = {0,0,0};
// int cntCombi(int n, int r) {
//     if(r==0) return 1;
//     if(n==r) return 1;

//     return cntCombi(n-1,r-1) + cntCombi(n-1,r);
// }
// void dfs(int leftbnum, int anum) {
//     // 개수만 구하면 되는거니까, b가 몇개 들어가는지 구하고,
//     // 각각에서 순열 구하면 돼
//     if(leftbnum ==0) {
//         // for (int i=0; i<3; i++) {
//         //     rs += cntCombi(bnum[i]+anum, anum);
//         // }
//         rs++;
//         return;
//     }
//     for(int i=0; i<3; i++) {
//         bnum[i]++;
//         dfs(leftbnum-1, anum);
//         bnum[i]--;
//     }
// }

// void dfs(string S,int idx, int acount, int splitcnt) {
    
//     if(acount > aMax) return;
//     if(splitcnt>2) return;
//     if(idx == S.length()-1 && splitcnt==2) {
//         rs++;
//         return;
//     }

//     for (int i=idx; i<S.length(); i++) {
//         char ec = S[i];
//         if(ec == 'a') {
//             v[splitcnt].push_back(ec);
//             dfs(S,i+1,acount+1,splitcnt);
//             v[splitcnt].pop_back();

//             v[splitcnt+1].push_back(ec);
//             dfs(S,i+1,1,splitcnt+1);
//             v[splitcnt+1].pop_back();
//         }
//         else if(ec == 'b') {
//             v[splitcnt].push_back(ec);
//             dfs(S,i+1,acount,splitcnt);
//             v[splitcnt].pop_back();

//             v[splitcnt+1].push_back(ec);
//             dfs(S,i+1,acount,splitcnt+1);
//             v[splitcnt+1].pop_back();
//         }

//     }
    
// }

void dfs(string S,int idx,int vidx) {
    
    for (int i=0; i<3; i++) {
        int acount = 0;
        // vector<int> v2 = v[i];
        for(int x=0; x<v[i].size(); x++) {
            if(v[i][x]=='a') acount++;
        }
        if(acount>aMax) return; 
    }
    int ssize = S.length();
    if(idx == ssize) {
        rs++;
        return;
    }

    // for (int i=idx; i<S.length(); i++) {
    char ec = S[idx];
    v[vidx].push_back(ec);
    dfs(S,idx+1,vidx);
    v[vidx].pop_back();
    
    if(vidx>=2) return;
    v[vidx+1].push_back(ec);
    dfs(S,idx+1,vidx+1);
    v[vidx+1].pop_back();

    // }
    
}


int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    //예외먼저 작성, a의 개수가 3의 배수가 아니면 0으로 return
    int cnt=0;
    int ssize = S.length();
    for (int i=0; i<ssize; i++) {
        char eachS = S[i];
        if(eachS == 'a') cnt++;
    }
    if(cnt%3 !=0) return 0;
    aMax = cnt/3;

    // dfs(ssize-cnt,cnt/3);
    dfs(S,0,0);

    return rs;
}


int main() {
    string S = "babaa";

    cout << solution(S) <<' ';
    // cout << cntCombi(3,2);

    return 0;
}