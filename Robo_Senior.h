/*
* Arquivo modificado: Robo_Senior.h
* Mudança: Trocado sf::Clock e sf::Time por floats
* para funcionar com o clock estatico de Ente.
*/

#pragma once
#include "Inimigo.h"
#include <nlohmann/json.hpp>
namespace CyberMetro {
    namespace Entidades {
        namespace Personagens {
            using json = nlohmann::json;

            class Robo_Senior : public Inimigo
            {
            private:
                int tamanho;
                float tempoProximaCura;
                float intervaloCura;

                bool estaNoChao;
                static const float ALTURA_PULO;
                static const float FORCA_PULO;

            protected:
                float xINI;

            public:
                Robo_Senior(float xi, float yi);
                ~Robo_Senior();
                void mover();
                void executar();
                void danificar(Entidades::Personagens::Jogador* pJogador);
                void salvar();
                void curar();

                virtual json salvarDataBuffer() const override;
                virtual void carregarDeBuffer(const json& data) override;
            };
        }
    }
}