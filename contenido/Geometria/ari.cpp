#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

struct Point{
    double x, y;
    Point(){} 
    Point(double a,double b) {
        x = a;
        y = b;
    }
};

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y-b.y); 
}

// Sort Ordernar puntos 
bool operator <(const Point &a, const Point &b) {
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}

double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A);
}

bool pointInConvex(const vector<Point> &polign, const Point &P) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints; i++) {
        double areaPoints = area(P, polign[i], polign[(i+1)%nroPoints]);
        if(areaPoints > 0) {
           areasPositive++;
        } else if(areaPoints < 0) {
           areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(),points.end());
    int k = 0; 
    Point hulls[points.size()+100]; 
    for(int i = 0; i<points.size();i++){
        while(k>=2 && area(hulls[k-2],hulls[k-1],points[i])<=0) {
            k--;
        }
        hulls[k++] = points[i];
    }
    for(int i = points.size()-2, t = k;i>=0; i--) {
        while( k > t && area(hulls[k-2],hulls[k-1],points[i])<= 0){
            k--;
        }
        hulls[k++] = points[i];
    }
    return vector<Point> (hulls,hulls+k-1);
}

int main(){
    input;
    output;
    vector<Point> poligono, poligono2;
    int points, points2;
    cin >> points;
    for (int i = 0; i < points; i++){
        int n, m;
        cin >> n >> m;
        poligono.push_back(Point(n,m));
    }
    poligono2 = convexHull(poligono);
    cin >> points2;
    for (int i = 0; i < points2; i++){
        int a, b;
        cin >> a >> b;
        if (pointInConvex(poligono2, Point(a, b))){
            cout << "inside" << endl;
        } else {
            cout << "outside" << endl;
        }
    }
    return 0;
}