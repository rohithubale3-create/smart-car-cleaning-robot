// Motor A — Left Motors (FL + BL)
#define ENA 5    // PWM speed pin - Left
#define IN1 6    // Direction pin 1 - Left
#define IN2 7    // Direction pin 2 - Left

// Motor B — Right Motors (FR + BR)
#define ENB 11   // PWM speed pin - Right
#define IN3 8    // Direction pin 1 - Right
#define IN4 9    // Direction pin 2 - Right

// LED indicator
const int ledPin = 13;

int valSpeed = 180;
String inputString = "";

void setup() {
  Serial.begin(9600);
  Serial.println("=== DEBUG: setup() started ===");

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("DEBUG: All pins set as OUTPUT");

  digitalWrite(ledPin, HIGH);
  Serial.println("DEBUG: LED ON");

  SetSpeed(valSpeed);
  Serial.print("DEBUG: Initial speed set to -> ");
  Serial.println(valSpeed);

  stopAllMotors();
  Serial.println("DEBUG: Motors stopped");

  Serial.println("=== DEBUG: setup() complete. Waiting for commands... ===");
}

void loop() {
  while (Serial.available() > 0) {
    char inChar = Serial.read();

    if (inChar == '\n') {
      Serial.print("DEBUG: Full command received -> [");
      Serial.print(inputString);
      Serial.println("]");
      processCommand(inputString);
      inputString = "";
    } else {
      inputString += inChar;
      Serial.print("DEBUG: Char buffered -> ");
      Serial.println(inChar);
    }
  }
}

void processCommand(String command) {
  Serial.print("DEBUG: processCommand() called with -> ");
  Serial.println(command);

  if (command.length() == 0) {
    Serial.println("DEBUG: Empty command, ignoring.");
    return;
  }

  char cmd = command.charAt(0);
  Serial.print("DEBUG: Parsed command char -> ");
  Serial.println(cmd);

  switch (cmd) {
    case 'F':
      Serial.println("DEBUG: Moving FORWARD");
      moveForward();
      break;

    case 'B':
      Serial.println("DEBUG: Moving BACKWARD");
      moveBackward();
      break;

    case 'R':
      Serial.println("DEBUG: Turning RIGHT");
      turnRight();
      break;

    case 'L':
      Serial.println("DEBUG: Turning LEFT");
      turnLeft();
      break;

    case 'S':
      Serial.println("DEBUG: STOP command received");
      stopAllMotors();
      break;

    case '1': Serial.println("DEBUG: Speed -> 65");  SetSpeed(65);  break;
    case '2': Serial.println("DEBUG: Speed -> 130"); SetSpeed(130); break;
    case '3': Serial.println("DEBUG: Speed -> 195"); SetSpeed(195); break;
    case '4': Serial.println("DEBUG: Speed -> 255"); SetSpeed(255); break;

    default:
      Serial.print("DEBUG: Unknown command -> ");
      Serial.println(cmd);
      break;
  }
}

// ========== MOVEMENT FUNCTIONS ==========

void moveForward() {
  // Left motors forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  // Right motors forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("DEBUG: moveForward() -> IN1=H, IN2=L, IN3=H, IN4=L");
}

void moveBackward() {
  // Left motors backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  // Right motors backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("DEBUG: moveBackward() -> IN1=L, IN2=H, IN3=L, IN4=H");
}

void turnRight() {
  // Left motors forward, right motors backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("DEBUG: turnRight() -> Left FWD, Right BWD");
}

void turnLeft() {
  // Left motors backward, right motors forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("DEBUG: turnLeft() -> Left BWD, Right FWD");
}

void stopAllMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("DEBUG: stopAllMotors() -> All IN pins LOW");
}

void SetSpeed(int val) {
  valSpeed = val;
  analogWrite(ENA, val);
  analogWrite(ENB, val);
  Serial.print("DEBUG: SetSpeed() -> ENA and ENB set to ");
  Serial.println(val);
}
