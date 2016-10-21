#pragma once

#include <banco/utils/tipos.hpp>
#include <cstdio>

namespace Banco
{
namespace Utils
{

	/**
	 * Classe de abstração de uso de arquivos.
	 */
	class Arquivo
	{

		public:

			/**
			 * Cria um novo arquivo.
			 * 
			 * @param caminho caminho do arquivo.
			 */
			Arquivo(const char* caminho);

			/**
			 * Destroi a instância do arquivo na memória.
			 */
			~Arquivo();

			/**
			 * Abre o arquivo no modo especificado.
			 *
			 * @param modo modo de abertura do arquivo.
			 * @return verdadeiro se o arquivo for aberto com sucesso.
			 */
			bool Abrir(const char *modo);

			/**
			 * Fecha o arquivo.
			 */
			void Fechar();

			/**
			 * Escreve um objeto no arquivo.
			 *
			 * @param objeto objeto a ser escrito
			 * @param tamanho tamanho do objeto.
			 * @return verdadeiro se o objeto foi escrito com sucesso.
			 */
			bool Escrever(void *objeto, uint tamanho);

			/**
			 * Lê todos os dados do arquivo.
			 *
			 * @param objeto objeto onde será colocado os dados lidos.
			 * @param tamanho tamanho de cada objeto que será lido.
			 */
			bool Ler(void *objeto, uint tamanho);

			/**
			 * Obtem o tamanho em bytes do arquivo.
			 *
			 * @return tamanho em bytes do arquivo.
			 */
			uint ObterTamanho();

		private:

			/**
			 * Ponteiro para o arquivo.
			 */
			FILE *arquivo;

			/**
			 * Nome do arquivo.
			 */
			const char *nome;
	};

}
}