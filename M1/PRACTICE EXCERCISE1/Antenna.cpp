#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;

    float best = 100;
    int pos;

    cin >> n;

    float p[n];

    float a[n],b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < n-1; i++) {
        p[i] = ((abs(a[i] - a[i+1])/(abs(a[i])+abs(a[i+1]))) + ((abs(b[i] - b[i+1])/(abs(b[i])+abs(b[i+1])))));

        //cout << p[i] << endl;
        if (best > p[i]) {
            best = p[i];
            pos = i;
            //cout << best << endl;
        }
    }
    p[n-1] = ((abs(a[0] - a[n-1])/(abs(a[0])+abs(a[n-1]))) + ((abs(b[0] - b[n-1])/(abs(b[0])+abs(b[n-1])))));
    //cout << p[n-1] << "<--p[n-1]" << endl;
    if (best > p[n-1]) {
            pos = n-1;
        }


    cout << a[pos+1] << " " << b[pos+1];

return 0;
}
