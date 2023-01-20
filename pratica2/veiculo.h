#include <iostream>

class Veiculo {
  protected:
    string nome;
  public:
    Veiculo(const char * pNome);
    virtual void mover() = 0;
    virtual ~Veiculo() = 0;
};

class Terrestre : public virtual Veiculo {
  private:
    int cap_pass;
  protected:
    Terrestre();
  public:
    Terrestre(const char * pNome);
    int getCapacidadeMax();
    void setCapacidadeMax(int capMax);
    void mover();
    virtual ~Terrestre();
};

class Aquatico : public virtual Veiculo {
  private:
    float carga_max;
  protected:
    Aquatico();
  public:
    Aquatico(const char * pNome);
    float getCargaMax();
    void setCargaMax(float cargaMax);
    void mover();
    virtual ~Aquatico();
};

class Aereo : public Veiculo {
  private:
    float vel_max;
  public:
    Aereo(const char * pNome);
    float getVelocidadeMax();
    void setVelocidadeMax(float velocidadeMax);
    void mover();
    virtual ~Aereo();
};

class Anfibio : public virtual Veiculo, public Terrestre, public Aquatico {
  public:
    Anfibio(const char * nome);
    void mover();
};
 
