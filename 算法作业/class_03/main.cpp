#include <iostream>
#include <vector>
using namespace std;

struct Marker {
    int id;
    int x_mm;
    int y_mm;
    int priority;
};


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
    Marker marker1 = {1, 100, 200, 80};
    Marker marker2 = {2, 200, -50, 95};
    Marker marker3 = {3, 0, 0, 60};
    vector<Marker> markers = {marker1, marker2, marker3};

    for (const auto& marker : markers) {
        cout << "编号" << marker.id << ":位置" << '(' << marker.x_mm << "," << marker.y_mm<<')' << ", 优先级" << marker.priority << endl;
    }

    int count = sum(markers);
    cout << "优先级不低于80的数量 = " << count << endl;
    Marker *ip;
    ip = &marker1;
    Marker &s = marker1;
    cout<<ip->id<<'\n'<< s.id<<endl;
    return 0;
}
