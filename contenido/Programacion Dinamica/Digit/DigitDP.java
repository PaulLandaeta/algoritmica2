package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class DigitDP {
	static long[][][] dp = new long[12][2][83];
	static int k;

	static String tostring(long numeroAConvertir) {
		String numero = "";
		while (numeroAConvertir != 0) {
			char digito = (char) ((numeroAConvertir % 10) + '0');
			numeroAConvertir /= 10;
			numero = digito + numero;
		}
		return numero;
	}
	static long solucionar(String numero, int indice, int tope, int resto) {
		// tope es int pero solo recivirá los valores de 0 y 1
		if (indice == numero.length()) {
			if (resto == 0) {
				return 1;
			}
			return 0;
		}
		if (dp[indice][tope][resto] == -1) {
			int limite = 9;
			if (tope == 1) {
				limite = numero.toCharArray()[indice] - '0';
			}
			long numeroDivisiblek = 0;
			for (int digito = 0; digito <= limite; digito++) {
				int nuevoTope;
				if (digito < (numero.toCharArray()[indice] - '0')) {
					nuevoTope = 0;
				} else {
					nuevoTope = tope;
				}
				numeroDivisiblek += solucionar(numero, indice + 1, nuevoTope, (digito + resto) % k);
			}
			dp[indice][tope][resto] = numeroDivisiblek;
		}
		return dp[indice][tope][resto];
	}

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		int a,b;
		String[] linea =bf.readLine().split(" ");
		a= Integer.parseInt(linea[0]);
		b= Integer.parseInt(linea[1]);
		k= Integer.parseInt(linea[2]);
		String numeroA =tostring(a-1);
		String numeroB =tostring(b);
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				Arrays.fill(dp[i][j], -1);
			}
		}
		long solB = solucionar(numeroB, 0, 1, 0);

		long solA = solucionar(numeroA, 0, 1, 0);
		System.out.println((solB-solA));
	}
}
