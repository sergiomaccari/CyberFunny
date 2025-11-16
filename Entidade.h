#pragma once
#include "Ente.h"
#include <nlohmann/json.hpp> 
namespace CyberMetro {
    namespace Entidades
    {

        using json = nlohmann::json;

        class Entidade : public Ente
        {
        protected:
            float x;
            float y;
            bool estaAtivo;
            float vel_grav;
            static const float grav;
        public:
            Entidade(float xi, float yi);
            Entidade();
            virtual ~Entidade();
            void setX(float novoX);
            void setY(float novoY);
            float getX() const;
            float getY() const;

            virtual void salvar() = 0;
            virtual void executar() = 0;

            void setPosicaoGrafica(float xi, float yi);
            void setPosicaoGrafica(const sf::Vector2f& novaPos);
            sf::Vector2f getPosicaoGrafica();

            virtual void setAtivo(bool b);
            virtual bool getAtivo() const;
            void setVel_Grav(float nv);
            float getVel_Grav() const;
            void gravidade(sf::Vector2f* pos);


            virtual json salvarDataBuffer() const;
            virtual void carregarDeBuffer(const json& data);
        };
    }
}