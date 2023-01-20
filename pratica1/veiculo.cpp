#include <iostream>
#include "veiculo.h"

Roda::Roda() {
  cout << "Roda criada" << endl;
}

Roda::~Roda() {
  cout << "Roda destruida" << endl;
}

Veiculo::Veiculo(const char * param) {
  this->nome = string(param);
  this->rodas = NULL;
}

Veiculo::~Veiculo(){ 
  cout << "Veiculo destruido" << endl;
  delete [] rodas;
}

void Veiculo::setNumRodas(int numRodas) {
  delete [] rodas;
  this->num_rodas = numRodas;
  this->rodas = new Roda[this->num_rodas];
}

int Veiculo::getNumRodas() {
  return this->num_rodas;
}

