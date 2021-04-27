/* Nome: Gustavo Caldas Silveira Borges; Matr�cula: UC21100557; Curso: Engenharia de Software 1� Semestre, 2021;

Um cinema de Bras�lia est� interessado em descobrir o perfil das pessoas que frequentam suas sess�es de filmes 
e para isso, necessita realizar algumas verifica��es nas informa��es prestadas. Devem ser solicitados a quantidade
de sess�es que ser�o realizadas, o nome do filme, a quantidade de pessoas que assistiram o filme, assim como o sexo e a idade.

Cap�tulo 2: C�digo Limpo, p�g 18: 
"o nome de uma vari�vel, fun��o ou classe deve responder a todas as grandes quest�es. Ele deve lhe dizer porque
existe, o que faz e como � usado. Se um nome requer um coment�rio ent�o ele n�o revela seu prop�sito." */

#include<stdio.h> //biblioteca printf e scanf
#include<string.h> //biblioteca para strlen e strcmp
#include<ctype.h> //biblioteca para o uso do toupper e tolower
#include<locale.h> //biblioteca para o uso de acentos
#include<stdlib.h> //biblioteca para system

int main(){    //estrutura padr�o para o come�o do c�digo
    setlocale(LC_ALL, "Portuguese"); //definindo a lingua Portuguesa para acentos <locale.h>

//declarando as vari�veis
    int sessoes, quantiaPessoas[2]={0,0}, idade[2]={0,0}, crianca[2]={0,0}, adolescente[2]={0,0}, adulto[2]={0,0}, idoso[2]={0,0}, homem[2]={0,0}, mulher[2]={0,0},
	maiorIdadeHomem[2]={0,0}, maiorIdadeMulher[2]={0,0};
	char nomeFilme[2][75], sexo;
	
	printf("------ BEM-VINDO A CENTRAL DE PERFILAMENTO DE CLIENTES DO CINEPOP - BRAS�LIA ------\n\n");
	do { //quantia de sess�es, sendo validado para aceitar exatamente 2 sess�es
		printf("Informe a quantidade de sess�es a serem analisadas [2]: "); //solicitando a quantia de sess�es
		scanf("%d", &sessoes); //recebendo a quantia de sess�es
		fflush(stdin); //limpando o buffer 
		if (sessoes != 2) //validando a quantia de sess�es [2]
		    printf("Quantia inv�lida, n�mero de sess�es deve ser 2\n"); //se for diferente de 2 apresenta a invalidez
	}while (sessoes != 2); //repeti��o quando houver invalidez
	system("cls"); //limpando o prompt de comando
	
	for (int x = 0; x < 2; x++){ //for para repetir o perfilamento 2x [2 sess�es]
		printf("------ PERFILAMENTO DE CLIENTES DO CINEPOP POR SESS�O - BRAS�LIA ------\n\n");
	
	do { //nome do filme, sendo validado para n�o aceitar o nome 'vazio' (null)
		printf("Informe o nome do filme da sess�o %d: ", x+1); //solicitando o nome do filme
		fgets(nomeFilme[x], 75, stdin); //recebendo a string (nome do Filme)
		fflush(stdin); //limpando o buffer
		if (strlen(nomeFilme[x]) <= 1) //validando se o nome n�o � null
		    printf("Nome vazio! informe um nome\n"); //se for vazio apresenta a invalidez
	}while (strlen(nomeFilme[x]) <= 1); //repeti��o quando houver invalidez
	
	do { //quantia de pessoas, sendo validado para no m�nimo 10 pessoas
		printf("Informe a quantia de pessoas na sess�o %d: ", x+1); //solicitando a quantia de pessoas
		scanf("%d", &quantiaPessoas[x]); //recebendo a quantia de pessoas
		fflush(stdin); //limpando o buffer
		if (quantiaPessoas[x] < 10) //validando a quantia m�nima [10]
		    printf("Quantia inv�lida, n�mero m�nimo permitido: 10\n"); //se for menor que 10 apresenta a invalidez
	}while (quantiaPessoas[x] < 10); //repeti��o quando houver invalidez
	
	for(int i = 0; i < quantiaPessoas[x]; i++){ //coleta de dados(sexo e idade) de acordo com a quantia de pessoas escolhidas
		do { //idade das pessoas, sendo validado para uma idade entre 3 e 100 anos
		    printf("Informe a idade da pessoa %d: ", i+1); //solicitando a idade da pessoa x
		    scanf("%d", &idade[x]); //recebendo a idade da pessoa x
		    fflush(stdin); //limpando o buffer
		    if (idade[x] < 3 || idade[x] > 100) //validando a quantia m�nima [3] e m�xima [100]
		        printf("Insira uma idade entre 3 a 100 anos\n"); //se for menor que 3 ou maior que 100 apresenta a invalidez
		}while (idade[x] < 3 || idade[x] > 100); //repeti��o enquanto houver invalidez
		
		do { //sexo das pessoas, sendo validado para M ou F
			printf("Informe o sexo da pessoa %d [M|F]: ", i+1); //solicitando o sexo da pessoa x
			scanf("%c", &sexo); //recebendo o sexo da pessoa x
			fflush(stdin); //limpando o buffer
			sexo = toupper(sexo); //colocando a vari�vel sexo em caixa alta, facilitando o if
			if (sexo != 'M' && sexo != 'F') //validando o sexo [M|F]
			    printf("Sexo inv�lido! Digite novamente.\n"); //se n�o for [M|F] apresenta a invalidez
		}while (sexo != 'M' && sexo != 'F'); //repeti��o enquanto houver invalidez
         
        if (idade[x]>=3 && idade[x]<=13) //aumentar a quantia de crian�as [3 � 13 anos]
            crianca[x]+=1; 
        else if (idade[x]>=14 && idade[x]<=17) //aumentar a quantia de adolescentes [14 � 17 anos]
            adolescente[x]+=1;
        else if (idade[x]>=18 && idade[x]<=64) //aumentar a quantia de adultos [18 � 64 anos]
            adulto[x]+=1;
        else if (idade[x]>=65 && idade[x]<=100) //aumentar a quantia de idosos [65 � 100 anos]
            idoso[x]+=1;
            
        if (idade[x]>=18 && sexo=='M') //aumentar a quantia de homens maiores de idade [18+]
            maiorIdadeHomem[x]+=1;
        if (idade[x]>=18 && sexo=='F') //aumentar a quantia de mulheres maiores de idade [18+]
            maiorIdadeMulher[x]+=1;
            
        if (sexo == 'F') //aumentar a quantia de mulheres [sexo = F]
            mulher[x]+=1;
        if (sexo == 'M') //aumentar a quantia de homens [sexo = M]
            homem[x]+=1;
		
	}
	
	system("cls"); //limpando o prompt de comando
	printf("-------- DADOS DA SESS�O %d --------\n\n", x+1); 
	printf("\tFilme: %s", nomeFilme[x]); //informa o nome do filme
	printf("\tPessoas do sexo feminino: %d\n", mulher[x]); //informa a quantia de pessoas do sexo feminino
	printf("\tPessoas do sexo masculino: %d\n", homem[x]); //informa a quantia de pessoas do sexo masculino
	printf("\tCrian�as: %d\n", crianca[x]); //informa a quantia de crian�as
	printf("\tAdolescentes: %d\n", adolescente[x]); //informa a quantia de adolescentes
	printf("\tAdultos: %d\n", adulto[x]); //informa a quantia de adultos
	printf("\tIdosos: %d\n", idoso[x]); //informa a quantia de idosos
	system("pause"); //system pause para solicitar o pressionamento de uma tecla para continuar os comandos
	system("cls"); //limpando o prompt de comando
	printf("-------- PESSOAS COM MAIORIDADE NA SESS�O %d [18+] --------\n\n", x+1); 
	printf("\tHomens: %d\n", maiorIdadeHomem[x]); //informa a quantia de homens maiores de idade
	printf("\tMulheres: %d\n", maiorIdadeMulher[x]); //informa a quantia de mulheres maiores de idade
	system("pause"); //system pause para solicitar o pressionamento de uma tecla para continuar os comandos
	system("cls"); //limpando o prompt de comando
	}
	printf("------- COMPARA��O ENTRE SESS�ES -------\n\n");
	//Informa todos os dados da sess�o 1 e 2
	printf("Filme sess�o 1: %s", nomeFilme[0]);
	printf("Filme sess�o 2: %s", nomeFilme[1]);
	printf("Quantia de pessoas:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", quantiaPessoas[0], quantiaPessoas[1]);
	printf("Crian�as:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", crianca[0], crianca[1]);
	printf("Adolescentes:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", adolescente[0], adolescente[1]);
	printf("Adultos:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", adulto[0],adulto[1]);
	printf("Idosos:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", idoso[0], idoso[1]);
	printf("Homens:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", homem[0], homem[1]);
	printf("Mulheres:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", mulher[0], mulher[1]);
	printf("Homens 18+:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", maiorIdadeHomem[0], maiorIdadeHomem[1]);
	printf("Mulheres 18+:\n");
	printf("Sess�o 1: %d                      Sess�o 2: %d\n", maiorIdadeMulher[0], maiorIdadeMulher[1]);
    
	return 0;  
}
