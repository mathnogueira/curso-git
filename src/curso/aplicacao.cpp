#include <curso/aplicacao.hpp>
#include <curso/utils/log.hpp>

using namespace Curso;

Aplicacao::Aplicacao()
{
	logger = new Utils::Logger();
	logger->Log("Aplicação iniciou a sua execução.");
}