# Cub3D - 42cursus

## Description
Le projet **Cub3D** est un moteur de rendu en 3D basé sur le principe du **ray-casting** pour afficher un labyrinthe avec une vue subjective. Il permet au joueur de naviguer dans un environnement en 3D à l'aide des contrôles de la caméra. Le projet utilise la **MinilibX** pour gérer la fenêtre graphique et les interactions avec l'utilisateur.


### Affichage 3D avec Ray-Casting
Le moteur utilise **ray-casting** pour afficher le labyrinthe en 3D. Le principe est de simuler les rayons projetés depuis la position du joueur et de les utiliser pour calculer les intersections avec les murs du labyrinthe. Ces calculs permettent de générer des colonnes verticales qui, une fois assemblées, créent l'illusion d'un monde en 3D. Chaque rayon génère une portion de la scène, en tenant compte des distances et des textures.

### Contrôles du Joueur
Le joueur peut naviguer dans le labyrinthe avec les touches suivantes :
- **Flèches gauche et droite** : Rotation de la caméra, permettant de regarder à gauche ou à droite.
- **W, A, S, D** : Déplacement dans le labyrinthe (avant, arrière, gauche, droite).
- **ESC** : Fermeture de la fenêtre et sortie propre du programme.
- **Croix rouge de la fenêtre** : Le programme se ferme proprement si l'utilisateur clique sur la croix rouge.

### Gestion des Textures
Les murs du labyrinthe sont affichés avec des textures différentes en fonction de leur orientation (nord, sud, est, ouest). Ces textures sont chargées à partir des chemins définis dans le fichier de configuration `.cub`. Le programme s'assure que les textures sont correctement affichées en fonction de la direction dans laquelle le joueur se trouve.

### Couleurs du Sol et du Plafond
Les couleurs du sol et du plafond sont personnalisables et définies par les valeurs RGB dans le fichier `.cub`. Le programme prend en compte ces couleurs pour rendre le sol et le plafond de manière réaliste en fonction de la position du joueur et de son orientation.

### Gestion des Collisions
Un des ajouts importants à ce projet a été l'implémentation de la **gestion des collisions contre les murs**. Lorsqu'un joueur tente de se déplacer dans une direction, le programme vérifie si la case devant lui est un mur (défini par un `1` dans la carte). Si c'est le cas, le déplacement dans cette direction est bloqué, empêchant ainsi le joueur de traverser les murs. Cela rend le jeu plus réaliste et améliore l'interaction avec l'environnement.

### Fichier de Configuration `.cub`
La carte du labyrinthe et les paramètres associés sont définis dans un fichier de configuration `.cub`. Ce fichier inclut des informations sur les textures des murs (nord, sud, est, ouest), ainsi que les couleurs du sol et du plafond. La position initiale du joueur et son orientation sont également définies dans ce fichier, ce qui permet de démarrer le jeu avec une scène correctement configurée.

### Gestion de la Mémoire
Tout au long du développement, une attention particulière a été portée à la gestion de la mémoire. Aucune fuite mémoire n'a été laissée et toutes les ressources allouées dynamiquement sont correctement libérées lors de la fermeture du programme.

## Prérequis
- **MinilibX** : Bibliothèque nécessaire pour la gestion des fenêtres et des graphismes.
- **Libft** : Si vous utilisez une bibliothèque libft, elle doit être incluse dans le projet.

## Installation

Clonez ce dépôt sur votre machine locale :
```bash
git clone https://github.com/your-username/cub3d.git
cd cub3d
