
// zoomkat 7-30-11 serial I/O string test
// type a string in serial monitor. then send or enter
// for IDE 0019 and later

String readString;

void setup() {
  Serial.begin(9600);
  Serial.println("serial test 0021"); // so I can keep track of what is loaded
}

void loop() {

  while (Serial.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    int c = Serial.read();
    Serial.write(c);
  }
  
//    readString += c;
//  }
//
//  if (readString.length() >0) {
//    Serial.println(readString);
//
//    readString="";
//  }
}
