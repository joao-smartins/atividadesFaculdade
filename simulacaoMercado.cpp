#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h> //biblioteca para colocar acentua��o
#define TF 10

//ola

struct TpData
{
	int Dia, Mes, Ano;
};

struct TpProdutos
{
	int CodProd, Estoque, CodForn;
	
	char Descr[30];
	
	float Preco;
	
	TpData DtValidade;	
};

struct TpFornecedores
{
	int CodForn;
	
	char NomeForn[30],Cidade[30];	
};

struct TpClientes
{
	int QtdeCompras;
	
	char NomeCli[30],CPFCli[17];	
	
	float ValorTotComprado;
};

struct TpVendas
{
	int CodVenda;
	
	float TotVendas;
	
	char CPFCli[17];
	
	TpData DtVendas;
};

struct TpVendasProduto
{
	int CodVenda,CodProd,Qtde;
	
	float ValorUni;
	
	
};

void Executar(void);
void Cadastro(TpProdutos Prod[TF],TpFornecedores Forn[TF], int &tlp, int &tlf);
int BuscaCod(TpProdutos Prod[TF], int tlp, int aux);
int BuscaForn(TpFornecedores Forn[TF],int tlf,int aux);
int BuscaCli(TpClientes cli[TF], int tlc, char aux[17]);
int CadastroForn(TpFornecedores Forn[TF],int &tlf, int aux);
void CadastroCli(TpClientes cli[TF], int &tlc);
void CadastroVendas(TpVendas vendas[TF],int &tlv,TpVendasProduto venpro[TF], int &tlvp, TpProdutos prod[TF],int tlp, TpClientes cli[TF], int tlc);
char menu (void);
int VerificaData(int auxd, int auxm, int auxa);
void InserirDados(TpProdutos TabProd[TF], int &TLP,TpFornecedores TabForn[TF],int&TLF, TpClientes TabCli[TF],int &TLC,
TpVendas TabVendas[TF],int &TLV,TpVendasProduto TabVendasProd[TF], int &TLVP);
void CupomFiscal(TpVendas vendas[TF],TpVendasProduto venpro[TF], int tlv , int tlvp, int prova, TpProdutos prod[TF], int tlp);
int BuscaVenda(TpVendasProduto venpro[TF], int tlvp, int aux);
void VarreduraFornPreco(TpProdutos prod[TF], int tlp , float auxaum, int codforn);
void AumentaPreco(TpProdutos prod[TF], int tlp , TpFornecedores forn[TF] , int tlf);
void ExcluirProd(TpProdutos prod[TF], int &tlp,TpVendasProduto venpro[TF], int tlvp);
int BuscaProdEmVendaProd(TpProdutos prod[TF], TpVendasProduto venpro[TF], int tlvp, int aux);
void VarreduraProd(TpProdutos prod[TF], int &tlp, int pos);
void ExcluirFornecedor(TpFornecedores forn[TF], int &tlf, int pos);
int BuscaFornEmProd(TpProdutos prod[TF], TpFornecedores forn[TF],TpVendasProduto venpro[TF],int tlvp, int tlp , int tlf, int aux);
void ExcluirForn(TpFornecedores forn[TF], int &tlf, TpProdutos prod[TF], int tlp, TpVendasProduto venpro[TF], int tlvp);
void ExclusaoCliente(TpClientes cli[TF], int &tlc);
void ExcluiCliente(TpClientes cli[TF], int &tlc, int pos);
void ConsultarProduto(TpProdutos prod[TF], int tlp);
void ConsultarFornecedor(TpFornecedores forn[TF], int tlf);
void ConsultarCliente(TpClientes cli[TF], int tlc);
void RelatorioProdutos(TpProdutos prod[TF], int tlp,TpFornecedores forn[TF], int tlf);
void RelatorioFornecedores(TpFornecedores forn[TF], int tlf);
void RelatorioClientes(TpClientes cli[TF], int tlc);
void RelatorioVendas(TpVendas vendas[TF], int tlv, TpVendasProduto venpro[TF], int tlvp, TpFornecedores forn[TF], int tlf, TpProdutos prod[TF], int tlp);
void ExcluirVenda(TpVendas vendas[TF], int &tlv , TpVendasProduto venpro[TF], int &tlvp , TpClientes cli[TF], int tlc);
void VarreduraVendaProd (TpVendasProduto venpro[TF], int &tlvp , int auxcod, int pos);
int BuscaVendaExcluir(TpVendas vendas[TF] , int tlv , int aux);
void VarreduraVendas(TpVendas vendas[TF], int &tlv , int pos);
char Menu(void);
char MenuProd(void);
char MenuForn(void);
char MenuCli(void);
char MenuVendas(void);
void ExecutarCli(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux);
void ExecutarForn(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux);
void ExecutarProd(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux);
void ExecutarVendas(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP);
void AlterarProd(TpProdutos Produtos[TF],int TLP);
char MenuAlterarProd(void);
void AlterarDescrProd(TpProdutos Produtos[TF], int tlp);
void AlterarEstoqueProd(TpProdutos Produtos[TF], int tlp);
void AlterarPrecoProd(TpProdutos Produtos[TF], int tlp);
void AlterarDataProd(TpProdutos Produtos[TF], int tlp);
void AlterarFornecedor(TpFornecedores Forn[TF],int tlf);
char MenuAlterarForn(void);
void AlterarNomeForn(TpFornecedores Forn[TF], int tlf);
void AlterarCidadeForn(TpFornecedores Forn [TF], int tlf);
void AlterarCliente(TpClientes cli[TF], int tlc);
void LimparMensagem(void);
void LimparLinha(int li);
void Limpar (int ci,int li,int cf, int lf);
void formulario(void);
void moldura(int ci,int li,int cf,int lf,int corT,int corF);
char MenuAlterarProd(void);
int verificaCPF(char CPF[17]);
int contagemVendas(TpVendasProduto venpro[TF], int tlvp, int aux);


void LimparMensagem(void)
{
	int a;
	for(a=13;a<78;a++)
	{
		gotoxy(a,23);
		printf("%c",32);
	}
}

void LimparLinha(int li)
{
	int a;
	for(a=30;a<79;a++)
	{
		gotoxy(a,li);
		printf("%c",32);
	}
}
void Limpar (int ci,int li,int cf, int lf)
{
	int a,b;
	gotoxy(ci,li);
	for(a=ci+1;a<cf-1;a++)
		for(b=li+1;b<lf-1;b++)
		{
			gotoxy(a,b);
			printf("%c",32);
		}	
}

void formulario(void)
{
	
	char resp;
	Limpar(2,5,27,21);
	moldura(1,1,80,25,15,9); // geral
	gotoxy(27,3);
	textcolor(14);
	printf(" # # # E S T R E L O # # #");
	
	moldura(2,2,79,4,15,9);//titulo
	moldura(2,5,27,21,15,9);//principal

	
	moldura(2,22,79,24,15,9);//mensagem
	gotoxy(4,23);
	textcolor(11);
	printf("MENSAGEM:");
	moldura(28,5,79,21,15,9); //menu secundaria	
	

}



void moldura(int ci,int li,int cf,int lf,int corT,int corF)
{
	int i;
	textcolor(corT);
	textbackground(corF);
	
	gotoxy(ci,li);
	printf("%c",201);
	gotoxy(ci,lf);
	printf("%c",200);
	gotoxy(cf,li);
	printf("%c",187);
	gotoxy(cf,lf);
	printf("%c",188);
	
	for(i=ci+1;i<cf;i++)
	{	
		gotoxy(i,li);
		printf("%c",205);
		gotoxy(i,lf);
		printf("%c",205);
	}
		
	
	for(i=li+1;i<lf;i++)
	{	
		gotoxy(ci,i);
		printf("%c",186);
		gotoxy(cf,i);
		printf("%c",186);
	}
	
	textcolor(15);
	textbackground(0);

}

int main(void)
{
	Executar();
	return 0;
}


char Menu(void)
{
	Limpar ( 2,5,27,22 );
	gotoxy(8,7);
	printf("### MENU ###",setlocale(LC_ALL,""));
	gotoxy(3,9);
	printf("[C]- Clientes");
	gotoxy(3,11);
	printf("[F]- Fornecedores");
	gotoxy(3,13);
	printf("[P]- Produtos");
	gotoxy(3,15);
	printf("[I]- Inserir Dados");
	gotoxy(3,17);
	printf("[V]- Vendas");
	gotoxy(3,20);
	printf("[ESC]- SAIR");
	
	return toupper(getch());
}

char MenuProd(void)
{
	Limpar ( 2,5,27,22 );
	gotoxy(4,7);
	printf("### MENU PRODUTOS ###");
	gotoxy(3,9);
	printf("[A]- Altera��o");
	gotoxy(3,10);
	printf("[B]- Cadastro");
	gotoxy(3,11);
	printf("[C]- Consulta");
	gotoxy(3,12);
	printf("[D]- Exclus�o");
	gotoxy(3,13);
	printf("[E]- Relat�rio Simples");
	gotoxy(3,14);
	printf("[F]- Aumentar Pre�o");
	gotoxy(3,18);
	printf("[ESC]- SAIR");
	return toupper(getch());
}

char MenuForn(void)
{
	Limpar ( 2,5,27,22 );
	gotoxy(5,7);
	printf("# MENU FORNECEDORES #");
	gotoxy(3,9);
	printf("[A]- Altera��o");
	gotoxy(3,11);
	printf("[B]- Cadastro");
	gotoxy(3,13);
	printf("[C]- Consulta");
	gotoxy(3,15);
	printf("[D]- Exclus�o");
	gotoxy(3,17);
	printf("[E]- Relat�rio Simples");
	gotoxy(3,20);
	printf("[ESC]- SAIR");
	return toupper(getch());
}


char MenuCli(void)
{
	Limpar ( 2,5,27,22 );
	gotoxy(4,7);
	printf("### MENU CLIENTES ###");
	gotoxy(3,9);
	printf("[A]- Altera��o");
	gotoxy(3,11);
	printf("[B]- Cadastro");
	gotoxy(3,13);
	printf("[C]- Consulta");
	gotoxy(3,15);
	printf("[D]- Exclus�o");
	gotoxy(3,17);
	printf("[E]- Relat�rio Simples");
	gotoxy(3,20);
	printf("[ESC]- SAIR");
	return toupper(getch());
}

