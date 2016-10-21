#pragma once

#include <banco/utils/log.hpp>

namespace Banco 
{

	/**
	 * Classe principal da aplicação. Responsável por delegar as ações da aplicação
	 * para os respectivos módulos.
	 */
	class Aplicacao
	{

		public:
			/**
			 * Construtor padrão da classe.
			 */
			Aplicacao();

			/**
			 * Destrutor da aplicação.
			 */
			~Aplicacao();

		private:

			/**
			 * Objeto de log da aplicação.
			 */
			Utils::Logger *logger;

	};

}