#ifndef LED_h
#define LED_h

#include <Arduino.h>



/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, desligar, ligar por tempo determinado, piscar continuamente e piscar por quantidade definida.
 * 
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
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

    /**
     * @brief Processa a loógica de piscada do LED.
     */
    void funcaoPiscar();
    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();



public:
/**
 * @brief Constroi um objeto LED.
 * @param pin Número do pino digital onde LED está conectado.
 */
    Led(uint8_t pin);
/**
 * @brief Liga o LED continuamente.
 */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint16_t tempoligado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();
    
    /**
     * @brief Inicia a piscada contínua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Inicia piscada continua com a frequancia.
     * @param frequencia  Quantidade aonde vai as piscadas.
     */
    void piscar(float frequencia);

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequencia da piscada em hertz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Retorna o resultado do estado.
     */
    bool getEstado();

    /**
     * @brief Retorna o estado do pino.
     */
    uint8_t getPino();
    
    /**
     * @brief Define manualmente o estado do LED.
     * @param estado true para ligado, false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Altera o estado do pino.
     */
    void alternar();

    /**
     * @brief Registra o estado.
     */
    void update();
};

#endif