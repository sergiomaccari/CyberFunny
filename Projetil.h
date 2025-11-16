#pragma once
#include "Entidade.h"
#include <nlohmann/json.hpp>
namespace CyberMetro {
    namespace Entidades
    {
        using json = nlohmann::json;

        class Projetil : public Entidades::Entidade
        {
        private:
            int dano;
            float vx;
            float vy;
            int idDono;// 0 =roboceo 1=jog1 2=jog2

            const float FORCA_GRAVIDADE_PROJETIL;

        public:
            Projetil();
            ~Projetil();
            virtual void executar();
            virtual void salvar();

            virtual json salvarDataBuffer() const;
            virtual void carregarDeBuffer(const json& data);

            void setVelocidade(float velX, float velY);
            void setIdDono(int id);
            int getIdDono() const;
            int getDano() const;
        };
    }
}