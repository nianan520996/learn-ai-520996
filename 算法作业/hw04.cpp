#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    int f = max(a,max(b,max(c,max(d,e))));
    int g = min(a,min(b,min(c,min(d,e))));
    int sum = a+b+c+d+e-f-g;
    double h = (sum-f-g)/3.0;
    cout << fixed << setprecision(2) << h << endl;
    return 0;
}