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
// Point A, Point B
// Point C(A.x+B.x, A.y+B.y);
// Point C = A + B;
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
// Sort Ordernar puntos 
bool operator <(const Point &a, const Point &b) {
    if(a.x != b.x) {
        return a.x < b.x;
    } else {
        return  a.y < b.y;
    }
}
// Sobrecarga del Operador Print
ostream& operator<<(ostream& os, Point p) {
    return os << "Este es el Punto ===>("<< p.x << "," << p.y << ")";
}



// 


// Funciones Basicas 
// Distancia de dos puntos // sqrt(B.x-A.x + B.y-A.y)
// http://www.cplusplus.com/reference/cmath/hypot/
double dist(const Point &A, const Point &B) {
    return hypot(A.x-B.x,A.y - B.y);  // sqrt((a.x-b.x)^2, (a.y-b.y)^2)
}

// Producto Escalar 
// A y B son vectores
// si el producto es 0 son perpendiculares
double dot(const Point &A, const Point &B) {
    return A.x * B.x + A.y * B.y; 
}

// Product Cross or producto Vectorial (Area de un paralelogramo)
// V y U son vectores
// si el producto es 0 son paralelos 
double cross(const Point &V, const Point &U) {
    return V.x * U.y - V.y * U.x;
}

// Get Area 

double areaP(const Point &V, const Point &U) {
    return abs(cross(V,U));
}

// Area de 3 puntos 

double area(const Point &A, const Point &B, const Point &C) {
    return cross(B - A, C - A); // 1
}

// Area de un triangulo 
// Area formada por 3 puntos. 
// Primero Crear el vector V = C-A y el vector U = B-A
// Por lo tanto puedo usar el cross product 

double areaTriangulo(const Point &A, const Point &B, const Point &C) {
    return abs(area(A,B,C))/2.; 
}

//  Formula de heron 

double areaHeron(double a, double b, double c) {
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// es rectangulo 

// bool is_triangle(Point &A, Point &B, Point &C) {
//     double a = dist(A,B);// cuadrado
//     double b = dist(A,C);// cuadrado
//     double c = dist(B,C);// cuadrado
//     double s = max(a,b,c);
//     return 2.0*s == a+b+c;
// }


// punto de interseccion de rectas 
// division entre dos double 
// multiplicacion Point por un Double // por esa razon lo llevamos (B-A) a la izq. 
Point lineIntersection(const Point &A,const Point &B,const Point &C,const Point &D) {
    return A+(B-A)*(cross(C-A,D-C)/cross(B-A,D-C));
}


// P esta dentro del segmento AB 
// 0.0
bool onSegment(const Point &A, const Point&B, const Point &P) {
    return areaTriangulo(A,B,P) == 0 && 
        (P.x >= min(A.x,B.x) && P.x <= max(A.x,B.x)) && 
        (P.y >= min(A.y,B.y) && P.y <= max(A.y,B.y));
}

bool intersectsSegment(const Point &A,const Point &B,const Point &C,const Point &D) {
    double A1 = area(C,A,D);   // el segmento es CD y A es el punto
    double A2 = area(C,B,D);   // el segmento es CD, y B es el punto 
    double A3 = area(A,B,C);   // el segmento es AB, y C es el punto
    double A4 = area(A,B,D);   // el segmento es AB, y D es el punto  

    if(((A1 > 0 && A2 < 0) || (A1<0 && A2>0)) && 
        ((A3 > 0 && A4 < 0) || (A3<0 && A4>0)))  {
            return true;
    }

    if(A1 == 0 && onSegment(C,D,A)) {
        return true;
    }

    if(A2 == 0 && onSegment(C,D,B)) {
        return true;
    }

    if(A3 == 0 && onSegment(A,B,C)) {
        return true;
    }

    if(A4 == 0 && onSegment(A,B,D)) {
        return true;
    }

    return false;
}



// poligono Convexo o No convexo 
// O(n) = n 
bool isConvex(const vector<Point> &polign) {
    int nroPoints = polign.size();    // 1
    int areasPositive =  0, areasNegative = 0; // 2
    for(int i = 0; i < nroPoints ;i++) {  // n
        double areaPoints = area(polign[i],polign[(i+1)%nroPoints],polign[(i+2)%nroPoints]);  // 3
        if(areaPoints>0) {  // 3
           areasPositive++; // 2
        } else if(areaPoints<0) {
           areasNegative++; // 2
        }
    }
    return areasPositive == 0 || areasNegative == 0; // 3 
}

bool pointInConvex(const vector<Point> &polign, const Point &P) {
    int nroPoints = polign.size();
    int areasPositive =  0, areasNegative = 0;
    for(int i = 0; i < nroPoints ;i++) { // n
        double areaPoints = area(P,polign[i],polign[(i+1)%nroPoints]);
        if(areaPoints>0) {
           areasPositive++;
        } else if(areaPoints<0) {
           areasNegative++;
        }
    }
    return areasPositive == 0 || areasNegative == 0;
}
// Area de un Poligono 

double areaPoligono(const vector<Point> &poligono) {
    int nroPoints = poligono.size(); 
    double areaTotal = 0; 
    for(int i = 1; i < nroPoints - 1; i++) {
        areaTotal += area(poligono[0],poligono[i],poligono[i+1]); 
    }
    return abs(areaTotal/2);
}

// Convex Hull 

vector<Point> convexHull(vector<Point> &points) {
    sort(points.begin(),points.end()); // Ordenamos los puntos para encontrar el punto mas a la izquierda
    int k = 0; // k cuenta cuantos puntos tendra el convex hull
    Point hulls[points.size()+100];   // Guardar los puntos del convex hull
    // Parte inferior 
    for(int i = 0; i<points.size();i++){
        while(k>=2 && area(hulls[k-2],hulls[k-1],points[i])<=0) {
            k--; // stack.pop();
        }
        hulls[k++] = points[i];
    }
    // [1,2,7,8,9]
    //  0 1 2 3 4
    // k = 5
    // 

    // Parte Superior
    for(int i = points.size()-2, t = k;i>=0; i--) {
        while( k > t && area(hulls[k-2],hulls[k-1],points[i])<= 0){
            k--;
        }
        hulls[k++] = points[i];
    }
    // [1,2,7,8,9,6,3]
    // k = 7
    //  0 1 2 3 4 5 6
    return vector<Point> (hulls,hulls+k-1);
}


int main(){
    input;
    int n;
    vector<Point> poligono;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        poligono.push_back(Point(x,y));
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        Point P(x,y);
        if(pointInConvex(poligono,P)) {
            cout << "inside" << endl;
        } else {
            cout << "outside" << endl;
        }
    }
    return 0;
}