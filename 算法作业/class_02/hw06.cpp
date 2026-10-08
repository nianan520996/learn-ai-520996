#include <iostream>
using namespace std;

struct student
{
    int id;
    int ch;
    int ma;
    int en;
    int sum;
};
int main() {
    int n;
    cin >> n;
    student students[300];
    for (int i=0; i<n; i++) {
        students[i].id = i + 1;
        cin>> students[i].ch >> students[i].ma >> students[i].en;
        students[i].sum = students[i].ch + students[i].ma + students[i].en;
    }
//比较与互换
for (int i=0; i<n-1; i++) {
    for(int j=0;j<n-1;j++){
        bool h=false;
        if(students[j].sum < students[j+1].sum){
            h=true;
        }
        else if(students[j].sum == students[j+1].sum){
            if(students[j].ch < students[j+1].ch){
                h=true;
            }else if(students[j].ch == students[j+1].ch){
                if(students[j].id > students[j+1].id){
                    h=true;
                }
            }
        }if(h){
            student temp = students[j];
            students[j] = students[j+1];
            students[j+1] = temp;
        }
    }
}
for (int i=0; i<n; i++) {
    cout << students[i].id << " " << students[i].sum << endl;
}
    return 0;
}