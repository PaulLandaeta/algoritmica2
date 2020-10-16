package teoriaDeGrafos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class EdmondsKarp {
	static int[][] grafo;
	static int[] camino;
	static int numeroDeNodos;
	static int numeroDeAristas;

	static int maximoFlujo(int s, int t) {
		// s nodo inicial
		// t nodo final
		int flujoMaximo = 0;
		while (true) {
			Arrays.fill(camino, -1);
			Queue<Integer> cola = new LinkedList<Integer>();
			cola.add(s);
			camino[s] = s;
			while (!cola.isEmpty() && camino[t] == -1) {
				int nodoActual = cola.poll();

				for (int i = 0; i <= numeroDeNodos; i++) {
					if (camino[i] == -1 && grafo[nodoActual][i] > 0) {
						camino[i] = nodoActual;
						cola.add(i);
					}
				}
			}
			int flujoMinimo = 1000000000;
			if (camino[t] == -1) {
				break;
			}
			for (int inicio = camino[t], fin = t; inicio != fin; inicio = camino[fin = inicio]) {
				flujoMinimo = Math.min(flujoMinimo, grafo[inicio][fin]);
			}
			for (int inicio = camino[t], fin = t; inicio != fin; inicio = camino[fin = inicio]) {
				grafo[fin][inicio]+=flujoMinimo;
				grafo[inicio][fin]-=flujoMinimo;
			}
			flujoMaximo+=flujoMinimo;
		}
		return flujoMaximo;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] linea = bf.readLine().split(" ");
		numeroDeNodos=Integer.parseInt(linea[0]);
		numeroDeAristas=Integer.parseInt(linea[1]);
		grafo=new int[numeroDeNodos+1][numeroDeNodos+1];
		camino=new int[numeroDeNodos+1];
		for (int i = 0; i < grafo.length; i++) {
			Arrays.fill(grafo[i], -1);
		}
		for (int i = 0; i < numeroDeAristas; i++) {
			linea=bf.readLine().split(" ");
			int origen=Integer.parseInt(linea[0]);
			int destino=Integer.parseInt(linea[1]);
			int capacidad=Integer.parseInt(linea[2]);
			grafo[origen][destino]=capacidad;
			grafo[destino][origen]=0;
		}
		System.out.println(maximoFlujo(1, 8));
	}

}
