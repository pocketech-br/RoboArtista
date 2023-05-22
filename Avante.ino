void Avante(int distancia)
{
  contadorE=0;                                        // reiniciar o contador do encoder da roda esquerda
  contadorD=0;                                        // reiniciar o contador do encoder da roda direita

  
  
  Pausar();
  delay(100);
  tensao=analogRead(bateria)/10;
  velocDesenho=26214/tensao*10/tensao;                     // correção na velocidade de desenho (fator=100% é quando a bateria estiver com 5V ou para leitura analógica recebendo 512)
  velocDesenho=velocDesenho*8/10;                              // ajuste na velocidade para previnir overshoot
  
  if(distancia>0)                                   // valores de distancia maiores que 0 fazem o robô ir para frente
  {
    velocRodaE=velocDesenho;
    velocRodaD=velocDesenho;
  }
  else                                             // valores de distancia maiores que 0 fazem o robô ir para trás
  {
    velocRodaE=-velocDesenho;
    velocRodaD=-velocDesenho;
  }
  distancia=abs(distancia);                          // considerando apenas a distancia que será percorrida
  if(giro==0) distancia*=tamanhoCaractere;
  int ols=velocRodaE;
  int ors=velocRodaD;
  
  
  while(contadorE<distancia || contadorD<distancia)        // continuar percurso até que ambos encoders estejam com a mesma distancia percorrida
  {
    if(contadorE>contadorD)                               
    {
      velocRodaE=0;
    }
    else
    {
      velocRodaE=ols;
    }
    if(contadorD>contadorE)
    {
      velocRodaD=0;
    }
    else
    {
      velocRodaD=ors;
    }
    Motores();
  }
  Pausar();                                          // garantir que ambos os motores estão complatamente parados
}
