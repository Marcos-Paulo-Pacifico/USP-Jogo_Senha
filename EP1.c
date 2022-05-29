
/***************************************************************/
/**                                                           **/
/**   Marcos Paulo Pacifico                      11233817     **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Alair Pereira do Lago                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int main() {

int k,                  /* numero de digitos da senha */
    senha,
    c,                  /* numero de cores */
    maxpalp;            /* numero maximo de palpites */
int i,
    j;                  /* numero de tentativas utilizadas */
int palp,               /* palpite do jogador */
    digp,               /* digito do palpite a ser comparado */
    digs,               /* digito da senha a ser comparado */
    pinp,               /* quantidade de pinos pretos */
    compsenha;          /* utilizada para fazer as operacoes de comparacao sem alterar o valor inicial da senha */

int errado = TRUE;      /* inicia definindo que o palpite esta errado */

printf("Entre com o numero de digitos da senha: ");
scanf("%d",&k);
printf("Entre com o numero de cores: ");
scanf("%d",&c);
printf("Entre com o numero maximo de palpites: ");
scanf("%d",&maxpalp);
printf("Entre com a senha de %d digitos (0 para valor aleatorio): ", k);
scanf("%d",&senha);

if (senha == 0) {
 srand(time(NULL));
 for (i=0; i<k; i++)                           /* criacao da senha aleatoria */
  senha = senha*10 + (rand() % c + 1);
}

j = 0;

while(j<maxpalp && errado == TRUE){            /* executa as comparacoes enquanto nao excedeu o num de palpites e ainda nao se descobriu a senha */
  printf("Digite seu palpite: ");
  scanf("%d",&palp);

  compsenha = senha;
  pinp = 0;

  while(palp>0 || compsenha>0){                /* faz as comparacoes digito a digito ate que a senha ou o palpite seja 0 */
   digs = compsenha % 10;
   digp = palp % 10;                           /* extrai o ultimo digito de ambos os valores */

   if(digs == digp) pinp ++;                   /* se os dois digitos forem iguais, o num de pinos pretos eh acrescido */

   compsenha = compsenha/10;                   /*atualiza os valores do palpite e da senha excluindo o ultimo digito */
   palp = palp/10;
  }

  printf("%d pretos\n", pinp);
  if (pinp == k)errado = FALSE;                /* se o num de pinos pretos for igaul ao num de digitos da senha, o usuario acertou e portanto o palpite esta certo */
  else errado = TRUE;                          /* caso contrario, permanece errado e retorna o laco para mais uma tentativa */
  j ++;                                        /* aumenta em 1 o num de tentativas utilizadas pelo jogador */
}

if (errado == FALSE) printf("Parabens! Voce descobriu a senha em %d tentativas", j);
else printf("Sinto muito, mas voce nao conseguiu acertar a senha %d", senha);

return 0;
}
