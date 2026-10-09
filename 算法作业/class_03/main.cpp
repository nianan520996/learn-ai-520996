#include <iostream>
#include <vector>
#include "include/MarkerManager.hpp"
#include <windows.h>
using namespace std;


int sum(const vector<Marker>& markers) {
    int total = 0;
    for (const auto& marker : markers) {
        if (marker.priority >= 80) {
            total += 1;
        }
    }
    return total;
}

int main() {
    vector<Marker> markers = { {1, 100, 200, 80}, {2, 200, -50, 95}, {3, 0, 0, 60} };

    for (const auto& marker : markers) {
        cout << "编号" << marker.id << ":位置" << '(' << marker.x_mm << "," << marker.y_mm<<')' << ", 优先级" << marker.priority << endl;
    }

    int count = sum(markers);
    cout << "优先级不低于80的数量 = " << count << endl;
    Marker *ip;
    ip = &markers[0];
    Marker &s = markers[0];
    cout<<ip->id<<'\n'<< s.id<<endl;
    Marker m1={1, 100, 200, 80};
    Marker m2={2, 150, 250, 90};
    Marker m3={3, 200, 300, 70};
    Marker m4={2,100,200,45};
    Marker m5={4,123,200,101};
    MarkerManager manager;
    manager.add(m1);
    manager.add(m3);
    cout<<manager.add(m2)<<endl;
    cout<<manager.add(m5)<<endl;
    cout<<manager.add(m4)<<endl;
    manager.showall();
    cout<<"请输入阈值：";
    int result=manager.num();
    cout<<result<<endl;


    return 0;
}