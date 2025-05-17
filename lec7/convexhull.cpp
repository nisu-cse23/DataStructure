#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

// Struct for a point in 2D space
struct Point {
    int x, y;
};

// Global point used for sorting by polar angle
Point p0;

// Function to swap two points
void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// Function to find the orientation of the triplet (p, q, r)
// 0 -> Collinear, 1 -> Clockwise, 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Function to return the square of the distance between p1 and p2
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Comparator function for sorting points based on polar angle with p0
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2);
}

// Function to find the convex hull using Graham's Scan algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();

    // Find the bottom-most point (or leftmost if tie)
    int minY = points[0].y, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < minY) || (points[i].y == minY && points[i].x < points[minIndex].x)) {
            minY = points[i].y;
            minIndex = i;
        }
    }

    // Place the bottom-most point at the first position
    swap(points[0], points[minIndex]);
    p0 = points[0];

    // Sort points based on polar angle with p0
    sort(points.begin() + 1, points.end(), compare);

    // Remove collinear points that are not the farthest
    int m = 1; // Initial size of modified array
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m++] = points[i];
    }

    // If less than 3 points remain, the convex hull is not possible
    if (m < 3) return {};

    // Initialize a stack and push the first three points
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    // Process remaining points
    for (int i = 3; i < m; i++) {
        while (s.size() > 1) {
            Point top = s.top();
            s.pop();
            Point nextToTop = s.top();
            if (orientation(nextToTop, top, points[i]) != 2) continue;
            s.push(top);
            break;
        }
        s.push(points[i]);
    }

    // Collect points from the stack into the result vector
    vector<Point> hull;
    while (!s.empty()) {
        hull.push_back(s.top());
        s.pop();
    }
    return hull;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the points (x, y) one per line:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << "The convex hull points in counterclockwise order are:" << endl;
    cout << hull.size() << endl;
    for (const auto& p : hull) {
        cout << p.x << " " << p.y << endl;
    }

    return 0;
}