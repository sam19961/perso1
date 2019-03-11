#include "Personnage.cpp"



int main(int argc, char *argv[])
{
  Personnage p1("mehramouz", "sam", 22, Homme, Couple); //Objet personnage basique
  cout << p1 << endl;

  Personnage p2("score.txt");// Objet personnage avec constructeur qui lit dans un fichier
  cout << p2 << endl;

  Personnage p3("Lolo", "LeS", 22, Homme, Couple, "non.txt"); // Objet perso avec une copie des infos dans un fichier
  cout << p3 << endl;

  ExtPersonnage p4("mehramouz", "sam", 22, Homme, Couple); //Objet fille de perso pour un affichage different
  cout << p4 << endl;



}
