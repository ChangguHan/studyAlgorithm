#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {

    // int b; cin >> b;
    // cout << b << '\n';
    cout << 3 << '\n';
    ifstream in("in.txt");
    int a;

    if(in.is_open()) {
        in>>a;
        cout << a << '\n';
        in >> a;
        cout << a << '\n';
        in >> a;
        cout << a << '\n';
    }
    cout << a << '\n';
    in.close();
    

    // string out_line;
    // ofstream out("in2.txt");
    // out << 11 << '\n';
    // out.close();

    return 0;
}