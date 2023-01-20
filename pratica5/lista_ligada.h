#include <iostream>
#include "lista.h"
using namespace std;

template <class T>
class ListaLigada: public Lista<T> {
  private:
    // atributos:
    // - itens da lista (ponteiro para T usado como array)
    // - capacidade e tamanho atual (inteiros)
    struct Element {
      Element * prox;
      T value;
    };
    Element * start;
    Element * end;
  public:
    ListaLigada(int capacidade): Lista<T>(capacidade) {
      // inicilização do array de itens, capacidade e tamanho
      this->start = NULL;
      this->end = NULL;
    }

    ~ListaLigada() {
      //destruição dos items 
      for (int index = 0; index < this->size; index++) {
        this->remove(index + 1);
      }
    }

    // adiciona um item ao final da lista
    void adiciona (const T & item) {
      // lança “Lista cheia” caso capacidade esgotada (testar antes)
      if (this->size == this->capacidade) {
			  throw "Lista cheia";
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

    Element * find(int idx) {
      Element * temp = this->start;
      idx = idx - 1;
      while(idx != 0) {
        temp = temp->prox;
        idx--;
      }
      return temp;
    }

    // pega um item pelo indice (começa em 1);
    T pega(int idx) {
      // lança “Item inválido” se posição inválida (testar antes)
      // ATENÇÃO: posições válidas são de 1 a N (= capacidade).
      if (idx < 1 || idx > this->size) {
        throw "Item invalido";
      }      
      
      Element * temp = this->find(idx);
      return temp->value;
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
      
      Element * element = new Element();
      element->value = item;
      element->prox = NULL;

      if (idx == 1) {
        element->prox = this->start;    
        this->start = element;
      } else {
        Element * anterior = this->find(idx - 1); 
        element->prox = anterior->prox;
        anterior->prox = element;
      }
    }

    // remove o item de uma posição indicada (a partir de 1)
    void remove(int idx) {
      // lança “Item inválido” se posição inválida
      // desloca itens uma posicao a esquerda sobre o item removido
      if (idx < 1 || idx > this->size) {
        throw "Item invalido";
      }      
      
      this->size--;
      
      Element * temp;

      if (idx == 1) {
        temp = this->start; 
        this->start = start->prox;
        if (this->end == temp) {
          this->end = NULL;
        }       
      } else {
        Element * anterior = this->find(idx - 1);
        temp = anterior->prox;
        anterior->prox = anterior->prox->prox;
        if (this->end == temp) {
          this->end = anterior;
        }
      }

      delete temp;
    }
    void exibe() {
      // exibe os itens da saida padrão separados por espaços
      for (int index = 0; index < this->size; index++) {
        if (index == this->size - 1) {
          cout << this->pega(index + 1) << "\n";
        } else {
          cout << this->pega(index + 1) << ", " ;
        }
      }
    }
    int tamanho() {
      // retorna a quantidade de itens atualmente na lista
      return this->size;
    }
};
