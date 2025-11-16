#include "Chao.h" 
#include "Gerenciador_Grafico.h"
#include <iostream> 
namespace CyberMetro {
	namespace Entidades
	{
		const float Entidades::Chao::largura = 32.0f;
		const float Entidades::Chao::altura = 32.0f;

		Chao::Chao(float xi, float yi)
			: Entidade(xi, yi)
		{
			if (pGG)
			{
				pFigura->setTextureRect(sf::IntRect(0, 0, (int)Chao::largura, (int)Chao::altura));
			}
			else
			{
				std::cerr << "Erro Chao" << std::endl;
			}

			this->x = xi;
			this->y = yi;
			setPosicaoGrafica(this->x, this->y);
		}

		Chao::~Chao()
		{

		}

		void Chao::salvar()
		{

		}

		json Chao::salvarDataBuffer() const
		{
			json j = Entidade::salvarDataBuffer();
			j["tipo"] = "Chao";
			return j;
		}

		void Chao::carregarDeBuffer(const json& data)
		{
			Entidade::carregarDeBuffer(data);
			if (pGG)
			{
				pFigura->setTextureRect(sf::IntRect(0, 0, (int)Chao::largura, (int)Chao::altura));
			}
		}

		void Chao::executar()
		{
			if (estaAtivo)
			{
				return;
			}
			bool fora_esquerda = (this->x + this->largura) < MUNDO_X_MIN;
			bool fora_direita = this->x > MUNDO_X_MAX;
			bool fora_cima = (this->y + this->altura) < MUNDO_Y_MIN;
			bool fora_baixo = this->y > MUNDO_Y_MAX;

			if (fora_esquerda || fora_direita || fora_cima || fora_baixo)
			{
				this->setAtivo(false);
			}
		}
	}
}