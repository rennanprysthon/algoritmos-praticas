template <class T>
class Pilha {
  protected:
    // Atributos para array de items, capacidade e topo da pilha
    int tam;
    int capacidade;
  public:
    Pilha(int capacidade) {
      // instancia array de items, inicializa capacidade e topo
      this->capacidade = capacidade;
      this->tam = 0;
    }
    virtual ~Pilha() {}
    
    virtual void empilha(T item) = 0;
    virtual T desempilha() = 0; 
    virtual int tamanho() = 0;
};
