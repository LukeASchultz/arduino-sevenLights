int input1, input2, input3;
boolean pressed, win;
boolean fiveMode = false;

boolean ledStates[] = {false, false, false, false, false, false, false};

void setup() {
  for (int i = 0; i <= 7; i++) {
    pinMode(i + 2, OUTPUT);
  }

  pinMode(12, INPUT_PULLUP);
}

void loop() {
  input1 = analogRead(A1);
  input2 = analogRead(A2);
  input3 = analogRead(A3);

  if (digitalRead(12) == LOW) {
    fiveMode = true;
  } else {
    fiveMode = false;
  }

  for (int i = 0; i <= 7; i++) {
    if (ledStates[i] == true) {
      digitalWrite(i + 2, HIGH);
    } else {
      digitalWrite(i + 2, LOW);
    }
  }

  if (((input1 > 300) && !(pressed)) || ((input2 > 300) && !(pressed)) || ((input3 > 300) && !(pressed))) {
    if (input1 >= 1020 && input1 <= 1023) {
      if (fiveMode) {
        changeStatesFive(0);
      } else {
        changeStatesThree(0);
      }
    } else if (input1 >= 1000 && input1 <= 1017) {
      if (fiveMode) {
        changeStatesFive(1);
      } else {
        changeStatesThree(1);
      }
    } else if (input3 >= 700 && input3 <= 1023) {
      if (fiveMode) {
        changeStatesFive(2);
      } else {
        changeStatesThree(2);
      }
    } else if (input1 >= 817 && input1 <= 870) {
      if (fiveMode) {
        changeStatesFive(3);
      } else {
        changeStatesThree(3);
      }
    } else if (input1 >= 940 && input1 <= 985) {
      if (fiveMode) {
        changeStatesFive(4);
      } else {
        changeStatesThree(4);
      }
    } else if (input2 >= 900 && input2 <= 970) {
      if (fiveMode) {
        changeStatesFive(5);
      } else {
        changeStatesThree(5);
      }
    } else if (input2 >= 1010 && input2 <= 1023) {
      if (fiveMode) {
        changeStatesFive(6);
      } else {
        changeStatesThree(6);
      }
    }
    pressed = true;
  } else if ((input1 <= 300) && (input2 <= 300) && (input3 <= 300)) {
    pressed = false;
  }

  checkWin();
}

void changeStatesThree(int pin) {
  if (pin == 0) {
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
    ledStates[1] = !ledStates[1];
  } else if (pin == 6) {
    ledStates[5] = !ledStates[5];
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
  } else {
    ledStates[pin - 1] = !ledStates[pin - 1];
    ledStates[pin] = !ledStates[pin];
    ledStates[pin + 1] = !ledStates[pin + 1];
  }
}

void changeStatesFive(int pin) {
  if (pin == 0) {
    ledStates[5] = !ledStates[5];
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
    ledStates[1] = !ledStates[1];
    ledStates[2] = !ledStates[2];
  } else if (pin == 1) {
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
    ledStates[1] = !ledStates[1];
    ledStates[2] = !ledStates[2];
    ledStates[3] = !ledStates[3];
  } else if (pin == 6) {
    ledStates[4] = !ledStates[4];
    ledStates[5] = !ledStates[5];
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
    ledStates[1] = !ledStates[1];
  } else if (pin == 5) {
    ledStates[3] = !ledStates[3];
    ledStates[4] = !ledStates[4];
    ledStates[5] = !ledStates[5];
    ledStates[6] = !ledStates[6];
    ledStates[0] = !ledStates[0];
  } else {
    ledStates[pin - 2] = !ledStates[pin - 2];
    ledStates[pin - 1] = !ledStates[pin - 1];
    ledStates[pin] = !ledStates[pin];
    ledStates[pin + 1] = !ledStates[pin + 1];
    ledStates[pin + 2] = !ledStates[pin + 2];
  }
}

void checkWin() {
  win = true;

  for (int i = 0; i < 7; i++) {
    if (ledStates[i] != true) {
      win = false;
    }
  }

  if (win) {
    for (int i = 0; i <= 7; i++) {
      digitalWrite(i + 2, HIGH);
    }
    delay(500);
    for (int i = 0; i <= 7; i++) {
      digitalWrite(i + 2, LOW);
    }
    delay(500);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(7, HIGH);
    delay(500);
    for (int i = 0; i <= 7; i++) {
      digitalWrite(i + 2, LOW);
    }
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(8, HIGH);
    delay(500);
    for (int i = 0; i <= 7; i++) {
      digitalWrite(i + 2, LOW);
    }
    for (int i = 0; i <= 7; i++) {
      digitalWrite(i + 2, HIGH);
      delay(100);
    }
    for (int i = 7; i >= 0; i--) {
      digitalWrite(i + 2, LOW);
      delay(100);
    }
    for (int i = 0; i <= 7; i++) {
      ledStates[i] = false;
    }
  }
}

