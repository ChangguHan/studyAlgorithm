#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 시뮬레이션
// while, 거절 없으면 종료
vector<string> solution(vector<string> companies, vector<string> applicants) {
    // 초기선택
    vector<char> board[26];
    vector<int> compkind;
    string compApp[26];
    int compPrefer[26];

    string appComp[26];
    int appPrefer[26];
    int appidx[26];
    int appN = applicants.size();
    fill(appidx, appidx+26,0);
    for(string x : applicants) {
        char appname = x[0];
        char eappPrefer = x[x.size()-1];
        string eappComp = x.substr(2,x.size()-4);

        appComp[appname-'a'] = eappComp;
        appPrefer[appname-'a'] = eappPrefer-'0';

        // 초기선택
        board[eappComp[0]-'A'].push_back(appname);
    }

    for(string x : companies) {
        char ecompname = x[0];
        compkind.push_back(ecompname-'A');
        char ecompPrefer = x[x.size()-1];
        string eComp = x.substr(2,x.size()-4);

        compApp[ecompname-'A'] = eComp;
        compPrefer[ecompname-'A'] = ecompPrefer-'0';        
    }

    // reject
    vector<char> rej;
    for(int i=0; i<26; i++) {
        if(board[i].size() <=compPrefer[i]) continue;
        
        int cnt=0;

        for(char x : compApp[i]) {
            
            vector<char>::iterator it = find(board[i].begin(), board[i].end(), x);
            if(it == board[i].end()) continue;
            if(cnt>=compPrefer[i]){
                board[i].erase(it);
                rej.push_back(x);
                continue;
            }else {
                cnt++;
            }
        }   
    }

    while(rej.size() != 0) {
        // 거절된사람 다시 기업에 매칭
        for(char x : rej) {
            int idx= x-'a';
            appidx[idx]++;
            if(appPrefer[idx] <= appidx[idx]) {

                continue;
            }
            // 선택
            board[appComp[idx][appidx[idx]]-'A'].push_back(x);
        }
        rej.clear();

        // 다시 회사 거절
        for(int i=0; i<26; i++) {
            if(board[i].size() <=compPrefer[i]) continue;
            
            int cnt=0;

            for(char x : compApp[i]) {
                
                vector<char>::iterator it = find(board[i].begin(), board[i].end(), x);
                if(it == board[i].end()) continue;
                if(cnt>=compPrefer[i]){
                    board[i].erase(it);
                    rej.push_back(x);
                    continue;
                }else {
                    cnt++;
                }
            }   
        }


    }
    vector<string> answer;
    // 오름차순
    sort(compkind.begin(), compkind.end());
    for(int i : compkind) {
        sort(board[i].begin(),board[i].end());
        string s(board[i].begin(),board[i].end());
        string rs="";
        char letter = static_cast<char>(i+'A');
        rs+= letter;
        rs+= "_";
        rs+=s;
        answer.push_back(rs);
    }








    
    return answer;
}

int main() {

    
    vector<string> companies;
    // companies.push_back("A fabdec 2");
    // companies.push_back("B cebdfa 2");
    // companies.push_back("C ecfadb 2");
    
    
    companies.push_back("B abc 1");	
    companies.push_back("A abc 2");
    vector<string> applicants;
    // applicants.push_back("a BAC 1");
    // applicants.push_back("b BAC 3");
    // applicants.push_back("c BCA 2");
    // applicants.push_back("d ABC 3");
    // applicants.push_back("e BCA 3");
    // applicants.push_back("f ABC 2");
    
    // applicants.push_back("a AB 1"); 
    // applicants.push_back("b AB 1");
    // applicants.push_back("c AB 1");	
    for(string x : solution(companies, applicants)) cout << x << '\n';
    return 0;
}
