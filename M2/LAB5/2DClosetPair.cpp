//66070501038 Phanthach
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a Point in 2D plane 
struct Point {
    int x, y;
};

// A utility function to find the distance between two points
float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A utility function to find the minimum of two float values
float min(float x, float y) {
    return (x < y) ? x : y;
}

// A utility function to find the smallest distance in the strip
float stripClosest(Point strip[], int size, float d) {
    float minDist = d; // Initialize the minimum distance as d
    sort(strip, strip + size, [](Point p1, Point p2) { return p1.y < p2.y; }); // Sort by y-coordinate

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j) {
            float currentDist = dist(strip[i], strip[j]);
            minDist = min(minDist, currentDist);
        }
    }
    return minDist;
}

// A recursive function to find the smallest distance
float closestUtil(Point P[], int n) {
    // If there are 2 or 3 points, then use brute force
    if (n <= 3) {
        float minDist = FLT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                minDist = min(minDist, dist(P[i], P[j]));
            }
        }
        return minDist;
    }

    // Find the middle point
    int mid = n / 2;
    Point midPoint = P[mid];

    // Find the smallest distance on the left and right
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    // Find the smaller of the two distances
    float d = min(dl, dr);

    // Build an array strip[] that contains points close to the line passing through the middle point
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j++] = P[i];

    // Return the minimum of d and closest distance in strip[]
    return min(d, stripClosest(strip, j, d));
}

// The main function that finds the smallest distance
float closest(Point P[], int n) {
    sort(P, P + n, [](Point p1, Point p2) { return p1.x < p2.x; }); // Sort by x-coordinate
    return closestUtil(P, n); // Use recursive function closestUtil()
}

int main() {
    int n;
    cin >> n;

    Point arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    printf("%.3f", closest(arr, n));
    return 0;
}
