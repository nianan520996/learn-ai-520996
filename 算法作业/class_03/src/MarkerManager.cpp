#include<iostream>
#include"MarkerManager.hpp"
#include<vector>
using namespace std;

bool MarkerManager::contains(int id) const {
    for (const auto& marker : MarkerManager) {
        if (marker.id == id) {
            return true;
        }
    }
    return false;
}
bool MarkerManager::add(const Marker& marker) {
    if (marker.id<=0||marker.priority<0||marker.priority>100||contains(marker.id)) {
        return false;
    }
    MarkerManager.push_back(marker);
    return true;
}
void MarkerManager::showall(){
    for(const auto& marker : MarkerManager)
    {
        cout << "编号" << marker.id << ":位置" << '(' << marker.x_mm << "," << marker.y_mm<<')' << ", 优先级" << marker.priority << endl;
    }
}

int MarkerManager::num(){
    int count = 0;
    int a;
    cin>>a;
    for(const auto& marker : MarkerManager)
    {if (marker.priority>=a)
        count++;
    }
    return count;

}