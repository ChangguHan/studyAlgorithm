#include <iostream>

#include <string>
#include <vector>

using namespace std;
struct node {
    char a;
    int child[5];
    int score[100010];
    node(char c) {
        a = c;
        for(int i=0; i<5; i++) child[i] = -1;
        fill(score, score+100010, 0);
    }
};
// 문자열 스플릿해서 만듬 : O(info)
// 스플릿 : O(query)
// 그냥 하면 무조건 시간초과날테니까
// trie 가능한가?, 생성 : O(info * 4)
// 조회 : O(Q * 4)
// 개발언어는 cpp, java, python 중 하나입니다.
// 직군은 backend, frontend 중 하나입니다.
// 경력은 junior, senior 중 하나입니다.
// 소울푸드는 chicken, pizza 중 하나입니다.

// 각각 -도 만들자
vector<node> trie;

void insert(vector<char>& v, int score, int idx, int nodi) {
    if(idx==v.size()+1) {
        return;
    }
    // 점수 등록
    for(int i=0; i<=score; i++) trie[nodi].score[i]++;
    int cur;
    if(idx==0) {
        if(v[idx]=='c') cur=1;
        else if(v[idx]=='j') cur=2;
        else if(v[idx]=='p') cur=3;
    } else if(idx==1) {
        if(v[idx]=='b') cur=1;
        else if(v[idx]=='f') cur=2;
    } else if(idx==2) {
        if(v[idx]=='j') cur=1;
        else if(v[idx]=='s') cur=2;
    } else if(idx==3) {
        if(v[idx]=='c') cur=1;
        else if(v[idx]=='p') cur=2;
    } 
    // -도 포함해주기
    if(trie[nodi].child[0]==-1) {        
        trie[nodi].child[0]=trie.size();
        trie.push_back(node('-'));
    }

    if(trie[nodi].child[cur]==-1) {        
        trie[nodi].child[cur]=trie.size();
        trie.push_back(node(v[idx]));
    }

    insert(v,score,idx+1, trie[nodi].child[0]);
    return insert(v,score,idx+1, trie[nodi].child[cur]);
}

int chk(vector<char>& v, int score, int idx, int nodi) {
    if(idx==v.size()) {
        return trie[nodi].score[score];
    }
    // 점수 등록
    int cur;
    if(idx==0) {
        if(v[idx]=='c') cur=1;
        else if(v[idx]=='j') cur=2;
        else if(v[idx]=='p') cur=3;
        else if(v[idx]=='-') cur=0;
    } else if(idx==1) {
        if(v[idx]=='b') cur=1;
        else if(v[idx]=='f') cur=2;
        else if(v[idx]=='-') cur=0;
    } else if(idx==2) {
        if(v[idx]=='j') cur=1;
        else if(v[idx]=='s') cur=2;
        else if(v[idx]=='-') cur=0;
    } else if(idx==3) {
        if(v[idx]=='c') cur=1;
        else if(v[idx]=='p') cur=2;
        else if(v[idx]=='-') cur=0;
    } 
    
    if(trie[nodi].child[cur]==-1) {        
        return 0;
    }

    return chk(v,score,idx+1, trie[nodi].child[cur]);
}




vector<int> solution(vector<string> info, vector<string> query) {
    trie.push_back(node('s'));
    for(string x : info) {
        int bi=0;
        vector<char> v;
        for(int i=0; i<x.size(); i++) {
            if(x[i]==' ') {
                v.push_back(x[bi]);
                bi = i+1;
            }
        }
        insert(v,stoi(x.substr(bi)),0,0);
        
    }

    vector<int> answer;

    for(string xx : query) {
        int bii=0;
        vector<char> v;
        int cnt=1;
        // int ccnt=0;
        for(int i=0; i<xx.size(); i++) {
            if(xx[i]==' ') {
                if(cnt==0) {
                    cnt++;
                }
                else {
                    v.push_back(xx[bii]);
                    if(v.size()==4) {
                        bii = i+1;
                    } else bii = i+5;
                    cnt=0;
                    // ccnt++;
                }
                
            }
        }
        answer.push_back(chk(v,stoi(xx.substr(bii)),0,0));
    }
    
    return answer;
}


int main() {
    vector<string> info;
    info.push_back("java backend junior pizza 150");
    info.push_back("python frontend senior chicken 210");
    info.push_back("python frontend senior chicken 150");
    info.push_back("cpp backend senior pizza 260");
    info.push_back("java backend junior chicken 80");
    info.push_back("python backend senior chicken 50");



    vector<string> query;
    
    query.push_back("java and backend and junior and pizza 100");
    query.push_back("python and frontend and senior and chicken 200");
    query.push_back("cpp and - and senior and pizza 250");
    query.push_back("- and backend and senior and - 150");
    query.push_back("- and - and - and chicken 100");
    query.push_back("- and - and - and - 150");


    for (int x : solution(info, query)) cout << x << ' ';
    return 0;
}