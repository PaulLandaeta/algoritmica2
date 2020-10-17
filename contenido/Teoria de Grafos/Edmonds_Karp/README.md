# Edmonds Karp 

El algoritmo Edmonds-Karp nos sirve para calcular el **flujo máximo** en una red de flujo. La ruta encontrada debe ser la ruta más corta que tenga capacidad disponible. Esto se puede encontrar mediante una **búsqueda en amplitud**. Otra propiedad de este algoritmo es que la longitud de la ruta de aumento más corta crece monótonamente.Por lo tanto, hay momentos en que un camino desde la fuente hasta el sumidero puede tomar más flujo, y ese es un camino en aumento.<br/>
Las rutas de aumento son simplemente cualquier ruta desde la fuente hasta el sumidero que actualmente puede tomar **más** flujo. 
<br/>

![Unsolved Problem](https://github.com/AleS900/prueba/blob/master/assets/EK1.png)<br/>
_**Min(100,50)=<p style='color:red'>50</p>**_
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK2.png)<br/>
_**Min(100,50)=50**_
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK3%20(1).png)<br/>
_**Min(50,50,75)=50**_
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK4.png)<br/>
_**Min(50,100,25)=25**_
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EKF.png)<br/>
_**Min(100,50)=50**_

### Código
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenidoeoria%20de%20Grafos/Edmonds_Karp/EdmondsKarp.java) - _Java/T
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/edmonds_karp.cpp) - _C++
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/edmonds_karp) - _Python

### Entrada de Prueba
-  [Edmonds Karp - input](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/in.txt)

## Problemas
### Juez Virtual
-  [UVa 10034 - Freckles](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Kruskal/in.txt)

## Referencias
### Sitios Web 
-  [Árbol de Expansión Mínima: Algoritmo de Kruskal](https://jariasf.wordpress.com/2012/04/19/arbol-de-expansion-minima-algoritmo-de-kruskal/)
-  [Explicación: Algoritmo de Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html)
-  [Explicación: Digit DP - CodeForces](https://codeforces.com/blog/entry/53960)

