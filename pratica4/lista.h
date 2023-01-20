using namespace std;

template <class T>
class Lista {
  private:
    // atributos:
    // - capacidade e tamanho atual (inteiros)
    // - itens da lista (ponteiro para T usado como array)
    T * items; 
    int capacidade;
    int size;
  public:
    Lista(int capacidade) {
      // inicilização do array de itens, capacidade e tamanho
      this->items = new T[capacidade];
      this->capacidade = capacidade;
      this->size = 0;
    }

    ~Lista() {
      //destruição do array
      delete [] items;
    }
    // adiciona um item ao final da lista
    void adiciona (const T & item) {
      // lança “Lista cheia” caso capacidade esgotada (testar antes)
      if (this->size == this->capacidade) {
        throw "Lista cheia";
      }

      this->items[this->size++] = item;
    }
     // pega um item pelo indice (começa em 1);
    T pega(int idx) {
      // lança “Item inválido” se posição inválida (testar antes)
      // ATENÇÃO: posições válidas são de 1 a N (= capacidade).
      if (idx < 1 || idx > this->size) {
        throw "Item invalido";
      }      
      
      return this->items[idx - 1];
    }
    // insere um item na posição indicada (a partir de 1).
    void insere (int idx, const T & item) {
      // lança “Lista cheia” caso cheia
      // lança “Item inválido” se posição inválida
      // se a lista contém N itens, só é possivel inserir até a posição N
      // deve deslocar itens existentes uma posição para a direita

      if (this->size == this->capacidade) {
        throw "Lista cheia";
      }

      if (idx < 1 || idx > this->capacidade) {
        throw "Item invalido";
      }      

      this->size++;

      for (int index = this->size; index > idx - 1; index--) {
        this->items[index] = this->items[index - 1];
      }
      
      this->items[idx - 1] = item;
    }

    // remove o item de uma posição indicada (a partir de 1)
    void remove(int idx) {
      // lança “Item inválido” se posição inválida
      // desloca itens uma posicao a esquerda sobre o item removido
      if (idx < 1 || idx > this->size) {
        throw "Item invalido";
      }      
      
      for (int index = idx - 1; index < this->capacidade; index++) {
        this->items[index] = this->items[index + 1];
      } 

      this->size--;
    }

    void exibe() {
      // exibe os itens da saida padrão separados por espaços
      for (int index = 0; index < this->size; index++) {
        if (index == this->size - 1) {
          cout << this->items[index] << "\n";
        } else {
          cout << this->items[index] << ", " ;
        }
      }
    }
    int tamanho() {
      // retorna a quantidade de itens atualmente na lista
      return this->size;
    }
};
