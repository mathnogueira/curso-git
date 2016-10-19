#include <curso/utils/log.hpp>
#include <iostream>

using namespace Curso::Utils;

Logger::Logger()
{
	// Construtor padrão do logger
}

void Logger::Log(const std::string &mensagem)
{
	m_Log(mensagem);
}

void Logger::Log(const char *mensagem)
{
	std::string msg(mensagem);
	m_Log(msg);
}

void Logger::m_Log(const std::string &mensagem)
{
	// Cria um log com a mensagem recebida via parametro
	std::cout << mensagem << std::endl;
}