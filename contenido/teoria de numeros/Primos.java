package teoriaDeNumeros;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Primos {
	static boolean[] criba;
	static int[] exponentesDescomposicionPrimos;
	static int potenciar(int numero,int exponente) {
		int potencia=1;
		for (int i = 0; i < exponente; i++) {
			potencia*=numero;
		}
		return potencia;
	}
	static void llenarCriba() {
		Arrays.fill(criba, true);
		for (int i = 2; i < criba.length; i++) {
			if (criba[i]) {
				for (int j = i * 2; j < criba.length; j += i) {
					criba[j] = false;
				}
			}
		}
	}

	static void llenarExponentes(int numero) {
		for (int i = 2; i < criba.length && i <= numero + 1; i++) {
			while (criba[i] && numero % i == 0) {
				numero /= i;
				exponentesDescomposicionPrimos[i]++;
			}
		}
	}

	static int cantidadDeDivisores(int numero) {
		exponentesDescomposicionPrimos = new int[numero + 1];
		llenarExponentes(numero);
		int resultado = 1;
		for (int i = 1; i <= numero; i++) {
			if (exponentesDescomposicionPrimos[i] != 0) {
				resultado *= (exponentesDescomposicionPrimos[i] + 1);
			}
		}
		return resultado;
	}
	static int sumaDivisores(int numero) {
		exponentesDescomposicionPrimos = new int[numero + 1];
		llenarExponentes(numero);
		int resultado =1;
		for(int i=1;i<=numero;i++) {
			if (exponentesDescomposicionPrimos[i] != 0) {
				int yatusabe=(potenciar(i,exponentesDescomposicionPrimos[i]));
				int d=(i-1);
				int r=(potenciar(i,exponentesDescomposicionPrimos[i])-1)/(i-1);
				resultado=resultado*((potenciar(i,exponentesDescomposicionPrimos[i]+1)-1)/(i-1));
			}
		}
		return resultado;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		criba=new boolean[10000];
		llenarCriba();
		int numero=Integer.parseInt(bf.readLine());
		System.out.println(cantidadDeDivisores(numero));
		System.out.println(sumaDivisores(numero));
	}
}
