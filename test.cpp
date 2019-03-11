#include "test.h"
#include <fstream>


using namespace std;

int Testeur::nb_testeur = 0;

Testeur::Testeur(): m_age(0), m_nom("inconnu")
{
  ++nb_testeur;
}

Testeur::Testeur(int age, string nom): m_age(age), m_nom(nom)
{
  ++nb_testeur;
}

Testeur::~Testeur()
{
  --nb_testeur;
}


string Testeur::get_nom()
{
  return m_nom;
}

int Testeur::get_age() const
{
  return m_age;
}

void Testeur::set_age(int age)
{
  m_age = age;
}

string Testeur::getFile(const char *Fily)
{
  string monNom;
  string fichierFily(Fily);
  ifstream fluxFily(fichierFily.c_str());
  getline(fluxFily, monNom);
  return monNom;

}

void Testeur::setFile(const char *Fily)
{
  string fichier(Fily);
  ofstream fluxFily(fichier);
  fluxFily << "bonjour le monde" << endl;

}

void Testeur::plusEleve()
{
  m_eleves.push_back(5);
  m_eleves.push_back(2);
  m_eleves.push_back(3);
  m_eleves.push_back(10);
  m_eleves.push_back(9);
}

/*void Testeur::ordre()
{
  m_eleves.sort();
}*/

void Testeur::affichageTab(ostream& flux) const
{
  for(int i(0); i<m_eleves.size(); ++i){
    cout << m_eleves[i] << endl;
  }

}

ostream& operator<<(ostream& flux, Testeur t)
{
    t.affichageTab(flux);
    return flux;
}

Testeur operator+(Testeur t1, Testeur t2)
{
  Testeur t3;
  t3.set_age(t1.get_age() + t2.get_age());
  return t3;

}

Testeur operator-(Testeur t1, Testeur t2)
{
  Testeur t3;
  t3.m_age = t1.m_age - t2.m_age;
  return t3;
}

void Testeur::ranger()
{
  sort(m_eleves.begin(), m_eleves.end());

}
