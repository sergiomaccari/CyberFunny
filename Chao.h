#pragma once
#include "Entidade.h"
#include <fstream> 
#include <string>  

namespace Entidades {

	class Chao : public Entidades::Entidade
	{
	private:
		static const float largura;
		static const float altura;

	public:
		Chao(float x, float y);
		~Chao();

		void salvar();
		void executar();
	};
}