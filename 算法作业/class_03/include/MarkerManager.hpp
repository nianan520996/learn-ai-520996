#include <iostream>
#include <vector>


struct Marker {
    int id;
    int x_mm;
    int y_mm;
    int priority;
};

class MarkerManager {
private:
    std::vector<Marker> MarkerManager;
public:
    bool add(const Marker& marker);
    bool contains(int id) const;
    void showall();
    int num();
};
