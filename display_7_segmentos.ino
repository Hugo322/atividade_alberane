int displayValue, decrementDisplayValue;

byte seven_seg_digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, //Digito 0
  { 0, 1, 1, 0, 0, 0, 0 }, //Digito 1
  { 1, 1, 0, 1, 1, 0, 1 }, //Digito 2
  { 1, 1, 1, 1, 0, 0, 1 }, //Digito 3
  { 0, 1, 1, 0, 0, 1, 1 }, //Digito 4
  { 1, 0, 1, 1, 0, 1, 1 }, //Digito 5
  { 1, 0, 1, 1, 1, 1, 1 }, //Digito 6
  { 1, 1, 1, 0, 0, 0, 0 }, //Digito 7
  { 1, 1, 1, 1, 1, 1, 1 }, //Digito 8
  { 1, 1, 1, 1, 0, 1, 1 }, //Digito 9
};

void setup() {
  pinMode(2, OUTPUT); // Define o pino 2 como saída
  pinMode(3, OUTPUT); // Define o pino 3 como saída
  pinMode(4, OUTPUT); // Define o pino 4 como saída
  pinMode(5, OUTPUT); // Define o pino 5 como saída
  pinMode(6, OUTPUT); // Define o pino 6 como saída
  pinMode(7, OUTPUT); // Define o pino 7 como saída
  pinMode(8, OUTPUT); // Define o pino 8 como saída
  pinMode(9, OUTPUT); // Define o pino 9 como saída

  decrementDisplayValue = 9;
  showDisplay(decrementDisplayValue);
}

void ligaPonto(byte dot) { // Aciona o ponto no display
  digitalWrite(9, dot);
}

void showDisplay(byte digit) {
  byte pino = 2;

  for (byte contadorSegmentos = 0; contadorSegmentos < 7; ++contadorSegmentos) {
    digitalWrite(pino, seven_seg_digits[digit][contadorSegmentos]);
    pino++;
  }
}

void loop() {
  if (displayValue == 10) {
    ligaPonto(1);
    delay(50);
    ligaPonto(0);

    delay(1000);
    showDisplay(decrementDisplayValue);
    decrementDisplayValue--;
  } else if (displayValue < 10) {
    delay(1000);
    showDisplay(displayValue);
    displayValue++;
  }
}
