
/* This code is Written by Rahul Bhatia

*/




int LmotorUp = 10; //initialising Arduino port 10 be be called as LmotorUp
int LmotorDn = 11; //initialising Arduino port 11 be be called as LmotorDn
int RmotorUp = 8;  //initialising Arduino port 8 be be called as RmotorUp
int RmotorDn = 9;  //initialising Arduino port 9 be be called as RmotorDn
int left = 6;
int right = 12;




void setup()
{
  Serial.begin(9600);
  // Setting ports as OUTPUTS as they supply signal values to motor driver
  pinMode(LmotorUp, OUTPUT);
  pinMode(LmotorDn, OUTPUT);
  pinMode(RmotorUp, OUTPUT);
  pinMode(RmotorDn, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  Serial.println("Welcome to automatic plant watering system Type 's' to start and press 'r' 'y' 't' to change the rpm or Enter 'd' days to automate watering");
  // A delay of 1 second for user
  delay(1000);
}


void loop()
{
  // Checking is Serial data available
  if (Serial.available() > 0)
  {
    // Storing value of read data into variable assigned
    int input = Serial.read();
    
    switch (input)
    {
      // Calling respective functions if mathced with case label
      case 's' : MoveF();
        Serial.println("System is started! Press h to stop the system");
        break;
      // Here is it important to use '' as that stores the ASCII value is the letter in the variable you can add CAPITAL letters
      case 'r' : MoveB();
        Serial.println("System is started! Press h to stop the system");
        break;
      case 'y' : MoveL();
        Serial.println("System is started! Press h to stop the system");
        break;
      case 't' : MoveR();
        Serial.println("System is started! Press h to stop the system");
        break;
      case 'h' : Stop();
        Serial.println("System is stopped! Press s to start the system");
        break;
      case 'd' : Automate(); 
        Serial.println();
        break;
      default : break;
    }
  }
  delay(50);
}

void MoveF()
{
  Serial.println("RPM has shifted to 100 to show true results the motor should support rpm limits");
  Serial.println("Welcome to automatic plant watering system Type 's' to start and press 'r' 'y' 't' to change the rpm");
  // We are writing a Digital HIGH to the upper left pin of the motor driver for postive polarity of 5V
  digitalWrite(LmotorUp, HIGH);
  // We are writing a Digital LOW to the lower left pin of the motor driver for negative polarity of 0V
  digitalWrite(LmotorDn, LOW);
  // We are writing a Digital HIGH to the upper right pin of the motor driver for postive polarity of 5V
  digitalWrite(RmotorUp, HIGH);
  // We are writing a Digital HIGH to the lower right pin of the motor driver for negative polarity of 0V
  digitalWrite(RmotorDn, LOW);
  // For entering speed to the pins
  digitalWrite(left, 100);
  // We are writing a Digital LOW to the lower right pin of the motor driver
  digitalWrite(right, 100);
}

void MoveB()
{
  Serial.println("RPM has shifted to 1000 to show true results the motor should support rpm limits");
  Serial.println("Welcome to automatic plant watering system Type 's' to start and press 'r' 'y' 't' to change the rpm");
  // We are writing a Digital HIGH to the upper left pin of the motor driver for postive polarity of 5V
  digitalWrite(LmotorUp, HIGH);
  // We are writing a Digital LOW to the lower left pin of the motor driver for negative polarity of 0V
  digitalWrite(LmotorDn, LOW);
  // We are writing a Digital HIGH to the upper right pin of the motor driver for postive polarity of 5V
  digitalWrite(RmotorUp, HIGH);
  // We are writing a Digital HIGH to the lower right pin of the motor driver for negative polarity of 0V
  digitalWrite(RmotorDn, LOW);
  // For entering speed to the pins
  digitalWrite(left, 100);
  // We are writing a Digital LOW to the lower right pin of the motor driver
  digitalWrite(right, 100);

}

void MoveL()
{
  Serial.println("RPM has shifted to 300 to show true results the motor should support rpm limits");
  Serial.println("Welcome to automatic plant watering system Type 's' to start and press 'r' 'y' 't' to change the rpm");
  // We are writing a Digital HIGH to the upper left pin of the motor driver for postive polarity of 5V
  digitalWrite(LmotorUp, HIGH);
  // We are writing a Digital LOW to the lower left pin of the motor driver for negative polarity of 0V
  digitalWrite(LmotorDn, LOW);
  // We are writing a Digital HIGH to the upper right pin of the motor driver for postive polarity of 5V
  digitalWrite(RmotorUp, HIGH);
  // We are writing a Digital HIGH to the lower right pin of the motor driver for negative polarity of 0V
  digitalWrite(RmotorDn, LOW);
  // For entering speed to the pins
  digitalWrite(left, 100);
  // We are writing a Digital LOW to the lower right pin of the motor driver
  digitalWrite(right, 100);

}

void MoveR()
{
  Serial.println("RPM has shifted to 200 to show true results the motor should support rpm limits");
  Serial.println("Welcome to automatic plant watering system Type 's' to start and press 'r' 'y' 't' to change the rpm");
  // We are writing a Digital HIGH to the upper left pin of the motor driver for postive polarity of 5V
  digitalWrite(LmotorUp, HIGH);
  // We are writing a Digital LOW to the lower left pin of the motor driver for negative polarity of 0V
  digitalWrite(LmotorDn, LOW);
  // We are writing a Digital HIGH to the upper right pin of the motor driver for postive polarity of 5V
  digitalWrite(RmotorUp, HIGH);
  // We are writing a Digital HIGH to the lower right pin of the motor driver for negative polarity of 0V
  digitalWrite(RmotorDn, LOW);
  // For entering speed to the pins
  digitalWrite(left, 100);
  // We are writing a Digital LOW to the lower right pin of the motor driver
  digitalWrite(right, 100);


}
void Automate()
{
  Serial.println("Enter days after which watering will start:");
  delay(4000);
  int days = Serial.read();
  String num = String(days);
  Serial.print("After exact "); Serial.print(char(days)); Serial.print(" days watering will automatically starts Thank you");
  
}

void Stop()
{
  //System will stop here
  //Writing a digital LOW to all pins associated with movement of motor driver causes all motors to stop
  digitalWrite(LmotorUp, LOW);
  digitalWrite(LmotorDn, LOW);
  digitalWrite(RmotorUp, LOW);
  digitalWrite(RmotorDn, LOW);
  // The motors will not recieve power
  digitalWrite(right, 00);
  digitalWrite(left, 00);
}
