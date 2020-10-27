package estructurasDeDatos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BIT {
	static int[] BIT = new int[100001];
	static int tamanoArray;

	static void update(int posicion, int valor) {
		for (; posicion <= tamanoArray; posicion += posicion & -posicion) {
			BIT[posicion] += valor;
		}

	}

	static int query(int posicion) {
		int resultado = 0;
		for (; posicion > 0; posicion -= posicion & -posicion) {
			resultado += BIT[posicion];
		}
		return resultado;
	}

	static int query2(int inicio, int fin) {
		return query(fin) - query(inicio - 1);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		tamanoArray=Integer.parseInt(bf.readLine());
		String[] arreglo = bf.readLine().split(" ");
		int[] arregloNumerico = new int[tamanoArray];
		for (int i = 0; i < arreglo.length; i++) {
			arregloNumerico[i]=Integer.parseInt(arreglo[i]);
			update(i+1,arregloNumerico[i]);
		}
		int queries = Integer.parseInt(bf.readLine());
		while(queries!=0) {
			System.out.println("Ingrese su query");
			queries--;
			int q=Integer.parseInt(bf.readLine());
			System.out.println(query(q));
		}
	}
}
