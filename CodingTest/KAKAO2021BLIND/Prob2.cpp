// 조합으로 하자
#include <iostream>


#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
vector<string> globalOrders;
vector<string> chk;
bool eachchk[30];
vector<string> answer[20];



vector<int> vec;
void cal(string& s,int k) {
    int cnt=0;
    for(string x : globalOrders) {
        bool eb = false;
        for(int ev : vec) {
            char ec = s[ev];
            if(x.find(ec)==string::npos) {
                eb=true;
            }
        }
        if(!eb) {
            string rs="";
            for(int ev : vec) rs+=s[ev];
            answer[k].push_back(rs);
        }
    }
    
}
void dfs(string& s, int k) {
    if(vec.size()==k) {
        
        string rs="";
        for(int ev : vec) rs+=s[ev];
        vector<string>::iterator it = find(chk.begin(), chk.end(), rs);
        if(it==chk.end()) {
            chk.push_back(rs);
            cal(s,k);
        }
        return;
    }
    int cur=-1;
    if(vec.size()!=0) cur=vec[vec.size()-1];

    for(int i=cur+1; i<s.size(); i++) {
        vec.push_back(i);
        dfs(s,k);
        vec.pop_back();
    }



}
vector<string> solution(vector<string> orders, vector<int> course) {
    
    globalOrders = orders;
    // 각자 순열 구하기
    for(int k : course) {
        vec.clear();
        for(string x : orders) {
            dfs(x,k);
        }
    }

    // 중복한거 자르기
    vector<string> rrs;
    for(int k : course) {
        // for(string x : answer[k])
        set<string> s(answer[k].begin(), answer[k].end());
        
        int maxv=0;
        for(string x : s) {
            int ec = count(answer[k].begin(), answer[k].end(),x);
            if(ec > maxv) maxv = ec;
        }
        for(string x : s) {
            int ec = count(answer[k].begin(), answer[k].end(),x);
            if(ec == maxv) rrs.push_back(x);
        }
        

    }
    sort(rrs.begin(), rrs.end());    
    return rrs;
}

int main() {

    vector<string> orders;
    orders.push_back("ABCFG");
    orders.push_back("AC");
    orders.push_back("CDE"); 
    orders.push_back("ACDE"); 
    orders.push_back("BCFG");
    orders.push_back("ACDEH");

    vector<int> course;
    course.push_back(2);
    course.push_back(3);
    course.push_back(4);


    for(string x : solution(orders, course)) cout << x << '\n';
    return 0;
}