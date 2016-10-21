#pragma once

#include <banco/persistencia/serializavel.hpp>

namespace Banco
{
namespace Autenticacao
{

	class Usuario : public Banco::Persistencia::Serializavel<Usuario>
	{
	};

}
}
