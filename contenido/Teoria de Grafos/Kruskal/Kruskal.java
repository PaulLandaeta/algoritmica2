package teoriaDeGrafos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Kruskal {
	static int MAX_N = 100010;
	static int[] nodos = new int[10000];
	static int[] padres = new int[10000];
	static int[] rango = new int[10000];
	static int numeroNodos, numeroAristas;

	static void init() {
		for (int i = 0; i <= numeroNodos; i++) {
			padres[i] = i;
			rango[i] = 0;
		}
	}

	static int find(int x) {
		if (x == padres[x]) {
			return x;
		} else {
			padres[x] = find(padres[x]);
			return padres[x];
		}
	}

	static boolean mismoComponente(int nodoA, int nodoB) {
		return find(nodoA) == find(nodoB);
	}

	static void unionRango(int x, int y) {
		int xRaiz = find(x);
		int yRaiz = find(y);
		if (rango[xRaiz] > rango[yRaiz]) {
			padres[yRaiz] = xRaiz;
		} else {
			padres[xRaiz] = yRaiz;
			if (rango[xRaiz] == rango[yRaiz]) {
				rango[yRaiz]++;
			}
		}
	}

	static Arista[] aristas = new Arista[numeroAristas];
	static Arista[] MST = new Arista[MAX_N];

	static void kruskal() {
		int origen, destino, peso;
		int total = 0;
		int numAristasArbol = 0;
		init();
		Arrays.sort(aristas);
		for (int i = 0; i < numeroAristas; i++) {
			origen = aristas[i].origen;
			destino = aristas[i].destino;
			peso = aristas[i].peso;

			if (!mismoComponente(origen, destino)) {
				total += peso;
				MST[numAristasArbol++] = aristas[i];
				unionRango(origen, destino);
			}
		}

		if (numAristasArbol != numeroNodos - 1) {
			System.out.println("no existe un arbol de expansion minima");
		} else {
			for (int i = 0; i < numeroNodos - 1; i++) {
				System.out.print(MST[i].origen+" ");
				System.out.print(MST[i].destino+" ");
				System.out.println(MST[i].peso);
			}
			System.out.println(total);
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		numeroNodos=Integer.parseInt(bf.readLine());
		numeroAristas=Integer.parseInt(bf.readLine());
		aristas =new Arista[numeroAristas]; 
		for (int i = 0; i < numeroAristas; i++) {
			String[] linea= bf.readLine().split(" ");
			int inicio=Integer.parseInt(linea[0]);
			int fin=Integer.parseInt(linea[1]);
			int peso=Integer.parseInt(linea[2]);
			Arista nuevaArista=new Arista(inicio, fin, peso);
			aristas[i]=nuevaArista;
		}
		kruskal();
	}
}

class Arista implements Comparable<Arista> {
	int origen;
	int destino;
	int peso;

	public Arista(int origen, int destino, int peso) {
		this.origen = origen;
		this.destino = destino;
		this.peso = peso;
	}

	@Override
	public int compareTo(Arista o) {
		// TODO Auto-generated method stub
		return this.peso - o.peso;
	}

}
