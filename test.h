#include <string.h>
#include <iostream>
#include <vector>

class Testeur
{
public:
  Testeur();
  Testeur(int age, std::string nom);
  ~Testeur();
  std::string get_nom();
  int get_age() const;
  void set_age(int age);
  std::string getFile(const char *Fily);
  void setFile(const char *Fily);
  void plusEleve();
  void affichageTab(std::ostream& flux) const;
  void ranger();
  //void ordre();

protected:
  std::vector<int> m_eleves;
  int m_age;
  std::string m_nom;
  static int nb_testeur;

  friend Testeur operator-(Testeur t1, Testeur t2);


};
