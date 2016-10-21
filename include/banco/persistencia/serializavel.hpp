#pragma once

#include <banco/utils/tipos.hpp>

namespace Banco 
{
namespace Persistencia
{

/**
 * Interface de objetos serializaveis que podem ser salvos.
 */
template <typename T>
class Serializavel
{
	public:

		/**
		 * Retorna o tamanho do objeto usando a definição da própria classe para isso.
		 *
		 * @return inteiro que representa o tamanho do objeto serializável.
		 */
		uint ObterTamanho() {
			return (uint) sizeof(T);
		}
};

}
}