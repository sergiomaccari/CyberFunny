#include "Robo_CEO.h" 
#include "Projetil.h" 
#include <cmath>
#include "Ente.h"
namespace CyberMetro {
    namespace Entidades {
        namespace Personagens {
            const int Robo_CEO::COOLDOWN_TIRO_CHEFE_FRAMES = 300;

            Robo_CEO::Robo_CEO(float xi, float yi) :
                Inimigo(xi, yi),
                forca(rand() % 10 + 1),
                pJogador(nullptr),
                cooldownTiro(0),
                PROJETIL_VELOCIDADE_CHEFE(1.2f + 0.06f * (float)forca),
                FORCA_GRAVIDADE_CHEFE(-0.0249f)
            {
                cooldownTiro = COOLDOWN_TIRO_CHEFE_FRAMES / 2; // meio cooldown

                this->x = xi;
                this->y = yi;
                this->velocidade = 150.0f;
                this->n_vidas = 10000;
                this->n_vidas_max = 10000;

                this->pontosPorMorte = 500;

                if (pGG)
                {
                    sf::Texture* tex = pGG->getTextura("Imagens/chefe.png");
                    if (tex)
                    {
                        pFigura->setTexture(*tex);
                        pFigura->setScale(64.0f / tex->getSize().x, 64.0f / tex->getSize().y);
                    }
                }
                else
                {
                    std::cerr << "Erro RoboCEO" << std::endl;
                }

                pFigura->setPosition(this->x, this->y);
                atualizarBarraVida();
            }

            Robo_CEO::~Robo_CEO()
            {

            }

            void Robo_CEO::anti_gravidade(sf::Vector2f* pos)
            {
                this->vel_grav = 0;
            }

            void Robo_CEO::setJogador(Jogador* j)
            {
                this->pJogador = j;
            }

            void Robo_CEO::mover()
            {
                movimento = sf::Vector2f(0.0f, 0.0f);
                float dt = Ente::g_dt;

                Entidade::gravidade(&this->movimento);

                this->x += movimento.x * dt * velocidade;
                this->y += movimento.y * dt * velocidade;

                setPosicaoGrafica(this->x, this->y);
            }

            void Robo_CEO::atirar()
            {
                if (cooldownTiro > 0)
                {
                    cooldownTiro--;
                    return;
                }
                cooldownTiro = COOLDOWN_TIRO_CHEFE_FRAMES;
                if (pJogador == nullptr)
                    return;

                Entidades::Projetil* p = new Entidades::Projetil();
                p->setGerenciadorGrafico(Ente::getGerenciadorGrafico());

                sf::FloatRect corpoChefe = pFigura->getGlobalBounds();
                float CentroX = corpoChefe.left + corpoChefe.width / 2.0f;
                float CentroY = corpoChefe.top + corpoChefe.height / 2.0f;

                float dx = pJogador->getX() - CentroX;
                float dy = pJogador->getY() - CentroY;

                float mag = std::sqrt(dx * dx + dy * dy);
                float dirX = 0.0f;
                float dirY = 0.0f;

                if (mag > 0.0f)
                {
                    dirX = dx / mag;
                    dirY = dy / mag;
                }

                float vx = dirX * PROJETIL_VELOCIDADE_CHEFE;
                float vy = dirY * PROJETIL_VELOCIDADE_CHEFE;
                p->setVelocidade(vx, vy);
                p->setX(CentroX - 32);
                p->setY(CentroY);

                p->setIdDono(0);
                projeteis.inserir(p);
            }

            void Robo_CEO::danificar(Jogador* pJogador)
            {
                if (pJogador)
                {
                    for (int i = 0; i < this->nivel_maldade; i++)
                        pJogador->operator--();
                }
            }

            void Robo_CEO::salvar()
            {

            }

            json Robo_CEO::salvarDataBuffer() const
            {
                json j = Inimigo::salvarDataBuffer();
                j["tipo"] = "Robo_CEO";
                j["forca"] = this->forca;
                j["cooldownTiro"] = this->cooldownTiro;
                return j;
            }

            void Robo_CEO::carregarDeBuffer(const json& data)
            {
                Inimigo::carregarDeBuffer(data);

                this->forca = data.value("forca", this->forca);
                this->cooldownTiro = data.value("cooldownTiro", this->cooldownTiro);
                PROJETIL_VELOCIDADE_CHEFE = 1.2f + 0.06f * (float)forca;

                if (pGG)
                {
                    sf::Texture* tex = pGG->getTextura("Imagens/chefe.png");
                    if (tex)
                    {
                        pFigura->setTexture(*tex);
                        pFigura->setScale(64.0f / tex->getSize().x, 64.0f / tex->getSize().y);
                    }
                }
            }

            void Robo_CEO::executar()
            {
                this->mover();
                this->atirar();
                this->projeteis.executar();
                atualizarBarraVida();
            }

            Listas::ListaEntidades* Robo_CEO::getProjeteis()
            {
                return &projeteis;
            }
        }
    }
}