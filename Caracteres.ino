// Instruções para gerar caracteres/imagens

void Coracao()
{
  Avante(3); Virar(-135); Baixo(); Avante(4); Virar(45); Avante(2); Virar(45); Avante(1); Virar(45); Avante(1); Virar(45); Avante(1); Virar(-90); Avante(1); Virar(45); Avante(1); Virar(45); Avante(1); Virar(45); Avante(2); Virar(45); Avante(4);Virar(45); Avante(2); Cima(); Virar(-135); Avante(5);
}

void Espaco()
{
  Pausar();                                          // garantir que os motores estão parados
  delay(100);                                      // delay para permitir que a tensão da bateria estabilize-se
  tensao = analogRead(bateria) / 10;                // receber novo valor de tensão para manter velocidade take new battery reading to maintain optimal speed
  velocDesenho = 26214 / tensao * 10 / tensao;             // correção na velocidade de desenho (fator=100% é quando a bateria estiver com 5V ou para leitura analógica recebendo 512)
  velocDesenho = velocDesenho * 8 / 10;                        // ajuste na velocidade para previnir overshoot
  Cima(); Avante(4);                                     // levantar o chassi e ir 4 espaços para frente
}

void Fim()
{
  while (1 < 2)
  {

  }
}
