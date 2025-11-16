#pragma once
#include "Obstaculo.h"
#include <nlohmann/json.hpp> 
namespace CyberMetro {
    namespace Entidades {
        namespace Obstaculos {
            using json = nlohmann::json;

            class Plataforma : public Obstaculo
            {
            private:
                static const float largura_plataforma;
                static const float altura_plataforma;

                float yOrigem;
                float amplitude;
                static const float VELOCIDADE_FLUTUACAO;
                float tempoOffset;

            public:
                Plataforma(float xi, float yi, int alt = 64);
                ~Plataforma();

                void obstaculizar(Entidades::Personagens::Jogador* pj);
                void salvar();
                void executar();

                virtual json salvarDataBuffer() const;
                virtual void carregarDeBuffer(const json& data);
            };
        }
    }
}