#include <iostream>
using namespace std;
#include "veiculo.cpp"

// int main() {
//   Veiculo veiculo("veiculo 1");
//   Terrestre terrestre1("Terrestre 1");
//
//   Aquatico aquatico("Aquatico 1");
//   Aereo aereo("Aereo 1");
//
//   return 0;
// }

int main () {
  Veiculo * terr, * aqua, * aereo, * anfi;

  terr = new Terrestre("VT1");
  terr->mover();
  dynamic_cast<Terrestre*>(terr)->setCapacidadeMax(45);

  aqua = new Aquatico("VQ1");
  aqua->mover();
  dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);

  aereo = new Aereo("VA1");
  aereo->mover();
  ((Aereo *)aereo)->setVelocidadeMax(1040.5);

  anfi = new Anfibio("ANF1");
  anfi->mover();

  delete terr;
  delete aqua;
  delete aereo;
  delete anfi; 

  return 0;
}
