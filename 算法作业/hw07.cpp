#include <iostream>
using namespace std;

int main() {
    int x=0;
    int y=0;
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='R') {
            x++;
        } else if (s[i]=='U') {
            y++;
        } else if (s[i]=='L') {
            x--;
        } else if (s[i]=='D') {
            y--;
        }
    }
    if (x==0 && y==0) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}