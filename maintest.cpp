#include "test.cpp"
//biblio algo, vector, surcharge, friend, virtual, iterator

int main(int argc, char *argv[])
{
  Testeur t1(10, "sam"), t2(2, "lolo"), t3;
  string name(t1.getFile("myName.txt"));
  cout << name << endl;
  t1.plusEleve();
  cout << t1 << endl;
  t3 = t2 - t1;
  cout << t3.get_age() << endl;

  t1.ranger();
  cout << t1 << endl;

  std::vector<int> tab;
  tab.push_back(2);
  tab.push_back(3);
  tab.push_back(1);
  tab.push_back(10);
  sort(tab.begin(), tab.end());

  for(std::vector<int>::iterator it = tab.begin(); it!=tab.end(); ++it){
    printf("%d\n", *it);
  }






}
