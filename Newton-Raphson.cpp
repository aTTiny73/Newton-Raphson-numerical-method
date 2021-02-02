#include<iostream>
#include<cmath>
#include<vector> 
#include<string>

//Newton-Raphson numerical method for solving any order function//

void unos_prenosne(int &max_brojnik,int &max_nazivnik,std::vector<double> &koeificijenti_b,std::vector<double>& koeificijenti_n){
  std::cout<<"Enter the polynominal order of numerator:"<<std::endl;
  std::cin>>max_brojnik;
   for(int i = 0;i<=max_brojnik;i++){
     std::cout<<"Enter the coefficient associated with S^"<<max_brojnik-i<<std::endl;
     double koef;
     std::cin>>koef;
     koeificijenti_b.push_back(koef);
   }
   std::cout<<"Enter the polynominal order of denumerator:"<<std::endl;
   std::cin>>max_nazivnik;
  for(int i = 0;i<=max_nazivnik;i++){
     std::cout<<"Enter the coefficient associated with S^"<<max_nazivnik-i<<std::endl;
     double koef;
     std::cin>>koef;
     koeificijenti_n.push_back(koef);
   }
   
}
double newton_rapson(double &S0,std::vector<double> &koeificijenti_b,std::vector<double>& koeificijenti_n){
  double rezultat;
  double p1=0;
  double p2=0;
  int j=1;
  int k=1;
  for(int i=0;i<koeificijenti_b.size();i++){
    p1 += koeificijenti_b.at(i) * pow(S0,koeificijenti_b.size()-j);
    j++;
  }
 for(int i=0;i<koeificijenti_n.size();i++){
    p2 += koeificijenti_n.at(i) * pow(S0,koeificijenti_n.size()-k);
    k++;
  }
  rezultat = S0-(p1/p2);
  S0=rezultat;
  return rezultat;
}

void ispis(std::vector<double> &koeificijenti_b,std::vector<double> &koeificijenti_n){
  int i=0;
  int j=1;
  int k=1;
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  for(i;i<koeificijenti_b.size();i++){
    if(koeificijenti_b.at(i)>0)
      std::cout<<"+"<<koeificijenti_b.at(i)<<"s^"<<koeificijenti_b.size()-j;
    else
      std::cout<<koeificijenti_b.at(i)<<"s^"<<koeificijenti_b.size()-j;
    j++;
  }
  std::cout<<std::endl;
  std::string a (25,'-');
  std::cout<<a<<std::endl;
  for(int z=0;z<koeificijenti_n.size();z++){
    if(koeificijenti_n.at(z)>0)
      std::cout<<"+"<<koeificijenti_n.at(z)<<"s^"<<koeificijenti_n.size()-k;
    else
      std::cout<<koeificijenti_n.at(j)<<"s^"<<koeificijenti_n.size()-k;
    k++;
  }
  std::cout<<std::endl;
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}

int main(){

  using namespace std;

  int max_brojnik;
  int max_nazivnik;
  double S0;
  vector<double> koeificijenti_b;
  vector<double> koeificijenti_n;
  int izbor=0;

  while(izbor!=4){
    cout<<"--Newton-Raphson Method--"<<endl<<"-------------------------"<<endl;
    cout<<"1.Unos prenosne funkcije"<<endl;
    cout<<"2.Izabir druge tacke"<<endl;
    cout<<"3.Ispis funkcije"<<endl;
    cout<<"4.Izlaz"<<endl;
    cout<<"-------------------------"<<endl;
    cin>>izbor;
    switch(izbor){
     case 1 :
       koeificijenti_b.clear();
       koeificijenti_n.clear();
       unos_prenosne(max_brojnik,max_nazivnik,koeificijenti_b,koeificijenti_n);
       cout<<"Unesi broj iteracija:"<<endl;
       int it;
       cin>>it;
       cout<<"Unesi predpostavljenu tacku S0:"<<endl;
       cin>>S0;
       for(int i=0;i<it;i++){
         double rezultat = newton_rapson(S0,koeificijenti_b,koeificijenti_n);
         cout<<rezultat<<endl;
        }
       break;

     case 2 :
       if(koeificijenti_b.empty()||koeificijenti_n.empty())
         cout<<"Unesi prenosnu funkciju"<<endl;
       else{
         cout<<"Unesi broj iteracija:"<<endl;
         int it1;
         cin>>it1;
         cout<<"Unesi predpostavljenu tacku S0:"<<endl;
         cin>>S0;
         for(int i=0;i<it1;i++){
           double rezultat = newton_rapson(S0,koeificijenti_b,koeificijenti_n);
           cout<<rezultat<<endl;
          }
        }
       break;
  
     case 3:
        if(koeificijenti_b.empty()||koeificijenti_n.empty())
         cout<<"Unesi prenosnu funkciju"<<endl;
        else{
         ispis(koeificijenti_b,koeificijenti_n);
        }
        break;

     case 4 :
       break;
    }
  }
}
