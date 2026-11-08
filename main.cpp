// aplicado em: projetos -> ProgComp16 propriedades -> C/C++ -> linha de comando -> Opções adicionais: 
// O casório entre utf-8 do Visual Studio e IBM 850 do Prompt de Comando do Windows ->
// /source-charset:utf-8 /execution-charset:.850

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

#define VERMELHO "\033[31m"
#define PADRAO "\033[m"

// Registros, uniões e enumerações:

	// Exercícios de Revisão:
struct Jogador {
	char  nome[50];
	float salario;
	int gols;
};

struct Meses {
	char nome[20];
};

struct Carro {
	char marca[20];
	int ano;
};

	// Atividades de Aprendizagem:
struct Palavra {
	char banco[20];
	int contador;
};

// Protótipos:

	// Exercícios de Revisão:
void estatico(int[]);
void exibir(int[], int);
void exibirDinamico(Jogador[], int);

	// Exercícios de Fixação:
void venda_deLivros();
void cadastro_deCarros(int*);

	// Atividades de Aprendizagem:
void timeJogador();
void concatenarCaracteres();
void vetores_emConjuntos();

// Funções reutilizáveis:
void definirTamanho_Solicitacao(int*);

// Funções:


int main() {

	// Exercícios de Revisão:
	// Enunciado da questão é possível de se acessar pelo link: https://github.com/JudsonSS/ProgComp/blob/master/Labs/Lab16/Lab16.pdf
	// Exercício 01:
	// Repete a execução se x != 0.

	// Exercício 02:
	
	char vetorCaractere[] = ("Pratique muito");
	int i = 0;
	for (i; vetorCaractere[i]; i++)
		std::cout << vetorCaractere[i];
	// Exercício 03:
	std::cout << "\n";
	int valoresExibir[] = {15,29,48,10,35};
	int tamanho = sizeof(valoresExibir) / sizeof(int);
	
	estatico(valoresExibir);
	exibir(valoresExibir, tamanho);

	// Exercício 04:
	int tamanhoRegistroJogador{ 0 };
	std::cout << "Escreva a quantidade de jogadores: ";
	definirTamanho_Solicitacao(&tamanhoRegistroJogador);

	Jogador * registroJogador = new Jogador[tamanhoRegistroJogador];
	std::cout << "\nDigite os dados do jogador: ";
	for (int i = 0; i < tamanhoRegistroJogador; i++) {
		std::cout << "\nJogador " << i + 1 << ": ";
		std::cout << "\nNome: ";
		std::cin.get();
		std::cin.getline((registroJogador + i)->nome, 50);
		std::cout << "\nSalário: ";
		std::cin >> (registroJogador + i)->salario;
		std::cout << "\nGols: ";
		std::cin >> (registroJogador + i)->gols;
	}
	exibirDinamico(registroJogador, tamanhoRegistroJogador);
	delete[] registroJogador;
	
	// Exercícios de Fixação:
	// Exercício 01:
	venda_deLivros();
	
	// Exercício 02:
	int tamanhoCarro{ 0 };
	cadastro_deCarros(&tamanhoCarro);

	// Atividades de Aprendizagem:
	// Atividade 01:
	timeJogador();

	// Atividade 02:
	concatenarCaracteres();
	
	// Atividade 03 e 04:

	vetores_emConjuntos();
	
}

