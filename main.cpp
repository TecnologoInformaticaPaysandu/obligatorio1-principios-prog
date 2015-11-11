#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    printf("Bienvenido al evaluador de expresiones aritmeticas:\n");
    printf("Las expresiones pueden tener a lo mas 9 numeros enteros y 8 operadores.\n");
    printf("Los operadores disponibles son +,-,*,/ y %c\n",'%');
    printf("Para terminar la expresion ingrese CTRL+Z\n\n");
    
    char opcion = 's';
    do{
    
    int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0, num7=0, num8=0, num9=0;
    char oper1='N', oper2='N', oper3='N', oper4='N', oper5='N', oper6='N', oper7='N', oper8='N';
    int numLeidos=0, operLeidos=0;
    char car;       
        
        
    printf("Ingrese la expresion a evaluar: ");

    do{
        car = getchar();
        if ((car >= 48) && (car <= 57)){
        //si el caracter es un dígito
            switch (numLeidos){
                  case 0:
    			       num1 = num1*10+(car-48);
    			       break;
                  case 1:
    			       num2 = num2*10+(car-48);
    			       break;
                  case 2:
    			       num3 = num3*10+(car-48);
    			       break;
                  case 3:
    			       num4 = num4*10+(car-48);
    			       break;
	              case 4:
           			   num5 = num5*10+(car-48);
           			   break;
  			      case 5:
    			       num6 = num6*10+(car-48);
    			       break;
  			      case 6:
    			       num7 = num7*10+(car-48);
    			       break;
  			      case 7:
    			       num8 = num8*10+(car-48);
    			       break;
  			      case 8:
    			       num9 = num9*10+(car-48);
    			       break;
              }
          }
          else {
               if (car=='+'||car=='-'||car=='*'||car=='/'||car=='%'){
                  //si el caracter es un operador
            	  ++numLeidos;
                  switch (operLeidos){
                      case 0:
       			       	   oper1 = car;
        			       break;
                      case 1:
       			       	   oper2 = car;
           			       break;
                      case 2:
       			       	   oper3 = car;
        			       break;
                      case 3:
       			       	   oper4 = car;
        			       break;
    	              case 4:
       			       	   oper5 = car;
               			   break;
      			      case 5:
       			       	   oper6 = car;
        			       break;
      			      case 6:
       			       	   oper7 = car;
        			       break;
      			      case 7:
       			       	   oper8 = car;
        			       break;
                  }//switch
           		  ++operLeidos;
               }//if
               }//else
    }//do
    while(car != EOF); 
                  
    ++numLeidos;
/*
    printf("\n\nLa expresion ingresada es:");
    printf("%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d%c%d\n",num1,oper1,num2,oper2,num3,oper3,num4,oper4,num5,oper5,num6,oper6,num7,oper7,num8,oper8,num9);
    printf("Cantidad de operadores= %d\n", operLeidos);
    printf("Cantidad de numeros= %d\n\n", numLeidos);
*/    
    bool error = false;
    
    if (operLeidos >= numLeidos){
    	printf("Error expresion mal formada: la cantidad de operadores leidos es mayor o igual que 	la 	cantidad de numeros leidos\n");
    	error = true;
     }
    if (operLeidos != numLeidos-1){
    	printf("Error expresion mal formada: la cantidad de operadores leidos no se corresponde con la 	cantidad de numeros leídos\n");
    	error = true;
     }   
    if (operLeidos == 0){
    	printf("Error expresion mal formada: no se ingresaron operadores\n");
     	error = true;
    }
    if(numLeidos == 0){
       printf("Error expresion mal formada: no se ingresaron numeros\n");
       error = true;
    }
 
//Bien, hasta aquí tengo leídos los números y los operadores y se que esta bien formada
//Paso a evaluar
  if(!error){     

      int res1=0, res2=0, res3=0, res4=0, res5=0, res6=0, res7=0, res8=0;
      bool eval1=false, eval2=false, eval3=false, eval4=false, eval5=false, eval6=false, eval7=false, eval8=false;
    
      //Conozco numLeidos, operLeidos y se que operLeidos=numLeidos-1
    
      int resTotal = 0;

      //EVALUO OPERADORES *,/;%
      if (oper1=='*'||oper1=='/'||oper1=='%'){
             switch (oper1){
                    case '*':
                        res1=num1*num2;
                        break; 
                    case '/':                       
                         res1=num1/num2;
                         break;    
                    case '%':
                         res1=num1%num2;
                         break;  
             } 
             eval1=true;
        	 resTotal = res1;               
      }

      if (oper2=='*'||oper2=='/'||oper2=='%'){
             switch (oper2){
                    case '*':
  		                 if (eval1==false)
			                res2=num2 * num3;
		                 else res2=res1 * num3;
		                 break;
                    case '/':                       
  		                 if (eval1==false)
			                res2=num2 / num3;
		                 else res2=res1 / num3;
                         break;   
                    case '%':
  		                 if (eval1==false)
			                res2=num2 % num3;
		                 else res2=res1 % num3;
		                 break;
             } 
             eval2=true;
        	 resTotal = res2;               
      }

      if (oper3=='*'||oper3=='/'||oper3=='%'){
             switch (oper3){
                    case '*':
                		if (eval2==false)
                			res3=num3 * num4;
                		else res3=res2 * num4;
                		break;
                    case '/':                       
                		if (eval2==false)
                			res3=num3 / num4;
                		else res3=res2 / num4;
                		break; 
                    case '%':
                		if (eval2==false)
                			res3=num3 % num4;
                		else res3=res2 % num4;
                		break;
             } 
             eval3=true;
        	 resTotal = res3;               
      }

      if (oper4=='*'||oper4=='/'||oper4=='%'){
             switch (oper4){
                    case '*':
                        if (eval3==false)
			                res4=num4 * num5;
                        else res4=res3 * num5;
                		break;
                    case '/':                       
                        if (eval3==false)
			                res4=num4 / num5;
                        else res4=res3 / num5;
                		break; 
                    case '%':
                        if (eval3==false)
			                res4=num4 % num5;
                        else res4=res3 % num5;
                		break;
             } 
             eval4=true;
        	 resTotal = res4;               
      }


      if (oper5=='*'||oper5=='/'||oper5=='%'){
             switch (oper5){
                    case '*':
		                if (eval4==false)
			               res5=num5 * num6;
                        else res5=res4 * num6;
                		break;
                    case '/':                       
		                if (eval4==false)
			               res5=num5 / num6;
                        else res5=res4 / num6;
                		break; 
                    case '%':
		                if (eval4==false)
			               res5=num5 % num6;
                        else res5=res4 % num6;
                		break;
             } 
             eval5=true;
        	 resTotal = res5;               
      }

      if (oper6=='*'||oper6=='/'||oper6=='%'){
             switch (oper6){
                    case '*':
                         if (eval5==false)
			                res6=num6 * num7;
                        else res6=res5 * num7;
                		break;
                    case '/':                       
                         if (eval5==false)
			                res6=num6 / num7;
                        else res6=res5 / num7;
                		break; 
                    case '%':
                         if (eval5==false)
			                res6=num6 % num7;
                        else res6=res5 % num7;
                		break;
             } 
             eval6=true;
        	 resTotal = res6;               
      }

      if (oper7=='*'||oper7=='/'||oper7=='%'){
             switch (oper7){
                    case '*':
		                 if (eval6==false)
			                res7=num7 * num8;
		                 else res7=res6 * num8;
                		break;
                    case '/':                       
		                 if (eval6==false)
			                res7=num7 / num8;
		                 else res7=res6 / num8;
                		break; 
                    case '%':
		                 if (eval6==false)
			                res7=num7 % num8;
		                 else res7=res6 % num8;
                		break;
             } 
             eval7=true;
        	 resTotal = res7;               
      }

      if (oper8=='*'||oper8=='/'||oper8=='%'){
             switch (oper8){
                    case '*':
                  		if (eval7==false)
		                	res8=num8 * num9;
		                else res8=res7 * num9;
                		break;
                    case '/':                       
                  		if (eval7==false)
		                	res8=num8 / num9;
		                else res8=res7 / num9;
                		break; 
                    case '%':
                  		if (eval7==false)
		                	res8=num8 % num9;
		                else res8=res7 % num9;
                		break;
             } 
             eval8=true;
        	 resTotal = res8;               
      }

      //EVALUO OPERADORES +,-
      if ((eval1 == false)&&(oper1=='+'||oper1=='-')){
                
         switch (oper1){
        	case '+':
        		if(eval2 && eval3 && eval4 && eval5 && eval6 && eval7 && eval8)
        			res1 = num1 + res8;
        		else if(eval2 && eval3 && eval4 && eval5 && eval6 && eval7)
        			res1 = num1 + res7;
        		else if(eval2 && eval3 && eval4 && eval5 && eval6)
        			res1 = num1 + res6;
        		else if(eval2 && eval3 && eval4 && eval5)
        			res1 = num1 + res5;
        		else if(eval2 && eval3 && eval4)
        			res1 = num1 + res4;
        		else if(eval2 && eval3)
        			res1 = num1 + res3;
        		else if(eval2)
        			res1 = num1 + res2;
        		else res1 = num1 + num2;
        		break;
        	case '-':
        		if(eval2 && eval3 && eval4 && eval5 && eval6 && eval7 && eval8)
        			res1 = num1 - res8;
        		else if(eval2 && eval3 && eval4 && eval5 && eval6 && eval7)
        			res1 = num1 - res7;
        		else if(eval2 && eval3 && eval4 && eval5 && eval6)
        			res1 = num1 - res6;
        		else if(eval2 && eval3 && eval4 && eval5)
        			res1 = num1 - res5;
        		else if(eval2 && eval3 && eval4)
        			res1 = num1 - res4;
        		else if(eval2 && eval3)
        			res1 = num1 - res3;
        		else if(eval2)
        			res1 = num1 - res2;
        		else res1 = num1 - num2;
        		break;
            }//switch
            eval1=true;
        	resTotal = res1;
         }

      if (oper2!='N'){
          switch (oper2){
	             case '+':
            		if(eval3 && eval4 && eval5 && eval6 && eval7 && eval8)
            			res2 = res1 + res8;
            		else if(eval3 && eval4 && eval5 && eval6 && eval7)
            			res2 = res1 + res7;
            		else if(eval3 && eval4 && eval5 && eval6)
            			res2 = res1 + res6;
            		else if(eval3 && eval4 && eval5)
            			res2 = res1 + res5;
            		else if(eval3 && eval4)
            			res2 = res1 + res4;
            		else if(eval3)
            			res2 = res1 + res3;
            		else res2 = res1 + num3;
            		break;
	             case '-':
            		if(eval3 && eval4 && eval5 && eval6 && eval7 && eval8)
            			res2 = res1 - res8;
            		else if(eval3 && eval4 && eval5 && eval6 && eval7)
            			res2 = res1 - res7;
            		else if(eval3 && eval4 && eval5 && eval6)
            			res2 = res1 - res6;
            		else if(eval3 && eval4 && eval5)
            			res2 = res1 - res5;
            		else if(eval3 && eval4)
            			res2 = res1 - res4;
            		else if(eval3)
            			res2 = res1 - res3;
            		else res2 = res1 - num3;
            		break;
        		 default:
                    res2=res1;
                    break;
        }//switch
       	
        eval2=true;
		resTotal = res2;
      }
        	
      if (oper3!='N'){
        switch (oper3){
        	case '+':
        		if(eval4 && eval5 && eval6 && eval7 && eval8)
        			res3 = res2 + res8;
        		else if(eval4 && eval5 && eval6 && eval7)
        			res3 = res2 + res7;
        		else if(eval4 && eval5 && eval6)
        			res3 = res2 + res6;
        		else if(eval4 && eval5)
        			res3 = res2 + res5;
        		else if(eval4)
        			res3 = res2 + res4;
        		else res3 = res2 + num4;
        		break;
        	case '-':
        		if(eval4 && eval5 && eval6 && eval7 && eval8)
        			res3 = res2 - res8;
        		else if(eval4 && eval5 && eval6 && eval7)
        			res3 = res2 - res7;
        		else if(eval4 && eval5 && eval6)
        			res3 = res2 - res6;
        		else if(eval4 && eval5)
        			res3 = res2 - res5;
        		else if(eval4)
        			res3 = res2 - res4;
        		else res3 = res2 - num4;
        		break;
       		 default:
                    res3=res2;
                    break;
        }		
        eval3=true;
        resTotal = res3;
        }
    
      if (oper4!='N'){
        switch (oper4){
        	case '+':
        		if(eval5 && eval6 && eval7 && eval8)
        			res4 = res3 + res8;
        		else if(eval5 && eval6 && eval7)
        			res4 = res3 + res7;
        		else if(eval5 && eval6)
        			res4 = res3 + res6;
        		else if(eval5)
        			res4 = res3 + res5;
        		else res4 = res3 + num5;
        		break;
        	case '-':
        		if(eval5 && eval6 && eval7 && eval8)
        			res4 = res3 - res8;
        		else if(eval5 && eval6 && eval7)
        			res4 = res3 - res7;
        		else if(eval5 && eval6)
        			res4 = res3 - res6;
        		else if(eval5)
        			res4 = res3 - res5;
        		else res4 = res3 - num5;
        		break;
        		 default:
                    res4=res3;
                    break;
        		
            }
        eval4=true;
        resTotal = res4;
        }
    
      if (oper5!='N'){
        switch (oper5){
        	case '+':
        		if(eval6 && eval7 && eval8)
        			res5 = res4 + res8;
        		else if(eval6 && eval7)
        			res5 = res4 + res7;
        		else if(eval6)
        			res5 = res4 + res6;
        		else res5 = res4 + num6;
        		break;
        	case '-':
        		if(eval6 && eval7 && eval8)
        			res5 = res4 - res8;
        		else if(eval6 && eval7)
        			res5 = res4 - res7;
        		else if(eval6)
        			res5 = res4 - res6;
        		else res5 = res4 - num6;
        		break;
        		 default:
                    res5=res4;
                    break;
        		
          }
        eval5=true;
        resTotal = res5;
        }
    
      if (oper6!='N'){
        switch (oper6){
        	case '+':
        		if(eval7 && eval8)
        			res6 = res5 + res8;
        		else if(eval7)
        			res6 = res5 + res7;
        		else res6 = res5 + num7;
        		break;
        	case '-':
        		if(eval7 && eval8)
        			res6 = res5 - res8;
        		else if(eval7)
        			res6 = res5 - res7;
        		else res6 = res5 - num7;
        		break;
        		 default:
                    res6=res5;
                    break;	
        }
        eval6=true;
        resTotal = res6;
        }
    
      if (oper7!='N'){
        switch (oper7){
        	case '+':
        		if(eval8)
        			res7 = res6 + res8;
        		else res7 = res6 + num8;
        		break;
        	case '-':
        		if(eval8)
        			res7 = res6 - res8;
        		else res7 = res6 - num8;
        		break;
        		 default:
                    res7=res6;
                    break;	        		
        }
        eval7=true;
        resTotal = res7;
        }
    
      if (oper8!='N'){
         switch (oper8){
            	case '+':
            		res8 = res7 + num9;
            		break;
            	case '-':
            		res8 = res7 - num9;
            		break;
        		 default:
                    res8=res7;
                    break;	
         }
        eval8=true;
        resTotal = res8;
        }
    
       printf("El resultado es: %d\n",resTotal);

    }// !error*/
    
    printf("Desea ingresar otra expresion (s/n):");
    opcion = getchar();
    }
    while (opcion == 's');
    
    printf("\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
