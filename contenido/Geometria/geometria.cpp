#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)


using namespace std; 


// Vector = Point Pero Vector = B - A 
// Vector A
// A = Point(4,5);
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

    Point unit() {
        double modulo = mod();
        return Point(x/modulo, y/modulo);
    }
};

Point operator +(const Point &a, const &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(const Point &a, const &b) {
    return Point(a.x - b.x, a.y-b.y); 
}

Point operator *(const Point &a, int k) {
    return Point(a.x*k,a.y*k); 
}

Point operator /(const Point &a, int k) {
    return Point(a.x/k, a.y/k); 
}

// Funciones Basicas 
// Distancia de dos puntos // sqrt(B.x-A.x + B.y-A.y)
// http://www.cplusplus.com/reference/cmath/hypot/
double dist(const Point &A, const Point &B) {
    return hypot(A.x-B.x,A.y - B.y);  
}

// Producto Escalar 
// A y B son vectores
double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y; 
}

// Product Cross or producto Vectorial (Area de un paralelogramo)
// V y U son vectores
double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

// Get Area 

double areaP(const Point &V, const Point &U) {
    return abs(cross(V,U));
}

// Area de un triangulo 
// Area formada por 3 puntos. 
// Primero Crear el vector V = C-A y el vector U = B-A
// Por lo tanto puedo usar el cross product 
double areaTriangulo(const Point &A, const Point &B, const Point &C) {
    return abs(cross(C - A, B - A))/2.; 
}


//  Formula de heron 

double areaHeron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}





