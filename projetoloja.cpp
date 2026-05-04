#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;


vector<int> Ids;
vector<string> Nome;
vector<int> Stock;
// mais qualquer coisa
vector<float>PrecoC;
vector<float>PrecoV;

int IDpro = 1;

	cout << "=========================================\n";
	cout << " BEM-VINDO A ZONA DAS VENDAS\n";
	cout << "=========================================\n\n";

bool nomerep(string nomes) {	
	for (string n : Nome) {
		if (n == nomes) {
			return true;
		}
	}
	return false;
}
alteracoes nisto 


int gerarFatura() {	//gera um numero a sorte
	return rand() % 1000 + 1;
}

void venda() {
	system("cls");

	int IDcliente;



	do {
		cout << "Diga qual o seu numero de Cliente (NIF): ";
		cin >> IDcliente;

		if (IDcliente < 100000000 || IDcliente > 999999999)
			cout << "NIF invalido! Deve ter exatamente 9 digitos.\n";
	isponiveis:\n";
	for (int i = 0; i < Ids.size(); i++) {
		if (Stock[i] == 0) continue;
		cout << "ID: " << Ids[i]
			<< " | Nome: " << Nome[i]
			<< " | Stock: " << Stock[i]
			<< " | Preco Venda: " << fixed << setprecision(2) << PrecoV[i]
			<< endl;
	}

	int idEscolhido;
	int indice = -1;

	while (indice == -1) {

		cout << "Escreva o ID do produto que pretende comprar: ";
		cin >> idEscolhido;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Nao pode inserir letras, tente novamente.\n\n";
			continue;
		}
//qualquer coisa
		for (int i = 0; i < Ids.size(); i++) {

			if (Ids[i] == idEscolhido) {

				if (Stock[i] == 0) {
					cout << "Esse produto esta ESGOTADO! Escolha outro.\n\n";
					indice = -1;
					break;
				}
				indice = i;
				break;
			}
		}
		if (indice == -1) {
			cout << "Produto nao encontrado ou sem stock, insira o ID de um produto da lista.\n\n";
		}
	}


	cout << "\nProduto selecionado:\n";
	cout << "ID: " << Ids[indice] << endl;
	cout << "Nome: " << Nome[indice] << endl;
	cout << "Stock: " << Stock[indice] << endl;
	cout << "Preco de Venda: " << fixed << setprecision(2) << PrecoV[indice] << endl << endl;

		int quantidade;
	while (true) {
		cout << "Insira a quantidade que deseja adquirir: ";
		cin >> quantidade;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Nao pode inserir letras, por isso encerramos o ato da compra" << endl;
			continue;
		}
		if (quantidade <= 0) {
			cout << "Quantidade invalida! Tente novamente.\n\n";
			continue;
		}
		if (quantidade > Stock[indice]) {
			cout << "\nStock insuficiente! Stock disponivel: " << Stock[indice] << "\n\n";
			continue;
		}
		break;
	}

	float precoComIVA = PrecoV[indice];
	float precoSemIVA = precoComIVA / 1.23;
	float valorIVA = precoComIVA - precoSemIVA;


	bool compraGratis = false;
	int sorte = rand() % 100 + 1;
	if (sorte <= 10) {
		compraGratis = true;
		precoComIVA = 0;
		precoSemIVA = 0;
		valorIVA = 0;
	}

	Stock[indice] -= quantidade;

	float totalCompra = precoComIVA * quantidade;
	float totalIVA = valorIVA * quantidade;

	int numeroFatura = gerarFatura();

	system("cls");
	cout << fixed << setprecision(2);
	cout << "RESUMO DA COMPRA:\n";
	cout << "Produto: " << Nome[indice] << endl;
	cout << "Quantidade: " << quantidade << endl;
	cout << "Preco Unidade: " << precoComIVA << endl;
	cout << "Subtotal: " << totalCompra << endl;

	if (compraGratis) {
		cout << "\nPARABENS!\nEsta compra e GRATIS.\n\n";
	}

	float valorPago = 0;
	float troco = 0;

	if (!compraGratis) {
		do {
			cout << "Valor entregue pelo cliente: ";
			cin >> valorPago;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Nao pode inserir letras, encerramos a compra." << endl;
				continue;
			}
			if (valorPago < totalCompra)
				cout << "Valor insuficiente.\n";
		} while (valorPago < totalCompra);

		troco = valorPago - totalCompra;
	}

	cout << "\nPagamento efetuado com sucesso!\n";
	cout << "O seu troco e de: " << troco << endl << endl;

	time_t agora = time(0);
	tm* data = localtime(&agora);

	cout << "\n========== TALAO ==========\n";
	cout << "Numero da fatura: " << numeroFatura << endl;
	cout << "Numero do cliente: " << IDcliente << endl;
	cout << "Data: " << data->tm_mday << "/" << data->tm_mon + 1 << "/" << data->tm_year + 1900 << endl;
	cout << "---------------------------\n";
	cout << "Produto: " << Nome[indice] << endl;
	cout << "Quantidade: " << quantidade << endl;
	cout << "Preco sem IVA (unidade): " << precoSemIVA << endl;
	cout << "IVA (23% por unidade): " << valorIVA << endl;
	cout << "Preco com IVA (unidade): " << precoComIVA << endl;
	cout << "---------------------------\n";
	cout << "Total da compra: " << totalCompra << endl;
	cout << "Total do IVA: " << totalIVA << endl;
	cout << "Valor entregue: " << valorPago << endl;
	cout << "Troco: " << troco << endl;
	cout << "===========================\n\n";
}


