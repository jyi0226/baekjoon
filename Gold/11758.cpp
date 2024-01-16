#include <iostream>

using namespace std;

int x1,y1,x2,y2,x3,y3;

void solution() {
    int a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

    if (a > 0) {
        cout << 1;
    }
    else if (a < 0) {
        cout << -1;
    }
    else {
        cout << 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    solution();
    
    return 0;
}
