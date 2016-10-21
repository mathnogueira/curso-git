# curso-git
Repositório configurado para usar travis CI para o curso de Git da III Semana de Tecnologia da Informação da UFLA


[![Build Status](https://travis-ci.org/mathnogueira/curso-git.svg?branch=master)](https://travis-ci.org/mathnogueira/curso-git)

## Sobre o projeto
Durante esse minicurso, iremos desenvolver uma aplicação de gerenciamento financeiro para uma agencia bancária. 
Os requisitos funcionais do software estão descritos abaixo.


## Requisitos

Como qualquer software, os requisitos aqui descritos podem ser
alterados a pedido do cliente para que o software reflita as atuais
regras de negócio da agencia bancária.

- O software deve ser capaz de gerenciar seus usuários e o credenciamento 
dos mesmos para que eles possam realizar certas ações. Portanto, cada usuário deve ter um login
e uma senha de acesso ao software.

- O software deve manter informações sobre os dados de cada usuário da agencia
em algum meio de armazenamento. 

- A situação financeira de cada usuário deve ser salva pelo sistema, 
portanto, deve-se guardar os dados da conta do usuário e seu saldo atual.

- O usuário deve ser capaz de realizar saques e depósitos em sua conta. Cada uma dessas operações
deve criar um registro de log para controle interno da agencia, caso algum de seus
clientes estejam envolvidos na Lava-Jato.
