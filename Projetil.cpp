#include "Projetil.h"
#include "Gerenciador_Grafico.h"
#include "Ente.h" // <-- MODIFICACAO: Inclui Ente para g_dt
namespace CyberMetro {
	namespace Entidades
	{
		Projetil::Projetil() :
			Entidade(0.f, 0.f),
			dano(1000),
			vx(0.0f),
			vy(0.0f),
			idDono(0),
			FORCA_GRAVIDADE_PROJETIL(-0.0249f) {

			if (pGG)
			{
				sf::Texture* tex = pGG->getTextura("Imagens/projetil.png");
				if (tex)
				{
					pFigura->setTexture(*tex);
					pFigura->setScale(20.0f / tex->getSize().x, 20.0f / tex->getSize().y);
				}
			}
		}
		Projetil::~Projetil() {}

		void Projetil::executar() {
			float dt = Ente::g_dt;
			vel_grav += (grav + FORCA_GRAVIDADE_PROJETIL);
			this->x += vx * dt * 100.0f;
			this->y += (vy * dt * 100.0f) + (vel_grav * dt);

			setPosicaoGrafica(this->x, this->y);

			if (this->x < 0.0f || this->x > 3200.0f || this->y < 0.0f || this->y > 900.0f)
			{
				this->setAtivo(false);
			}
		}

		void Projetil::salvar()
		{

		}

		json Projetil::salvarDataBuffer() const
		{
			json j = Entidade::salvarDataBuffer();
			j["tipo"] = "Projetil";
			j["dano"] = this->dano;
			j["vx"] = this->vx;
			j["vy"] = this->vy;
			j["idDono"] = this->idDono;
			return j;
		}

		void Projetil::carregarDeBuffer(const json& data)
		{
			Entidade::carregarDeBuffer(data);
			this->dano = data.value("dano", this->dano);
			this->vx = data.value("vx", this->vx);
			this->vy = data.value("vy", this->vy);
			this->idDono = data.value("idDono", this->idDono);
		}


		void Projetil::setVelocidade(float velX, float velY)
		{
			vx = velX;
			vy = velY;
			vel_grav = 0.0f;
		}
		void Projetil::setIdDono(int id)
		{
			idDono = id;
		}

		int Projetil::getIdDono() const
		{
			return idDono;
		}

		int Projetil::getDano() const
		{
			return dano;
		}
	}
}