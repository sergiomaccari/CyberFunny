#pragma once
#include "Entidade.h"
#include <fstream> 
#include <string>  
#include <nlohmann/json.hpp>
namespace CyberMetro {
	namespace Entidades {
		using json = nlohmann::json;

		class Chao : public Entidades::Entidade
		{
		private:
			static const float largura;
			static const float altura;

		public:
			Chao(float x, float y);
			~Chao();

			void salvar() ;
			void executar() ;

			virtual json salvarDataBuffer() const;
			virtual void carregarDeBuffer(const json& data) ;
		};
	}
}