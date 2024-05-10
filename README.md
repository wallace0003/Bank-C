# Projeto-4 Banco quem poupa tem

Este é um sistema simples de gerenciamento bancário desenvolvido em C. O programa permite que você crie, exclua, liste, faça depósitos, saques, transferências e gere extratos para os clientes do banco.

Funcionalidades:
O sistema possui as seguintes funcionalidades

--Criar Cliente: Permite criar um novo cliente com nome, CPF, tipo de conta, saldo inicial e senha.
--Excluir Cliente: Remove um cliente existente do banco de dados.
--Listar Clientes: Mostra todos os clientes cadastrados, incluindo seus nomes, CPFs, tipos de conta e saldos.
--Depositar: Permite que um cliente deposite uma quantia em sua conta.
--Debitar: Permite que um cliente saque uma quantia de sua conta, com aplicação de tarifas de acordo com o tipo de conta.
--Transferência: Permite a transferência de fundos entre contas de clientes.
--Extrato: Gera um extrato de operações para um cliente específico, incluindo informações sobre transações anteriores.


Instruções de Uso:
--Compilação: Compile o programa usando um compilador C. Por exemplo, gcc -o bank main.c bank.c.
--Execução: Execute o programa compilado. Por exemplo, ./bank.
-Menu: O programa exibirá um menu de opções numeradas. Escolha a opção desejada digitando o número correspondente.
-Instruções: Siga as instruções na tela para interagir com o sistema e realizar operações bancárias.


Observações:
--Certifique-se de que os arquivos bank.h, bank.c e main.c estejam no mesmo diretório.
--Os dados dos clientes são armazenados em um arquivo binário chamado Clientes.bin.
--Os extratos de operações são gerados em arquivos de texto separados, com o nome do arquivo correspondendo ao CPF do cliente.
--Este sistema de gerenciamento bancário foi desenvolvido como um projeto simples para demonstrar conceitos básicos de programação em C e não deve ser usado em ambientes de produção.