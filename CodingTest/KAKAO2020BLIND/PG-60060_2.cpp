// 그냥 생으로 비교하면, 
// words * queries * len
// e5 * e5 * e4. e14

// trie 쓰면
// O(MN), e6
// 매번 조회, e6
// e6 + e6으로 가능

// 물음표 제외하고 우선 구현해보자
// 접미사는 거꾸로 구현해야함
// 그니까 거꾸로 있는것까지

// 길이마다 trie벡터를 따로 만들으라고?
// 이게 맞아??
// 맞든 아니든, 시간초과의 문제는 아님

// map을 찾는데, 시간이 오래걸리나
// 최악의 조건 조회할때
// 쿼리 개수 * 쿼리 길이 * 쿼리길이(map 찾는데 조회하는시간)
// 1e6 * 1e4 >> 1e10

// 그래서 처음부터 길이를 찾아가지고 들어가나
// 그럼 map 찾는데 시간 안써도되니까


// MAP의 문제는 아닌듯하고
// trie의 구조에 문제가있나




#include <iostream>


#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct node {
    int child[26];
    
    // 이거 메모리 계산해보자
    // 총 1e6개 노드가 e4개씩 4byte
    // 4 * 1e10
    // 400MB
    // 총 2개니까 기본이 800MB
    // 메모리 끌수밖에 없음.

    // ?를 어떻게 효율적으로,,.
    // map을 쓰면 될까?
    // int leftLen[10010];
    // int cnt;
    map<int,int> cnt;
    
    // ?를 여기에다 놓으면, 글자 길이를 비교할수 없음
    // 끝에 몇글자가 더있는지에다만 인덱스 놓으면 안될까?
    node() {
        for(int i=0; i<26; i++) child[i] = -1;
        // cnt=0;

    }
};

// vector<node> trie[10010];
// vector<node> trieRev[10010];
vector<node> trie;
vector<node> trieRev;

// 뭐야 왜 string에서 &를 쓰면 통과가 되지
//???!!!!!!
// 로직이 문제는 아닐테고
// 바로 가지고 오냐 안가지고 오냐의 차이인가??



void insert(string& s, int idx, int nodi, vector<node>& vec) {
    if(idx==s.size()) {

        return;
    }

    int cur = s[idx]- 'a';
    // 현재글자부터 남은것 개수,
    // 물음표 오면 그걸 샐수있음
    // vec[nodi].cnt++;
    map<int,int>::iterator it = vec[nodi].cnt.find(s.size()-idx);
    if(it==vec[nodi].cnt.end()) vec[nodi].cnt.insert(make_pair(s.size()-idx,1));
    else it->second++;
    
    if(vec[nodi].child[cur]==-1) {
        vec[nodi].child[cur] = vec.size();
        vec.push_back(node());
    }
    return insert(s,idx+1,vec[nodi].child[cur], vec);
}

int srch(string s, int idx, int nodi, vector<node>& vec) {
    // ?이면 종료
    if(s[idx]=='?') {
        // 남은 숫자
        map<int,int>::iterator it = vec[nodi].cnt.find(s.size()-idx);
        if(it==vec[nodi].cnt.end()) return 0;
        else return it->second;
    }
    int cur = s[idx]-'a';
    // 없는경우 처리
    if(vec[nodi].child[cur] == -1) {
        return 0;
    }

    return srch(s, idx+1, vec[nodi].child[cur],vec);
}

// reverse의 문제인가...

vector<int> solution(vector<string> words, vector<string> queries) {
    // tree 초기화
    trie.push_back(node());
    trieRev.push_back(node());
    // for(int i=0; i<10010; i++) {
    //     trie[i].push_back(node());
    //     trieRev[i].push_back(node());
    // }
    

    for (string x : words) {

        insert(x,0,0,trie);
        reverse(x.begin(), x.end());
        insert(x,0,0,trieRev);

        // insert(x,0,0,trie[x.size()]);
        // reverse(x.begin(), x.end());
        // insert(x,0,0,trieRev[x.size()]);
    }

    // 이제 찾아야지
    vector<int> answer;
    for(string x : queries) {
        if(x[0]=='?') {
            reverse(x.begin(), x.end());
            // answer.push_back(srch(x,0,0,trieRev[x.size()]));
            answer.push_back(srch(x,0,0,trieRev));
        }else {
            // answer.push_back(srch(x,0,0,trie[x.size()]));
            answer.push_back(srch(x,0,0,trie));
        }
    }

    
    return answer;
}



int main() {

    vector<string> words;
    words.push_back("frodo");
    words.push_back("front");
    words.push_back("frost");
    words.push_back("frozen");
    words.push_back("frame");
    words.push_back("kakao");

    vector<string> queries;
    queries.push_back("fro??");
    queries.push_back("????o");
    queries.push_back("fr???");
    queries.push_back("fro???");
    queries.push_back("pro?");
    
    vector<int> rs = solution(words, queries);
    for( int x : rs) cout << x <<' ';


    return 0;
}


