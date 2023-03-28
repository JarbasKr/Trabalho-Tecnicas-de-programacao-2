// Exercicio 2 do trabalho do terceiro semestre de ciência da computação.
// Matéria:Técnicas de programação II/Laboratório de programação II.
// Alunos:Jarbas Frederico Krempel,Lucas Eduardo Sechirolli da Silva, Nicolas Carvalho de Souza.
#include <iostream>
using namespace std;

// Informações de cada cliente.
struct cliente
{
  // Informações básicas.
  string nome;
  string CPF;
  string endereco;
  string dataNascimento;
  string dataEmprestimo;
  string dataPagamento;

  /*Valores que participarão na parte das parcelas.
   parcelasMensais é a quantidade de parcelas de um emprestimo.
   parcelasPagar é a quantidade de parcelas que faltam para pagar um emprestimo.
   valorTotal é o valor total do emprestimo.
   valorPagar é a quantidade restante para pagar o emprestimo
   valorParcelas é o valor de cada parcela*/
  int parcelasMensais, parcelasPagar, valorPagar;
  float valorTotal, valorParcelas;

  // Vetores que armazenaram as parcelas e as datas de pagamento.
  string parcelasNaoPagas[12];
  string datasPagamentos[12];
};

int main()
{
  // Opções para os menus.
  int opcao, opcao2;
  string opcao4;
  // String que irá percorrer o vetor de clientes para identificar um cliente(Caso o cpf pesquisado seja igual ao do cliente, irá retornar a ação desejada pelo usuario).

  string cpfCliente;
  int numerodeClientes = 0;
  int limiteClientes = 1000;
  float novovalorTotal;
  int novoParcelas;
  string novoItem, dataPagamento;
  bool clienteEncontrado = false;
  // novoValorTotal, novoParcelas e novoItem servem para alterar o valor de uma caracteristica de um cliente quando a opção 3 do menu for selecionada.

  cliente clientes[limiteClientes]; // Vetor que irá armazenar clientes.
  cliente novoCliente;              // Cliente que será cadastrado.

  cliente Jarbas; // Exemplo de cliente.

  Jarbas.nome = "Jarbas";
  Jarbas.CPF = "1234567890";
  Jarbas.dataNascimento = "09/04/2002";
  Jarbas.endereco = "RuaItarare";
  Jarbas.dataEmprestimo = "--/--/----";
  Jarbas.valorTotal = 0;
  Jarbas.parcelasMensais = 0;

  clientes[numerodeClientes] = Jarbas;
  numerodeClientes = numerodeClientes + 1;

  // A função do comando do while é repetir esse menu para o usuário até que ele queria sair da operação, ou seja, enquanto o usuario não digitar o numero 7, o programa continuará mostrando o menu.
  do
  {
    clienteEncontrado = false;
    cout << endl
         << "Seja bem vindo(a)! Como podemos te ajudar hoje?" << endl
         << "1 - Cadastrar cliente" << endl
         << "2 - Visualizar as informacoes de um cliente" << endl
         << "3 - Editar as informacoes de um cliente" << endl
         << "4 - Cadastrar parcela paga" << endl
         << "5 - Cadastrar emprestimo" << endl
         << "6 - Excluir cliente" << endl
         << "7 - Sair" << endl;

    cin >> opcao; // Lendo a opção

    switch (opcao)
    {
    case 1:
      // Aqui é onde o usuário irá passar as informações básicas de cada cliente
      cout << "Qual e o nome do cliente que gostaria de cadastrar?" << endl;
      cin >> novoCliente.nome;

      cout << "Qual e o CPF do cliente?" << endl;
      cin >> novoCliente.CPF;

      cout << "Qual e o endereco do cliente?" << endl;
      cin >> novoCliente.endereco;

      cout << "Qual e a data de nascimento do cliente?(dd/mm/aaaa)" << endl;
      cin >> novoCliente.dataNascimento;

      cout << "Cliente Cadastrado com sucesso!" << endl
           << "Nome: " << novoCliente.nome << endl
           << "CPF: " << novoCliente.CPF << endl
           << "Endereco: " << novoCliente.endereco << endl
           << "Data de nascimento: " << novoCliente.dataNascimento << endl
           << endl;

      // O cadastramento de emprestimos só pode ser feito na opção de emprestimos, por isso, deixaremos as opções seguintes dessa maneira.
      novoCliente.parcelasMensais = 0;
      novoCliente.dataEmprestimo = "--/--/----";
      novoCliente.valorTotal = 0;
      novoCliente.parcelasPagar = 0;

      // Adicionamos o cliente no vetor e aumentamos a quantidade de clientes no sistema.
      clientes[numerodeClientes] = novoCliente;
      numerodeClientes = numerodeClientes + 1;

      break;
    case 2:

      // Procurando o cliente por base do CPF
      cout << "Digite o CPF do cliente:" << endl;
      cin >> cpfCliente;

      for (int i = 0; i < numerodeClientes + 1; i++)
      {
        if (clientes[i].CPF.compare(cpfCliente) == 0)
        // Caso o CPFcliente for igual ao cpf do clientes[i].cpf, ele iniciara a instrução, caso contrário, retornará como cliente não encontrado.
        {
          // Mostrando as informações.
          clienteEncontrado = true;
          cout << "Cliente encontrado! Segue os dados do cliente " << clientes[i].nome << ":" << endl
               << "Nome: " << clientes[i].nome << endl
               << "CPF: " << clientes[i].CPF << endl
               << "Endereco: " << clientes[i].endereco << endl
               << "Data de nascimento: " << clientes[i].dataNascimento << endl;

          // Caso o cliente pesquisado já tenha um empréstimo, o sistema irá mostrar as informações do empréstimo, caso contrário, irá mostrar que o cliente não possui um emprestimo cadastrado.
          if (clientes[i].parcelasPagar > 0)
          {
            cout << "Data do emprestimo: " << clientes[i].dataEmprestimo << endl
                 << "Valor total do emprestimo: " << clientes[i].valorTotal << endl
                 << "Valor restante a pagar: " << clientes[i].valorPagar << endl
                 << "Quantidade de parcelas do emprestimo: " << clientes[i].parcelasMensais << endl
                 << "Quantidade de parcelas restantes a pagar: " << clientes[i].parcelasPagar << endl
                 << "Informacoes das parcelas: " << endl;
            for (int j = 0; j < clientes[i].parcelasMensais; j++)
            {
              cout << "[" << j + 1 << "]" << clientes[i].parcelasNaoPagas[j] << " - " << clientes[i].valorParcelas << "R$ - Data do Pagamento: "
                   << clientes[i].datasPagamentos[j] << endl;
            }
          }
          else
          {
            cout << "O cliente nao possui um emprestimo cadastrado." << endl;
          }
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente nao encontrado, por favor, tente novamente." << endl;
      }
      break;
    case 3:

      cout << "Digite o CPF do cliente: " << endl;
      cin >> cpfCliente;

      for (int i = 0; i < numerodeClientes + 1; i++)
      {
        if (clientes[i].CPF.compare(cpfCliente) == 0)
        {
          // Ao localizar o cpf, um segundo menu é mostrado, aguardando a leitura da opção2 para a alteração de um dado.
          clienteEncontrado = true;
          cout << "Cliente encontrado!Qual e a informacao que gostaria de alterar?" << endl
               << "1 - Nome" << endl
               << "2 - CPF" << endl
               << "3 - Endereco" << endl
               << "4 - Data de Nascimento" << endl
               << "5 - Data do emprestimo" << endl
               << "6 - Valor total" << endl
               << "7 - Parcelas Mensais" << endl;

          cin >> opcao2; // leitura opção2

          switch (opcao2)
          {
          case 1:
            cout << "Digite o novo nome: " << endl;
            cin >> novoItem;
            // O novoItem é a alteração de um dado do cliente.Ao receber um valor, clientes[i].dado recebe o valor do novoItem. Esse metodo é repetido para as outras opções, porém, para casos como valorTotal, o item novoValorTotal será lido, pois novoItem é uma string, enquanto novoValorTotal é uma float.

            clientes[i].nome = novoItem;

            cout << "Nome corrigido com sucesso!" << endl;
            break;

          case 2:
            cout << "Digite o novo nome para o cliente: ";
            cin >> novoItem;

            clientes[i].CPF = novoItem;

            cout << "CPF corrigido com sucesso!" << endl;
            break;

          case 3:
            cout << "Digite o novo endereco: ";
            cin >> novoItem;

            clientes[i].endereco = novoItem;

            cout << "Endereco corrigido com sucesso!" << endl;
            break;

          case 4:
            cout << "Digite a nova data de nascimento: ";
            cin >> novoItem;

            clientes[i].dataNascimento = novoItem;

            cout << "Data de nascimento corrigida com sucesso!" << endl;
            break;

          case 5:
            cout << "Digite a nova data do emprestimo: ";
            cin >> novoItem;

            clientes[i].dataEmprestimo = novoItem;

            cout << "Data do emprestimo corrigida com sucesso!" << endl;
            break;

          case 6:
            cout << "Digite o novo valor total: ";
            cin >> novovalorTotal;

            clientes[i].valorTotal = novovalorTotal;

            clientes[i].parcelasPagar = clientes[i].parcelasMensais;
            clientes[i].valorParcelas = clientes[i].valorTotal / clientes[i].parcelasMensais;
            clientes[i].valorPagar = clientes[i].valorTotal;

            cout << "Valor total do emprestimo corrigido com sucesso!" << endl;
            break;

          case 7:
            cout << "Digite a nova quantidade de parcelas: ";
            cin >> novoParcelas;

            // O limite de parcelas por emprestimo é de 12, então caso o usuário digitar um numero maior que 12 ou menor ou igual que 0, o sistema irá repetir essa tela até a condição ser satisfeita;
            if (novoParcelas > 12 || novoParcelas <= 0)
            {
              do
              {
                cout << "Numero invalido, por favor, digite um numero valido(0 < x <= 12): " << endl;
                cin >> novoParcelas;
              } while (novoParcelas > 12 || novoParcelas < 0);
            }

            clientes[i].parcelasMensais = novoParcelas;

            // Atribuindo valores
            clientes[i].parcelasPagar = clientes[i].parcelasMensais;
            clientes[i].valorParcelas = clientes[i].valorTotal / clientes[i].parcelasMensais;
            clientes[i].valorPagar = clientes[i].valorTotal;

            cout << "Parcelas corrigidas com sucesso!" << endl;
            break;

          default:
            cout << "Opcao invalida." << endl;
          }
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente nao encontrado, por favor, tente novamente." << endl;
      }

      break;
    case 4:

      cout << "Digite o CPF do cliente: " << endl;
      cin >> cpfCliente;

      for (int i = 1; i < numerodeClientes; i++)
      {
        if (clientes[i].CPF == cpfCliente)
        {
          clienteEncontrado = true;

          // parcelasPagar é um valor que mostra para o usuário a quantidade de parcelas restantes do emprestimo, recebendo o mesmo valor de parcelasMensais. Cada vez que uma parcela é paga, parcelasPagar é decrementado por 1 até chegar em 0, e caso chegue em 0, mostrará que o cliente não possui um empréstimo cadastrado no sistema.
          if (clientes[i].parcelasPagar == 0)
          {
            cout << "O cliente nao possui um emprestimo cadastrado no sistema." << endl;
            break;
          }
          // Mostrando as informações do emprestimo.
          cout << "Aqui estao as informacoes das parcelas do cliente " << clientes[i].nome << ":" << endl
               << "Valor total do emprestimo: " << clientes[i].valorTotal << "R$" << endl
               << "Valor restante a pagar: " << clientes[i].valorPagar << "R$" << endl
               << "Quantidade de parcelas: " << clientes[i].parcelasMensais << endl
               << "Parcelas restantes: " << clientes[i].parcelasPagar << endl
               << endl;

          // Loop que irá mostrar as informações de cada parcela.
          for (int j = 0; j < clientes[i].parcelasMensais; j++)
          {
            cout << "[" << j + 1 << "]"
                 << " - " << clientes[i].parcelasNaoPagas[j] << " - " << clientes[i].valorParcelas << "R$ - Data do Pagamento: "
                 << clientes[i].datasPagamentos[j] << endl;
          }

          cout << "Qual parcela gostaria de pagar?" << endl;
          cin >> opcao2;

          // O usuario pode escolher a parcela que gostaria pelo numero ao lado dela.Caso a opção2 seja igual ao indice k que percorre o vetor, a parcela sera paga.
          for (int k = 0; k <= clientes[i].parcelasMensais; k++)
          {
            if (opcao2 == k)
            {
              cout << "Qual e a data de pagamento da parcela?" << endl;
              cin >> dataPagamento;

              cout << "A parcela foi paga!" << endl;

              // pagando a parcela e adicionando a data de pagamento.
              clientes[i].parcelasNaoPagas[k - 1] = "Parcela Paga!";
              clientes[i].datasPagamentos[k - 1] = dataPagamento;

              // Decrementando parcelasPagar e o valorPagar, que é o valor restante a ser pago da parcela.
              clientes[i].parcelasPagar = clientes[i].parcelasPagar - 1;
              clientes[i].valorPagar = clientes[i].valorPagar - clientes[i].valorParcelas;

              // Caso parcelasPagar <= 0, o sistema irá retornar com a informação de que o emprestimo foi pago completamente e retorna as informações seguintes para seus valores iniciais;
              if (clientes[i].parcelasPagar <= 0)
              {
                cout << "O emprestimo foi pago completamente!" << endl;

                clientes[i].parcelasMensais = 0;
                clientes[i].dataEmprestimo = "--/--/----";
                clientes[i].parcelasMensais = 0;
              }
            }
          }
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente nao encontrado, por favor, tente novamente." << endl;
      }
      break;
    case 5:

      cout << "Digite o CPF do cliente: " << endl;
      cin >> cpfCliente;

      for (int i = 0; i < numerodeClientes + 1; i++)
      {
        if (clientes[i].CPF.compare(cpfCliente) == 0)
        {
          // parcelasPagar é um dado que começa em 0 e depois recebe o mesmo valor que parcelas mensais, que ocorre quando um emprestimo é cadastrado.Então quando parcelasPagar recebe um valor(indenpendente qual seja), acaba sendo diferente de 0, e se o cliente tentar criar outro emprestimo enquanto ele já possui um em ativa, o sistema irá retornar que o cliente já possui um emprestimo.
          clienteEncontrado = true;
          if (clientes[i].parcelasPagar != 0)
          {
            cout << "O cliente ja possui um emprestimo cadastrado" << endl;
            break;
          }
          // Recebendo os valores.
          cout << "Qual e o valor total do emprestimo realizado pelo cliente " << clientes[i].nome << "?" << endl;
          cin >> clientes[i].valorTotal;

          cout << "Qual e a data em que o emprestimo foi realizado?(dd/mm/aaaa)" << endl;
          cin >> clientes[i].dataEmprestimo;

          cout << "Em quantas parcelas?(Atencao!O maximo de parcelas por emprestimo sao 12)" << endl;
          cin >> clientes[i].parcelasMensais;

          if (clientes[i].parcelasMensais > 12 || clientes[i].parcelasMensais <= 0)
          {
            do
            {
              cout << "Numero invalido, por favor, digite um numero que nao seja maior que 12 ou menor que 0: " << endl;
              cin >> clientes[i].parcelasMensais;
            } while (clientes[i].parcelasMensais > 12 || clientes[i].parcelasMensais < 0);
          }

          // Essa parte é a responsável por criar as parcelas.Ao inserir a data do empréstimo, precisamos separar da string o dia, mes e o ano do emprestimo, para que as parcelas sejam feitas.
          size_t primeiraBarra = clientes[i].dataEmprestimo.find('/');
          size_t segundaBarra = clientes[i].dataEmprestimo.find('/', primeiraBarra + 1);

          string diaEmprestimo = clientes[i].dataEmprestimo.substr(0, primeiraBarra);
          string mesEmprestimo = clientes[i].dataEmprestimo.substr(primeiraBarra + 1, segundaBarra - primeiraBarra - 1);
          string anoEmprestimo = clientes[i].dataEmprestimo.substr(segundaBarra + 1);

          // convertendo as strings para ints
          int ano = std::stoi(anoEmprestimo);
          int mes = std::stoi(mesEmprestimo);
          int dia = std::stoi(diaEmprestimo);

          for (int j = 0; j + 1 < clientes[i].parcelasMensais + 1; j++)
          {
            // Condição para caso haja parcelas que deverão ser pagas em outro ano.Caso ano seja maior que 11, mes voltara como 0(valendo 1) e será adicionado 1 ao ano.
            if (mes > 11)
            {
              mes = 0;
              ano++;
            }
            mes = mes + 1;

            // Adicionando a parcela ao vetor e convertendo os valores para uma string
            clientes[i].parcelasNaoPagas[j] = std::to_string(dia) + '/' + std::to_string(mes) + '/' + std::to_string(ano);
          }

          // Atribuindo valores
          clientes[i].parcelasPagar = clientes[i].parcelasMensais;
          clientes[i].valorParcelas = clientes[i].valorTotal / clientes[i].parcelasMensais;
          clientes[i].valorPagar = clientes[i].valorTotal;

          cout << "Emprestimo cadastrado!" << endl;
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente nao encontrado, por favor, tente novamente." << endl;
      }

      break;
    case 6:
      cout << "Digite o CPF do cliente: " << endl;
      cin >> cpfCliente;

      for (int i = 1; i < numerodeClientes + 1; i++)
      {
        if (clientes[i].CPF == cpfCliente)
        {
          clienteEncontrado = true;
          // Renomeando o cliente para "" assim como o seu CPF, para não ser mais localizado pela busca de cliente.
          clientes[i].nome = "";
          clientes[i].CPF = "";

          cout << "Cliente apagado!" << endl;
        }
      }
      if (!clienteEncontrado)
      {
        cout << "Cliente nao encontrado, por favor, tente novamente." << endl;
      }
      break;
    case 7:
      // Sistema desligando...
      cout << "Saindo...";
      break;

    default:
      // Caso o usuário digite um valor inválido
      cout << "Opcao invalida." << endl;
    }
  } while (opcao != 7);
}