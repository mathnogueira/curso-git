#pragma once

#include <banco/persistencia/serializavel.hpp>
#include <banco/utils/tipos.hpp>
#include <iostream>
#include <vector>

namespace Banco
{
namespace Persistencia
{

	/**
	 * Classe genérica que salva objetos serializaveis em algum meio de armazenamento.
	 */
	template <typename T>
	class DAO
	{
		public:

			/**
			 * Salva um objeto serializavel em um meio de armazenamento.
			 *
			 * @param objeto objeto a ser salvo.
			 * @return verdadeiro se o objeto foi salvo com sucesso.
			 */
			bool Salvar(Serializavel<T> &objeto)
			{
				return SalvarObjeto(objeto, objeto.ObterTamanho());
			}

			/**
			 * Lista todos os registros salvos no meio de armazenamento.
			 *
			 * @param container vector que irá ser populado com os objetos carregados.
			 * @return verdadeiro se pelo menos um objeto pôde ser carregado.
			 */
			void Listar(std::vector<T> &container)
			{
				ListarObjetos(container);
			}

		protected:

			/**
			 * Função que deve ser implementada que salva o objeto de fato
			 * no meio de armazenamento. 
			 *
			 * @param objeto objeto que será salvo.
			 * @param tamanho tamanho do objeto em bytes.
			 * @return verdadeiro se o objeto foi salvo com sucesso.
			 */
			virtual bool SalvarObjeto(Serializavel<T> &objeto, const uint tamanho) = 0;

			/**
			 * Função que deve ser implementada para listar todos os registros salvos no
			 * meio de armazenamento.
			 *
			 * @param container vector que conterá os elementos obtidos no meio de armazenamento.
			 * @return verdadeiro se pelo menos um objeto pôde ser carregado.
			 */
			virtual bool ListarObjetos(std::vector<T> &container) = 0;
	};
}
}