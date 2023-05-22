
#define bateriaBaixa     45                           // Definição do nível baixo de bateria
#define tamanhoCaractere    1                         // Multiplicador do tamanho dos caracteres

#define pinoRodaD  8                                  // Pino de controle do motor direito
#define pinoPWMD 10                                    // Pino de modulação de largura de pulso do motor direito
#define pinoRodaE  7                                  // Pino de controle do motor esquerdo
#define pinoPWME  9                                    // Pino de modulação de largura de pulso do motor esquerdo
#define pinoServo 4                                   // Pino do controle do servo do chassi

#define bateria  7                                    // Pino do monitor de tensão da bateria(entrada analógica)

int tensao;                                           // variável inteira utilizada para a tensão da alimentação
int pausa = -1;                                       // O valor -1 significa que a tensão da bateria está ok, 0 e 1 são utilizados para piscar o LED na saída D13 caso a mesma esteja abaixo do nível ideal
byte caneta;
byte giro;

int velocRodaE;                                        // Velocidade na roda esquerda, variando de -255 a +255 (valores negativos são para movimentos reversos)
int velocRodaD;                                        // Velocidade na roda direita, variando de -255 a +255 (valores negativos são para movimentos reversos)
int velocDesenho=80;                                   // Velocidade de desenho, variando de +50 to +200

volatile int contadorD;
volatile int contadorE;

void setup()
{
  attachInterrupt(0,Rcount,CHANGE);
  attachInterrupt(1,Lcount,CHANGE);
  
  Serial.begin(57600);                                 // Inicializar interface serial - 57600 baud   
  pinMode(pinoRodaE,OUTPUT);                           // definição do pino do motor esquerdo como saída
  pinMode(pinoRodaD,OUTPUT);                           // definição do pino do motor esquerdo como saída
  pinMode(pinoServo,OUTPUT);                           // definição do pino que controla o chassi como saída
  
  digitalWrite(2,1);                                   // habilitar o pino D2
  digitalWrite(3,1);                                   // habilitar o pino D3
  
  Cima();                                              // Iniciar o programa com o chassi levantado e consequentemente a caneta desencostada do papel
  delay(1000);
  
}

void loop()
{ 
  tensao=analogRead(bateria)/10;                       // leitura da tensão do case de pilhas   
  
  if(tensao<bateriaBaixa || pausa!=-1)                 // Caso a tensão de alimentação seja menor do que o valor de nível baixo da bateria ou se pausa não tiver o mesmo valor que -1 
  {
    velocRodaE=0;                                      // Motor esquerdo parado
    velocRodaD=0;                                      // Motor direito parado
    Motores();                                         // atualizar os pinos de controle do motor
    if (pausa<0) Cima();                               // certificar que o chassi esteja levantado quando a tensão de alimentação for menor que o valor determinado para bateria baixa
    pausa++;                                           // incrementar pausa
    if(pausa>1) pausa=0;                               // alternar o valor da pausa entre 0 e 1 quando a bateria estiver descarregada
    digitalWrite(13,pausa);                            // piscar LED do pino D13
    delay(100);                                        // definir a velocidade do piscar do LED
    return;                                            // reiniciar o loop
  }
                                                       // Corrente é proporcional à tensão e potência (Potência = Tensão x Corrente)/ 
                                                       // A medida que a tensão da bateria diminui, a variável velocDesenho aumenta seu valor para manter uma velocidade constante
  
  velocDesenho=26214/tensao*10/tensao;                 // correção na velocidade de desenho (fator=100% é quando a bateria estiver com 5V ou para leitura analógica recebendo 512)
  velocDesenho=velocDesenho*8/10;                      // ajuste na velocidade para previnir overshoot
   
Coracao();Fim();
  //O();I();Espaco();S();O();M();O();S();Espaco();A();Espaco();P();O();C();K();E();T();E();C();H();Fim();
  // Alfabeto: A();B();C();D();E();F1();G();H();I();J();K();L();M();N();O();P();Q();R();S();T();U();V();W();X();Y();Z();Fim();
  // Números: N0();N1();N2();N3();N4();N5();N6();N7();N8();N9();Fim();
  // Desenho: Coracao();
}


  
