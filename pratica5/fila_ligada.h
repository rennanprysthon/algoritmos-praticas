#include "fila.h" 

template <class T>
class FilaLigada: public Fila<T> {
	private:
		// array de itens, capacidade, tamanho, posição inicial, etc.
    struct Element {
      T value;
      Element * prox;
    };
    Element * start;
    Element * end; 
	public:
		FilaLigada(int capacidade) : Fila<T>(capacidade) {
			// inicializar array de items, capacidade, tamanho, posição inicial
			this->start = NULL;
      this->end = NULL;
		}
		 
		~FilaLigada() {
			// destruir items		
      while(this->size != 0) {
        this->desenfileira();
      }
    }
		 
		void enfileira(const T & item) {
			// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
			if (this->size == this->capacidade) {
			  throw "Fila cheia";
			}

      this->size++;
      
      Element * element = new Element();
      element->value = item;
      element->prox = NULL;

      if (this->start == NULL) {
        this->start = element;   
      } else {
        this->end->prox = element;
      }
      
      this->end = element;
		}

		T desenfileira() {
			// remove um item do inicio da fila; lança “Fila vazia” caso vazia
      if (this->start == NULL) {
        throw "Fila vazia";
      }

      this->size--;
 
      Element * temp = this->start;

      this->start = this->start->prox;

      if (this->start == NULL) {
        this->end = NULL;
      }

      T element = temp->value;

      delete temp;

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
