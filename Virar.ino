void Virar(int angulo)                               // +angulo=CW, -angulo=CCW, +/-8 =90degrees 1 motor, +/- 32+4=90 degrees 2 motors
{
  if(angulo==45) angulo=34;
  if(angulo==-45) angulo=-34;
  if(angulo==90) angulo=36;
  if(angulo==-90) angulo=-36;
  if(angulo==135) angulo=38;
  if(angulo==-135) angulo=-38;
  if(angulo==180) angulo=40;
  if(angulo==-180) angulo=-40;
  if(angulo==225) angulo=42;
  if(angulo==-225) angulo=-42;
  if(angulo==270) angulo=44;
  if(angulo==-270) angulo=-44;
  if(angulo==315) angulo=46;
  if(angulo==-315) angulo=-46; 
  if(angulo==360) angulo=48;
  if(angulo==-360) angulo=-48;
  

  byte oldcaneta=caneta;
  byte flag=0;
  if(abs(angulo)>32)                                // angulos maiores que 32, utilizará o segundo método de giro (em torno de seu eixo, girando cada roda para um lado)
  {                                                // angulos entre 1 e 32, utilizam o primeiro método de giro (uma roda para seu movimento, girando em torno do seu eixo)
    Cima();
    giro=1;
    Avante(5);
    giro=0;
    flag=1;
  }
  contadorE=0;
  contadorD=0;
  
  if(angulo<0)
  {
    velocRodaD=velocDesenho;
    velocRodaE=0;
    if(angulo<-32) 
    {
      velocRodaE=-velocDesenho;
      angulo+=32;
    }
  }
  else
  {
    velocRodaE=velocDesenho;
    velocRodaD=0;
    if(angulo>32) 
    {
      velocRodaD=-velocDesenho;
      angulo-=32;
    }
  }
  angulo=abs(angulo);
  int ols=velocRodaE;
  int ors=velocRodaD;
  Motores();

  if(velocRodaE==0 || velocRodaD==0)                       // giro em torno de uma roda (método 1 de giro)
  {  
    while(contadorE<angulo && contadorD<angulo)
    {
    }
  }
  else                                             // giro em torno do seu próprio eixo (método 2 de giro)
  {
    while(contadorE<angulo || contadorD<angulo)
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
  }
  Pausar();
  if(flag==1)                                      // giro em torno do seu próprio eixo (método 2 de giro)
  {
    giro=1;
    Avante(-5);
    giro=0;
    if(oldcaneta==1) Baixo();
  }
}
