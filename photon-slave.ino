// Photon Tester
// By Jeremy Ellis June 2017
// MIT license





String mySlaveIn;

String Serial_uART  = "Bad";
String Serial_I2C   = "Bad";
String Serial_SPI   = "Bad";




void setup() {

    // Master working photon 
    // Slave unknown photon
    // connect GND to GND
    // on Master TX to slave RX
    // On Master RX to slave TX


    // Photon I2C setup
    // GND master to GND slave
    // D0 (SDA = data) on master to D0 on slave
    // D1 (SCL = clock) on Master to D1 on slave
    // pullup 470 k ohm resistor from D0 to 3V3
    // pullup 470 k ohm resistor from D1 to 3V3
    
    
    
    // following declared in setup

   
//    Serial1.begin(9600);  // only if using this photon as a slave?
    
//    Particle.publish("uART Serial1 started", "On TX and RX", 60, PRIVATE);
//    delay(1000);
    
    
    Wire.begin(8);   // label this slave as # 9
    Wire.onReceive(receiveEvent);
    
    
    // Attach a function to trigger when something is received.

   
    Particle.publish("I2C Wire started", "On D0 (SDA) and D1 (SCL)", 60, PRIVATE);
    delay(1000);
    

    

}


void receiveEvent(int bytes){
    int idx = 0;
    mySlaveIn = "";
    while (Wire.available()) { 
        mySlaveIn += 'H';   // for setCharAt to work the string needs a character to replace
        mySlaveIn.setCharAt(idx, (char)Wire.read() );    // update string

        idx ++;
    } 
}





void requestEvent2() {
    Wire.write('H');         // respond with message of 6 bytes as expected by master
    // careful what code you put here!
}



void requestEvent() {
    Wire.write('F');         // respond with message of 6 bytes as expected by master
    // careful what code you put here!
}






void myUART(){
    // connect second photon and run program using console
    // Schematic needs lines from TX, TR the other for each photon
    


    if (Serial1.available() > 0) {
        
        Particle.publish("Serial1 Available", "---", 60, PRIVATE);
        delay(1000);
        int incomingFromMaster = Serial1.read();
        if (incomingFromMaster == 'A') {
            Serial_uART = "Good";
            Particle.publish("Serial1 working A = 65", String(incomingFromMaster), 60, PRIVATE);
            Serial1.write('B');
            delay(1000);            
            
       } else {Serial_uART = "Bad";}
       
    }
    Particle.publish("uART Serial is", Serial_uART, 60, PRIVATE);
    delay(1000); 
    
   // Serial1.end();  // only if using this photon as a slave?
}    



void myI2C(){
    // connect second photon and run program using console
    // Schematic needs lines from D0, D1
    
   //If value received is 0 blink LED for 200 ms

  //If value received is 3 blink LED for 400 ms
  
  //  Particle.publish("I2C before, x="+String(x), mySlaveIn , 60, PRIVATE);
   // delay(1000);
   // mySlaveIn.replace("_", " ");  //get rid of the remaining characters "_________" using a null char
    //mySlaveIn.remove(mySlaveIn.indexOf("_"));
  // mySlaveIn.remove(x+1);
   
    if (mySlaveIn == "FRed") {
        Wire.onRequest(requestEvent);
        Particle.publish("I2C working", mySlaveIn, 60, PRIVATE);
    }   
    Particle.publish("I2C after "+String( mySlaveIn.length()), mySlaveIn , 60, PRIVATE);

   
   delay(10000); 
    
}



void mySPI(){
    // connect second photon and run program using console
    // Schematic needs lines from A2, A3, A4, A5 to each photon
}




void loop() {

  //  myUART();   // move to photon slave.ino 

    myI2C();

 //   mySPI();

    
    Particle.publish("---", "---", 60, PRIVATE);
    delay(3000);

}
