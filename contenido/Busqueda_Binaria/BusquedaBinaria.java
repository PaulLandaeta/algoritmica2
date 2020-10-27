package teoriaDeNumeros;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BusquedaBinaria {
	static int arr[];

	static int busquedaBinariaRecursiva(int izquierda, int derecha, int objetivo) {
		if (derecha >= izquierda) {
			int medio = izquierda + (derecha - izquierda) / 2;
			if (arr[medio] == objetivo) {
				return medio;
			} else if (arr[medio] > objetivo) {
				return busquedaBinariaRecursiva(izquierda, medio - 1, objetivo);
			} else {
				return busquedaBinariaRecursiva(medio + 1, derecha, objetivo);
			}
		} else {
			return -1;
		}
	}

	static int busquedaBinariaIterativa(int objetivo) {
		int izquierda = 0;
		int derecha = arr.length - 1;
		while (izquierda <= derecha) {
			int medio = izquierda + (derecha - izquierda) / 2;
			if (arr[medio] == objetivo) {
				return medio;
			}
			if (arr[medio] < objetivo) {
				izquierda = medio + 1;
			} else {
				derecha = medio - 1;
			}
		}
		return -1;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] arreglo = bf.readLine().split(" ");
		arr = new int[arreglo.length];
		for (int i = 0; i < arreglo.length; i++) {
			arr[i] = Integer.parseInt(arreglo[i]);
		}
		Arrays.sort(arr);
		int objetivo = Integer.parseInt(bf.readLine());
		System.out.println(busquedaBinariaIterativa(objetivo));
		System.out.println(busquedaBinariaRecursiva(0, arr.length-1, objetivo));
	}
}
