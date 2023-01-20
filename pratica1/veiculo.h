#include <iostream>
using namespace std;

class Roda {
  public:
    Roda();
    ~Roda();
}; 

class Veiculo {
  private:
    string nome;
    int num_rodas;
    Roda * rodas;
  public:
    Veiculo(const char * param);
    ~Veiculo();
    void setNumRodas(int numRodas);
    int getNumRodas();
};

