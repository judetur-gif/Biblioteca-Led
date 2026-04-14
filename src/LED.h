#ifndef LED_h
#define LED_h

#include <Arduino.h>

class Led
{
private:
    uint8_t pino;
    bool estado;
    bool desligarPorTempo;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;

    uint16_t repeticoes;

    void funcaoPiscar();
    void funcaoDesligamento();

public:
    Led(uint8_t pin);//Método construtor,

    void ligar();
    void ligar(uint16_t tempoligado_ms);

    void desligar();
    
    void piscar();
    void piscar(float frequencia);
    void piscar(float frequencia, uint16_t repeticoes);

    bool getEstado();
    uint8_t getPino();
    
    void setEstado(bool estado);

    void alternar();

    void update();
};

#endif