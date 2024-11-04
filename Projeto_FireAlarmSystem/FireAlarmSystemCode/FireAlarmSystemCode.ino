//Bibliotecas
#include <SoftwareSerial.h> 
#include <Thermistor.h>

#define vermelho 4 //RGB 
#define verde 3    //RGB 
#define azul 2     //RGB
#define buzzer 6   //Buzzer passivo
#define SensorGas 0 //Sensor de gás - Porta analógica
#define SensorTemp 1 //Sensor de temperatura - porta analógica

SoftwareSerial SerialBluetooth(8,11); //Portas serais do bluetooth (RX, TX)
Thermistor temp(SensorTemp); //Cria o objeto temp associado ao pino A1 da classe thermistor 

enum Estado {START, STOP}; //Define o enum
Estado estadoAtual = STOP;  //Inicializa o estado como Desligado

byte Dadobluetooth; //Variavel responsável por guardar os valores que passam pela comunicação bluetooth

//Função para controlar os LEDs
void ControlaLED(bool vermelhoON, bool azulON, bool verdeON){
  digitalWrite(vermelho, vermelhoON ? HIGH : LOW);
  digitalWrite(azul, azulON ? HIGH : LOW);
  digitalWrite(verde, verdeON ? HIGH : LOW);
}

//Função enviar mensagens (strings) serial bluetooth
void mensagemblue(char mensagem[28]){
  SerialBluetooth.println(mensagem);
}

//Função do envio de dados (byte) pelo serial bluetooth
void dadosblue(byte valor){
  SerialBluetooth.print(valor);
}

void setup() {
  
  SerialBluetooth.begin(9600); //Inicializa a comunicação serial bluetooth
  Serial.begin(9600); //Inicializa a comunicação Serial
  pinMode(vermelho, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(buzzer, OUTPUT);

  //Confirmação de inicialização do sistema
  digitalWrite(azul, HIGH);
  delay(500);
  digitalWrite(azul, LOW);
  delay(10000); //10 segundos de estabilização do sensor de gás

}
void loop() {

  if (SerialBluetooth.available()){
    Dadobluetooth = SerialBluetooth.read();
    Serial.println(Dadobluetooth);
    if (Dadobluetooth == '1'){
      estadoAtual = START;
      mensagemblue("Sistema Ligado!");
    }
    if (Dadobluetooth == '0'){
      estadoAtual = STOP;
      mensagemblue("Sistema Desligado!");
    }
  }

  switch (estadoAtual){
    case STOP:         
      for (int x = 2; x <= 4; x++){
        digitalWrite(x, LOW); //Desliga todos os pinos do LED
      }
      break;
    case START:
      int temperatura = temp.getTemp(); //Recebe o cálculo do valor de temperatua pela biblioteca
      int EmissaoGas = analogRead(SensorGas); //Informações do Sensor de gás

      //Envio das informações
      mensagemblue("Temperatura: ");
      dadosblue(temperatura);
      mensagemblue("°C");
      mensagemblue("Sensor de gas: ");
      dadosblue(EmissaoGas);
      mensagemblue("");
      mensagemblue("");
      delay(5000);

      if ((EmissaoGas < 350) && (temperatura <= 27)){ //ambiente normal
        ControlaLED(false, false, true);
        noTone(buzzer);
      }
      else if ((EmissaoGas > 350) || (temperatura > 50)){ //alerta, possível caso de incêndio
        ControlaLED(true, false, false);
        for (int x = 0; x <= 5; x++){
          tone(buzzer, 1500, 1000);
        }
        
      }
      else if (temperatura > 32){ //Niveis de temperatura preocupante
        ControlaLED(true, false, true);
        mensagemblue("Temperatura acima de 35°C");
        mensagemblue("Recomenda-se prestar atenção!");
        delay(60000);
      }
      break;
  }
}
