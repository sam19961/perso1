#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>

enum sex{Homme, Femme, Autre};
enum situation{Couple, Celibataire};


//Questions: virtualiser un opérateur surchargé ?
//mieux tri fusion ou refaire un aglo ?
//complile: g++ -Wall -o test test.cpp
//Comment Passer un pointeur sur vecteur en paramètre d'une fonction
//nb: marche avec une référence
//operator ternaire (condition) ? (if_true) : (if_false)
//difference entre cerr, cout et clog
//switch avec comparaison type <= and <
//Classe abstraite si "virtual int nbrRoues() const = 0;"


/// gerer les erreurs d'inputs
/// mettre des valeurs par défaut à certains paramètres
/// __TIME__

class Personnage
{

  public:

  Personnage();
  Personnage(std::string nom, std::string prenom, int age, sex sex1, situation sit);
  Personnage(const char *filename);
  Personnage(std::string nom, std::string prenom, int age, sex sex1, situation sit, const char *filename);
  virtual ~Personnage();

  void afficheInformations() const;
  bool loadFromFile(const char *filename);
  bool saveToFile(const char *filename) const;
  void affichage(std::ostream& flux, Personnage const& p) const;
  static int nb_Personnage();


protected:


  std::string m_nom;
  std::string m_prenom;
  int m_age;
  sex m_sex;
  situation m_situation;

  static int compteur_Personnage;



};

class ExtPersonnage : public Personnage
{
public:
  ExtPersonnage();
  ExtPersonnage(std::string nom, std::string prenom, int age, sex sex1, situation sit);
  virtual ~ExtPersonnage();  //virtual hérité de Personnage et non necessaire ici

  void afficheInformations() const;
  void affichage(std::ostream& flux, ExtPersonnage const& p) const;
  static int nb_ExtPersonnage();

protected:
  static int compteur_ExtPersonnage;

};

#endif
