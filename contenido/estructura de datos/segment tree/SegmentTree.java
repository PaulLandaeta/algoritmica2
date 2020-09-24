package estructurasDeDatos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SegmentTree {
	static int inf = 10000;

	static class Nodo {
		int suma, multiplicacion, minimo, maximo;
	}

	static Nodo[] segmentTree = new Nodo[inf * 2];
	static int a[] = new int[inf];

	static void init(int inicio, int fin, int nodoActual) {
		if (segmentTree[nodoActual] == null) {
			segmentTree[nodoActual] = new Nodo();
		}
		if (inicio == fin) {
			segmentTree[nodoActual].maximo = a[inicio];
			segmentTree[nodoActual].minimo = a[inicio];
			segmentTree[nodoActual].multiplicacion = a[inicio];
			segmentTree[nodoActual].suma = a[inicio];
		} else {
			int medio = (inicio + fin) / 2;
			int nodoIzquierdo = 2 * nodoActual + 1;
			int nodoDerecho = 2 * nodoActual + 2;
			// Ir por lado izquierdo
			init(inicio, medio, nodoIzquierdo);
			// Ir por lado derecho
			init(medio + 1, fin, nodoDerecho);

			segmentTree[nodoActual].suma = segmentTree[nodoIzquierdo].suma + segmentTree[nodoDerecho].suma;
			segmentTree[nodoActual].maximo = Math.max(segmentTree[nodoIzquierdo].maximo,
					segmentTree[nodoDerecho].maximo);
			segmentTree[nodoActual].minimo = Math.min(segmentTree[nodoIzquierdo].minimo,
					segmentTree[nodoDerecho].minimo);
			segmentTree[nodoActual].multiplicacion = segmentTree[nodoIzquierdo].multiplicacion
					* segmentTree[nodoDerecho].multiplicacion;
		}
	}

	static Nodo query(int inicio, int fin, int nodoActual, int izquierda, int derecha) {
		if (inicio >= izquierda && fin <= derecha) {
			return segmentTree[nodoActual];
		}

		int medio = (inicio + fin) / 2;
		int nodoIzquierdo = 2 * nodoActual + 1;
		int nodoDerecho = 2 * nodoActual + 2;

		if (derecha <= medio) {
			return query(inicio, medio, nodoIzquierdo, izquierda, derecha);
		} else if (izquierda > medio) {
			return query(medio + 1, fin, nodoDerecho, izquierda, derecha);
		} else {
			Nodo maxIzquierdo = query(inicio, medio, nodoIzquierdo, izquierda, derecha);
			Nodo maxDerecho = query(medio + 1, fin, nodoDerecho, izquierda, derecha);

			Nodo result = new Nodo();
			result.maximo = Math.max(maxIzquierdo.maximo, maxDerecho.maximo);
			result.minimo = Math.min(maxIzquierdo.minimo, maxDerecho.minimo);
			result.multiplicacion = maxIzquierdo.multiplicacion * maxDerecho.multiplicacion;
			result.suma = maxIzquierdo.suma + maxDerecho.suma;
			return result;
		}
	}

	static void update(int inicio, int fin, int nodoActual, int posicion, int valor) {
		if (posicion < inicio && posicion > fin) {
			return;
		}

		if (inicio == fin) {
			segmentTree[nodoActual].maximo = a[inicio];
			segmentTree[nodoActual].minimo = a[inicio];
			segmentTree[nodoActual].suma = a[inicio];
			segmentTree[nodoActual].multiplicacion = a[inicio];
		} else {

			int mid = (inicio + fin) / 2;
			int nodoIzquierdo = 2 * nodoActual + 1;
			int nodoDerecho = 2 * nodoActual + 2;
			// Actualizar por lado izquierdo
			update(inicio, mid, nodoIzquierdo, posicion, valor);
			// Actualizar por lado derecho
			update(mid + 1, fin, nodoDerecho, posicion, valor);

			segmentTree[nodoActual].suma = segmentTree[nodoIzquierdo].suma + segmentTree[nodoDerecho].suma;
			segmentTree[nodoActual].maximo = Math.max(segmentTree[nodoIzquierdo].maximo,
					segmentTree[nodoDerecho].maximo);
			segmentTree[nodoActual].minimo = Math.min(segmentTree[nodoIzquierdo].minimo,
					segmentTree[nodoDerecho].minimo);
			segmentTree[nodoActual].multiplicacion = segmentTree[nodoIzquierdo].multiplicacion
					* segmentTree[nodoDerecho].multiplicacion;

		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] arreglo = bf.readLine().split(" ");
		for (int i = 0; i < arreglo.length; i++) {
			a[i] = Integer.parseInt(arreglo[i]);
		}
		init(0, arreglo.length - 1, 0);
		String operacion = "vacio";
		while (!operacion.equals("salir")) {
			operacion = bf.readLine();
			if (operacion.equals("query")) {
				String[] izquierdaDerecha = bf.readLine().split(" ");
				int izquierda = Integer.parseInt(izquierdaDerecha[0]);
				int derecha = Integer.parseInt(izquierdaDerecha[1]);
				Nodo respuesta = query(0, arreglo.length - 1, 0, izquierda, derecha);
				System.out.println(respuesta.maximo);
				System.out.println(respuesta.minimo);
				System.out.println(respuesta.suma);
				System.out.println(respuesta.multiplicacion);
			} else if (operacion.equals("update")) {
				String[] posicionValor = bf.readLine().split(" ");
				int posicion = Integer.parseInt(posicionValor[0]);
				int valor = Integer.parseInt(posicionValor[1]);
				a[posicion] = valor;
				update(0, arreglo.length - 1, 0, posicion, valor);
			}
		}
	}
}
