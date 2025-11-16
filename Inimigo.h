#pragma once
#include "Personagem.h"
#include "Jogador.h"
namespace CyberMetro {
    namespace Entidades {
        namespace Personagens
        {
            class Inimigo : public Personagem
            {
            protected:
                int nivel_maldade;
                int pontosPorMorte;

            public:
                Inimigo(float xi, float yi);
                virtual ~Inimigo();
                ;
                virtual void danificar(Entidades::Personagens::Jogador* pJogador) = 0;
                virtual void mover() = 0;
                virtual void executar() = 0;

                int getPontosPorMorte() const;
            };
        }
    }
}