#pragma once
#include "Obstaculo.h"
#include <nlohmann/json.hpp>
namespace CyberMetro {
	namespace Entidades {
		namespace Obstaculos {
			using json = nlohmann::json;

			class Choquinho : public Obstaculos::Obstaculo
			{
			private:
				short int danosidade;

			public:
				Choquinho(float xi, float yi);
				~Choquinho();

				virtual void obstaculizar(Personagens::Jogador* pj);
				virtual void salvar();
				virtual void executar();

				virtual json salvarDataBuffer() const;
				virtual void carregarDeBuffer(const json& data);
			};
		}
	}
}