void editprod() {
	system("cls");

	cout << "=========================================\n";
	cout << "    EDITAR PRODUTO\n";
	cout << "=========================================\n\n";

	cout << "Produtos existentes:\n";
	for (int i = 0; i < Ids.size(); i++) {
		cout << "ID: " << Ids[i]
			<< " | Nome: " << Nome[i]
			<< " | Stock: " << Stock[i]
			<< " | Preco Custo: " << PrecoC[i] << fixed << setprecision(2)
			<< " | Preco Venda: " << PrecoV[i] << fixed << setprecision(2)
			<< endl;
	}

	int id;
	cout << "\nDigite o ID do produto a editar: ";
	cin >> id;

	int indice = -1;
	for (int i = 0; i < Ids.size(); i++) {
		if (Ids[i] == id) {
			indice = i;
			break;
		}
	}

	if (indice == -1) {
		cout << "Produto nao encontrado!" << endl;
		return;
	}
	system("cls");
	cout << "\nProduto selecionado: " << Nome[indice] << endl;

	int opcao;
	do {
		cout << "\nO que quer editar?\n";
		cout << "1 - Nome\n";
		cout << "2 - Stock\n";
		cout << "3 - Preco de custo\n";
		cout << "0 - Sair\n";
		cout << "Opcao: ";
		cin >> opcao;
		system("cls");

		switch (opcao) {

		case 1: {
			string novoNome;
			cout << "Novo nome: ";
			cin >> novoNome;
			bool repetido = false;
			for (int i = 0; i < Nome.size(); i++) {
				if (i != indice && Nome[i] == novoNome) {
					repetido = true;
					break;
				}
			}
			if (novoNome == Nome[indice]) {
				cout << "O nome e igual ao atual. Nenhuma alteracao foi feita." << endl;
				break;
			}

			if (repetido) {
				cout << "Nome ja existe. Alteracao cancelada." << endl;
			}
			else {
				Nome[indice] = novoNome;
				cout << "Nome alterado com sucesso." << endl;
			}
			break;
		}

		case 2: {
			int novoStock;
			cout << "Novo stock: ";
			cin >> novoStock;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Valor invalido." << endl;
				return;
			}
			//verifica se o stock que inseriu é maior que 1 e nao pode ser igual, se nao o stock muda
			if (novoStock < 1) {
				cout << "Valor invalido, o stock nao pode ser 0." << endl;
				return;
			}
			if (novoStock == Stock[indice]) {
				cout << "Valor invalido, o stock nao pode ser igual ao mesmo." << endl;
				return;
			}
			else {
				Stock[indice] = novoStock;
				cout << "Stock atualizado." << endl;
			}
			break;
		}

		case 3: {
			float novoPrecoC;
			cout << "Novo preco de custo(uma casa decimal): ";
			cin >> novoPrecoC;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Valor invalido." << endl;
				return;
			}
			//verifica se o preco de custo que inseriu é maior que 0 e tambem nao pode ser igual, se nao o preco de custa muda
			if (novoPrecoC <= 0) {
				cout << "Valor invalido, o preco de custo nao pode ser 0." << endl;
				return;
			}
			if (novoPrecoC == PrecoC[indice]) {
				cout << "Valor invalido, o preco de custo nao pode ser igual ao mesmo." << endl;
			}
			else {
				PrecoC[indice] = novoPrecoC;
				PrecoV[indice] = novoPrecoC * 1.30 * 1.23;
				cout << "Preco atualizado." << endl;
			}
			break;
		}

		case 0:
			cout << "A sair da edicao...\n";
			break;

		default:
			cout << "Opcao invalida." << endl;
		}

	} while (opcao != 0);
}

