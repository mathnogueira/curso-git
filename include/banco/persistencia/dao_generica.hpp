#pragma once

#include <banco/persistencia/dao.hpp>
#include <banco/utils/arquivo.hpp>
#include <banco/utils/tipos.hpp>
#include <cstdlib>
#include <cstdio>

namespace Banco
{
namespace Persistencia
{

	/**
	 * DAO capaz de salvar um determinado tipo de objeto em um arquivo
	 * especificado no construtor.
	 */
	template <typename T>
	class FDAO : public DAO<T>
	{
		public:

			/**
			 * Cria um novo objeto DAO capaz de salvar dados no arquivo especificado.
			 *
			 * @param arquivo arquivo onde os dados serão salvos.
			 */
			FDAO(const char *arquivo)
			{
				this->arquivo = new Banco::Utils::Arquivo(arquivo);
			}

			/**
			 * Destroi a estrutura DAO.
			 */
			~FDAO() 
			{
				delete arquivo;
			}

		protected:

			/**
			 * Função que salva o objeto de fato no meio de armazenamento. 
			 *
			 * @param objeto objeto que será salvo.
			 * @param tamanho tamanho do objeto em bytes.
			 * @return verdadeiro se o objeto foi salvo com sucesso.
			 */
			bool SalvarObjeto(Serializavel<T> &objeto, const uint tamanho)
			{
				if (!arquivo->Abrir("ab")) return false; 
				arquivo->Escrever(&objeto, tamanho);
				arquivo->Fechar();
				return true;
			}

			/**
			 * Função que deve ser implementada para listar todos os registros salvos no
			 * meio de armazenamento.
			 *
			 * @param container vector que conterá os elementos obtidos no meio de armazenamento.
			 * @return verdadeiro se pelo menos um objeto pôde ser carregado.
			 */
			bool ListarObjetos(std::vector<T> &container)
			{
				arquivo->Abrir("rb");
				uint tamanho = arquivo->ObterTamanho() / sizeof(T);
				T *dados = new T[tamanho];
				arquivo->Ler(dados, sizeof(T));
				for (uint i = 0; i < tamanho; ++i)
				{
					container.push_back(dados[i]);
				}
				delete[] dados;
				arquivo->Fechar();
				return true;
				
			}

		private:

			/**
			 * Arquivo usado para guardar as informações.
			 */
			Banco::Utils::Arquivo *arquivo;
	};

}
}