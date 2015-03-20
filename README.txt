Pour lancer le programme :

- inclure le chemin vers la biblio glm
- se placer dans le répertoire ped/build-ped-isv-QT5-Debug/
- taper la commande make
- lancer l'exécutable ./ped_isv + nom_fichier + prototype + test

-> plusieurs nom_fichiers :

Pour le prototype :
- TestRobotFixe
- TestDroneFixe
- TestDroneMobile

Pour le drone :
- objet1.txt

-> prototype est un booléen qui permet au programme de savoir si on utilise un fichier de prototype (value = 1) ou non (value = 0).

-> test est un booléen qui permet de lancer les tests s'il vaut 1, 0 sinon.
Pour revenir à la scène demandée et non à la scène de test il faut faire un clic molette.

Il est possible de déplacer la scène à l'aide de la souris (bouton clic gauche maintenu)
et de zoomer/dezoomer à l'aide de sa molette.

/!\ Les déplacements se font dans le repère local de la scène cela peut être déroutant.
