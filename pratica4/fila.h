template <class T>
class Fila {
  private:
    T * items;
    int inicio;
    int size;
    int capacidade;

  public:
    Fila(int capacidade) {
      this->capacidade = capacidade; 
      this->items = new T[capacidade];
      this->size = 0;
      this->inicio = 0;
    }
    
    ~Fila() {
      delete [] this->items;
    }
    
    void enfileira(const T & item) {
      if (this->size >= this->capacidade) {
        throw "Lista cheia";
      }
      
      int index = (this->inicio + this->size) % this->capacidade;

      this->items[index] = item;

      this->size++;
    }

    T desenfileira() {
      if (this->size == 0) {
        throw "Lista vazia";
      }
      
      T element = this->items[this->inicio];
      this->inicio = (this->inicio + 1) % this->capacidade;
      this->size--;

      return element;
    }

    int cheia () {
      return this->size == this->capacidade;
    }
    
    int vazia () {
      return this->size == 0;
    }
    
    int tamanho() {
      return this->size;   
    }
};
