// 문자열 탐색
// 그냥 비교를 하게되면,
//O(queries * words * len)
// 1e5 * e4 *5, e14

// TRIE
// make :O(M*N) = O(1e6)
// search : O(1e6)


// ?을 어떻게 활용하지
// 모든 탐색한다음, ? 있으면 있는 수만큼 넘기고, fin 발견하면 종료
// 있는만큼 모두 넘기고,  근데 접미사를 어떻게 찾지?
// 그럼 시간복잡도, 최대, 26^e4
// 그럼 trie 각 레벨마다, ?의 개수를 남겨줘야하나
// ㅇㅇㅋ 그럼 그건 그렇다고 쳐

// 접미사로 붙어있으면 어떻게하지
// 앞에 ?가 있는 알파벳들을 따로 관리해줘야하나
// 그럼 최대 26^1, 26^2, ... 26^10000
// 아니지 전체 키워드 길이 합이 100000 이니까
// 메모리 초과는 안날듯. ㅔ그럼 이렇게 한번 해보자


// 이거 불가능해, tree 두개만들어서 양쪽끝에서 탐색하는게 빠를것같아

#include <iostream>


#include <string>
#include <vector>

using namespace std;


// vector<int> alphastart[10001][26];
struct node {
    bool fin;
    int child[26];
    char ch;
    // vector<int> childvec;
    node() {
        fin = false;
        for(int i=0; i<26; i++) child[i]= -1;

    }
};
vector<node> tree;
vector<node> treereverse;

void insert(string& s, int idx, int nodi) {
    if(s.size() == idx) {
        tree[nodi].fin = true;
        return;
    }
    int cur= s[idx] - 'a';
    
    if(tree[nodi].child[cur] == -1) {
        int treeidx = tree.size();
        tree[nodi].child[cur]  = treeidx;
        // tree[nodi].childvec.push_back(cur);

        // 몇번째 알파벳인지의 tree 위치를 적어주기
        //alphastart[10001][26];
        // alphastart[idx][cur].push_back(tree.size());

        tree.push_back(node());
        tree[treeidx].ch = s[idx];
    }
    
    

    return insert(s, idx+1, tree[nodi].child[cur]);
}



void insertreverse(string& s, int idx, int nodi) {
    if(idx == -1) {
        treereverse[nodi].fin = true;
        return;
    }
    int cur= s[idx] - 'a';
    if(treereverse[nodi].child[cur] == -1) {
        int treeidx = treereverse.size();
        treereverse[nodi].child[cur]  = treeidx;
        // treereverse[nodi].childvec.push_back(cur);

        treereverse.push_back(node());
        treereverse[treeidx].ch = s[idx];
    }
    
    

    return insertreverse(s, idx-1, treereverse[nodi].child[cur]);
}

int search(string& s, int idx, int nodi, int fi) {
    // ? 없을경우
    if(fi==0) {
        if(s.size() == idx) {
            return 1;
        }
        
        int cur = s[idx] - 'a';
        // 문자열 없으면
        if(tree[nodi].child[cur] == -1) {
            return 0;
        }

        return search(s, idx+1, tree[nodi].child[cur],fi);
    } else {
        // ? 만날경우
        if(idx == s.size() && tree[nodi].fin == 1) return 1;
        if(idx==s.size()) return 0;
        if(idx>=fi) {
            int rs=0;
            for (int i=0; i<26; i++ ) {
                if(tree[nodi].child[i] != -1) {
                    rs += search(s, idx+1, tree[nodi].child[i], fi);
                } 
            }
            return rs;
        }
        int cur = s[idx] - 'a';
        // 문자열 없으면
        if(tree[nodi].child[cur] == -1) {
            return 0;
        }

        return search(s, idx+1, tree[nodi].child[cur], fi);

    }

}

int searchreverse(string& s, int idx, int nodi, int fi) {
    if(idx == -1 && treereverse[nodi].fin == 1) return 1;
    if(idx == -1) return 0;
    if(idx<=fi) {
        int rs=0;
        for (int i=0; i<26; i++ ) {
            if(treereverse[nodi].child[i] != -1) {
                rs += searchreverse(s, idx-1, treereverse[nodi].child[i], fi);
            }
        }
        return rs;
    }
    int cur = s[idx] - 'a';
    // 문자열 없으면
    if(treereverse[nodi].child[cur] == -1) {
        return 0;
    }

    return searchreverse(s, idx-1, treereverse[nodi].child[cur], fi);

    

}            

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 처음에 우선 트리에 만들어주자
    tree.clear();
    tree.push_back(node());
    treereverse.clear();
    treereverse.push_back(node());
    for( string x : words) {
        insert(x,0,0);
        insertreverse(x,x.size()-1,0);
    }


    // 이제 찾아야지
    for(string x : queries) {
        string::size_type idx = x.find('?');
        // ? 없을경우
        if(idx == string::npos) {
            answer.push_back(search(x,0,0,0));
        } else if(idx== 0) {
            // ?가 앞에 있을경우
            int cnt=0;
            while(idx!=string::npos) {
                cnt++;
                idx = x.find('?',idx+1);
            }
            // // ~번째에 있는 알파벳 모두 불러와서 넣어주기
            // int nidx = x[cnt]-'a';
            // int ers = 0;
            // for (int nd : alphastart[cnt][nidx]) {
            //     ers += search(x,0,0,);
            // }
            // answer.push_back(ers);

            answer.push_back(searchreverse(x,x.size()-1,0,cnt-1));
            
        } else if(idx != 0) {
            answer.push_back(search(x,0,0,idx));
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
    for(int x : rs) cout << x << '\n';
    return 0;
}