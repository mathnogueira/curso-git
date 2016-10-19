#pragma once

#include <string>

namespace Curso
{
namespace Utils
{
	// Namespace Curso::Utils

	class Logger 
	{
		public:
			/**
			 * Construtor padrão do logger.
			 */
			Logger();

			/**
			 * Executa a função de log do componente.
			 *
			 * @param mensagem mensagem que será exibida no log.
			 */
			void Log(const std::string &mensagem);

			/**
			 * Executa a função de log do componente usando uma string do C.
			 *
			 * @param mensagem mensagem no formato de string da linguagem C.
			 */
			void Log(const char *mensagem);

		private:
			
			/**
			 * Função que implementa a funcionalidade de log de mensagens.
			 *
			 * @param mensagem string da linguagem C++
			 */
			void m_Log(const std::string &mensagem);
	};
	
}}