char MenuVendas(void) 
{
	Limpar ( 2,5,27,22 );
	gotoxy(4,7);	
	printf("### MENU VENDAS ###");
	gotoxy(3,9);
	printf("[A]- Realizar Venda");
	gotoxy(3,11);
	printf("[B]- Excluir Venda");
	gotoxy(3,13);
	printf("[C]- Relat�rio");
	gotoxy(3,18);
	printf("[ESC]- SAIR");
	return toupper(getch());
}

void ExecutarCli(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux)
{
	char op;
	do
	{
		op=MenuCli();
		
		switch(op)
		{			
			case'A':
				AlterarCliente(Clientes, TLC);
				break;
					
			case'B':
				CadastroCli(Clientes,TLC);
				break;
			
			case'C':
				ConsultarCliente(Clientes, TLC);
				break;
				
			case'D':
				ExclusaoCliente(Clientes,TLC);
				break;
			
			case'E':
				RelatorioClientes(Clientes,TLC);
				break;
		}
		
	}while(op != 27);
}

void ExecutarForn(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux)
{
	char op;
	do
	{
		op=MenuForn();
		
		switch(op)
		{
			case'A':
				AlterarFornecedor(Fornecedores,TLF);
				break;
				
			case'B':
				CadastroForn(Fornecedores,TLF,aux);
				break;
			
			case'C':
				ConsultarFornecedor(Fornecedores , TLF);
				break;
				
			case'D':
				ExcluirForn(Fornecedores, TLF, Produtos, TLP, VendasProduto,TLVP);
				break;
			
			case'E':
				RelatorioFornecedores(Fornecedores,TLF);
				break;
		}
		
	}while(op != 27);
}

void ExecutarProd(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP, int &aux)
{
	char op;
	
	do
	{
		op=MenuProd();
		
		switch(op)
		{
			case'A':
				AlterarProd(Produtos, TLP);
				break;
				
			case'B':
				Cadastro(Produtos,Fornecedores,TLP,TLF);
				break;
			
			case'C':
				ConsultarProduto(Produtos,TLP);
				break;
				
			case'D':
				ExcluirProd(Produtos,TLP,VendasProduto,TLVP);
				break;
			
			case'E':
				RelatorioProdutos(Produtos,TLP,Fornecedores,TLF);
				break;
				
			case'F':
				AumentaPreco(Produtos, TLP , Fornecedores , TLF);
				break;
		}
		
	}while(op != 27);
}

void ExecutarVendas(TpProdutos Produtos[TF], int &TLP , TpFornecedores Fornecedores[TF], int &TLF, TpClientes Clientes[TF], int &TLC, TpVendas Vendas[TF], int &TLV, TpVendasProduto VendasProduto[TF], int &TLVP)
{
	char op;
	
	do
	{
		op=MenuVendas();
		
		switch(op)
		{
	
			case'A':
				CadastroVendas(Vendas,TLV, VendasProduto, TLVP, Produtos, TLP,Clientes, TLC);
				break;
			
			case'B':
				ExcluirVenda(Vendas, TLV ,VendasProduto, TLVP ,Clientes, TLC);
				break;
				
			case'C':
				RelatorioVendas(Vendas, TLV, VendasProduto, TLVP,Fornecedores, TLF, Produtos, TLP);
				break;
		}
		
	}while(op != 27);
}

void Executar(void)
{
	int TLP=0, TLF=0, TLC=0, TLV=0, TLVP=0,aux=0;
	
	TpProdutos Produtos[TF];
	TpFornecedores Fornecedores[TF];
	TpClientes Clientes[TF];
	TpVendas Vendas[TF];
	TpVendasProduto VendasProduto[TF];	
	
	formulario();
	char op;
	do
	{
		op=Menu();
		
		switch(op)
		{
			case'C':
				ExecutarCli(Produtos, TLP, Fornecedores, TLF, Clientes, TLC, Vendas, TLV, VendasProduto, TLVP,aux);
				break;
				
			case'F':
				ExecutarForn(Produtos, TLP, Fornecedores, TLF, Clientes, TLC, Vendas, TLV, VendasProduto, TLVP,aux);
				break;
			
			case'P':
				ExecutarProd(Produtos, TLP, Fornecedores, TLF, Clientes, TLC, Vendas, TLV, VendasProduto, TLVP,aux);
				break;
				
			case'I':
				InserirDados(Produtos, TLP, Fornecedores, TLF, Clientes, TLC, Vendas, TLV, VendasProduto, TLVP);
				break;
			
			case'V':
				ExecutarVendas(Produtos, TLP, Fornecedores, TLF, Clientes, TLC, Vendas, TLV, VendasProduto, TLVP);
				break;
		}
		
		
	}while(op != 27);
}