void elimprod() {
	system("cls");
	cout << "=========================================\n";
	cout << " ELIMINAR PRODUTO\n";
	cout << "=========================================\n\n";
	for (int i = 0; i < Ids.size(); i++) {
		cout << "ID: " << Ids[i]
			<< " | Nome: " << Nome[i]
			<< " | Stock: " << Stock[i]
			<< " | Preco de Custo: " << PrecoC[i] << fixed << setprecision(2)
			<< " | Preco de Venda: " << PrecoV[i] << fixed << setprecision(2)
			<< endl;
	}

	int id;

	cout << "Digite o ID do produto a eliminar: ";
	cin >> id;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
	}
	int indice = -1;
	for (int i = 0; i < Ids.size(); i++) {
		if (Ids[i] == id) {
			indice = i;
			break;
		}
	}
	if (indice == -1) {
		cout << "Produto nao encontrado!" << endl << endl;
		return;
	}

	string confirmar;
	cout << "Tem certeza que deseja eliminar o produto '" << Nome[indice] << "'? (s/n): ";
	cin >> confirmar;

	if (confirmar == "s" || confirmar == "S" || confirmar == "sim" || confirmar == "SIM" || confirmar == "Sim") {
		Ids.erase(Ids.begin() + indice);
		Nome.erase(Nome.begin() + indice);
		Stock.erase(Stock.begin() + indice);
		PrecoC.erase(PrecoC.begin() + indice);
		PrecoV.erase(PrecoV.begin() + indice);

		cout << "Produto eliminado com sucesso!" << endl << endl;
	}
	else if (confirmar == "n" || confirmar == "N" || confirmar == "nao" || confirmar == "NAO" || confirmar == "Nao") {
		cout << "O produto nao foi eliminado!" << endl << endl;
	}
	else
	{
		cout << "Eliminacao cancelada. So pode inserir s,S,sim,SIM,Sim para eliminar o produto ou n,N,nao,NAO,Nao para cancelar." << endl << endl;
	}

}

void listarprod() {
	system("cls");
	cout << "=========================================\n";
	cout << "   LISTAGEM DE PRODUTOS\n";
	cout << "=========================================\n\n";
	//roda o vetor Ids para depois listar todos da mesma posicao dos outros vetores
	for (int i = 0; i < Ids.size(); i++) {
		cout << "ID: " << Ids[i]
			<< " | Nome: " << Nome[i]
			<< " | Stock: " << Stock[i]
			<< " | Preco de Custo: " << PrecoC[i] << fixed << setprecision(2)
			<< " | Preco de Venda: " << PrecoV[i] << fixed << setprecision(2)
			<< endl;
	}
	return;
}

