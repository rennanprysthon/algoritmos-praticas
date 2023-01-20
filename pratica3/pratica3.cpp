#include <iostream>
 
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

using namespace std;
using namespace func;

int main() {
  float x = 5.5, y = 10.15, z = 30.7;
  
  cout << "Antes: x = " << x << " y = " << y << endl;
  trocar(x, y);
  cout << "Depois : x = " << x << " y = " << y << endl;
  cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << endl;
  cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << endl;
   
  cout << "Minimo de \"strA\" e \"strB\": " << minimo("strA", "strB") << endl;
  cout << "Maximo de \"strA\" e \"strB\": " << maximo("strA", "strB") << endl;

  // Arranjo<int> arr(10);
  // arr.set(4, 5);
  // arr.set(7, 15);
  // arr.set(8, 22);
  // arr.exibir();    

  // try {
  //   Arranjo<float> arrFloat(10);
  //   arrFloat.set(2, 1.2);
  //   arrFloat.set(4, 5.2);
  //   arrFloat.set(1, 12.2);
  // arrFloat.set(11, 12.2);
  //   arrFloat.exibir();
  // } catch (IndiceInvalido in) {
  //   cout << "Error: " << in.getMessage() << endl;
  // }

  Arranjo<Aluno> turma(3);
  turma.set(0, Aluno("Joao","1234"));
  turma.set(1, Aluno("Maria","5235"));
  turma.set(2, Aluno("Jose","2412"));
  turma.exibir();

  return 0;
}

