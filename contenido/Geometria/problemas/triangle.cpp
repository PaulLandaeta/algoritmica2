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

    double angle() {
        return atan2(y,x);
    }

    double mod() {
        return sqrt(x*x+y*y);
    }

    Point ort() {
        return Point(-y,x);  /// (1,0)  (0,1)  (-1,0)  (0,-1)
    }

    Point unit() {
        double modulo = mod();
        return Point(x/modulo, y/modulo);
    }
};

Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y-b.y); 
}

Point operator *(const Point &a, double k) {
    return Point(a.x*k,a.y*k); 
}

Point operator /(const Point &a, double k) {
    return Point(a.x/k, a.y/k); 
}

bool operator <(const Point &a, const Point &b) {
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}

double dist(const Point &A, const Point &B) {
    return hypot(A.x-B.x,A.y - B.y);  
}

double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y; 
}

double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

// Area de 3 puntos 

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A); 
}

bool isRight(Point A, Point B, Point C) {
    return area(A,B,C)!=0 && (dot(B-A,C-A) == 0 || dot(A-C,B-C) == 0 || dot(A-B,C-B) == 0);
}

bool isAlmost(Point a, Point b, Point c) {
    bool isAlmostRight = false;
    Point unit(1,0);
    for(int i = 0; i < 4; i++) {
        if(isRight(a+unit,b,c)) {
            isAlmostRight = true;
        }
        if(isRight(a,b+unit,c)) {
            isAlmostRight = true;
        }
        if(isRight(a,b,c+unit)) {
            isAlmostRight = true;
        }
        unit = unit.ort();
    }

    return isAlmostRight;
}

int main() {
    input;
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    // Creando puntos 
    Point a(x1,y1);
    Point b(x2,y2);
    Point c(x3,y3);

    if(isRight(a,b,c)) {
        cout<<"RIGHT"<<endl;
    }
    else if(isAlmost(a,b,c)) {
        cout<<"ALMOST"<<endl;
    }
    else{
        cout<<"NEITHER"<<endl;
    }
    return 0;
}

//0 0 1 0 4 1 