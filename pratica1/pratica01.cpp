#include <iostream>
#include "veiculo.cpp"
using namespace std;

//int main() {
// cout << "Primeira aplicalção C++" << endl;
// return 1;
//}

//int main () {
//  {
//    Veiculo veiculo("v2");
//    {
//      Veiculo veiculo3("v2");
//      {
//        Veiculo veiculo4("v3");
//      }
//    }
//  }
//  return 1;
//}


// int main() {
//  {
//    Veiculo * veiculo2 = new Veiculo("v1");
//    {
//      Veiculo * veiculo3 = new Veiculo("v2");
//      {
//        Veiculo * veiculo4 = new Veiculo("v3");
//        delete veiculo4; 
//      }
//      delete veiculo3; 
//    }
//    delete veiculo2; 
//  }
//}

int main () {
  Veiculo * veiculo = new Veiculo("v2");

  veiculo->setNumRodas(4);
  veiculo->setNumRodas(4);

  cout << "Numero de rodas: " << veiculo->getNumRodas() << endl;

  delete veiculo;
}
