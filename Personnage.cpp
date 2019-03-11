#include "Personnage.h"
#include <fstream>
#define TAB_MAX  30


using namespace std;
int Personnage::compteur_Personnage = 0;
int ExtPersonnage::compteur_ExtPersonnage = 0;


void afficheArray(char tab[], int n)
{
  for(int i = 0; i<n; ++i){
    cout << tab[i];
  }
}

Personnage::Personnage(): m_nom(), m_prenom(), m_age(), m_sex(), m_situation()
{
  ++compteur_Personnage;
}

Personnage::Personnage(string nom, string prenom, int age, sex sex1, situation sit): m_nom(nom), m_prenom(prenom), m_age(age),
m_sex(sex1), m_situation(sit)
{
  ++compteur_Personnage;

}

Personnage::Personnage(const char *filename)
{
  ++compteur_Personnage;
  loadFromFile(filename);

}


Personnage::Personnage(string nom, string prenom, int age, sex sex1, situation sit, const char *filename): m_nom(nom),
m_prenom(prenom), m_age(age), m_sex(sex1), m_situation(sit)
{
  ++compteur_Personnage;
  saveToFile(filename);
}

Personnage::~Personnage()
{
  --compteur_Personnage;
}

ExtPersonnage::ExtPersonnage() : Personnage()
{
  ++compteur_ExtPersonnage;
}

ExtPersonnage::ExtPersonnage(string nom, string prenom, int age, sex sex1, situation sit):
Personnage(nom, prenom, age, sex1, sit)
{
  ++compteur_ExtPersonnage;
}

ExtPersonnage::~ExtPersonnage()
{
  --compteur_ExtPersonnage;
}


int Personnage::nb_Personnage()
{
  return compteur_Personnage;
}

int ExtPersonnage::nb_ExtPersonnage()
{
  return compteur_ExtPersonnage;
}


void Personnage::afficheInformations() const
{
    string sexaff, situationaff;
    if(m_sex == Homme){
      sexaff = "Mr";
    }
    else if(m_sex == Femme)
      sexaff = "Mme";
    else
      sexaff = "autre";

    (m_situation == Couple)? situationaff = "en couple": situationaff = "celibataire";




    cout << sexaff << " " << m_nom << " " << m_prenom << " est ne en " << 2018 - m_age <<
    " (" << m_age << " ans) "<< ", il est "<< situationaff << endl;
}

bool Personnage::loadFromFile(const char *filename)
{

  string age;
  string sex;
  string situation;
  string fichier(filename);
  ifstream leflux(fichier.c_str());
  if(leflux){
    getline(leflux, m_nom);
    getline(leflux, m_prenom);
    getline(leflux, age);
    m_age = stoi(age);

    getline(leflux, sex);
    if(sex == "Homme"){
      m_sex = Homme;
    }
    else if(sex == "Femme"){
      m_sex = Femme;
    }
    else
      m_sex = Autre;

    getline(leflux, situation);
    (situation == "couple")? m_situation = Couple : m_situation = Celibataire;;

      //fermeture de fichier automatique en fin de fonction
    return 1;
  }

  else
    return 0;

}

bool Personnage::saveToFile(const char *filename) const
{
  string fichier(filename);
  ofstream leflux(fichier.c_str());
  if(leflux){
    leflux << m_nom << endl;
    leflux << m_prenom << endl;
    leflux << m_age << endl;
    (m_situation == Couple)? leflux << "Couple" << endl : leflux << "Celibataire" << endl;

    if(m_sex == Homme){
      leflux << "Homme" << endl;
    }
    else if(m_sex == Femme){
      leflux << "Femme" << endl;
    }
    else
      leflux << "autre" << endl;

    return 1;
  }
  else
    return 0;
}

void ExtPersonnage::afficheInformations() const
{
  string act;
  int age = 2018 - m_age;
  int nb2(age%10), nb1;
  age /= 10;
  nb1 = age%10;
  char prenom;
  char nom[TAB_MAX];
  prenom = toupper(m_prenom[0]);

  if(m_age >= 0 and m_age < 12)
    act = "ENFANT";
  else if(m_age >=12 and m_age < 18)
    act = "ADOLESCENT";
  else if(m_age >=18 and m_age < 65)
    act = "ACTIF";
  else
    act = "RETRAITE";

  for(int i = 0; i<m_nom.length(); ++i){
    nom[i] = toupper(m_nom[i]);
  }

  cout << "[" << act << " : " << prenom << ".";
  afficheArray(nom, m_nom.length());
  cout << "-" << nb1 << nb2 << "]" << endl;
}

void Personnage::affichage(ostream& flux, Personnage const& p) const
{
  p.afficheInformations();

}

ostream& operator<<(ostream& flux, Personnage &p)
{
  p.affichage(flux, p);
  return flux;
}

void ExtPersonnage::affichage(ostream& flux, ExtPersonnage const& p) const
{
  p.afficheInformations();
}

ostream& operator<<(ostream& flux, ExtPersonnage& p)
{
  p.affichage(flux, p);
  return flux;
}
