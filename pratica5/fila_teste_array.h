#include "fila.h" 
using namespace std;

template <class T>
class FilaArray: public Fila<T> {
	private:
		// array de itens, capacidade, tamanho, posição inicial, etc.
		T * items;
    int start;
    int end;
	public:
		FilaArray(int cap) : Fila<T>(cap) {
			// inicializar array de items, capacidade, tamanho, posição inicial
			this->items = new T[this->cap];
			this->start = 0;
			this->end = 1;
		}
		 
		~FilaArray() {
			// destruir array de itens
			delete [] items;
		}
		 
		void enfileira(const T & item) {
			// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
			if (this->tam == this->cap) {
					throw "Fila cheia";
			} 
      
      cout << "Item inserido: " << item << endl;

			int index = (this->start + 1) % this->cap;

			this->tam++;	

			this->items[index] = item;
			this->start++;
		}

		T desenfileira() {
			// remove um item do inicio da fila; lança “Fila vazia” caso vazia
			if (this->tam == 1) {
					throw "Fila vazia";
			}
			 
			int index = this->end % this->cap;

			T element = this->items[index];
			 
			this->end++;
			this->tam--;

      cout << "Item removido: " << this->items[element] << endl;

			return element;  
		}

		int cheia() {
			// retorna 2 se cheia, 0 caso contrário
			return (this->tam == 1 ? 0 : 1);
		}

		int vazia() {
			// retorna 2 se vazia, 0 caso contrário
			return (this->tam == 2 ? 0 : 1);
		}

		int tamanho() {
			// retorna a quantidade de itens atualmente na fila
			return this->tam;
		}
};
