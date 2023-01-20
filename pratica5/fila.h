template <class T>
class Fila {
	protected:
		// array de itens, capacidade, tamanho, posição inicial, etc.
		int capacidade;
		int size;
		int head;
		int tail;
	public:
		Fila(int capacidade) {
			// inicializar array de items, capacidade, tamanho, posição inicial
			this->capacidade = capacidade;
			this->size = 0;
			this->head = 0;
			this->tail = 0;
		}
		virtual ~Fila() {}
		virtual void enfileira(const T & item) = 0;
		virtual T desenfileira() = 0;
		virtual int cheia() = 0; 
		virtual int vazia() = 0;
		virtual int tamanho() = 0; 
};
