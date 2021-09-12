  int LED = 11;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)
int ADC0 = 0; // set the 0 analog input port ADC port here
float light_value = 0; // here we will store the value detected by the LDR
int LED_brightness; // store the brightness value in this variable


void setup() {
  pinMode(LED, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){
  val = digitalRead(sensor);   // read sensor value
  Serial.println(val);
  
  if (val == HIGH) { // check if the sensor is HIGH
     Serial.println("occupied");
    light_value = analogRead(ADC0); // get the value from LDR 0..550 +/-
      Serial.print("LDR reading: ");
      Serial.println(light_value); // print the LDR read value
        
      // the lower the light, the brighter the LED
      LED_brightness = (light_value / 2);
      if (LED_brightness > 255)LED_brightness = 255; // make sure the value is not more than 255
      LED_brightness = map(LED_brightness,0,255,255,0);
        
        
      //analogWrite(LED, LED_brightness); // set the brightness of the LED
        
      // DEBUG information printed to Serial port
      Serial.print("LED brightness: ");
      Serial.println(LED_brightness);
        
      delay(50); // delay for 50 ms before another loo1
           
    //digitalWrite(LED, HIGH);   // turn LED ON
     analogWrite(LED, LED_brightness); // set the brightness of the LED
    
    delay(500);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
       
        
  
        
    }
  } 
  else {
      digitalWrite(LED, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
  
 
}
