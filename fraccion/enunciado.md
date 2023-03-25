### Descripcion

Haga un programa en el cual desarrolle una clase para manejo de números racionales. Un número racional debe tener un numerador y un denominador. Cree un constructor para instanciar numeros racionales especificando ambas partes del número, asi como un constructor para instanciarlo especificando la fracción en forma de cadena (por ejemplo "4/5"). Debe sobrecarar los opoeradores de suma, resta, multiplicación y división para permitir hacer operaciones entre fracciones. Todas estas operaciones deben poder hacerse entre dos fracciones, y también entre una fracción y un número entero. Todas estas operaciones dan como resultado un número racional. Tambien debe sobrecargar el operador de asignación para poder asignar los elementos de la fracción en forma de cadena.

Ademas, sobrecargue el operador << para poder enviar un número fraccionario al objeto cout para su impresión. Suponiendo que el numerador es 3 y el denominador 4, debe imprimir 3/4. Pero si el numerador es más grande que el denominador, deberá imprimir como una fracción mixta (entero y una fracción).

En la función main(), haga codigo para probar la clase. Debe crear varias instancias de numeros fraccionarios y realizar operaciones entre ellos, mostrando los resultados en pantalla. No es necesario un menú y que el usuario capture la información de los números.

El siguiente código debería funcionar (supeniendo que su clase se llame Fraccion).

    Fraccion f1(3, 4);          //crea la fraccion 3/4
    Fraccion f2("2/4");         //crea la fracción 2/4
    Fraccion f3= f1+ f2;
    cout<<f1<<"+"<<f2<<"="<<f3; //debe imprimir 3/4 + 2/4= 1 1/4