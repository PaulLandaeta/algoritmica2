package estructurasDeDatos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Trie {
	static int tamanoAlfabeto = 26;

	static class Nodo {
		Nodo[] hijos = new Nodo[tamanoAlfabeto];
		boolean FinDePalabra;

		Nodo() {
			FinDePalabra = false;
			for (int i = 0; i < tamanoAlfabeto; i++)
				hijos[i] = null;
		}
	}

	static Nodo raiz;

	static void agregarPalabra(String palabra) {
		Nodo nodoActual = raiz;
		int letras = palabra.length();
		for (int i = 0; i < letras; i++) {
			char caracter = palabra.charAt(i);
			if (nodoActual.hijos[caracter - 'a'] == null) {
				nodoActual.hijos[caracter - 'a'] = new Nodo();
			}
			nodoActual = nodoActual.hijos[caracter - 'a'];
		}
		nodoActual.FinDePalabra = true;
	}

	static boolean busqueda(String palabra) {
		int letras = palabra.length();
		Nodo nodoActual = raiz;
		for (int i = 0; i < letras; i++) {
			char caracter = palabra.charAt(i);
			if (nodoActual.hijos[caracter - 'a'] == null) {
				return false;
			} else {
				nodoActual = nodoActual.hijos[caracter - 'a'];
			}
		}
		return nodoActual.FinDePalabra;
	}

	static void borrarPalabra(String palabra) {
		int letras = palabra.length();
		Nodo nodoActual = raiz;
		for (int i = 0; i < letras; i++) {
			char caracter = palabra.charAt(i);
			if (nodoActual.hijos[caracter - 'a'] == null) {
				break;
			} else {
				nodoActual = nodoActual.hijos[caracter - 'a'];
			}
		}
		if (nodoActual.FinDePalabra) {
			nodoActual.FinDePalabra = false;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String entrada = "nada";
		raiz = new Nodo();
		while (!entrada.equals("salir")) {
			entrada = bf.readLine();
			if (entrada.equals("buscar")) {
				entrada = bf.readLine();
				if (busqueda(entrada)) {
					System.out.println("Si hay");
				} else {
					System.out.println("No hay");
				}
			} else if (entrada.equals("agregar")) {
				entrada = bf.readLine();
				agregarPalabra(entrada);
				System.out.println(entrada + " ha sido agregada");
			} else if (entrada.equals("eliminar")) {
				entrada = bf.readLine();
				borrarPalabra(entrada);
				System.out.println(entrada + " ha sido borrada");
			}
		}
	}
}
