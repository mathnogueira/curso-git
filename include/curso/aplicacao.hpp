#pragma once

#include <curso/utils/log.hpp>

namespace Curso 
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

		private:

			/**
			 * Objeto de log da aplicação.
			 */
			Utils::Logger *logger;

	};

}