void Cadastro(TpProdutos Prod[TF],TpFornecedores Forn[TF], int &tlp, int &tlf)
{
	int auxcod,i,auxest,auxforn=0,j,a,auxdia,auxmes,auxano,x;
	char auxdescr[30],resp;
	float auxpre;
	
	Limpar(28,5,79,21);
	gotoxy(40,6);
	printf("### CADASTRO PPRODUTOS ###");
	gotoxy(30,8);
	printf("Digite o c�digo do produto:");
	gotoxy(30,9);
	scanf("%d",&auxcod);
	while(auxcod != 0 && tlp < TF)
	{
		i=BuscaCod(Prod,tlp,auxcod);
		if(i == -1)
		{
			gotoxy(30,10);
			printf("Digite o c�digo do fornecedor:");
			gotoxy(30,11);
			scanf("%d",&auxforn);
			j=BuscaForn(Forn,tlf,auxforn);
			if(j == -1)
			{
				gotoxy(30,12);
				printf("Deseja Cadastrar o Forn? [S/N]");
				resp=tolower(getch());
				while( resp != 's' && resp!= 'n')
				{
					resp=tolower(getch());
				}
				
				if(resp == 's')
				{
					a=CadastroForn(Forn,tlf,auxforn);
					if(a == 1)
					{
						Limpar(28,6,79,21);
						gotoxy(30,7);
						printf("Digite a descri��o:");
						gotoxy(30,8);
						fflush(stdin);
						gets(auxdescr);
						gotoxy(30,9);
						printf("Digite o estoque:");
						gotoxy(30,10);
						scanf("%d",&auxest);
						gotoxy(30,11);
						printf("Digite o Pre�o:");
						gotoxy(30,12);
						scanf("%f",&auxpre);
						gotoxy(30,13);
						printf("Digite a data[dd/mm/aaaa]");
						gotoxy(30,14);
						scanf("%d %d %d",&auxdia,&auxmes,&auxano);
						x=VerificaData(auxdia,auxmes,auxano);
						while(x == -1)
						{
							gotoxy(30,13);
							printf("Digite a data[dd/mm/aaaa]");
							LimparLinha(14);
							gotoxy(30,14);
							scanf("%d %d %d",&auxdia,&auxmes,&auxano); 
							x=VerificaData(auxdia,auxmes,auxano);
						}
						gotoxy(30,15);
						printf("Deseja Concluir o Cadastro [S/N]:");
						resp=tolower(getch());
						if(resp == 's')
						{
							Prod[tlp].CodProd=auxcod;
							Prod[tlp].Preco=auxpre;
							strcpy(Prod[tlp].Descr,auxdescr);
							Prod[tlp].Estoque=auxest;
							Prod[tlp].DtValidade.Dia=auxdia;
							Prod[tlp].DtValidade.Mes=auxmes;
							Prod[tlp].DtValidade.Ano=auxano;
							Prod[tlp].CodForn=auxforn;
							tlp++;
							
							
							gotoxy(13,23);
							printf("Produto Cadastrado com sucesso!");
							getch();
							LimparMensagem();
						}
					}
					
				}
				
			}
			else
			{
	//			gotoxy(13,23);
	//			printf("Forn ja cadastrado:");
		
				Limpar(28,6,79,21);
				gotoxy(30,7);
				printf("Digite a descri��o:");
				gotoxy(30,8);
				fflush(stdin);
				gets(auxdescr);
				gotoxy(30,9);
				printf("Digite o estoque:");
				gotoxy(30,10);
				scanf("%d",&auxest);
				gotoxy(30,11);
				printf("Digite o Pre�o:");
				gotoxy(30,12);
				scanf("%f",&auxpre);
				gotoxy(30,13);
				printf("Digite a data[dd/mm/aaaa]");
				gotoxy(30,14);
				scanf("%d %d %d",&auxdia,&auxmes,&auxano);
				x=VerificaData(auxdia,auxmes,auxano);
				while(x == -1)
				{
				
					LimparLinha(14);
					gotoxy(30,14);
					scanf("%d %d %d",&auxdia,&auxmes,&auxano); 
					x=VerificaData(auxdia,auxmes,auxano);
				}
				gotoxy(30,15);
				printf("Deseja Concluir o Cadastro [S/N]:");
				resp=tolower(getch());
				if(resp == 's')
				{
					Prod[tlp].CodProd=auxcod;
					Prod[tlp].Preco=auxpre;
					strcpy(Prod[tlp].Descr,auxdescr);
					Prod[tlp].Estoque=auxest;
					Prod[tlp].DtValidade.Dia=auxdia;
					Prod[tlp].DtValidade.Mes=auxmes;
					Prod[tlp].DtValidade.Ano=auxano;
					Prod[tlp].CodForn=auxforn;
					tlp++;
					
					gotoxy(13,23);
					printf("Produto Cadastrado com sucesso!");
				}
			}
					
		}
		else
		{
			gotoxy(13,23);
			printf("Produto J� Cadastrado!");
			
		}
		
		Limpar(28,5,79,21);
		gotoxy(40,6);
		printf("### CADASTRO PRODUTOS ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		
		}
		
	
		Limpar(28,5,79,21);
		LimparMensagem();
}

int BuscaCod(TpProdutos Prod[TF], int tlp, int aux)
{
	int pos;
	pos=0;
	while( pos< tlp && aux != Prod[pos].CodProd)
		pos++;
	if(pos<tlp)
		return pos;
	else
		return -1;	
}


int BuscaForn(TpFornecedores Forn[TF],int tlf,int aux)
{
	int pos;
	pos=0;
	while(pos<tlf && aux != Forn[pos].CodForn)
		pos++;
	if(pos<tlf)
		return pos;
	else
		return -1;
}

int CadastroForn(TpFornecedores Forn[TF],int &tlf, int aux) 
{
	char auxnome[30],auxcid[30],resp;
	int i,auxcod;
	if(aux>0)
	{
		gotoxy(30,13);
		printf("Digite o nome do forncedor:");
		fflush(stdin);
		gotoxy(30,14);
		gets(auxnome);
		gotoxy(30,15);
		printf("Digite a Cidade do fornecedor:");
		fflush(stdin);
		gotoxy(30,16);
		gets(auxcid);
		
		gotoxy(30,17);
		printf("Deseja Confirmar o Cadastro?[S/N]");
		resp=tolower(getch());
		if(resp == 's')
		{
			Forn[tlf].CodForn=aux;
			strcpy(Forn[tlf].NomeForn,auxnome);
			strcpy(Forn[tlf].Cidade,auxcid);
			tlf++;
			
			gotoxy(13,23);
			printf("Fornecedor cadastrado!");
			getch();
			LimparMensagem();
			
			Limpar(28,5,79,21);
			return 1;
			
		}
		else
			return -1;
		
		
	}
	else
	{

		gotoxy(40,6);
		printf("### Cadastro Fornecedor ###");
		gotoxy(30,8);
		printf("Digite o c�digo do fornecedor:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		while(auxcod > 0 && tlf < TF)
		{
			i=BuscaForn(Forn,tlf,auxcod);
			if( i == -1)
			{
				gotoxy(30,10);
				printf("Digite o nome do fornecedor:");
				gotoxy(30,11);
				fflush(stdin);
				gets(auxnome);
				gotoxy(30,12);
				printf("Digite a Cidade do fornecedor:");
				gotoxy(30,13);
				fflush(stdin);
				gets(auxcid);
				
				gotoxy(30,14);
				printf("Deseja Confirmar o Cadastro?[S/N]");
				resp=tolower(getch());
				if(resp == 's')
				{
					Forn[tlf].CodForn=auxcod;
					strcpy(Forn[tlf].NomeForn,auxnome);
					strcpy(Forn[tlf].Cidade,auxcid);
					tlf++;
					
					gotoxy(13,23);
					printf("Fornecedor cadastrado!");
					getch();
					LimparMensagem();
					
				
				
				}
				
										
				
			}
			else
			{
				gotoxy(13,23);
				printf("Fornecedor j� cadastrado");
				getch();
				LimparMensagem();
			}
				
				
			Limpar(28,7,79,21);
			gotoxy(30,8);
			printf("Digite o c�digo do fornecedor:");
			gotoxy(30,9);
			scanf("%d",&auxcod);
		
		}
	
	}
	Limpar(28,5,79,21);
}
void InserirDados(TpProdutos TabProd[TF], int &TLP,TpFornecedores TabForn[TF],int&TLF, TpClientes TabCli[TF],int &TLC,
TpVendas TabVendas[TF],int &TLV,TpVendasProduto TabVendasProd[TF], int &TLVP)
{
	TabProd[TLP].CodProd = 7000;
	strcpy(TabProd[TLP].Descr,"Lasanha");
	TabProd[TLP].Estoque = 52;
	TabProd[TLP].Preco = 9.98;
	TabProd[TLP].DtValidade.Dia = 10;
	TabProd[TLP].DtValidade.Mes = 9;
	TabProd[TLP].DtValidade.Ano = 2024;
	TabProd[TLP].CodForn = 200;
	TLP++;
	
	TabProd[TLP].CodProd = 1000;
	strcpy(TabProd[TLP].Descr,"Suco");
	TabProd[TLP].Estoque = 188;
	TabProd[TLP].Preco = 1.62;
	TabProd[TLP].DtValidade.Dia = 15;
	TabProd[TLP].DtValidade.Mes = 5;
	TabProd[TLP].DtValidade.Ano = 2025;
	TabProd[TLP].CodForn = 500;
	TLP++;
	
	TabProd[TLP].CodProd = 4000;
	strcpy(TabProd[TLP].Descr,"Biscoito");
	TabProd[TLP].Estoque = 63;
	TabProd[TLP].Preco = 4.56;
	TabProd[TLP].DtValidade.Dia = 22;
	TabProd[TLP].DtValidade.Mes = 11;
	TabProd[TLP].DtValidade.Ano = 2024;
	TabProd[TLP].CodForn = 300;
	TLP++;
	
	TabForn[TLF].CodForn = 200;
	strcpy(TabForn[TLF].NomeForn,"Fabrica Matao");
	strcpy(TabForn[TLF].Cidade,"Matao");
	TLF++;
	
	TabForn[TLF].CodForn = 500;
	strcpy(TabForn[TLF].NomeForn,"Sapore S.A.");
	strcpy(TabForn[TLF].Cidade,"Campinas");
	TLF++;
	
	TabForn[TLF].CodForn = 300;
	strcpy(TabForn[TLF].NomeForn,"Basteck");
	strcpy(TabForn[TLF].Cidade,"Guarapuava");
	TLF++;
	
	strcpy(TabCli[TLC].CPFCli,"132.456.987-44");
	strcpy(TabCli[TLC].NomeCli,"Windislaisson");
	TabCli[TLC].QtdeCompras = 5;
	TabCli[TLC]. ValorTotComprado = 2841.63;
	TLC++;
	
	strcpy(TabCli[TLC].CPFCli,"651.325.984-77");
	strcpy(TabCli[TLC].NomeCli,"Astolfo");
	TabCli[TLC].QtdeCompras = 2;
	TabCli[TLC]. ValorTotComprado = 1450.25;
	TLC++;
	
	strcpy(TabCli[TLC].CPFCli,"159.357.654-52");
	strcpy(TabCli[TLC].NomeCli,"Armelinda");
	TabCli[TLC].QtdeCompras = 11;
	TabCli[TLC]. ValorTotComprado = 1982.54;
	TLC++;
	
	TabVendas[TLV].CodVenda=1;
	strcpy(TabVendas[TLV].CPFCli,"651.325.984-77");
	TabVendas[TLV].DtVendas.Dia = 10;
	TabVendas[TLV].DtVendas.Mes = 8;
	TabVendas[TLV].DtVendas.Ano = 2023;
	TabVendas[TLV].TotVendas = 451.90;	
	TLV++;
	
	TabVendas[TLV].CodVenda=2;
	strcpy(TabVendas[TLV].CPFCli,"132.456.987-44");
	TabVendas[TLV].DtVendas.Dia = 15;
	TabVendas[TLV].DtVendas.Mes = 7;
	TabVendas[TLV].DtVendas.Ano = 2023;
	TabVendas[TLV].TotVendas = 450.60;	
	TLV++;
	
	TabVendas[TLV].CodVenda=3;
	strcpy(TabVendas[TLV].CPFCli,"159.357.654-52");
	TabVendas[TLV].DtVendas.Dia = 6;
	TabVendas[TLV].DtVendas.Mes = 4;
	TabVendas[TLV].DtVendas.Ano = 2023;
	TabVendas[TLV].TotVendas = 182.14;	
	TLV++;
	
	TabVendasProd[TLVP].CodVenda=1;
	TabVendasProd[TLVP].CodProd=1000;
	TabVendasProd[TLVP].Qtde=10;
	TabVendasProd[TLVP].ValorUni=1.62;
	TLVP++;
	
	TabVendasProd[TLVP].CodVenda=1;
	TabVendasProd[TLVP].CodProd=7000;
	TabVendasProd[TLVP].Qtde=20;
	TabVendasProd[TLVP].ValorUni=9.98;
	TLVP++;
	
	TabVendasProd[TLVP].CodVenda=1;
	TabVendasProd[TLVP].CodProd=4000;
	TabVendasProd[TLVP].Qtde=53;
	TabVendasProd[TLVP].ValorUni=4.56;
	TLVP++;
	
	TabVendasProd[TLVP].CodVenda=2;
	TabVendasProd[TLVP].CodProd=4000;
	TabVendasProd[TLVP].Qtde=10;
	TabVendasProd[TLVP].ValorUni=4.56;
	TLVP++;
	
	TabVendasProd[TLVP].CodVenda=3;
	TabVendasProd[TLVP].CodProd=7000;
	TabVendasProd[TLVP].Qtde=1;
	TabVendasProd[TLVP].ValorUni=9.98;
	TLVP++;
	
	gotoxy(13,23);
	printf("Dados Inseridos!");
	getch();
	LimparMensagem();
}



void CadastroCli(TpClientes cli[TF], int &tlc) 
{
	int i,x;
	char auxnome[30],auxcpf[17];
		
	do
	{
		gotoxy(40,6);
		printf("### CADASTRO CLIENTE ###");
		gotoxy(30,8);
		printf("Digite o CPF do cliente:");
		gotoxy(30,9);
		fflush(stdin);
		gets(auxcpf);
		x=verificaCPF(auxcpf);
		if(x != -1)
		{
			i=BuscaCli(cli,tlc,auxcpf);
			if(i == -1 )
			{
				gotoxy(30,10);
				printf("Digite o nome do cliente!");
				gotoxy(30,11);
				fflush(stdin);
				gets(auxnome);
				gotoxy(30,12);
				printf("Deseja Confirmar o Cadastro?[S/N]");
				if(toupper(getch()) == 'S')
				{
					strcpy(cli[tlc].NomeCli,auxnome);
					cli[tlc].QtdeCompras=0;
					cli[tlc].ValorTotComprado=0;
					strcpy(cli[tlc].CPFCli, auxcpf);
					tlc++;	
					gotoxy(13,23);
					printf("Cliente Cadastrado com sucesso!");
					getch();
					LimparMensagem();
					Limpar(28,5,79,21);
				}
				else
					Limpar(28,5,79,21);
				
			}
			else
			{
				gotoxy(13,23);
				printf("Cliente j� cadastrado!");
				getch();
				LimparMensagem();
			}	
		}
		else
		{
			gotoxy(13,23);
			printf("CPF Inv�lido!");
			getch();
			LimparMensagem();
		}
			
	Limpar(28,7,79,21);		
	}while(strlen(auxcpf)>1);
	Limpar(28,5,79,21);
	
}

int BuscaCli(TpClientes cli[TF], int tlc, char aux[17])
{
	int pos;
	pos=0;
	while( pos < tlc && strcmp(aux,cli[pos].CPFCli) != 0)
		pos++;
	if(pos == tlc)
		return -1;
	else
		return pos;
}

void CadastroVendas(TpVendas vendas[TF],int &tlv,TpVendasProduto venpro[TF], int &tlvp, TpProdutos prod[TF],int tlp,TpClientes cli[TF], int tlc)
{
	int i,j,provatlvp = tlvp,auxprod,auxd,auxm,auxa,a,auxqntd;
	char auxcpf[17];
	float somatotal = 0;
	
	do
	{
		LimparLinha(6);
		gotoxy(40,6);
		printf("### VENDAS ###");
		
		gotoxy(30,8);
		printf("Digite o CPF do cliente:");
		gotoxy(30,9);
		fflush(stdin);
		gets(auxcpf);
		i=BuscaCli(cli,tlc,auxcpf);
		if(i == -1)
		{
			gotoxy(13,23);
			printf("Cliente n�o encontrado!");
			getch();
			LimparMensagem();
			
			}	
		else
		{
			gotoxy(30,10);
			printf("Digite o c�digo do Produto:");
			gotoxy(30,11);
			scanf("%d",&auxprod);
			
			while(auxprod > 0 && tlv < TF && tlvp < TF)
			{
				
				float soma = 0;
				j=BuscaCod(prod,tlp,auxprod);
				if(j == -1)
				{
					gotoxy(13,23);
					printf("Produto n�o encontrado!");
					LimparMensagem();
					Limpar(28,7,79,21);
					getch();
				}	
				else
				{
					gotoxy(30,12);
					printf("Digite a quantidade desejada:");
					gotoxy(30,13);
					scanf("%d",&auxqntd);
					if(auxqntd <= prod[j].Estoque)
					{
						gotoxy(30,14);
						printf("Deseja concluir a venda?");
						if(toupper(getch()) == 'S')
						{
							gotoxy(13,23);
							printf("Venda Conclu�da!");
							venpro[tlvp].CodVenda=tlv+1;
							venpro[tlvp].CodProd= prod[j].CodProd;
							venpro[tlvp].Qtde= auxqntd;
							venpro[tlvp].ValorUni = prod[j].Preco;
							
							soma = venpro[tlvp].ValorUni * auxqntd;
							somatotal+=soma;
						
							tlvp++;
							Limpar(28,7,79,21);
							getch();
							LimparMensagem();
						}
					}
					else
					{	
						gotoxy(13,23);
						printf("Estoque Insuficiente!");
						getch();
						LimparMensagem();
						Limpar(28,7,79,21);
						

						}	
					
				}
				if(tlv < TF && tlvp < TF)
				{
					gotoxy(30,8);
					printf("Digite o c�digo do Produto:");
					gotoxy(30,9);
					scanf("%d",&auxprod);
				}
		
			}
			
			if(provatlvp !=  tlvp)
			{
				vendas[tlv].CodVenda= tlv+1;
				strcpy(vendas[tlv].CPFCli,auxcpf);
				gotoxy(30,10);
				printf("Digite a data da venda:");
				gotoxy(30,11);
				scanf("%d %d %d",&auxd, &auxm, &auxa);
				a=VerificaData(auxd,auxm,auxa);
				
				while(a == -1) // se errar a data continua, para nn perder a venda
				{	
					gotoxy(30,10);
					printf("Digite a data da venda:");
					LimparLinha(11);
					gotoxy(30,11);
					scanf("%d %d %d",&auxd, &auxm, &auxa);
					a=VerificaData(auxd,auxm,auxa);
				}
				
				if(a != -1)
				{
					vendas[tlv].DtVendas.Dia = auxd;
					vendas[tlv].DtVendas.Mes = auxm;
					vendas[tlv].DtVendas.Ano = auxa;
					vendas[tlv].TotVendas += somatotal;
					
				}
				
				cli[i].QtdeCompras++;
				cli[i].ValorTotComprado += somatotal;
				//printf("%.2f",cli[i].ValorTotComprado);
				
				CupomFiscal(vendas,venpro,tlv,tlvp, provatlvp, prod, tlp);
			
				tlv++;
			}
	
	
		}
		Limpar(28,5,79,21);
	}while(strlen(auxcpf)>1);
}

int VerificaData(int auxd, int auxm, int auxa)
{
	if(auxd > 0 && auxd <32)
	{
		if(auxm > 0 && auxm <13)
		{
			if(auxa > 2022)
			{
				return 1;
			}
			else
			{
				
				gotoxy(13,23);
				printf("Ano Inv�lido!");
				LimparMensagem();
				return -1;
			}
		}
		else
		{
			
			gotoxy(13,23);
			printf("Mes Inv�lido!");
			LimparMensagem();
			return -1;
		}
	}
	else
	{
		
		gotoxy(13,23);
		printf("Dia Inv�lido!");
		LimparMensagem();
		return -1;
	}
	
	
}

void CupomFiscal(TpVendas vendas[TF],TpVendasProduto venpro[TF], int tlv , int tlvp, int prova, TpProdutos prod[TF], int tlp)
{
	int a,x,i,b, aux= vendas[tlv].CodVenda,auxcod,j,max,min;
	char op;
	x=tlvp - prova;
	
	Limpar(28,5,79,21);
	gotoxy(40,6);
	printf("### CUPOM FISCAL ###");
	gotoxy(30,8);
	printf("CPF na nota[S/N]?");
	if(toupper(getch()) == 'S')
	{
		gotoxy(30,9);
		printf("CPF Cliente: %s",vendas[tlv].CPFCli);
		gotoxy(30,10);
		printf("C�digo De Venda: %d", vendas[tlv].CodVenda);
		gotoxy(30,11);
		printf("Produtos:");
		a=BuscaVenda(venpro, tlvp, aux );
		if( a == -1)
		{
			gotoxy(13,23);
			printf("Venda n�o realizada!");	
			getch();
			LimparMensagem();
		}
		else
		{
			min=a;
			max=a+x;
			for(b=min ; b<max && op!='X' ;	)
			{
				auxcod=venpro[b].CodProd;
				i=BuscaCod(prod, tlp, auxcod);
				gotoxy(30,12);
				printf("%d ",venpro[b].CodProd);
				gotoxy(30,13);
				printf("Descri��o: %s",prod[i].Descr);
				gotoxy(30,14);
				printf("Quantidade Comprada: %d",venpro[b].Qtde);
				gotoxy(30,15);
				printf("Valor Total: %.2f",venpro[b].Qtde * venpro[b].ValorUni);
				
				if(b==min  && x > 1)		
				{
					gotoxy(30,17);
					printf("[P] Pr�xima Pagina");
						
				}
					
				if(b>min && b < max -1)
				{
					gotoxy(30,17);
					printf("[P]- Pr�xima Pagina");
					gotoxy(30,18);
					printf("[A]- P�gina Anterior");
				}
				
				if(b == max -1 && x > 1)
				{
					gotoxy(30,17);
					printf("[A]- P�gina Anterior");
				}
				
				gotoxy(30,19);
				printf("[X]-Voltar ao Menu");	
				
				op=toupper(getch()); 
					
				if(b != max -1 && op == 'P')
				{
					b++;
					LimparLinha(12);
					LimparLinha(13);
					LimparLinha(14);
					LimparLinha(15);
					LimparLinha(16);
					LimparLinha(17);
					LimparLinha(18);
					}	
		
				if(b > min && op =='A')
				{
					LimparLinha(12);
					LimparLinha(13);
					LimparLinha(14);
					LimparLinha(15);
					LimparLinha(16);
					LimparLinha(17);
					LimparLinha(18);
					b--;
					}	
					
						
			}
			gotoxy(30,16);
			printf("Valor Total da compra: %.2f",vendas[tlv].TotVendas);
		}
	}
	else
	{
		gotoxy(30,9);
		printf("C�digo De Venda: %d", vendas[tlv].CodVenda);
		gotoxy(30,10);
		printf("Produtos:");
		a=BuscaVenda(venpro, tlvp, aux );
		if( a == -1)
		{
			gotoxy(13,23);
			printf("Venda n�o realizada!");	
			getch();
			LimparMensagem();
		}
		else
		{
			min=a;
			max=a+x;
			for( b=min; b<max && op!= 'X' ; )
			{
				auxcod=venpro[b].CodProd;
				i=BuscaCod(prod, tlp, auxcod);
				gotoxy(30,11);
				printf("%d ",venpro[b].CodProd);
				gotoxy(30,12);
				printf("Descri��o: %s",prod[i].Descr);
				gotoxy(30,13);
				printf("Quantidade Comprada: %d",venpro[b].Qtde);
				gotoxy(30,14);
				printf("Valor Total: %.2f",venpro[b].Qtde * venpro[b].ValorUni);
				
				if(b==min  && x > 1)		
				{
					gotoxy(30,17);
					printf("[P] Pr�xima Pagina");
						
				}
					
				if(b>min && b < max -1)
				{
					gotoxy(30,17);
					printf("[P]- Pr�xima Pagina");
					gotoxy(30,18);
					printf("[A]- P�gina Anterior");
				}
				
				if(b == max -1 && x > 1)
				{
					gotoxy(30,17);
					printf("[A]- P�gina Anterior");
				}
				
				
				gotoxy(30,19);
				printf("[X]-Voltar ao Menu");	
				
				op=toupper(getch()); 
					
				if(b != max -1 && op == 'P')
				{
					b++;
					LimparLinha(12);
					LimparLinha(13);
					LimparLinha(14);
					LimparLinha(15);
					LimparLinha(16);
					LimparLinha(17);
					LimparLinha(18);
					}	
		
				if(b > min && op =='A')
				{
					LimparLinha(12);
					LimparLinha(13);
					LimparLinha(14);
					LimparLinha(15);
					LimparLinha(16);
					LimparLinha(17);
					LimparLinha(18);
					b--;
					}	
				
			}
			gotoxy(30,15);
			printf("%.2f",vendas[tlv].TotVendas);
		}
	}
	Limpar(28,7,79,21);

}

int BuscaVenda(TpVendasProduto venpro[TF], int tlvp, int aux)
{
	int pos;
	pos=0;
	while( pos < tlvp && aux != venpro[pos].CodVenda)
		pos++;
	if( pos < tlvp)
		return pos;
	else
		return -1;
}

void AumentaPreco(TpProdutos prod[TF], int tlp , TpFornecedores forn[TF] , int tlf)
{
	int auxcod,i;
	float aumento;
	gotoxy(40,6);
	printf("### AUMENTAR PRE�O ###");
	gotoxy(30,8);
	printf("Digite o c�digo do Fornecedor:");
	gotoxy(30,9);
	scanf("%d",&auxcod);
	i=BuscaForn(forn,tlf,auxcod);
	if(i == -1)
	{
		gotoxy(13,23);
		printf("Fornecedor n�o encontrado!");
		getch();
		LimparMensagem();
		Limpar(28,5,79,21);
	}
		
	else
	{
		gotoxy(30,10);
		printf("C�digo Fornecedor: %d",forn[i].CodForn);
		gotoxy(30,11);
		printf("Nome Fornecedor: %s",forn[i].NomeForn);
		gotoxy(30,12);
		printf("Cidade Fornecedor: %s",forn[i].Cidade);
		gotoxy(30,13);
		printf("Digite o aumento:");
		gotoxy(30,14);
		scanf("%f",&aumento);
		gotoxy(30,15);
		printf("Deseja concluir o aumento?[S/N]");
		if(toupper(getch())== 'S')
		{

			VarreduraFornPreco(prod,tlp,aumento,auxcod);
			gotoxy(13,23);
			printf("Aumento(s) concluido(s)!");
			getch();
			LimparMensagem();
		}
	}
	Limpar(28,5,79,21);
	
}

void VarreduraFornPreco(TpProdutos prod[TF], int tlp , float auxaum, int codforn)
{
	int i;
	float aumento;
	aumento= (auxaum / 100) + 1;
	
	for(i=0 ; i < tlp ; i++)
		if( codforn == prod[i].CodForn  )
			prod[i].Preco *= aumento;
}

void ExcluirProd(TpProdutos prod[TF], int &tlp,TpVendasProduto venpro[TF], int tlvp) 
{
	int auxcod,a,i;
	
	if(tlp == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Produto cadastrado!");
		getch();
		LimparMensagem();
	}
		
	else
	{
		gotoxy(40,6);
		printf("### EXCLUIR PRODUTO ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto que excluir�:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		while(auxcod > 0 && tlp >0)
		{
			i=BuscaCod(prod,tlp,auxcod);
			if( i == -1)
			{
				gotoxy(13,23);
				printf("Produto n�o encontrado!");
				getch();
				LimparMensagem();
				
			}
				
			else
			{
				a= BuscaProdEmVendaProd(prod,venpro,tlvp,auxcod);
				if(a != -1)
				{
					gotoxy(13,23);
					printf("Produto n�o pode ser excluido!");
					getch();
					LimparMensagem();	
				}
					
				else
				{
					gotoxy(30,10);
					printf("Deseja Concluir a exclus�o?[S/N]");
					if(toupper(getch())== 'S')
						VarreduraProd(prod,tlp,i);
				}
		
			}
			Limpar(28,7,79,21);
			gotoxy(30,8);
			printf("Digite o c�digo do produto excluir�:");
			gotoxy(30,9);
			scanf("%d",&auxcod);
			
		}
	}
	Limpar(28,5,79,21);
}

int BuscaProdEmVendaProd(TpProdutos prod[TF], TpVendasProduto venpro[TF], int tlvp, int aux) 
{
	int pos;
	pos=0;
	while( pos < tlvp && aux != venpro[pos].CodProd)
		pos++;

	if(pos < tlvp)
		return pos;
	else
		return -1;
}

void VarreduraProd(TpProdutos prod[TF], int &tlp, int pos)
{
	int i;

	for(i=pos ; i<tlp -1 ; i++)
	{
		prod[i]= prod[i+1];

	}
	tlp--;
	gotoxy(13,23);
	printf("Produto Exclu�do com sucesso!");
	getch();
	LimparMensagem();
	
}

void ExcluirForn(TpFornecedores forn[TF], int &tlf, TpProdutos prod[TF], int tlp, TpVendasProduto venpro[TF], int tlvp) 
{
	int auxcod,a,b,i;
	
	if(tlf == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Fornecedor Cadastrado!");
		getch();
		LimparMensagem();
	}
		
	else
	{
		gotoxy(40,6);
		printf("### EXCLUIR FORNECEDOR ###");
		gotoxy(30,8);
		printf("Digite o c�digo do fornecedor que excluir�:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		while(auxcod > 0 && tlf >0)
		{
			b= BuscaForn(forn,tlf,auxcod);
			if(b == -1)
			{
				gotoxy(13,23);
				printf("Fornecedor n�o encontrado!");
				getch();
				LimparMensagem();
				
			}
				
			else
			{
				a= BuscaFornEmProd(prod,forn, venpro,tlvp, tlp , tlf, auxcod);
				if(a == -1)
				{
					gotoxy(13,23);
					printf("Esse Fornecedor n�o pode ser exclu�do!");
					getch();
					LimparMensagem();			
				}
					
				else
				{
					gotoxy(30,10);
					printf("Codigo Fornecedor: %d",forn[b].CodForn);
					gotoxy(30,11);
					printf("Nome Fornecedor: %s",forn[b].NomeForn);
					gotoxy(30,12);
					printf("Cidade Fornecedor: %s",forn[b].Cidade);
					gotoxy(30,13);
					printf("Deseja confirmar a exclus�o? [S/N]");
					if(toupper(getch())=='S')
					{
						for(i=0 ; i<tlp ; i++)
							if(prod[i].CodForn == auxcod)
								VarreduraProd(prod,tlp,i); 
								 
						ExcluirFornecedor(forn,tlf,b);
						gotoxy(13,23);
						printf("Fornecedor Exclu�do!");	
						getch();
						LimparMensagem();
					}
					
				}
			}
			Limpar(28,7,79,21);
			gotoxy(30,8);
			printf("Digite o c�digo do fornecedor que excluir�:");
			gotoxy(30,9);
			scanf("%d",&auxcod);	
		}
	}
	Limpar(28,5,79,21);	

	
}

int BuscaFornEmProd(TpProdutos prod[TF], TpFornecedores forn[TF],TpVendasProduto venpro[TF],int tlvp, int tlp , int tlf, int aux) 
{
	int i,cont=0,a,auxcod;
	for(i=0 ; i<tlp ; i++)
		if(prod[i].CodForn == aux)
		{
			auxcod=prod[i].CodProd;
			a=BuscaProdEmVendaProd(prod,venpro, tlvp, auxcod);
			if(a != -1)
				cont++;
		}
	if (cont > 0)
		return -1;
	
	
	
	else	
	    return cont;                                         
	
	
}

void ExcluirFornecedor(TpFornecedores forn[TF], int &tlf, int pos) 
{
	int i;

	for(i=pos ; i<tlf -1 ; i++)
		forn[i]= forn[i+1];
	tlf--;
	
}

void ExclusaoCliente(TpClientes cli[TF], int &tlc)
{
	char auxCPF[17];
	int a;
	if(tlc == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Cliente cadastrado!");
		getch();
		LimparMensagem();
	}
		
	else
	{
		gotoxy(40,6);
		printf("### EXCLUIR CLIENTE ###");
		gotoxy(30,8);
		printf("Digite o CPF do cliente?");
		gotoxy(30,9);
		fflush(stdin);
		gets(auxCPF);
		while(strlen(auxCPF)>1 && tlc < TF)
		{
			a=BuscaCli(cli,tlc,auxCPF);
			if(a == -1)
			{
				gotoxy(13,23);
				printf("Cliente n�o encontrado!");
				getch();
				LimparMensagem();
			}
				
			else
				if(cli[a].QtdeCompras > 0)
				{
					gotoxy(13,23);
					printf("N�o � possivel excluir esse cliente!");	
					getch();
					LimparMensagem();
				}
				
				else
				{
					gotoxy(30,10);
					printf("Deseja concluir a exclus�o?[S/N]");
					if(toupper(getch()) == 'S')
					{
						gotoxy(13,23);
						printf("Cliente Exclu�do com sucesso!");
						ExcluiCliente(cli,tlc,a);
						getch();
						LimparMensagem();
					}
				}
					
			Limpar(28,7,79,21);
			gotoxy(30,8);
			printf("Digite o CPF do cliente?");
			gotoxy(30,9);
			fflush(stdin);
			gets(auxCPF);		
			
		}
	}
	Limpar(28,5,79,21);
}

void ExcluiCliente(TpClientes cli[TF], int &tlc, int pos)
{
	int i;

	for(i=pos ; i<tlc -1 ; i++)
		cli[i]= cli[i+1];
	tlc--;
}

void ConsultarProduto(TpProdutos prod[TF], int tlp)
{
	int auxcod,a;
	if(tlp == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Produto Cadastrado");
		getch();
		LimparMensagem();
	}
		
	else
	{
		gotoxy(40,6);
		printf("### CONSULTAR PRODUTO ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto que deseja:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		while(auxcod > 0 )
		{
			a=BuscaCod(prod, tlp, auxcod);
			if(a == -1)
			{
				gotoxy(13,23);
				printf("Produto nao encontrado!");
				getch();
				LimparMensagem();
			}
				
			else
			{
				gotoxy(29,10);
				printf(" Detalhes do Produto ");
				gotoxy(30,11);
                printf("C�digo: %d",prod[a].CodProd);
                gotoxy(30,12);
                printf("Descri��o: %s",prod[a].Descr);
                gotoxy(30,13);
                printf("Estoque: %d",prod[a].Estoque);
                gotoxy(30,14);
                printf("Pre�o: R$ %.2f",prod[a].Preco);
                gotoxy(30,15);
                printf("%d/",prod[a].DtValidade.Dia);
                gotoxy(33,15);
                printf("%d/", prod[a].DtValidade.Mes);
                gotoxy(35,15);
                printf("%d",prod[a].DtValidade.Ano);
                gotoxy(30,16);
                printf("C�digo Fornecedor: %d",prod[a].CodForn);
                getch();
         	}
               
			Limpar(28,7,79,21);
			gotoxy(30,8);
			printf("Digite o c�digo do produto que deseja:");
			gotoxy(30,9);
			scanf("%d",&auxcod);
		}
		
	}
	Limpar(28,5,79,21);
}


void ConsultarFornecedor(TpFornecedores forn[TF], int tlf)
{
	
	int auxcod,a;
	if(tlf == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Fornecedor Cadastrado!");
		getch();
		LimparMensagem();
	}
		
	else
	{
		gotoxy(40,6);
		printf("### CONSULTAR FORNECEDOR ###");
		gotoxy(30,8);
		printf("Digite o c�digo do fornecedor:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		while(auxcod > 0 )
		{
			a=BuscaForn(forn, tlf, auxcod);
			if(a == -1)
			{
				gotoxy(13,23);
				printf("Fornecedor n�o encontrado!");
				getch();
				LimparMensagem();
			}
			
			else
			{
				gotoxy(30,10);
				printf("Detalhes do Fornecedor:");
				gotoxy(30,11);
                printf("C�digo do Fornecedor: %d",forn[a].CodForn);
                gotoxy(30,12);
                printf("Nome: %s",forn[a].NomeForn);
                gotoxy(30,13);
                printf("Cidade: %s",forn[a].Cidade);
                getch();
			}
				
                
			Limpar(28,7,79,21);
			gotoxy(30,8);  
			printf("Digite o c�digo do Fornecedor:");
			gotoxy(30,9);
			scanf("%d",&auxcod);
		}
		
	}
	Limpar(28,5,79,21);
}


void ConsultarCliente(TpClientes cli[TF], int tlc)
{

	int a;
	char auxcpf[17];
	if(tlc == 0)
	{
		gotoxy(13,23);
		printf("Nenhum Cliente Cadastrado!");
		getch();
		LimparMensagem();
	}
	
	else
	{
		gotoxy(40,6);
		printf("### Consultar Cliente ###");
		gotoxy(30,8);
		printf("Digite o CPF do cliente:");
		gotoxy(30,9);
		fflush(stdin);
		gets(auxcpf);
		
		while(strlen(auxcpf) > 1 )
		{
			a=BuscaCli(cli, tlc, auxcpf);
			if(a == -1)
			{
				gotoxy(13,23);
				printf("Cliente n�o encontrado!");
				getch();
				LimparMensagem();
			}
				
			else
			{
				gotoxy(30,10);
				printf("Detalhes do Cliente:");
				gotoxy(30,11);
				printf("CPF: %s",cli[a].CPFCli);
				gotoxy(30,12);
				printf("Nome: %s",cli[a].NomeCli);
				gotoxy(30,13);
                printf("Quantidade de compras: %d",cli[a].QtdeCompras);
                gotoxy(30,14);
                printf("Total comprado: %.2f",cli[a].ValorTotComprado);
              	getch();
			}
				
			Limpar(28,7,79,21);
			gotoxy(30,8) ;
			printf("Digite o CPF do cliente:");
			gotoxy(30,9);
			fflush(stdin);
			gets(auxcpf);
		}
		
	}
	Limpar(28,5,79,21);	
}


void RelatorioProdutos(TpProdutos prod[TF], int tlp,TpFornecedores forn[TF], int tlf)
{
	int i=0,auxforn,a;
	char op;
	if(tlp == 0)
	{
		gotoxy(13,23);
		printf("Nao h� produtos cadastrados!");
		getch();
		LimparMensagem();
	}
	while(i<tlp && op!= 'X')
	{
		gotoxy(40,6);
		printf("### RELATORIO PRODUTOS ###");
		gotoxy(30,7);
		printf("Detalhes do Produto:");
		gotoxy(30,8);
        printf("C�digo: %d",prod[i].CodProd);
        gotoxy(30,9);
        printf("Descri��o: %s",prod[i].Descr);
        gotoxy(30,10);
        printf("Estoque: %d",prod[i].Estoque);
        gotoxy(30,11);
        printf("Pre�o: R$ %.2f",prod[i].Preco);
        gotoxy(30,12);
        printf("Data de Validade: %d/",prod[i].DtValidade.Dia);
        gotoxy(51,12);
        printf("%d/",prod[i].DtValidade.Mes);
        gotoxy(53,12);
        printf("%d",prod[i].DtValidade.Ano);
        gotoxy(30,13);
        printf("C�digo Fornecedor: %d",prod[i].CodForn);
        auxforn=prod[i].CodForn;
        a=BuscaForn(forn,tlf,auxforn);
        	if(a != -1)
        	{
        		gotoxy(30,14);
        		printf("Nome Forn: %s",forn[a].NomeForn);
			}
        	
				        	
        if(i==0  && tlp > 1)
		{
			gotoxy(30,16);
			printf("[P] Pr�xima Pagina");
		}		
			
		if(i>0 && i < tlp -1)
		{
			gotoxy(30,16);
			printf("[P]- Pr�xima Pagina");
			gotoxy(30,17);
			printf("[A]- P�gina Anterior");
		}
		
		if(i == tlp -1)
		{
			gotoxy(30,16);
			printf("[A]- P�gina Anterior");
		}
		
		
		gotoxy(30,18);	
		printf("[X]-Voltar ao Menu");	
		
		op=toupper(getch()); 
			
		if(i != tlp -1 && op == 'P')
		{
			i++;
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);
			LimparLinha(14);
			LimparLinha(15);
			LimparLinha(16);
			LimparLinha(17);
		}	
		
        
		if(i > 0 && op =='A')
		{
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);
			LimparLinha(14);
			LimparLinha(15);
			LimparLinha(16);
			LimparLinha(17);
			
			i--;
		}	
	}
	Limpar(28,5,79,21);
}

void RelatorioFornecedores(TpFornecedores forn[TF], int tlf)
{
	
	int i=0;
	char op;
	
	if(tlf == 0)
	{
		gotoxy(13,23);
		printf("N�o h� fornecedores cadastrados!");
		getch();
		LimparMensagem();
	}
	while(i<tlf && op != 'X')
	{
		gotoxy(40,6);
		printf("### RELATORIO FORNECEDORES ###");
		gotoxy(30,8);
		printf("Detalhes do Fornecedor:");
		gotoxy(30,8);
        printf("C�digo do Fornecedor: %d",forn[i].CodForn);
        gotoxy(30,9);
        printf("Nome: %s",forn[i].NomeForn);
        gotoxy(30,10);
        printf("Cidade: %s",forn[i].Cidade);
        
        if(i==0)	
		{
			gotoxy(30,12);
			printf("[P] Proxima Pagina");
		}	
			
		if(i>0 && i < tlf -1)
		{
			gotoxy(30,12);
			printf("[P]- Pr�xima Pagina");
			gotoxy(30,13);
			printf("[A]- P�gina Anterior");
		}
		
		if(i == tlf -1)
		{
			gotoxy(30,12);
			printf("[A]- P�gina Anterior");
		}
			
		
		gotoxy(30,15);
		printf("[X]-Voltar ao Menu");
			
		op=toupper(getch()); 
			
		if(i != tlf -1 && op == 'P')
		{
			i++;
			LimparLinha(8);
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);	
		}	
		
        
		if(i > 0 && op =='A')
		{
			i--;
			LimparLinha(8);
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);
				
		}	
	}
	Limpar(28,5,79,21);
}


void RelatorioClientes(TpClientes cli[TF], int tlc)
{
	
	int i=0;
	char op;
	if(tlc == 0)
	{
		gotoxy(13,23);
		printf("N�o h� clientes cadastrados!");
		getch();
		LimparMensagem();
		
	}
	while(i<tlc && op!= 'X')
	{
		gotoxy(40,6);
		printf("### RELATORIO CLIENTES ###");
		gotoxy(30,8);
		printf(" Detalhes do Cliente ");
		gotoxy(30,9);
		printf("CPF: %s",cli[i].CPFCli);
		gotoxy(30,10);
		printf("Nome: %s",cli[i].NomeCli);
		gotoxy(30,11);
        printf("Quantidade de compras: %d",cli[i].QtdeCompras);
        gotoxy(30,12);
        printf("Total comprado: %.2f",cli[i].ValorTotComprado);
              
        if(i==0)		
        {
        	gotoxy(30,14);
			printf("[P] Pr�xima Pagina");	
		}
			
		if(i>0 && i < tlc -1)
		{
			gotoxy(30,14);
			printf("[P]- Pr�xima Pagina");
			gotoxy(30,15);
			printf("[A]- P�gina Anterior");
		}
	 
		if(i == tlc -1)
		{
			gotoxy(30,14);
			printf("[A]- P�gina Anterior");
		}
			
		
		gotoxy(30,17);
		printf("[X]-Voltar ao Menu");
		
		op=toupper(getch()); 
			
		if(i != tlc -1 && op == 'P')
		{
			i++;
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);
			LimparLinha(14);
			LimparLinha(15);
		}	
		
        
		if(i > 0 && op =='A')
		{
			i--;
			LimparLinha(9);
			LimparLinha(10);
			LimparLinha(11);
			LimparLinha(12);
			LimparLinha(13);
			LimparLinha(14);
			LimparLinha(15);
		}	
		
        	
	}
	Limpar(28,5,79,21);
}


void RelatorioVendas(TpVendas vendas[TF], int tlv, TpVendasProduto venpro[TF], int tlvp, TpFornecedores forn[TF], int tlf, TpProdutos prod[TF], int tlp) //ARRUMAR
{
	
	
	int i=0,a,b,c,auxforn,auxcod,aux,j,auxqntd,min,max;
	char op;
	if(tlv == 0)
	{
		gotoxy(13,23);
		printf("Nenhuma venda realizada!");
		getch();
		LimparMensagem();
	}
	else
	{
	
		while( i < tlv && op!='X')
		{
			gotoxy(40,6);
			printf("### RELAT�RIO DE VENDAS ###");
			gotoxy(30,8);
			printf("C�digo de Venda: %d",vendas[i].CodVenda);
			gotoxy(30,9);
			printf("Produtos:");
			aux=vendas[i].CodVenda;
			
			auxqntd= contagemVendas(venpro, tlvp,  aux);
			j=BuscaVenda(venpro, tlvp, aux);
			
			min=j;
		
			max=j+auxqntd;
			
	        for(a=j; a <  max && op!= 'X'; )
	        
	        	{
	        		gotoxy(30,10);
	        		printf("C�digo: %d",venpro[a].CodProd);
	        		auxcod=venpro[a].CodProd;
	        		
					b=BuscaCod(prod, tlp, auxcod);
	        		if(b!= -1)
	        		{
	        			gotoxy(30,11);
						printf("Descri��o: %s",prod[b].Descr);	
					}	
	        		gotoxy(30,12);
	       			printf("Quantidade: %d",venpro[a].Qtde);
	       			gotoxy(30,13);
	       			printf("Valor Comprado: R$ %.2f",venpro[a].Qtde*venpro[a].ValorUni);
	       			auxforn = prod[b].CodForn;
	       			
					c=BuscaForn(forn,tlf,auxforn);
	       			if(c!= -1)
	       			{
	       				gotoxy(30,14);
	       				printf("Nome Fornecedor: %s",forn[c].NomeForn);
					   }
					   
					gotoxy(30,16);      	
					printf("Total da Venda: %.2f",vendas[i].TotVendas);   
	       		
					if(a==min  && auxqntd > 1)		
					{
						gotoxy(30,17);
						printf("[P] Pr�xima Pagina");
							
					}
						
					if(a>min && a < max -1)
					{
						gotoxy(30,17);
						printf("[P]- Pr�xima Pagina");
						gotoxy(30,18);
						printf("[A]- P�gina Anterior");
					}
					
					if(a == max -1 && auxqntd > 1)
					{
						gotoxy(30,17);
						printf("[A]- P�gina Anterior");
					}
					
					LimparLinha(19);
					gotoxy(30,19);
					printf("[X]-Alterar venda");	
					
					op=toupper(getch()); 
						
					if(a != max -1 && op == 'P')
					{
						a++;
						LimparLinha(10);
						LimparLinha(11);
						LimparLinha(12);
						LimparLinha(13);
						LimparLinha(14);
						LimparLinha(15);
						LimparLinha(16);
						LimparLinha(17);
						LimparLinha(18);
						LimparLinha(19);
					}	
				
		        
					if(a > min && op =='A')
					{
						a--;
						LimparLinha(9);
						LimparLinha(10);
						LimparLinha(11);
						LimparLinha(12);
						LimparLinha(13);
						LimparLinha(14);
						LimparLinha(15);
						LimparLinha(16);
						LimparLinha(17);
						LimparLinha(18);
						LimparLinha(19);		
					}
				   
				   		
				}
	        //gotoxy(30,16);      	
//			printf("%.2f",vendas[i].TotVendas);
				
				LimparLinha(9);
				LimparLinha(10);
				LimparLinha(11);
				LimparLinha(12);
				LimparLinha(13);
				LimparLinha(14);
				LimparLinha(15);
				LimparLinha(16);
				LimparLinha(17);
				LimparLinha(18);
				LimparLinha(19);

	       	if(i==0)	
			   {
			   		LimparLinha(17);
					gotoxy(30,17);
				   	printf("[P] Pr�xima venda");
			   }	
			
			if(i>0 && i < tlv -1)
			{
				LimparLinha(17);
				gotoxy(30,17);
				printf("[P]- Pr�xima venda");
				LimparLinha(18);
				gotoxy(30,18);
				printf("[A]- Venda Anterior");
			}
		 
			if(i == tlv -1)
			{
				LimparLinha(18);
				gotoxy(30,18);
				printf("[A]- Venda Anterior  ");
			}
				
			LimparLinha(19);
			gotoxy(30,19);
			printf("[X]-Voltar ao menu");
			
			op=toupper(getch()); 
				
			if(i != tlv -1 && op == 'P')
			{
					i++;
				LimparLinha(10);
				LimparLinha(11);
				LimparLinha(12);
				LimparLinha(13);
				LimparLinha(14);
				LimparLinha(15);
				LimparLinha(16);
				LimparLinha(17);
				LimparLinha(18);
				LimparLinha(19);
				LimparLinha(20);
			}	
			
	        
			if(i > 0 && op =='A')
			{
				i--;
				LimparLinha(10);
				LimparLinha(11);
				LimparLinha(12);
				LimparLinha(13);
				LimparLinha(14);
				LimparLinha(15);
				LimparLinha(16);
				LimparLinha(17);
				LimparLinha(18);
				LimparLinha(19);
				LimparLinha(20);		
			}
		}
	}
	Limpar(28,5,79,21);
}

void ExcluirVenda(TpVendas vendas[TF], int &tlv , TpVendasProduto venpro[TF], int &tlvp , TpClientes cli[TF], int tlc)
{
    int auxcod,a,b,c,i;
    char auxCPF[17];
	
	if(tlv == 0)
	{
		gotoxy(13,23);
		printf("Nenhuma Venda Realizada!");
		getch();
		LimparMensagem();
		
	}
	else
	{	
		gotoxy(40,6);
		printf("### EXCLUIR VENDAS ###");
		gotoxy(30,8);
	    printf("Digite o C�digo da Venda que deseja excluir:");
	    gotoxy(30,9);
		scanf("%d",&auxcod);
	    while(auxcod > 0 && tlv > 0)
	    {
	        a=BuscaVenda(venpro,tlvp,auxcod);
			b=BuscaVendaExcluir(vendas,tlv,auxcod);
			
	        if(b == -1)
	        {
	        	gotoxy(13,23);
	        	printf("Venda n�o encontrada!");
	        	getch();
	        	LimparMensagem();
			}
	            
	        else
	        {
	        	gotoxy(30,10);
	            printf("C�digo Venda:%d",vendas[b].CodVenda);
	            gotoxy(30,11);
	            printf("CPF:%s",vendas[b].CPFCli);
	            gotoxy(30,12);
	            printf("Data Venda: %d/",vendas[b].DtVendas.Dia );
	            gotoxy(46,12);
	            printf("%d/",vendas[b].DtVendas.Mes);
	            gotoxy(49,12);
	            printf("%d",vendas[b].DtVendas.Ano);
	            
	            gotoxy(30,13);
	            printf("TotVenda:%.2f",vendas[b].TotVendas);
	            
				gotoxy(30,14);
	            printf("Confirma a exclus�o? [S/N]");
	            if(toupper(getch()) == 'S')
	            {
					strcpy(auxCPF,vendas[b].CPFCli);
	            	c=BuscaCli(cli,tlc,auxCPF);	
	            	cli[c].ValorTotComprado -= vendas[b].TotVendas;
	            	cli[c].QtdeCompras--;	
					VarreduraVendaProd(venpro,tlvp,auxcod,a);
					VarreduraVendas(vendas,tlv,b);
					
					
					for(i=a ; i<tlvp;i++)
						venpro[i].CodVenda -=1;
					
					for(i=b ; i<tlv;i++)
						vendas[i].CodVenda -=1;
						
					gotoxy(13,23);
					printf("Venda Exclu�da Com Sucesso!");
					getch();
					LimparMensagem();
				  }   
	
	        }

	       	Limpar(28,7,79,21);
			gotoxy(30,8);
	        printf("Digite o C�digo da Venda que deseja excluir:");
	        gotoxy(30,9);
	        scanf("%d",&auxcod);
	    }
	}
	Limpar(28,5,79,21);
}

void VarreduraVendaProd (TpVendasProduto venpro[TF], int &tlvp , int auxcod, int pos)
{
	
	int i,a;

	for(i=pos ; i < tlvp - 1; i++)
		if(venpro[i].CodVenda == auxcod)
		{
			
			for(a= i; a < tlvp -1 ; a++)
				venpro[a]=venpro[a+1];
			tlvp--;
			i--;
		}	
		
}

void VarreduraVendas(TpVendas vendas[TF], int &tlv , int pos)
{
	int i;

	for(i=pos ; i<tlv-1; i++)
		vendas[i]=vendas[i+1];
	
	vendas[tlv-1].TotVendas	= 0;
		
	tlv--;
	
}

int BuscaVendaExcluir(TpVendas vendas[TF] , int tlv , int aux)
{
	int pos;
	pos=0;
	while( pos < tlv && aux != vendas[pos].CodVenda)
		pos++;
	if( pos < tlv)
		return pos;
	else
		return -1;
}


void AlterarProd(TpProdutos Produtos[TF],int TLP)
{
	int auxcod;
	char op;
	
	do
	{
		op=MenuAlterarProd();
		switch(op)
		{
			case'A':
				AlterarDescrProd(Produtos, TLP);
				break;
			
			case'B':
				AlterarEstoqueProd(Produtos,TLP);
				break;
			
			case'C':
				AlterarPrecoProd(Produtos,TLP);
				break;
				
			case'D':
				AlterarDataProd(Produtos,TLP);
				break;
		}
		
	}while(op != 27);
	
}

char MenuAlterarProd(void)
{
	Limpar(2,5,27,22);
	gotoxy(6,7);
	printf("### MENU ALTERAR ###");
	gotoxy(3,9);
	printf("[A]- Alterar Descri��o");
	gotoxy(3,11);
	printf("[B]- Alterar Estoque");
	gotoxy(3,13);
	printf("[C]- Alterar Pre�o");
	gotoxy(3,15);
	printf("[D]- Alterar Validade");
	gotoxy(3,17);
	printf("[ESC]- Sair");
	
	return toupper(getch());
}

void AlterarDescrProd(TpProdutos Produtos[TF], int tlp)
{
	char auxdescr[30];
	int auxcod,a;

	do
	{
		Limpar(28,5,79,21);	
		gotoxy(40,6);
		printf("### Alterar Descri��o ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaCod(Produtos,tlp,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto n�o encontrado!");
			getch();
			LimparMensagem();
			}	
		else
		{
			gotoxy(30,10);
			printf("Digite a nova Descri��o:");
			gotoxy(30,11);
			fflush(stdin);
			gets(auxdescr);
			gotoxy(30,12);
			printf("Deseja concluir a Alteracao? [S/N]");
			if(toupper(getch()) == 'S')
			{
				strcpy(Produtos[a].Descr,auxdescr);
				gotoxy(13,23);
				printf("Altera��o Conclu�da!");
				getch();
				LimparMensagem();
			}
			
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);	
}


void AlterarEstoqueProd(TpProdutos Produtos[TF], int tlp)
{
	
	int auxcod,a,auxest;

	do
	{
		Limpar(28,5,79,21);	
		gotoxy(40,6);
		printf("### ALTERAR ESTOQUE ###");
		gotoxy(30,8);
		printf("Digite o cod do produto:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaCod(Produtos,tlp,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto nao encontrado!");
			getch();
			LimparMensagem();
		}
			
		else
		{
			gotoxy(30,10);
			printf("Digite o novo estoque:");
			gotoxy(30,11);
			scanf("%d",&auxest);
			if(auxest > 0)
			{
				gotoxy(30,12);
				printf("Deseja concluir a Altera��o?[S/N]");
				if(toupper(getch()) == 'S')
				{
					Produtos[a].Estoque = auxest;
					gotoxy(13,23);
					printf("Alteracao Conclu�da!");
					getch();
					LimparMensagem();
				}
			}
			else
			{
				gotoxy(13,23);
				printf("Quantidade Inv�lida!");
				getch();
				LimparMensagem();
			}
				
			
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);	
}

void AlterarPrecoProd(TpProdutos Produtos[TF], int tlp)
{
	float auxpre;
	int auxcod,a;

	do
	{
		Limpar(28,5,79,21);	
		gotoxy(40,6);
		printf("### ALTERAR PRE�O ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaCod(Produtos,tlp,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto n�o encontrado!");
			getch();
			LimparMensagem();
		}
			
		else
		{
			gotoxy(30,10);
			printf("Digite o novo pre�o:");
			gotoxy(30,11);
			scanf("%f",&auxpre);
			if(auxpre > 000)
			{
				gotoxy(30,12);
				printf("Deseja concluir a Altera��o?[S/N]");
				if(toupper(getch()) == 'S')
				{
					Produtos[a].Preco = auxpre;
					gotoxy(13,23);
					printf("Altera��o Conclu�da!");
					getch();
					LimparMensagem();
					
				}
			}
			else
			{
				gotoxy(13,23);
				printf("Quantidade Inv�lida!");
				getch();
				LimparMensagem();
			}	
			
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);
}

void AlterarDataProd(TpProdutos Produtos[TF], int tlp)
{
	
	int auxcod,a,auxest,auxd,auxm,auxa,b;

	do
	{
		Limpar(28,5,79,21);
		gotoxy(40,6);
		printf("### ALTERAR DATA ###");
		gotoxy(30,8);
		printf("Digite o c�digo do produto:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaCod(Produtos,tlp,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto n�o encontrado!");
			getch();
			LimparMensagem();
			}	
		else
		{
			gotoxy(30,10);
			printf("Digite a data da venda:");
			gotoxy(30,11);
			scanf("%d %d %d",&auxd, &auxm, &auxa);
			b=VerificaData(auxd,auxm,auxa);
			
			while(b == -1) // se errar a data continua, para nn perder a venda
			{	
				LimparLinha(11);
				gotoxy(30,11);
				scanf("%d %d %d",&auxd, &auxm, &auxa);
				b=VerificaData(auxd,auxm,auxa);
			}
			
			if(b != -1)
			{
				gotoxy(30,12);
				printf("Deseja concluir a Altera��o?[S/N]");
				if(toupper(getch()) == 'S')
				{
					Produtos[a].DtValidade.Dia = auxd;
					Produtos[a].DtValidade.Mes = auxm;
					Produtos[a].DtValidade.Ano = auxa;
					gotoxy(13,23);
					printf("Altera��o Conclu�da!");
					getch();
					LimparMensagem();
				}	
			}
				
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);
}

void AlterarFornecedor(TpFornecedores Forn[TF],int tlf)
{
	int auxcod;
	char op;
	
	do
	{
		op=MenuAlterarForn();
		switch(op)
		{
			case'A':
				AlterarNomeForn(Forn, tlf);
				break;
			
			case'B':
				AlterarCidadeForn(Forn,tlf);
				break;
			
		
		}
		
	}while(op != 27);
	
}

char MenuAlterarForn(void)
{
	Limpar( 2,5,27,22 );
	gotoxy(6,7);
	printf("### MENU ALTERAR ###");
	gotoxy(3,9);
	printf("[A]- Alterar Nome");
	gotoxy(3,11);
	printf("[B]- Alterar Cidade");
	gotoxy(3,17);
	printf("[ESC]- Sair");
	
	return toupper(getch());
}

void AlterarNomeForn(TpFornecedores Forn[TF], int tlf)
{
	char auxnome[30];
	int auxcod,a;

	do
	{
		Limpar(28,5,79,21);
		gotoxy(40,6);
		printf("### ALTERAR C�DIGO ###");
		gotoxy(30,8);
		printf("Digite o c�digo do fornecedor:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaForn(Forn,tlf,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto n�o encontrado!");
			getch();
			LimparMensagem();
		}
			
		else
		{
			gotoxy(30,10);
			printf("Digite o Nome do Fornecedor:");
			gotoxy(30,11);
			fflush(stdin);
			gets(auxnome);
			gotoxy(30,12);
			printf("Deseja concluir a Altera��o?[S/N]");
			if(toupper(getch()) == 'S')
			{
				strcpy(Forn[a].NomeForn,auxnome);
				gotoxy(13,23);
				printf("Altera��o Conclu�da!");
				getch();
				LimparMensagem();
			}
			
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);
}

void AlterarCidadeForn(TpFornecedores Forn [TF], int tlf)
{
	char auxcid[30];
	int auxcod,a;

	do
	{
		Limpar(28,5,79,21);
		gotoxy(40,6);
		printf("### ALTERAR NOME ###");
		gotoxy(30,8);
		printf("Digite o c�digo do fornecedor:");
		gotoxy(30,9);
		scanf("%d",&auxcod);
		a=BuscaForn(Forn,tlf,auxcod);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Produto n�o encontrado!");
			getch();
			LimparMensagem();
		}
			
		else
		{
			gotoxy(30,10);
			printf("Digite a cidade do Fornecedor:");
			gotoxy(30,11);
			fflush(stdin);
			gets(auxcid);
			gotoxy(30,12);
			printf("Deseja concluir a Altera��o?[S/N]");
			if(toupper(getch()) == 'S')
			{
				strcpy(Forn[a].Cidade,auxcid);
				gotoxy(13,23);
				printf("Altera��o Conclu�da!");
				getch();
				LimparMensagem();
			}
			
		}		
	}while(auxcod > 0 );
	Limpar(28,5,79,21);
}


