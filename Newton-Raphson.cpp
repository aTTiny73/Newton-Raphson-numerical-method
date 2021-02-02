#include<iostream>
#include<cmath>
#include<vector> 
#include<string>

//Newton-Raphson numerical method for solving any order function//

void functionInput(int &max_numerator,int &max_denumerator,std::vector<double> &coefficient_b,std::vector<double>& coefficient_n){
  std::cout<<"Enter the polynominal function order:"<<std::endl;
  std::cin>>max_numerator;
   for(int i = 0;i<=max_numerator;i++){
     std::cout<<"Enter the coefficient associated with S^"<<max_numerator-i<<std::endl;
     double koef;
     std::cin>>koef;
     coefficient_b.push_back(koef);
   }
   std::cout<<"Enter the polynominal order of differentiated function:"<<std::endl;
   std::cin>>max_denumerator;
  for(int i = 0;i<=max_denumerator;i++){
     std::cout<<"Enter the coefficient associated with S^"<<max_denumerator-i<<std::endl;
     double koef;
     std::cin>>koef;
     coefficient_n.push_back(koef);
   }
   
}
double newton_raphson(double &S0,std::vector<double> &coefficient_b,std::vector<double>& coefficient_n){
  double result;
  double p1=0;
  double p2=0;
  int j=1;
  int k=1;
  for(int i=0;i<coefficient_b.size();i++){
    p1 += coefficient_b.at(i) * pow(S0,coefficient_b.size()-j);
    j++;
  }
 for(int i=0;i<coefficient_n.size();i++){
    p2 += coefficient_n.at(i) * pow(S0,coefficient_n.size()-k);
    k++;
  }
  result = S0-(p1/p2);
  S0=result;
  return result;
}

void printFunc(std::vector<double> &coefficient_b,std::vector<double> &coefficient_n){
  int i=0;
  int j=1;
  int k=1;
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
  for(i;i<coefficient_b.size();i++){
    if(coefficient_b.at(i)>0)
      std::cout<<"+"<<coefficient_b.at(i)<<"s^"<<coefficient_b.size()-j;
    else
      std::cout<<coefficient_b.at(i)<<"s^"<<coefficient_b.size()-j;
    j++;
  }
  std::cout<<std::endl;
  std::string a (25,'-');
  std::cout<<a<<std::endl;
  for(int z=0;z<coefficient_n.size();z++){
    if(coefficient_n.at(z)>0)
      std::cout<<"+"<<coefficient_n.at(z)<<"s^"<<coefficient_n.size()-k;
    else
      std::cout<<coefficient_n.at(j)<<"s^"<<coefficient_n.size()-k;
    k++;
  }
  std::cout<<std::endl;
  std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}

int main(){

  using namespace std;

  int max_numerator;
  int max_denumerator;
  double S0;
  vector<double> coefficient_b;
  vector<double> coefficient_n;
  int choice=0;

  while(choice!=4){
    cout<<"--Newton-Raphson Method--"<<endl<<"-------------------------"<<endl;
    cout<<"1.Enter the polynominal function"<<endl;
    cout<<"2.Choose another starting point"<<endl;
    cout<<"3.Print the entered polynominal function"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"-------------------------"<<endl;
    cin>>choice;
    switch(choice){
     case 1 :
       coefficient_b.clear();
       coefficient_n.clear();
       functionInput(max_numerator,max_denumerator,coefficient_b,coefficient_n);
       cout<<"Enter the number of iterations:"<<endl;
       int it;
       cin>>it;
       cout<<"Enter the starting point S0:"<<endl;
       cin>>S0;
       for(int i=0;i<it;i++){
         double result = newton_raphson(S0,coefficient_b,coefficient_n);
         cout<<result<<endl;
        }
       break;

     case 2 :
       if(coefficient_b.empty()||coefficient_n.empty())
         cout<<"Enter the polynominal function"<<endl;
       else{
         cout<<"Enter the number of iterations:"<<endl;
         int it1;
         cin>>it1;
         cout<<"Enter the starting point S0:"<<endl;
         cin>>S0;
         for(int i=0;i<it1;i++){
           double result = newton_raphson(S0,coefficient_b,coefficient_n);
           cout<<result<<endl;
          }
        }
       break;
  
     case 3:
        if(coefficient_b.empty()||coefficient_n.empty())
         cout<<"Enter the polynominal function"<<endl;
        else{
         printFunc(coefficient_b,coefficient_n);
        }
        break;

     case 4 :
       break;
    }
  }
}
