#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

//Num de equa��es
#define LIN 4
//Num de ic�gnitas + 1
#define COL 4

double * SomaLL(double *, double *);
double * MultiLn(double *, double n);
void atribuiL(double [LIN][COL], int, double *);
void ImprimeM(double [LIN][COL]);
void escalonarM(double [LIN][COL]);

char icog[] = "xyz";

int main(){
	setlocale(LC_ALL, "Portuguese");	
	double m[LIN][COL];
	int i, j;	
		
	for (i=0; i<LIN; i++){
		printf("%d� Equa��o:\n", i+1);
		for (j=0; j<COL; j++){
			if (j<COL-1){
				printf("    Digite o coeficiente de %c: ", icog[j]);
				scanf("%lf", &m[i][j]);
			}
			else{
				printf("    Digite o resultado da equa��o: ");
				scanf("%lf", &m[i][j]);
			}				
		}
	}
	printf("\nSistema:\n");
	ImprimeM(m);
				
	escalonarM(m);
	
	printf("Sa�da de dados:\n");
	
	ImprimeM(m);
	
}

void escalonarM(double a[LIN][COL]){
	int i, j;
	
	/*printf("Matriz:\n");
	ImprimeM(a);	
	
	printf("\nOpera��es:");*/
	
	//--- Opera��es no tri�ngulo inferior ---
	float multi;	
	//Percorre a matriz
	for (i=0; i<LIN; i++){
		for (j=0; j<COL; j++){
			
			//Se faz parte do tri�ngulo inferior e se o n�mero � diferente de 0			
			if (i>j && a[i][j] != 0){
							
				//multi = - a(i)(j) / a(j)(j)
				multi = (- a[i][j]) / a[j][j];
				
				//a(i) = a(i) + a(j) . multi
				atribuiL(a, i, SomaLL(a[i], MultiLn(a[j], multi)));
				
				//ImprimeM(a);
			}
				
		}		
		//printf("\n");
	}
	
	//--- Opera��es na diagonal principal ---	
	//Percorre a matriz
	for (i=0; i<LIN; i++){
		for (j=0; j<COL; j++){
			
			//Se faz parte da diagonal principal e se o n�mero for diferente de 1		
			if (i==j && a[i][j] != 1.0){
				
				//a(i) = a(i) / a(i)(j)   --   Multiplica toda a linha pelo inverso do n�mero, ou seja, divide por ele;
				if (a[i][j] != 0) // N�o existe denominador 0
					atribuiL(a, i, MultiLn(a[i], 1.0/a[i][j]));
					
				//Se o n�mero � igual a -1, ent�o troca o sinal da linha
				if (a[i][j] == -1)
					atribuiL(a, i, MultiLn(a[i], -1));
					
				//ImprimeM(a);
			}
				
		}		
		//printf("\n");
	}
	
	/*printf("Resultado: \n");
	ImprimeM(a);*/
}

double * SomaLL(double L1[COL], double L2[COL]){
	//Soma uma linha com outra e retona
	
	int i;
	double L_Res [COL];
	
	for (i=0; i<COL; i++){
		L_Res[i] = L1[i] + L2[i];
	}	
	
	return L_Res;
}

double * MultiLn(double L[COL], double n){
	//Multiplica toda a linha por n e retorna
	
	int i;
	double L_Res [COL];
	
	for (i=0; i<COL; i++){
		L_Res[i] = 1.0 * L[i] * n;
			
		//printf("TESTE = %f", L_Res[i]);
	}	
	
	return L_Res;
}

void atribuiL(double m[LIN][COL], int i, double L[COL]){
	//Substitui uma linha de uma matriz por outra
	
	int j;
	for (j=0; j<COL; j++){
		m[i][j] = L[j];
	}	
}

void ImprimeM(double m[LIN][COL]){
	//Imprime a matr�z
	
	int i, j;
	
	for (i=0; i<LIN; i++){
		for (j=0; j<COL; j++){
			if (m[i][j] != 0 || (j == COL-1)){
				
				if (j>0 && m[i][j-1] != 0){
					if (m[i][j] > 0 && j != COL-1)
						printf(" + ");
					else if (m[i][j] < 0 && j != COL-1)
						printf(" - ");
					else
						printf(" = ");
				}
				
				if (j == COL-1)
					printf("%.2f", m[i][j]);
				else
					printf("%.2f%c", fabs(m[i][j]), icog[j]);
				
			}
				
		}
		printf("\n");
	}
	printf("\n");
}
