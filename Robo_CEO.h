/*
* Arquivo modificado: Robo_CEO.h
* Mudança: - Adicionado includes e declarações para salvar/carregar.
* - Corrigido 'const' para variaveis de tiro.
*/

#pragma once
#include "Inimigo.h"
#include "Jogador.h" 
#include "ListaEntidades.h"
#include "Projetil.h"
#include <nlohmann/json.hpp>
namespace CyberMetro {
    namespace Entidades {
        namespace Personagens {
            using json = nlohmann::json;

            class Robo_CEO : public Inimigo {
            private:
                int forca;
                Jogador* pJogador;
                Listas::ListaEntidades projeteis;

                float PROJETIL_VELOCIDADE_CHEFE;
                static const int COOLDOWN_TIRO_CHEFE_FRAMES;
                const float FORCA_GRAVIDADE_CHEFE;
                int cooldownTiro;

                void atirar();

            public:
                Robo_CEO(float xi, float yi);
                ~Robo_CEO();
                void mover();
                void executar();
                void danificar(Jogador* pJogador);
                void salvar();
                void setJogador(Jogador* j);
                Listas::ListaEntidades* getProjeteis();
                void anti_gravidade(sf::Vector2f* pos);
                virtual json salvarDataBuffer() const;
                virtual void carregarDeBuffer(const json& data);
            };
        }
    }
}