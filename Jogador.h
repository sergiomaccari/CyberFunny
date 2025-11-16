#pragma once
#include "Personagem.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include <nlohmann/json.hpp>

namespace CyberMetro {
    namespace Fases
    {
        class Fase;
    }
    namespace Entidades {
        namespace Personagens
        {
            using json = nlohmann::json;

            class Jogador : public Personagem
            {
            private:
                int pontos;
                Listas::ListaEntidades projeteis;
                int cooldown;
                int playerNum;
                float ultimaDirecaoX;
                static const float PROJETIL_VELOCIDADE_JOGADOR;

                sf::Time stun;
                sf::Time obstaculoCooldown;

                Fases::Fase* pFaseAtual;

            public:
                Jogador(int numJogador);
                Jogador(int numJogador, float xi, float yi);
                virtual ~Jogador();
                void mover();
                void executar();
                void salvar();

                void atirar();
                Listas::ListaEntidades* getProjeteis();
                void trava_mov(float t);

                void iniciarObstaculoCooldown(sf::Time duracao);
                sf::Time getObstaculoCooldown() const;

                void resetar(float posX, float posY);
                void adicionarPontos(int p);

                int getPontos() const;

                virtual json salvarDataBuffer() const;
                virtual void carregarDeBuffer(const json& data);
            };
        }
    }
}