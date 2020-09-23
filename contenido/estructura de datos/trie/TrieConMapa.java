package estructurasDeDatos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;


public class TrieConMapa {
	static int tamanoAfabeto = 26;

	static class Nodo {
		Map<Character, Nodo> hijos;
		boolean FinDePalabra;

		Nodo() {
			FinDePalabra = false;
			hijos = new HashMap<Character, TrieConMapa.Nodo>();
		}
	}

	static Nodo raiz;

	static void agregarPalabra(String palabra) {
		Nodo nodoActual = raiz;
		int letras = palabra.length();
		for (int i = 0; i < letras; i++) {
			if (nodoActual.hijos.containsKey(palabra.charAt(i))) {
				nodoActual = nodoActual.hijos.get(palabra.charAt(i));
			} else {
				nodoActual.hijos.put(palabra.charAt(i), new Nodo());
				nodoActual = nodoActual.hijos.get(palabra.charAt(i));
			}
		}
		nodoActual.FinDePalabra = true;
	}

	static boolean buscarPalabra(String palabra) {
		Nodo nodoActual = raiz;
		int letras = palabra.length();
		for (int i = 0; i < letras; i++) {
			if (nodoActual.hijos.containsKey(palabra.charAt(i))) {
				nodoActual = nodoActual.hijos.get(palabra.charAt(i));
			} else {
				return false;
			}
		}
		return nodoActual.FinDePalabra;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String entrada = "nada";
		raiz = new Nodo();
		while (!entrada.equals("salir")) {
			entrada = bf.readLine();
			if (entrada.equals("buscar")) {
				entrada = bf.readLine();
				if (buscarPalabra(entrada)) {
					System.out.println("Si hay");
				} else {
					System.out.println("No hay");
				}
			} else if (entrada.equals("agregar")) {
				entrada = bf.readLine();
				agregarPalabra(entrada);
				System.out.println(entrada + " ha sido agregada");
			} 
		}
	}

}
