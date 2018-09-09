#include <Servo.h> // including servo library and declaring and naming them below
Servo bicep1L;     // hi tech 2
Servo bicep1R;     // hi tech 9
Servo bicep2L;     // hi tech 30
Servo bicep2R;     // hi tech 35
Servo shoulder1L;  // hi tech 31
Servo shoulder2L;  // hi tech 32
Servo shoulder1R;  // hi tech 36
Servo shoulder2R;  // hi tech 37
Servo FaceUD;
Servo FaceRL;      // hi tech 38

Servo F1L; // Pins for fingers,thumb and wrist motors on the left hand= 3,4,5,6,7,8.
Servo F2L;
Servo F3L;
Servo F4L;
Servo TL;
Servo WL;

Servo F1R; // Pins for fingers, thumb and wrist motors on the right hand = 10,13,40,41,42,43.
Servo F2R;
Servo F3R;
Servo F4R;
Servo TR;
Servo WR;

bool flag = 0, flag1 = 0, val = 0, val1 = 0, flag2 = 0; //used flag in fingers open close and bicep
char cmd; // cmd to store command sent via bluetooth

void facerightleft() { //Letter A
  if (cmd == 'A') { // comparing the cmd with set values to provide choice of movement
    FaceRL.write(10);
    delay(200);
    FaceRL.write(90);
  }
  else if (cmd == 'a') {
    FaceRL.write(170);
    delay(200);
    FaceRL.write(90);
  }
}

void mouthupdown() { //Letter B
  if (cmd == 'B') {
    if (flag2 == 0) {
      FaceUD.write(100);
    }
    if (flag2 ==  1) {
      FaceUD.write(160);
    }
    flag2 = !flag2;
  }
}

void bicepleft() { //Letters C and D
  //Bicep 1
  if (cmd == 'C') { // elbow left relax movement
    if (val == 0) { // setting boolean to restrict movement to once only as to not cause damage to hardware
      bicep1L.write(10); // degree 1
      delay(1000); // delay dictates the time for which the motor keeps rotating. Not precise.
      bicep1L.write(90); // degree 2; degree2-1 sets the speed of rotation
      val = !val; // Changin the boolean value to avoid flex movement twice at a time
    }
  }
  else if (cmd == 'c') {
    if (val == 1) { // elbow left flex movement
      bicep1L.write(170);
      delay(1350);
      bicep1L.write(90);
      val = !val;
    }
  }

  //Bicep 2 Left
  else if (cmd == 'D') { // shoulder rotation of left hand
    bicep2L.write(10);
    delay(750);
    bicep2L.write(90);
  }
  
  else if (cmd == 'd') {// shoulder rotation of left hand
    bicep2L.write(170);
    delay(750);
    bicep2L.write(90);
  }
}

void bicepright() { //Letters E and F
  if (cmd == 'E') { // relax movement of right elbow
    if (val1 == 0) {
      bicep1R.write(10);
      delay(1000);
      bicep1R.write(90);
      val1 = !val1;
    }
  }
  else if (cmd == 'e') { // flex movement of right elbow
    if (val1 == 1) {
      bicep1R.write(170);
      delay(1350);
      bicep1R.write(90);
      val1 = !val1;
    }
  }
  else if (cmd == 'F') { // shoulder rotation of right hand
    bicep2R.write(10);
    delay(250);
    bicep2R.write(90);
  }
  else if (cmd == 'f') { // shoulder rotation of right hand
    bicep2R.write(170);
    delay(250);
    bicep2R.write(90);
  }
}

void shoulderleft() { //Letter G and H
  if (cmd == 'G') { // shoulder vertical of left hand
    shoulder1L.write(10);
    delay(750);
    shoulder1L.write(90);
  }
  else if (cmd == 'g') { // shoulder vertical of left hand
    shoulder1L.write(170);
    delay(750);
    shoulder1L.write(90);
  }
  else if (cmd == 'H') { // shoulder vertical of left hand
    shoulder2L.write(10);
    delay(500);
    shoulder2L.write(90);
  }
  else if (cmd == 'h') { // shoulder vertical of left hand
    shoulder2L.write(170);
    delay(500);
    shoulder2L.write(90);
  }
}

void shoulderright() { //Letters I and J
  if (cmd == 'I') {  // shoulder vertical of right hand
    shoulder1R.write(10);
    delay(750);
    shoulder1R.write(90);
  }
  else if (cmd == 'i') { // shoulder vertical of right hand
    shoulder1R.write(170);
    delay(750);
    shoulder1R.write(90);
  }
  else if (cmd == 'J') { // shoulder vertical of right hand
    shoulder2R.write(10);
    delay(500);
    shoulder2R.write(90);
  }
  else if (cmd == 'j') { // shoulder vertical of right hand
    shoulder2R.write(170);
    delay(500);
    shoulder2R.write(90);
  }
}

void leftfingers() { //Letters K to P
  if (cmd == 'K') { // Open
    F1L.write(170);
  }
  else if (cmd == 'k') {//Close
    F1L.write(10);
  }
  else if (cmd == 'L') {
    F2L.write(170);
  }
  else if (cmd == 'l') {
    F2L.write(10);
  }
  else if (cmd == 'M') {
    F3L.write(180);
  }
  else if (cmd == 'm') {
    F3L.write(10);
  }
  else if (cmd == 'N') {
    F4L.write(10);
  }
  else if (cmd == 'n') {
    F4L.write(170);
  }
  else if (cmd == 'O') {
    TL.write(10);
  }
  else if (cmd == 'o') {
    TL.write(170);
  }
  else if (cmd == 'P') {
    WL.write(60);
  }
  else if (cmd == 'p') {
    WL.write(150);
  }
}