void estatico(int vetorEstatico[]) {
	std::cout << "Estático (Perigoso): ";
	std::cout << vetorEstatico[0] << " ";
	std::cout << vetorEstatico[1] << " ";
	std::cout << vetorEstatico[2] << " ";
	std::cout << vetorEstatico[3] << " ";
	std::cout << vetorEstatico[4] << std::endl;

}
void exibir(int vetor[], int tamanho) {
	std::cout << "Em loop: ";
	for (int i = 0; i < tamanho; i++)
		std::cout << vetor[i] << " ";
	std::cout << std::endl;
}
void exibirDinamico(Jogador vetor[], int tamanho) {
	for (int i = 0; i < tamanho; i++)
		std::cout << "\nNome do Jogador: " << vetor[i].nome << std::fixed << std::setprecision(2) << "\nSalário: " << vetor[i].salario << "\nGols: " << vetor[i].gols;
	std::cout << std::endl;
}
void venda_deLivros() {
	const char* meses[12] = { "Janeiro", "Fervereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outrobro", "Novembro", "Dezembro" };
	int livrosCont{ 0 }, contador{ 0 };
	std::cout << "\nDigite o número de livros vendidos: ";
	for (int i = 0; i < 12; i++) {
		std::cout << "\n" << meses[i] << ": ";
		std::cin >> livrosCont;
		contador = contador + livrosCont;
		std::cout << "\n";
	}
	std::cout << "Em um ano foram vendidos " << contador << " livros.";
}
void cadastro_deCarros(int*tamanho) {
	std::cout << "\nQuantos carros deseja catalogar: ";
	definirTamanho_Solicitacao(tamanho);
	Carro * carros = new Carro[*tamanho];

	for (int i = 0; i < *tamanho; i++) {
		std::cout << "\nCarro #" << i + 1;
		std::cout << "\nAno: "; std::cin >> (carros + i)->ano;
		std::cout << "\nMarca: "; std::cin.get(); std::cin.getline((carros + i)->marca, 20);
	}
	std::cout << "\nAqui está a sua coleção: ";
	for (int i = 0; i < *tamanho; i++) {
		std::cout << (carros + i)->ano << " " << (carros + i)->marca;
		std::cout << ".\n";
		
	}
	delete[] carros;
}

void timeJogador() {
	char equipeJogador[20]{ 0 };
	int i{ 0 };
	char* time{ 0 };
	std::cout << "Digite jogador/time: "; std::cin >> equipeJogador;
	
	for(i; (equipeJogador[i] != '/'); i++)
		time = (equipeJogador + i);
	
	std::cout << "\nO nome do jogador tem " << i << " letras"
		<< "\nO seu time é: " << (time + 2);
}

void concatenarCaracteres() {
	int a{ 0 }, contador{ 0 };
	Palavra palavras[4] = { { " " },{ " " },{ " " },{ " " }};
	std::cout << "\nDigite 4 palavras: ";
	
	for (int i = 0; i < 4; i++) {
		std::cin >> palavras[i].banco;
		for (a = 0; palavras[i].banco[a]; a++) {
			palavras[i].contador++;
		}
		contador = contador + palavras[i].contador;
	}
	
	char* concatenador = new char[contador + 4] { 0 };

	for (int i = 0; i < 4; i++) {
		strcat(concatenador, palavras[i].banco);
		if (i < 3) {
			strcat(concatenador, " ");
		}
	}
	std::cout << concatenador;
	delete[] concatenador;
}

void vetores_emConjuntos() {
	//int i;
	int* A1_ptr{ 0 }, * A2_ptr{ 0 };
	int A[10] = { 48,78,40,96,74,58,32,56,91,6 };
	int B[10]{ 32,16,47,10,82,29,30,28,15,64 };
	std::cout << "\nSeparação em conjutos";
	std::cout << "\nCom ponteiros [primeiro, segundo]: ";

	for (int i = 0; i < 10; i = i + 2) {
		A1_ptr = (A + i);
		A2_ptr = (A + (i + 1));
		std::cout << "[" << *A1_ptr << "," << *A2_ptr << "] ";
	}
	
	std::cout << "\nSem ponteiros [primeiro, ultimo]: ";
	int contador{ 0 };
	for (int i = 0; i < 5; i++) {
		std::cout << "[" << B[i] << "," << B[9-i] << "] ";
	}
}

// Funções reutilizáveis:
void definirTamanho_Solicitacao(int* tamanho) {
	for (std::cin >> *tamanho; *tamanho < 1; std::cin >> *tamanho)
		std::cout << VERMELHO << "\nA quantidade precisa ser maior que 0: " << PADRAO;
}