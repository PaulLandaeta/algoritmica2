package estructurasDeDatos;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UnionFind {
	static int[] padre = new int[10000];
	static int[] rango = new int[10000];
	static int n;
	static void init() {
		for(int i=0; i<=n;i++) {
			padre[i]=i;
			rango[i]=0;
		}
	}
	static int find(int x) {
		if(x==padre[x]) {
			return x;
		}else {
			padre[x]=find(padre[x]);
			return padre[x];
		}
	}
	static void unionRango(int x, int y) {
		int xRaiz = find(x);
		int yRaiz=find(y);
		if(rango[xRaiz]>rango[yRaiz]) {
			padre[yRaiz] = xRaiz;
		}else {
	        padre[xRaiz] = yRaiz;
	        if(rango[xRaiz] == rango[yRaiz]) {
	            rango[yRaiz]++;
	        }
	    }
	}
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		n=Integer.parseInt(bf.readLine());
		init();
		int uniones=Integer.parseInt(bf.readLine());
		while(uniones>0) {
			int x,y;
			String[] linea =bf.readLine().split(" ");
			x=Integer.parseInt(linea[0]);
			y=Integer.parseInt(linea[1]);
			unionRango(x, y);
			uniones--;
		}
		for(int i=0;i<=n;i++){ 
	        System.out.print("["+i+"] ");
	    }
		System.out.println();
		for(int i=0;i<=n;i++){ 
			System.out.print("["+padre[i]+"] ");
	    }
		System.out.println();
	    for(int i=0;i<=n;i++){ 
			System.out.print("["+rango[i]+"] ");
	    }
	    System.out.println();
	}
}
