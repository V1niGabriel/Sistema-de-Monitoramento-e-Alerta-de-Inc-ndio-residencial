
# Sistema de Monitoramento e Alerta de Incêndio Residêncial

Este repositório contém um projeto desenvolvidos para aprendizado, prática e demonstração de habilidades em programação, eletrônica, microcontroladores.  Servindo como um portfólio de experimento.

Data de Iníco: 1 de outubro de 2024

Versão Atual: FireAlarmSystem-29-10-2024

## Visão Geral

 **Objetivo** 
  - Desenvolvimento de um sistema de alerta de incêndios baseado em Arduino que monitore a temperatura e presença de gases inflamáveis e fumaça. O sistema é capaz de informar, por meio de sinais visuais e sonoros, o início de um incêndio ou possível foco.  

  **descrição**
  - O projeto usa sensores conectados a uma placa Arduino para medir constantemente os valores de temperatura e presença/concentração de gás e fumaça no ambiente. Caso as medições do ambiente ultrapassem as condições de temperatura e presença de fumaça consideradas normais, um alerta visual e sonoro é emitido, notificando rapidamente os moradores da residência na qual o sistema está instalado. Resultando em uma resposta mais eficiente dos envolvidos.

## Componentes do sistema

**Hardware**
| Componente                     | Função                                          |
|--------------------------------|-------------------------------------------------|
| Arduino BlackBoard UNO R3      | Controlador principal para processamento e controle dos dispositivos |
| Sensor de Temperatura Termistor NTC | Para medição da temperatura ambiente         |
| Sensor de gás MQ135            | Detectar gases inflamáveis e fumaça               |
| Buzzer Piezoelétrico ativo     | Emite alertas sonoros                             |
| LED RGB                        | Alertas visuais                                   |
| Módulo Bluetooth HC-05         | Notificação e comunicação remota via Bluetooth    |


**Software**

IDE Arduino - Ambiente de Desenvolvimento para codificação e upload de código para o Arduino.

Bibliotecas Arduino:

- [Thermistor.h](https://github.com/panStamp/thermistor?tab=readme-ov-file)
- [SoftwareSerial.h](https://docs.arduino.cc/learn/built-in-libraries/software-serial/)

## Diagrama de Circuito

### Requisistos do Sistema

Requisitos Funcionais:
- Emissão de alerta sonoro e visual quando os valores de temperatura ou fumaça ultrapassam os limites seguros
- Monitoramento contínuo de temperatura e presença de fumaça

Requisitos Não Funcionais:
- Baixo consumo de energia para operação prolongada
- Alta precisão na leitura dos sensores


## Testes e Calibração

Em função da garantia de qualidade e precisão, o sistema precisa ser calibrado:

- Teste Sensor de Temperatura: Expor o sensor a diferentes temperaturas verificando os valores lidos, confirmando se coincide com a temperatura do ambiente. *Taxa de erro: 1°C a 2°C.*
- Sensor de Gás: É recomendado deixar o sensor de gás ligado por 24 horas, passando pelo processo de tempo de queima **(burn-in-time)**. Período necessário para que o sensor estabilize sua resistência interna e apresente leituras mais precisa.
- Teste de Alerta: Simular situações críticas para validar as repostas dos alertas sonoros e luminosos

## Manutenção e Atualizações

**Manutenção Regular:**
- Verificar a recalibrar os sensores periodicamente
- Garantir que os componentes estejam protegidos contra poeira e umidade

**Possíveis Atualizações**
- Integração com sistemas de casas inteligentes
- Integração com aplicativos móveis para notificações instantâneas.
