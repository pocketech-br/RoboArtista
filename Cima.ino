void Cima()                                          // Levantar o chassi, desencostando a caneta da superfície
{
  for(int i=0;i<15;i++)                            // enviar 15 pulsos parw permitir que o servo alcaçe sua nova posição
  {
    digitalWrite(pinoServo,1);                       // definir o pino de controle do servo como HIGH para início dos pulsos
    delayMicroseconds(1500);                       // manter o pulso em HIGH por 1500uS
    digitalWrite(pinoServo,0);                       // definir o pino de controle do servo como HIGH para finalizar o pulso
    delay(20);                                     // aguardar 20mS antes de iniciar o próximo pulso
  }
  caneta=0;
}
