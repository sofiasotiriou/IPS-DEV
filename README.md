# INPS - Projet 1

## Pré-requis :
 - Armadillo, CXXTests
 - Python : numpy, matplotlib, pandas

## Compiler
```{shell}
make
```

## Executer le programme
```{shell}
bin/main
```

L'exécution produit un fichier csv contenant les valeurs à afficher dans _ressources/tab.csv_.
Ensuite, le fichier _src/plot.py_ est exécuté et affiche les courbes correspondantes aux données.


## Effacer les éléments temporaires
```{shell}
make clean
```

## Compiler et exécuter les tests
```{shell}
make test
```

## Forcer la compilation de la doc
```{shell}
make doc
```