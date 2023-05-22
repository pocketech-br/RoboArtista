void Motores()                                      // controlar os motores direito e esquerdo
{
  int lmotor=abs(velocRodaE);                       // Variáveis temporárias que serão utilizadas para correção da velocidade
  int rmotor=abs(velocRodaD);
  
  if(lmotor>255) lmotor=255;                       // Definição do valor limite de velocidade que o motor esquerdo terá 
  if(rmotor>255) rmotor=255;                       // Definição do valor limite de velocidade que o motor direito terá   
  
  digitalWrite(pinoRodaE,(velocRodaE<0));           // define sendo positivo ou negativo o valor de velocidade do motor esquerdo
  analogWrite (pinoPWME,lmotor);                    // define a velocRodaE para seu valor absoluto (ignora os sinais de + or -)
  
  digitalWrite(pinoRodaD,(velocRodaD<0));           // define sendo positivo ou negativo o valor de velocidade do motor direito
  analogWrite (pinoPWMD,rmotor);                    // define a velocRodaD para seu valor absoluto (ignora os sinais de + or -)
}
