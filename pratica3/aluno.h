class Aluno {
  private:
    string nome;
    string mat;
  public:
    Aluno() {}
    Aluno(const char * nome, const char * mat) : nome(nome), mat(mat) {}
    void set(int idx, const Aluno & aluno);
    void exibir();

    friend class ostream;
    friend class Arranjo<Aluno>;
};

// ostream & operator<<(ostream & out, const Aluno & aluno) {
//   out << "mat = " << aluno.mat << " = " << aluno.nome;
//   return out;
// }

template<>
void Arranjo<Aluno>::set(int idx, const Aluno & aluno) {
  // atribua nome e mat individualmente para o item do array
  // isto é, pegue o aluno no array, e atribua cada campo um a um
  if (idx < 0 || idx > this->tamanho) {
    throw IndiceInvalido("Indice invalido");
  }
  
  this->items[idx].nome = aluno.nome;
  this->items[idx].mat = aluno.mat;

}

template<>
void Arranjo<Aluno>::exibir() {
  // exiba cada aluno do array no formato "idx : mat = nome"
  for (int i = 0; i < this->tamanho; i++) {
    Aluno aluno = this->items[i];
    //cout << i << " : " << aluno << endl;
    cout << i << " : " << "mat = " << aluno.mat << " = " << aluno.nome << endl;
  }
}
