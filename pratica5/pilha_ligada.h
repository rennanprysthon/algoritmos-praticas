#include "pilha.h"

template <class T>
class PilhaLigada : public Pilha<T>{
  private:
    struct Element {
      Element * prox;
      T value;
    };
    Element * top; 
  public:
    PilhaLigada(int capacidade) : Pilha<T>(capacidade){
      // instancia array de items, inicializa capacidade e topo
      this->top = NULL;
    }

    ~PilhaLigada() {
      // destroy array de items
      while(this->tam != 0) {
        this->desempilha();
      }
    }

    void empilha(T item) {
      // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
      if (this->tam + 1 > this->capacidade) {
        throw "Estouro da pilha";
      }

      this->tam++;

      Element * element = new Element();
      element->value = item;
      element->prox = this->top;

      this->top = element;
    }

    T desempilha() {
      // remove um item do topo da pilha; lança “Pilha vazia” se vazia
      if (this->tam == 0) {
        throw "Pilha vazia";
      }
      this->tam--;

      Element * temp = this->top;
      T value = temp->value;
      
      this->top = temp->prox;

      delete temp;

      return value; 
    }

    int tamanho() {
      // retorna o número de elementos na pilha.
      return this->tam;
    }
};
