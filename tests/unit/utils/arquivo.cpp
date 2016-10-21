#include <gtest/gtest.h>
#include <banco/utils/tipos.hpp>
#include <banco/utils/arquivo.hpp>

using namespace Banco::Utils;

TEST(Arquivo, SalvarNovoRegistro)
{
	Arquivo arquivo("arquivo_teste.tst");
	arquivo.Abrir("ab");
	// Pega o tamanho do arquivo
	uint tamanhoArquivo = arquivo.ObterTamanho();
	int numeroEscrito = 8;
	arquivo.Escrever(&numeroEscrito, sizeof(int));
	uint novoTamanho = arquivo.ObterTamanho();
	arquivo.Fechar();
	// Verifica resultado (tamanho do arquivo + tamanho do inteiro)
	ASSERT_EQ(novoTamanho, tamanhoArquivo + sizeof(int));
}

TEST(Arquivo, VerificarValorSalvo)
{
	int numero = 42;
	int valorSalvo;
	// Abre o arquivo para escrita e leitura binária
	Arquivo arquivo("arquivo_teste.tst");
	arquivo.Abrir("wb+");
	// Escreve o número no arquivo e depois tenta ler o número, batendo os resultados
	arquivo.Escrever(&numero, sizeof(int));
	arquivo.Ler(&valorSalvo, sizeof(int));
	arquivo.Fechar();
	ASSERT_EQ(numero, valorSalvo);
}