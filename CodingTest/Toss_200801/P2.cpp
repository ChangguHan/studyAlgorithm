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
    vector<int> v = split(ip, ' ');
    
    int bef=-1;
    for (int x : v) {
        // 범위
        if(!(x>=1 && x<=45)) {
            cout << "false";
            return 0;
        }
        //중복, 오름
        if(x<=bef) {
            cout << "false";
            return 0;
        }
        
        bef = x;
    }
    // 위조건 통과하는 개수
    if(v.size() != 6) {
        cout << "false";
        return 0;
    }

    cout << "true";

    return 0;
}