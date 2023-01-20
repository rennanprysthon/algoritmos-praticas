class IndiceInvalido {
  private:
    IndiceInvalido () {}
    string message;
  public:
    IndiceInvalido(const char * msg);
    string getMessage();
};

IndiceInvalido::IndiceInvalido(const char * msg) {
  this->message = string(msg);
}

string IndiceInvalido::getMessage() {
  return this->message;
}
 
template <class T>
class Arranjo {
  private:
    int tamanho; // tamanho do arranjo
    T * items; //items do arranjo
  public:
    Arranjo(int tam) {
      // instanciar o array de items com new (pratica 1) e setar tamanho;
      this->tamanho = tam;
      this->items = new T[this->tamanho];
    }
     
    virtual ~Arranjo() {
      // destruir o array de items (prática 1);
      delete [] this->items;
    }
     
    virtual T get(int idx) {
      // retornar um item do array a partir do indice;
      if (idx < 0 || idx > this->tamanho) {
        cout << "Erro" <<endl;
        throw IndiceInvalido("Indice invalido");
      }

      return this->items[idx];
    }
     
    virtual void set(int idx, const T & item) {
      // set o item do array apontado pelo indice usando =
      if (idx < 0 || idx > this->tamanho) {
        throw IndiceInvalido("Indice invalido");
      }
      this->items[idx] = item;
    }

    virtual void exibir();
};
 
template<class T>
void Arranjo<T>::exibir() {
  // exibir cada item numa linha da forma "<idx>: <item>"
  for (int i = 0; i < this->tamanho; i++) {
    cout << i << " : " << this->items[i] << endl;
  } 
}

