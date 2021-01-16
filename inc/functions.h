#ifndef _FUNCAO_
#define _FUNCAO_

typedef struct 
{
	int numero;
	char data[20];
	char horario[20];
	int resultado[6];
	float valor;
	int status;
}Concurso;

typedef struct 
{
	char nome[100];
	int aposta[6];	
	int bilhete;
	int concurso;
	int status;
}Jogador;

typedef struct
{
	int bilhete;
	int concurso;
	char nome[100];
	float quantia;
}Ganhador;	




void MostrarMenu();
void MostrarSubMenuAposta();
void OpcaoIncorreta();
void EscolherOpcao();
void EscolhaSubMenu();
void RelatorioConcurso(Concurso s);
void RelatorioAposta(Jogador x, int opcao);
int NovoConcurso(Concurso *x, int ult);
Jogador NovaAposta();
void Limpar();
void sair();
int lerUltimoBilhete();
int LeituradeConcursos();
int SalvandoNumBilhete(int bilhete);
int SalvandoNumConcurso(int numero);
void salvarAposta(Jogador x);
int SalvarConcurso(Concurso x);
void ListarApostas(int concurso);
int ContaDigitos(int num);
void Sorteio();
int situacaoConcurso();
void CriarArquivos();
void RelatorioSorteio(Concurso c);
int verificaArquivo(char arquivo[], int opc);
Concurso dadosConcurso();
int verificaNumeroConcursos();
Concurso verificaConcursos();
void VerificarGanhadores(Concurso x, int *total_5, int *total_6);
float ValorConcurso();
int casoDeErroAposta(int *numero);
int modificaAposta();
int verificaSeArquivoNaoVazio(FILE * arquivo);

#endif