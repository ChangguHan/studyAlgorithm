
// 변수를 하나 저장해서 계산해주면 됨
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> v;
    stringstream ss(str);
    string temp;

    while( getline(ss,temp, delimiter)) {
        v.push_back(temp);
    }
    return v;
}

int main() {
    string ip;
    getline(cin, ip);
    vector<string> v = split(ip, ' ');

    vector<string> v2;
    for (int i=0; i<v.size(); i++) {
        bool sw=false;
        for(int j=0; j<v2.size(); j++) {
            if(v[i] == v2[j]) {
                v2.erase(v2.begin() + j);
                
                sw=true;
            }
        }
        v2.insert(v2.begin(),v[i]);
        int cnt=0;
        for (string x : v2 ) {
            cnt++;
            cout << x << ' ';
            if(cnt==5)  break;
        }
        cout << '\n';

    }
    

        

    return 0;
}