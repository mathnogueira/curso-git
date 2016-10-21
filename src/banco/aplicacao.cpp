#include <banco/aplicacao.hpp>
#include <banco/utils/log.hpp>

using namespace Banco;

Aplicacao::Aplicacao()
{
	logger = new Utils::Logger();
	logger->Log("Aplicação iniciou a sua execução.");
}

Aplicacao::~Aplicacao()
{
	delete logger;
}