void AlterarCliente(TpClientes cli[TF], int tlc)
{
	int auxcod,a;
	char auxCPF[17],auxnome[30];
	
	do
	{
		Limpar(28,5,79,21);
		gotoxy(40,6);
		printf("### ALTERAR CPF ###");
		gotoxy(30,8);
		printf("Digite o CPF do Cliente");
		gotoxy(30,9);
		fflush(stdin);
		gets(auxCPF);
		a=BuscaCli(cli,tlc, auxCPF);
		if(a == -1)
		{
			gotoxy(13,23);
			printf("Cliente n�o encontrado!");
			getch();
			LimparMensagem();
		}
		
		else
		{
			gotoxy(30,10);
			printf("Digite o novo nome do cliente:");
			gotoxy(30,11);
			fflush(stdin);
			gets(auxnome);
			gotoxy(30,12);
			printf("Deseja Concluir a Altera��o?[S/N]");
			if(toupper(getch()) == 'S')
			{
				strcpy(cli[a].NomeCli,auxnome);
				gotoxy(13,23);
				printf("Altera��o Conclu�da!");
				getch();
				LimparMensagem();
			}
		}
		
	}while(strlen(auxCPF)>1);
	Limpar(28,5,79,21);
}

int verificaCPF(char CPF[17]){
	
	int i,j, h = 0, num[11],m,verifica;
	
	char aux[17], aux2;
	
	strcpy(aux,CPF);
	
	
	for(i = 0; i < 15 - h; i++)
	{
		if(aux[i] == '.' || aux[i] == '-')
		{
			for(j = i; j < 15 - h; j++ )
				aux[j] = aux[j+1];
			
			h++;
		}
	}
	


	for(i = strlen(aux)-1, j = 0; i>=0 ; i--, j++)
	{
		num[i] = (aux[i] - 48);
	}
	
	
	
	int soma = 0;
	for(i = 0,m = 10; i < 9; i++,m--)
		soma+= num[i] * m;
	
	
	verifica = 11 - (soma % 11);
	if(verifica == 10 || verifica == 11)
		verifica = 0;
		
	if(verifica == num[9])
	{
		soma = 0;
		for(i = 0,m = 11; i < 10; i++,m--)
			soma+= num[i] * m;
		
		verifica = 11 -(soma % 11);
		if(verifica == 10 || verifica == 11)
		verifica = 0;
		
		if(verifica == num[10])
			return 1;
		else
			return -1;	
	}
	else
		return -1;
	
	
}

int contagemVendas(TpVendasProduto venpro[TF], int tlvp, int aux)
{

    int pos, cont;
    pos=0;
    cont = 0;
    while( pos < tlvp)
    {
        if(aux == venpro[pos].CodVenda)
            cont++;

        pos++;
    }

    return cont;
}


//BSI - 2� Termo
// Caio Henrique Aranda Sumida
// Jo�o Vitor Santos Martins
