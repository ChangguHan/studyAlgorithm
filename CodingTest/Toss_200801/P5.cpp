
// 변수를 하나 저장해서 계산해주면 됨
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split(string str, char delimiter) {
    vector<int> v;
    stringstream ss(str);
    string temp;

    while( getline(ss,temp, delimiter)) {
        v.push_back(stoi(temp));
    }
    return v;
}

int main() {
    string ip;
    getline(cin, ip);
    vector<int> kv = split(ip, ' ');
    getline(cin, ip);
    vector<int> lv = split(ip, ' ');
    
    vector<int> rs;
    int togive=0;

    for(int i=0; i<kv.size(); i++) {
        togive = togive + kv[i] - lv[i];
        if(togive>0) {
            rs.push_back(togive);
            togive=0;
        }else rs.push_back(0);
    }

    for (int x : rs) cout << x << ' ';


        

    return 0;
}