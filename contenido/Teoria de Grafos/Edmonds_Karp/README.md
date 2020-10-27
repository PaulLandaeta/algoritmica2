# Edmonds Karp 

El algoritmo Edmonds-Karp nos sirve para calcular el **flujo máximo** en una red de flujo. La ruta encontrada debe ser la ruta más corta que tenga capacidad disponible. Esto se puede encontrar mediante una **búsqueda en amplitud**. Otra propiedad de este algoritmo es que la longitud de la ruta de aumento más corta crece monótonamente.Por lo tanto, hay momentos en que un camino desde la fuente hasta el sumidero puede tomar más flujo, y ese es un camino en aumento.<br/>
Las rutas de aumento son simplemente cualquier ruta desde la fuente hasta el sumidero que actualmente puede tomar **más** flujo. 
<br/>

### Esquema inicial<br/>
![Unsolved Problem](https://github.com/AleS900/prueba/blob/master/assets/EK1.png)<br/><br/>
### _Primera Ruta:    **Min(100,50)=50**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK2.png)<br/><br/>
### _Segunda Ruta:    **Min(50,50,75)=50**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK3%20(1).png)<br/><br/>
### _Tercera Ruta:    **Min(50,100,25)=25**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EK4.png)<br/><br/>
### _**NO EXISTEN RUTAS DISPONIBLES**_<br/>
![Problem Solution Step 1](https://github.com/AleS900/prueba/blob/master/assets/EKF.png)
### _**FlujoMAX= 50 + 50 + 25 = 125**_<br/><br/>

## Algoritmos Base
### Código
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/EdmondsKarp.java) - _Java/T_
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/edmonds_karp.cpp) - _C++_
-  [Edmonds Karp](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/edmonds_karp) - _Python_

#### Entrada de Prueba
-  [Edmonds Karp - input](https://github.com/PaulLandaeta/algoritmica2/blob/master/contenido/Teoria%20de%20Grafos/Edmonds_Karp/in.txt)

## Problemas
### Juez Virtual
-  [UVa 820 - Internet Bandwidth](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=761)

## Referencias
### Sitios Web 
-  [Explicación - Código: Edmonds-Karp y Ford-Fulkerson](https://cp-algorithms.com/graph/edmonds_karp.html) - _CP-Algorithms_
-  [Explicación - Revisión: Edmonds-Karp](https://brilliant.org/wiki/edmonds-karp-algorithm/) - _Brilliant_
-  [Explicación - Pseudocódigo - Complejidad: Edmonds-Karp](https://iq.opengenus.org/edmonds-karp-algorithm-for-maximum-flow/) - _OpenGenus IQ: Learn Computer Science_
### Material Audiovisual
-  [Explicación: Edmonds-Karp](https://www.youtube.com/watch?v=RppuJYwlcI8)
-  [Explicación - Implementación: Edmonds-Karp](https://www.youtube.com/watch?v=GiN3jRdgxU4)
-  [Explicación - Analisís: Edmonds-Karp](https://www.youtube.com/watch?v=FlIB73vSl4s)
