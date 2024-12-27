/*
    Programador: (c) 2024 Pedro Ferreira
    Data.......: 17/12/2024
    Observações: Led + Botão
*/

const byte PINO_LED = 12;
const byte PINO_BOTAO = 4;

byte estadoBotao = LOW;
byte ultimoEstadoBotao = LOW;
unsigned long tempoUltimoDebounce = 0;
const unsigned long tempoDebounce = 50;

void setup() {
    Serial.begin(9600);
    pinMode(PINO_LED, OUTPUT);
    pinMode(PINO_BOTAO, INPUT);
}

void loop() {
    lerEstadoBotao();

    if (estadoBotao == HIGH) {
        digitalWrite(PINO_LED, HIGH);
    } else {
        digitalWrite(PINO_LED, LOW);
    }
}

void lerEstadoBotao() {
    int leitura = digitalRead(PINO_BOTAO);

    if (leitura != ultimoEstadoBotao) {
        tempoUltimoDebounce = millis();
    }

    if ((millis() - tempoUltimoDebounce) > tempoDebounce) {
        if (leitura != estadoBotao) {
            estadoBotao = leitura;
        }
    }

    ultimoEstadoBotao = leitura;
}
