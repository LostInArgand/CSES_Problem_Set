#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long ll;

using namespace std;

struct point{
    ll x, y;
};

int orientation(point a, point b, point c){
    double area = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (area > 0) return 1;     // Counter-clockwise
    if (area == 0) return 0;    // Collinear
    return -1;                  // Clockwise
}

bool is_clockwise(point a, point b, point c, bool collinear){
    int orient = orientation(a, b, c);
    return orient < 0 || (collinear && orient == 0);
}

bool is_collinear(point a, point b, point c){
    return orientation(a, b, c) == 0;
}

void convex_hull(vector<point> & points, bool collinear = false){
    point p0 = *min_element(points.begin(), points.end(), [](point a, point b){return make_pair(a.y, a.x) < make_pair(b.y, b.x);});
    sort(points.begin(), points.end(), [&p0](const point& a, const point& b){
        int orient = orientation(p0, a, b);
        if (orient == 0) {
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        }
        return orient < 0;
    });
    if (collinear){
        int i = (int) (points.size()) - 1;
        while(i >= 0 && is_collinear(p0, points[i], points.back())) i--;
        reverse(points.begin() + i + 1, points.end());
    }
    vector<point> st;
    for(auto & p : points){
        while(st.size() > 1 && !is_clockwise(st[st.size() - 2], st.back(), p, collinear)){
            st.pop_back();
        }
        st.push_back(p);
    }
    points = st;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    ll x, y;
    cin >> n;
    vector<point> points;
    while(n--){
        cin >> x >> y;
        point p = (point){.x=x, .y=y};
        points.push_back(p);
    }
    convex_hull(points, true);
    cout << size(points) << endl;
    for(auto & p : points){
        cout << p.x << ' ' << p.y << endl;
    }
    return 0;
}
