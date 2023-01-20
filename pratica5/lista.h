template <class T>
class Lista {
  protected:
    int capacidade;
    int size;
  
  public:
    Lista(int capacidade) {
      this->capacidade = capacidade;
      this->size = 0;
    }
    virtual ~Lista() {}
    virtual void adiciona(const T & item) = 0;
    virtual T pega(int idx) = 0;
    virtual void insere(int idx, const T & item) = 0; 
    virtual void remove(int idx) = 0;
    virtual void exibe() = 0; 
    virtual int tamanho() = 0;
};
