#pragma once
#include "Entidade.h"
#include <nlohmann/json.hpp> 
namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}
namespace CyberMetro {
    namespace Entidades {
        namespace Obstaculos
        {
            using json = nlohmann::json;

            class Obstaculo : public Entidades::Entidade
            {
            protected:
                bool danoso;

            public:
                Obstaculo(float xi, float yi);
                virtual ~Obstaculo();
                virtual void obstaculizar(Personagens::Jogador* pj) = 0;

                virtual json salvarDataBuffer() const override;
                virtual void carregarDeBuffer(const json& data) override;

                bool getDanoso() const;
            };
        }
    }
}