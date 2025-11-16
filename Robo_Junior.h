#pragma once
#include "Inimigo.h"
#include <nlohmann/json.hpp> 
namespace CyberMetro {
    namespace Entidades {
        namespace Personagens {
            using json = nlohmann::json;

            class Robo_Junior : public Inimigo
            {
            protected:
                int volta = 1;
                float xINI;
                float raio;

            public:
                Robo_Junior(float xi, float yi);
                ~Robo_Junior();
                void mover();
                void danificar(Jogador* pJogador);
                void salvar();
                void executar();
                virtual json salvarDataBuffer() const;
                virtual void carregarDeBuffer(const json& data);
 
            };
        }
    }
}