package geometria;

import java.util.Arrays;

public class Geometria {
	class Punto implements Comparable<Punto>{
		double x, y;

		public Punto(double x, double y) {
			this.x = x;
			this.y = y;
		}

		double angulo() {
			return Math.atan2(y, x);
		}

		double mod() {
			return Math.sqrt(x * x + y * y);
		}

		Punto unitario() {
			double modulo = mod();
			return new Punto(x / modulo, y / modulo);
		}

		@Override
		public int compareTo(Punto o) {
			if(this.x != o.x) {
		        return (int) (100*(this.x - o.x));
		    } else {
		        return  (int) (100*(this.y - o.y));
		    }
		}
	}

	Punto suma(Punto a, Punto b) {
		return new Punto(a.x + b.x, a.y + b.y);
	}

	Punto resta(Punto a, Punto b) {
		return new Punto(a.x - b.x, a.y - b.y);
	}

	Punto multiplicacion(Punto a, double k) {
		return new Punto(a.x * k, a.y * k);
	}

	Punto division(Punto a, double k) {
		return new Punto(a.x / k, a.y / k);
	}

	// Funciones Basicas
	// Distancia de dos puntos // sqrt(B.x-A.x + B.y-A.y)
	double distancia(Punto A, Punto B) {
		return Math.hypot(A.x - B.x, A.y - B.y);
	}

	// Producto Escalar
	// A y B son vectores
	// si el producto es 0 son perpendiculares
	double dot(Punto A, Punto B) {
		return A.x * B.x + A.y * B.y;
	}

	// Product Cross or producto Vectorial (Area de un paralelogramo)
	// V y U son vectores
	// si el producto es 0 son paralelos 
	double cross(Punto V, Punto U) {
		return V.x * U.y - V.y * U.x;
	}

	// Get Area
	double areaP(Punto V, Punto U) {
		return Math.abs(cross(V, U));
	}

	// Area de 3 puntos
	double area(Punto A, Punto B, Punto C) {
		return cross(resta(C, A), resta(B, A));
	}

	// Area de un triangulo
	// Area formada por 3 puntos.
	// Primero Crear el vector V = C-A y el vector U = B-A
	// Por lo tanto puedo usar el cross product
	double areaTriangulo(Punto A, Punto B, Punto C) {
		return Math.abs(area(A, B, C)) / 2;
	}

	// Formula de heron
	double areaHeron(double a, double b, double c) {
		double s = (a + b + c) / 2;
		return Math.sqrt(s * (s - a) * (s - b) * (s - c));
	}

	// es rectangulo
	boolean esTriangulo(Punto A, Punto B, Punto C) {
		double a = distancia(A, B);
		double b = distancia(A, C);
		double c = distancia(B, C);
		return 2 * Math.max(Math.max(a, b), c) == a + b + c;
	}

	// punto de interseccion de rectas
	// division entre dos double
	// multiplicacion Point por un Double // por esa razon lo llevamos (B-A) a la
	// izq.
	Punto InterseccionRectas(Punto A, Punto B, Punto C, Punto D) {
		return multiplicacion(suma(A, resta(B, A)), cross(resta(C, A), resta(D, C)) / cross(resta(B, A), resta(D, C)));
	}

//	// P esta dentro del segmento AB 
	boolean enSegmento(Punto A, Punto B, Punto P) {
		return areaTriangulo(A, B, P) == 0 && (P.x >= Math.min(A.x, B.x) && P.x <= Math.max(A.x, B.x))
				&& (P.y >= Math.min(A.y, B.y) && P.y <= Math.max(A.y, B.y));
	}

	boolean intersectaSegmento(Punto A, Punto B, Punto C, Punto D) {
		double A1 = area(C, A, D); // el segmento es CD y A es el punto
		double A2 = area(C, B, D); // el segmento es CD, y B es el punto
		double A3 = area(A, B, C); // el segmento es AB, y C es el punto
		double A4 = area(A, B, D); // el segmento es AB, y D es el punto
		if (((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) && ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0))) {
			return true;
		}

		if (A1 == 0 && enSegmento(C, D, A)) {
			return true;
		}

		if (A2 == 0 && enSegmento(C, D, B)) {
			return true;
		}

		if (A3 == 0 && enSegmento(A, B, C)) {
			return true;
		}

		if (A4 == 0 && enSegmento(A, B, D)) {
			return true;
		}
		return false;
	}

	// poligono Convexo o No convexo 
	boolean esConvexo(Punto[] poligono) {
		int nroPuntos=poligono.length;
		int areasPositivas=0;
		int areasNegativas=0;
		for(int i=0;i<nroPuntos;i++) {
			double areaPuntos=area(poligono[i],poligono[(i+1)%nroPuntos],poligono[(i+2)%nroPuntos]);
			if(areaPuntos>0) {
				areasPositivas++;
			}else if(areaPuntos<0) {
				areasNegativas++;
			}
		}
		return areasPositivas==0||areasNegativas==0;
	}
	// Area de un Poligono 
	double areaPoligono(Punto[] poligono) {
		int nroPuntos = poligono.length;
		double areaTotal =0;
		for (int i = 1; i < nroPuntos-1; i++) {
			areaTotal += area(poligono[0],poligono[i],poligono[i+1]);
		}
		return Math.abs(areaTotal/2);
	}

	// Convex Hull 
	
	Punto[] convexHull(Punto[] puntos) {
		Arrays.sort(puntos);
		int k=0;
		Punto[] hulls =new Punto[puntos.length+1];
		for (int i = 0; i < puntos.length; i++) {
			while(k>=2&&area(hulls[k-2],hulls[k-1],puntos[i])<=0) {
				k--;
			}
			hulls[k++]=puntos[i];
		}
		for(int i=puntos.length-2,t=k;i>=0;i--) {
			while( k > t && area(hulls[k-2],hulls[k-1],puntos[i])<=0){
	            k--;
	        }
	        hulls[k++] = puntos[i];
		}
		Punto[] resultado= new Punto[k-1];
		for (int i = 0; i < resultado.length; i++) {
			resultado[i]=hulls[i];
		}
		return resultado;
	}

}
