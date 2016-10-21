#include <banco/utils/arquivo.hpp>
#include <cstdlib>
#include <iostream>

using namespace Banco::Utils;

/**
 * Cria um novo arquivo.
 * 
 * @param caminho caminho do arquivo.
 */
Arquivo::Arquivo(const char* caminho) : nome(caminho)
{
	this->arquivo = NULL;
}

/**
 * Destroi a instância do arquivo na memória.
 */
Arquivo::~Arquivo()
{
	Fechar();
}

/**
 * Abre o arquivo no modo especificado.
 *
 * @param modo modo de abertura do arquivo.
 * @return verdadeiro se o arquivo for aberto com sucesso.
 */
bool Arquivo::Abrir(const char *modo)
{
	arquivo = fopen(nome, modo);
	return (arquivo != NULL);
}

/**
 * Fecha o arquivo.
 */
void Arquivo::Fechar()
{
	if (arquivo == NULL) return;
	fclose(arquivo);
	arquivo = NULL;
}

/**
 * Escreve um objeto no arquivo.
 *
 * @param objeto objeto a ser escrito
 * @param tamanho tamanho do objeto.
 * @return verdadeiro se o objeto foi escrito com sucesso.
 */
bool Arquivo::Escrever(void *objeto, uint tamanho)
{
	return (fwrite(objeto, (size_t) tamanho, 1, arquivo) != 0);
}

/**
 * Lê todos os dados do arquivo.
 *
 * @param objeto objeto onde será colocado os dados lidos.
 * @param tamanho tamanho de cada objeto que será lido.
 */
bool Arquivo::Ler(void *objeto, uint tamanho)
{
	uint registros = ObterTamanho() / tamanho;
	if (registros == 0) return false;
	fread(objeto, (size_t) tamanho, registros, arquivo);
	return true;
}

/**
 * Obtem o tamanho em bytes do arquivo.
 *
 * @return tamanho em bytes do arquivo.
 */
uint Arquivo::ObterTamanho()
{
	if (arquivo == NULL) return 0;
	fseek(arquivo, 0, SEEK_END);
	long tamanho = ftell(arquivo);
	fseek(arquivo, 0, SEEK_SET);
	return (uint) tamanho;
}