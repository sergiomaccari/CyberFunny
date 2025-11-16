#pragma once
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Ente.h" // <-- CORREÇÃO 1: Faltava este include

#include <vector> 
#include <SFML/System/Vector3.hpp> 
#include <SFML/Graphics.hpp> 
#include <string> 

// <-- CORREÇÃO 2: A declaração antecipada de Jogo
// deve estar DENTRO do namespace CyberMetro.
namespace CyberMetro {
	class Jogo;
}

namespace CyberMetro {
	namespace Fases {
		class Fase : public Ente
		{
		protected:
			struct SpawnPlataforma {
				float x;
				float y;
				int altura;
			};

			sf::Texture texturaTileset;
			std::vector<std::vector<unsigned int>> gridMapa;

			Entidades::Personagens::Jogador* pJogador1;
			Entidades::Personagens::Jogador* pJogador2;

			Listas::ListaEntidades* pListaInimigos;
			Listas::ListaEntidades* pListaObstaculos;
			Listas::ListaEntidades* pListaChao;

			Gerenciadores::Gerenciador_Colisoes* pColisoes;

			std::vector<sf::Vector2f> posi_robo_junior;
			std::vector<sf::Vector3f> posi_plataforma;

			sf::FloatRect areaDeSaida;
			sf::Texture texturaSaida;
			sf::Sprite spriteSaida;

			const int TILESET_LARGURA_EM_BLOCOS = 8;
			const float TAMANHO_BLOCO_X = 32.0f;
			const float TAMANHO_BLOCO_Y = 32.0f;
			void criarRoboJunior(float x, float y);
			void criarRoboJunior(const sf::Vector2f& pos);
			void criarPlataforma(float x, float y, int altura);
			void criarChao(float x, float y);
			CyberMetro::Jogo* pJogo;

			void verificarFimDeFase();

			bool terminou;
			sf::Clock relogioFase;

		public:
			Fase(Entidades::Personagens::Jogador* jogador1, Entidades::Personagens::Jogador* jogador2 = nullptr);
			virtual ~Fase();

			virtual void executar() override;
			void desenharFase();

			void limpar();
			virtual void adicionarJogador2(Entidades::Personagens::Jogador* j2);
			virtual void criarInimigos() = 0;
			virtual void criarObstaculos() = 0;
			void criarCenario(const std::string& arquivoJson);
			virtual void desenharMapa();


			void setJogo(CyberMetro::Jogo* pJ);

			bool getTerminou() const;
			sf::FloatRect getAreaSaida() const;
			float getTempoDecorrido() const;

			Listas::ListaEntidades* getListaInimigos() const;
			Listas::ListaEntidades* getListaObstaculos() const;
			Listas::ListaEntidades* getListaChao() const;
		};
	}
}