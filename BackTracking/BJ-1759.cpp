// 조합(백트), 체크

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L,C;
vector<int> v;
char chs[20];
char mos[5]= {'a','e','i','o','u'};
void mocheck() {
    int mo = 0;
    int ja = 0;

    for (int x : v) {
        bool sw = false;
        for(int i=0; i<5;i++) {
            if(mos[i]==chs[x]) {
                mo++;
                sw = true;
                break;
            }
        }
        if(sw==false) ja++;
    }
    if(ja>=2 && mo>=1) {
        for(int x:v) cout << chs[x];
        cout << '\n';
    }
    


}
void dfs() {
    if(v.size() == L) {
        mocheck();
        return;
    }
    int idx=-1;
    if(v.size()!=0) idx = v.back();
    for (int i= idx+1; i<C; i++) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }

}
int main() {
    cin >> L >> C;
    for(int i=0; i<C; i++) {
        cin >> chs[i];
    }
    sort(chs, chs+C);
    dfs();

    return 0;
}