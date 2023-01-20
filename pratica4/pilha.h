template <class T>
class Pilha {
  private:
    // Atributos para array de items, capacidade e topo da pilha
    T * items;
    int tam;
    int capacidade;
  public:
    Pilha(int capacidade) {
      // instancia array de items, inicializa capacidade e topo
      this->capacidade = capacidade;
      this->tam = 0;
      this->items = new T[this->capacidade];
    }
    ~Pilha() {
      // destroy array de items
      delete [] items;
    }
    void empilha(T item) {
      // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
      if (this->tam + 1 > this->capacidade) {
        throw "Estouro da pilha";
      }

      this->items[this->tam++] = item;
    }
    T desempilha() {
      // remove um item do topo da pilha; lança “Pilha vazia” se vazia
      if (this->tam == 0) {
        throw "Pilha vazia";
      }

      T item = this->items[--this->tam];
      return item;
    }
    int tamanho() {
      // retorna o número de elementos na pilha.
      return this->tam;
    }
};
