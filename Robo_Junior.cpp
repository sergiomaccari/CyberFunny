#include "Robo_Junior.h"
#include "Jogador.h" 
#include <iostream>
#include "Ente.h"
namespace CyberMetro {
	namespace Entidades {
		namespace Personagens {

			Robo_Junior::Robo_Junior(float xi, float yi) :
				Inimigo(xi, yi), // <-- Inicializador de base
				volta(1),
				raio((float)((rand() % 2) + 1) + 28) //raio de 29 a 30
			{
				this->xINI = xi;
				this->x = xi;
				this->y = yi;
				this->velocidade = 150.0f;
				this->n_vidas = 2;
				this->n_vidas_max = 2;
				this->pontosPorMorte = 100;


				if (pGG)
				{
					sf::Texture* tex = pGG->getTextura("Imagens/inimigo_facil.png");
					if (tex)
					{
						pFigura->setTexture(*tex);
						pFigura->setScale((float)raio / tex->getSize().x, (float)raio / tex->getSize().y);
					}
				}
				else
				{
					std::cerr << "Erro RoboJunior" << std::endl;
				}

				pFigura->setPosition(sf::Vector2f(static_cast<float>(this->x), static_cast<float>(this->y)));
				atualizarBarraVida();
			}
			Robo_Junior::~Robo_Junior()
			{

			}

			void Robo_Junior::mover()
			{
				sf::Vector2f movimento = sf::Vector2f(0.0f, 0.0f);

				float dt = Ente::g_dt;

				if (volta == 1 && this->x >= xINI + (int)raio * 3) {
					volta = -1;
				}
				else if (volta == -1 && this->x <= xINI) {
					volta = 1;
				}

				if (this->x <= x + (int)raio && volta == 1)
				{
					movimento += sf::Vector2f(1.0f, 0.f);

				}

				if (this->x >= x && volta == -1)
				{
					movimento += sf::Vector2f(-1.0f, 0.f);
				}

				Personagem::gravidade(&movimento);

				this->x += movimento.x * dt * velocidade;
				this->y += movimento.y * dt * velocidade;

				setPosicaoGrafica(this->x, this->y);
			}

			void Robo_Junior::danificar(Jogador* pJogador)
			{
				if (pJogador)
				{
					for (int i = 0; i < this->nivel_maldade - ((int(raio) % 28)); i++)
						pJogador->operator--();
				}
			}

			void Robo_Junior::salvar()
			{

			}

			json Robo_Junior::salvarDataBuffer() const
			{
				json j = Inimigo::salvarDataBuffer();
				j["tipo"] = "Robo_Junior";
				j["xINI"] = this->xINI;
				j["raio"] = this->raio;
				j["volta"] = this->volta;

				return j;
			}

			void Robo_Junior::carregarDeBuffer(const json& data)
			{
				Inimigo::carregarDeBuffer(data);
				this->xINI = data.value("xINI", this->xINI);
				this->raio = data.value("raio", this->raio);
				this->volta = data.value("volta", this->volta);
				if (pGG)
				{
					sf::Texture* tex = pGG->getTextura("Imagens/inimigo_facil.png");
					if (tex)
					{
						pFigura->setTexture(*tex);
						pFigura->setScale((float)raio / tex->getSize().x, (float)raio / tex->getSize().y);
					}
				}
			}

			void Robo_Junior::executar()
			{
				this->mover();
				atualizarBarraVida();
			}
		}
	}
}