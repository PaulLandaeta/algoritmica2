package backTracking;

import java.io.IOException;

public class Queen8 {
	static int[] filas = new int[8];
	static boolean solucionHallada =false;

	static boolean esValido(int fila, int columna) {
		for (int previo = 0; previo < columna; previo++) {
			if (filas[previo] == fila || Math.abs(filas[previo] - fila) == Math.abs(previo-columna)) {
				return false;
			}
		}
		return true;
	}

	static void solucionar(int columna) {
		if (columna == 8) {
			for (int i = 0; i < 8; i++) {
				System.out.print("[" + (filas[i] + 1) + "] ");
			}
			System.out.println();
			solucionHallada = true;
			return;
		}
		for (int fila = 0; fila < 8; fila++) {
			if (esValido(fila, columna)) {

				filas[columna] = fila;
				solucionar(columna + 1);
				if(solucionHallada) {
					break;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		solucionar(0);
	}
}
