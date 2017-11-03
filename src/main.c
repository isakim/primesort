#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*	PrimeSort
 *
 *	Esta tarefa é sobre usar pipes e ferramentas do Linux. Nela, você deverá escrever um prorama que 
 *	recebe como entrada uma sequência de números inteiros positivos, separados por um caractere newline. 
 *	A sequência é encerrada pelo número -1. O programa deve escrever na tela todos os números não-primos 
 *	dessa sequência, um por linha ordenados do maior para o menor.
 */

#include <stdio.h>

int ehprimo (int n){

	int div, lim, i;

        if(n==1 || n==0) {
      		return 0;
   	} else {
		div=0;
       		lim = n+1;
       		for(i=1; i<lim; i++){
           		if((n%i)==0){
               			div++;
				if (div==3) {
                                return 0;
                                }
                        }
        	}
    
       		if(div==2) {
          		return 1;
       		}

        }
		return 0;
}

int main() {

	int num;
	FILE *pipe;	

	if ((pipe = popen("sort -r -n", "w"))==NULL) {
        	perror("popen");
    		exit(1);	
        }

	//scanf("%d", &num);

	while (1){

		scanf ("%d\n", &num);	  	

	  	if (num == -1){	  		
	  		break;
	  	} else {
	  		if (ehprimo(num) == 0){	  			
	  			fprintf (pipe, "%d\n",num);		  				  				  			
	  		}
		}
	}

	pclose (pipe);
	  
	return 0;
}