void adicionarproduto() {
	system("cls");
	string nomes;
	int stock;
	float precoc;

	cout << "=========================================\n";
	cout << "    ADICIONAR NOVO PRODUTO\n";
	cout << "=========================================\n\n";

	cout << "Nome do produto: ";
	cin >> nomes;
	if (nomerep(nomes)) {
		cout << "Este produto ja existe." << endl << endl;
		return;
	}

	cout << "Quantidade do produto: ";
	cin >> stock;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Valor invalido." << endl;
		return;
	}

	if (stock < 1) {
		cout << "Valor invalido, o stock nao pode ser 0." << endl;
		return;
	}


	cout << "Preco de custo: ";
	cin >> precoc;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Valor invalido." << endl;
		return;
	}

	if (precoc <= 0) {
		cout << "Valor invalido, o valor de custo nao pode ser 0." << endl;
		return;
	}


	Ids.push_back(IDpro++);
	Nome.push_back(nomes);
	Stock.push_back(stock);
	PrecoC.push_back(precoc);
	PrecoV.push_back(precoc * 1.30 * 1.23);

	cout << "Produto adicionado com sucesso!!!!" << endl << endl;

}


void menuproduto() {	//menu dos produtos
	system("cls");
	int opcao;

	do {
		cout << "=========================================\n";
		cout << "    GESTAO DE PRODUTOS\n";
		cout << "=========================================\n\n";
		cout << "1->Adicionar Produto" << endl;
		cout << "2->Editar Produto" << endl;
		cout << "3->Eliminar Produto" << endl;
		cout << "4->Listar Produto" << endl << endl;
		cout << "0->Sair" << endl << endl;
		cout << "Diga para onde quer ir:";

		cin >> opcao;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Nao pode inserir letras." << endl;
			return;
		}

		switch (opcao) {
		case 1: adicionarproduto(); break;
		case 2: editprod(); break;
		case 3: elimprod(); break;
		case 4: listarprod(); break;

		case 0: cout << "A sair..." << endl; break;
		default: cout << "Opcao invalida!";
		}
	} while (opcao != 0);

}


void menu() {	//menu principal
	system("cls");
	int opcao;

	do {
		cout << "================================================\n";
		cout << "        Seja bem-vindo ao Mercado Vende Tudo\n";
		cout << "================================================\n\n";
		cout << "1->Venda" << endl;
		cout << "2->Produto" << endl << endl;
		cout << "0->Sair" << endl << endl;
		cout << "Diga para onde quer ir:";

		cin >> opcao;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Nao pode inserir letras." << endl;
			return;
		}

		switch (opcao) {
		case 1: venda(); break;
		case 2: menuproduto(); break;
		case 0: cout << "A sair..."; break;
		default: cout << "Opcao invalida!";
		}
	} while (opcao != 0);
}

void prodja() {
	Ids.push_back(IDpro++);
	Nome.push_back("Agua");
	Stock.push_back(50);
	PrecoC.push_back(1.50);
	PrecoV.push_back(1.50 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("CocaCola");
	Stock.push_back(30);
	PrecoC.push_back(0.80);
	PrecoV.push_back(0.80 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Sandes");
	Stock.push_back(20);
	PrecoC.push_back(1.20);
	PrecoV.push_back(1.20 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Batatas Fritas");
	Stock.push_back(40);
	PrecoC.push_back(1.10);
	PrecoV.push_back(1.10 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Azeite");
	Stock.push_back(20);
	PrecoC.push_back(2);
	PrecoV.push_back(2 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Alface");
	Stock.push_back(20);
	PrecoC.push_back(0.30);
	PrecoV.push_back(0.30 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Couve Flor");
	Stock.push_back(20);
	PrecoC.push_back(0.30);
	PrecoV.push_back(0.30 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Redbull");
	Stock.push_back(100);
	PrecoC.push_back(1);
	PrecoV.push_back(1 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Arroz");
	Stock.push_back(50);
	PrecoC.push_back(1.20);
	PrecoV.push_back(1.20 * 1.30 * 1.23);

	Ids.push_back(IDpro++);
	Nome.push_back("Azeitonas");
	Stock.push_back(35);
	PrecoC.push_back(1.70);
	PrecoV.push_back(1.70 * 1.30 * 1.23);
}

int main()
{
	srand(time(0));
	prodja();
	menu();
}

