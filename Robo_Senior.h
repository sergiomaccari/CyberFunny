#pragma once
#include "Inimigo.h"
// sf::Clock e sf::Time em entidade

namespace Personagens {
    class Robo_Senior : public Inimigo
    {
    private:
        int tamanho;
        sf::Clock tempoCura;
        sf::Time intervaloCura;

    protected:
        int volta;
        float xINI;
        int ALCANCE;

    public:
        Robo_Senior(float xi, float yi);
        ~Robo_Senior();
        void mover();
        void executar();
        void danificar(Jogador* pJogador);
        void salvar();
    };
}