#include <iostream>
#include <string>

using namespace std;

int main() {
    long long int ip;
    cin >> ip;

    string ips = to_string(ip);

    for (int i=0; i<ips.length(); i++) {
        if(ips[i]== '1') {
            if(i==ips.length()-1) {
                cout << "false";
                return 0;
            }
            if(ips[i+1] != '2') {
                cout << "false";
                return 0;
            }
        } else if  (ips[i]== '2') {
            if(i==ips.length()-1) {
                cout << "true";
                return 0;
            }
            if(!(ips[i+1] == '1' || ips[i+1] == '2')) {
                cout << "false";
                return 0;
            }
        }
    }
    cout <<"true";

    return 0;

}