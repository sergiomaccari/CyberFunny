/*
* Arquivo modificado: Plataforma.cpp
* Mudança: Usa Ente::g_tempoTotal para movimento senoidal
* e calcula o tempoOffset relativo a ele.
*/

#include "Plataforma.h"
#include <iostream>
#include <cmath>
#include "Ente.h"
#include "Jogador.h"
namespace CyberMetro {
    using namespace Entidades::Personagens;
    namespace Entidades {
        namespace Obstaculos {

            const float Plataforma::altura_plataforma = 32.0f;
            const float Plataforma::largura_plataforma = 32.0f;
            const float Plataforma::VELOCIDADE_FLUTUACAO = 1.5f;

            Plataforma::Plataforma(float xi, float yi, int alt)
                : Obstaculo(xi, yi),
                yOrigem(yi),
                amplitude((float)alt - 32),
                tempoOffset(0.0f)
            {
                if (pGG)
                {
                    sf::Texture* tex = pGG->getTextura("Imagens/plataforma.png");
                    if (tex)
                    {
                        pFigura->setTexture(*tex);
                        pFigura->setScale(32.0f / tex->getSize().x, 32.0f / tex->getSize().y);
                    }
                }
                else
                {
                    std::cerr << "Erro Plataforma" << std::endl;
                }


                this->x = xi;
                this->y = yi;
                setPosicaoGrafica(this->x, this->y);
                this->danoso = false;
                this->tempoOffset = (float)(rand() % 1000) / 100.0f;
            }

            Plataforma::~Plataforma()
            {

            }

            void Plataforma::obstaculizar(Jogador* pj)
            {
                pj->iniciarObstaculoCooldown(sf::seconds(15.0f));
            }

            void Plataforma::salvar()
            {

            }

            json Plataforma::salvarDataBuffer() const
            {
                json j = Obstaculo::salvarDataBuffer();
                j["tipo"] = "Plataforma";
                j["yOrigem"] = this->yOrigem;
                j["amplitude"] = this->amplitude;
                j["tempoOffset"] = this->tempoOffset;

                return j;
            }

            void Plataforma::carregarDeBuffer(const json& data)
            {
                Obstaculo::carregarDeBuffer(data);
                this->yOrigem = data.value("yOrigem", this->yOrigem);
                this->amplitude = data.value("amplitude", this->amplitude);

                this->tempoOffset = data.value("tempoOffset", this->tempoOffset);
            }

            void Plataforma::executar()
            {

                this->y = yOrigem + (amplitude * std::sin((this->tempoOffset + Ente::g_tempoTotal)*VELOCIDADE_FLUTUACAO));
                setPosicaoGrafica(this->x, this->y);
            }

        }
    }
}