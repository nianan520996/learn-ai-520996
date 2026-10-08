#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int x;
    int i = 0;
    while (cin >> x) {
        if (x == 0) break;
        arr[i] = x;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j] << " ";
    }
    return 0;
}