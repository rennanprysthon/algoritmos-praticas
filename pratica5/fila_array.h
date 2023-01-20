#include "fila.h" 

template <class T>
class FilaArray: public Fila<T> {
  private:
    T * items;
    int inicio;
    int fim;

  public:
    FilaArray(int capacidade) : Fila<T>(capacidade){
      this->items = new T[capacidade];
      this->inicio = 0;
      this->fim = 0;
    }
    
    ~FilaArray() {
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
      if (this->size == this->capacidade) {
        return 1; 
      }
      return 0;
    }
    
    int vazia () {
      if (this->size == 0) {
        return 1;
      }
      return 0;
    }
    
    int tamanho() {
      return this->size;   
    }
};
