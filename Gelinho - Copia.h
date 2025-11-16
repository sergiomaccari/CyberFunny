#pragma once
#include "Obstaculo.h"
#include <nlohmann/json.hpp>
namespace CyberMetro {
    namespace Entidades {
        namespace Obstaculos {
            using json = nlohmann::json;

            class Gelinho : public Obstaculo
            {
            private:
                float largura;
            public:
                Gelinho(float xi, float yi);
                ~Gelinho();

                virtual void obstaculizar(Entidades::Personagens::Jogador* pj) override;
                virtual void salvar() override;
                virtual void executar() override;

                virtual json salvarDataBuffer() const override;
                virtual void carregarDeBuffer(const json& data) override;
            };
        }
    }
}