void rightfingers() { //Letters Q to V
  if (cmd == 'Q') { // Open
    F1R.write(10);
  }
  else if (cmd == 'q') {//Close
    F1R.write(170);
  }
  else if (cmd == 'R') {
    F2R.write(10);
  }
  else if (cmd == 'r') {
    F2R.write(170);
  }
  else if (cmd == 'S') {
    F3R.write(10);
  }
  else if (cmd == 's') {
    F3R.write(170);
  }
  else if (cmd == 'T') {
    F4R.write(10);
  }
  else if (cmd == 't') {
    F4R.write(170);
  }
  else if (cmd == 'U') {
    TR.write(170);
  }
  else if (cmd == 'u') {
    TR.write(10);
  }
  else if (cmd == 'V') {
    WR.write(60);
  }
  else if (cmd == 'v') {
    WR.write(150);
  }
}

void allleftfingers() { //Letter W
  if (cmd == 'W') {
    if (flag1 == 0) {
      TL.write(10);
      delay(300);
      F1L.write(170);
      F2L.write(170);
      F3L.write(180);
      F4L.write(10);
    }
    if (flag1 == 1) {
      F1L.write(10);
      F2L.write(10);
      F3L.write(10);
      F4L.write(170);
      delay(300);
      TL.write(170);
    }
    flag1 = !flag1;
  }
}

void allrightfingers() { //Letter X 
  if (cmd == 'X') {
    if (flag == 0) {
      TR.write(170);
      delay(300);
      F1R.write(10);
      F2R.write(10);
      F3R.write(10);
      F4R.write(10);
    }
    if (flag == 1) {
      F1R.write(170);
      F2R.write(170);
      F3R.write(170);
      F4R.write(170);
      delay(300);
      TR.write(10);
    }
    flag = !flag;
  }
}

void handshake(){ //Letter Y
  if (cmd == 'Y'){
    //Open all fingers
    TR.write(170);
    delay(300);
    F1R.write(10);
    F2R.write(10);
    F3R.write(10);
    F4R.write(10);
    
    flag = 1;
    flag1 = 1;
  
    //Take bicep and shoulder on position
    bicep1R.write(170);
    delay(1350);
    bicep1R.write(90);
      
    shoulder1L.write(170);
    delay(2000);
    shoulder1L.write(90);
  
    bicep2R.write(10);
    delay(2000);
    bicep2L.write(90);

    TR.write(100);
    F1R.write(40);
    F2R.write(40);
    F3R.write(40);
    F4R.write(30);
    
    delay(1000);
  
    //Back to normal position
    TR.write(170);
    delay(300);
    F1R.write(10);
    F2R.write(10);
    F3R.write(10);
    F4R.write(10);
    
    bicep2R.write(170);
    delay(2000);
    bicep2R.write(90);
  
    shoulder1R.write(10);
    delay(2000);
    shoulder1R.write(90);  
  
    bicep1R.write(10);
    delay(1000);
    bicep1R.write(90);
  }
}

void setup() {
  Serial.begin(38400); // Setting the baud rate
  FaceRL.attach(38); //.......Letter A
  FaceUD.attach(33); //.......Letter B
  bicep1L.attach(2); //......Letter C         Elbow of left hand, 1200 delay
  bicep2L.attach(30); //.....Letter D         Shoulder rotation of left
  bicep1R.attach(9);//.......Letter E         Elbow of right hand 1200 delay
  bicep2R.attach(35);//......Letter F         Shoulder rotation of left
  shoulder1L.attach(31);//...Letter G         Vertical or horizontal movement of left
  shoulder2L.attach(32);//...Letter H         Vertical or horizontal movement of left
  shoulder1R.attach(36);//...Letter I         Vertical or horizontal movement of right
  shoulder2R.attach(37);//...Letter J         Vertical or horizontal movement of right

  //Left Fingers
  F1L.attach(4);//...........Letter K
  F2L.attach(5);//...........Letter L
  F3L.attach(6);//...........Letter M
  F4L.attach(7);//...........Letter N
  TL.attach(3);//............Letter O
  WL.attach(8);//............Letter P

  //Right Fingers
  F1R.attach(13);//..........Letter Q
  F2R.attach(40);//..........Letter R
  F3R.attach(41);//..........Letter S
  F4R.attach(42);//..........Letter T
  TR.attach(10);//...........Letter U
  WR.attach(43);//...........Letter V

  //Open all Fingers
  F1L.write(170);//finger open
  F2L.write(170);
  F3L.write(180);
  F4L.write(10);// this finger is open at 10(opp)
  TL.write(10);// this finger is open at 10(opp)
  WL.write(90);

  F1R.write(10);//finger open
  F2R.write(10);
  F3R.write(10);
  F4R.write(10);
  TR.write(170);// this finger is open at 10(opp)
  WR.write(90);

}

void loop() {
  if (Serial.available()) {
    cmd = Serial.read(); // Recognising the command set by controller
    facerightleft();
    mouthupdown();
    bicepleft();
    bicepright();
    shoulderleft();
    shoulderright();
    leftfingers();
    rightfingers();
    allleftfingers();
    allrightfingers();
    if (cmd == 'Z'){
      WL.write(180);
    }
    if (cmd == 'z'){
      WR.write(0);
    }
  }
}
