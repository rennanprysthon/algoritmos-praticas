#include "veiculo.h"

Veiculo::Veiculo(const char * pNome) {
  this->nome = string(pNome);
  cout << "Veiculo com nome " << this->nome << " foi criado" << endl;
}

Veiculo::~Veiculo() {}

Terrestre::Terrestre(const char * pNome) : Veiculo(pNome){
  this->cap_pass = 5;
}

int Terrestre::getCapacidadeMax() {
  return this->cap_pass;
}
 
void Terrestre::setCapacidadeMax(int capMax) {
  this->cap_pass = capMax;
}

void Terrestre::mover() {
  cout << "Veiculo terrestre moveu" << endl;
}

Terrestre::~Terrestre() {
  cout << "Veiculo terrestre foi destruido" << endl;
}
 
Terrestre::Terrestre() : Veiculo("qualquer") {}

Aquatico::Aquatico(const char * pNome) : Veiculo(pNome){
  this->carga_max = 10;  
}
 
float Aquatico::getCargaMax() {
   return this->carga_max;
}
 
void Aquatico::setCargaMax(float cargaMax) {
  this->carga_max = cargaMax;
}
 
void Aquatico::mover() {
  cout << "Veiculo aquatico moveu" << endl;
}
 
Aquatico::Aquatico() : Veiculo("qualquer") {}
 
Aquatico::~Aquatico() {
  cout << "Veiculo aquatico foi destruido" << endl;
}

Aereo::Aereo(const char * pNome) : Veiculo(pNome){
  this->vel_max = 100;
}

float Aereo::getVelocidadeMax() {
  return this->vel_max;
}
 
void Aereo::setVelocidadeMax(float velocidadeMax) {
  this->vel_max = velocidadeMax;
}
 
void Aereo::mover() {
  cout << "Veiculo aereo moveu" << endl;
}
 
Aereo::~Aereo() {
  cout << "Veiculo Aereo foi destruido" << endl;
}

Anfibio::Anfibio(const char * nome) : Veiculo(nome), Terrestre(), Aquatico() {}
 
void Anfibio::mover() {
  Terrestre::mover();
  Aquatico::mover();
}
