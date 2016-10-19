// Arquivo de execução dos testes automatizados do programa
// Não precisa editar esse arquivo, ele já varre todos os arquivos .cpp
// contidos na pasta tests do projeto

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}