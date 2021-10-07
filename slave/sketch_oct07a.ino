
// Connect the HC-06 RX to Arduino pin 3 (as TX) through a voltage divider.
 
char c = ' '; //initializes to a space
 
void setup() 
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
 
    // HC-05 default serial speed for communication mode is 9600
    Serial1.begin(9600);  
    Serial.println("BTserial started at 9600");
}
 
void loop()
{
   // Keep reading from HC-05 and send to Arduino Serial Monitor


    if (Serial1.available())
    {  
        c = Serial1.read();
        Serial.write(c);
    }
 
   // Keep reading from Arduino Serial Monitor and send to HC-06
    if (Serial.available())
    {
        c =  Serial.read();

        if(c == 'a'){
          digitalWrite(LED_BUILTIN, HIGH);
        }
        if(c == 'b'){
          digitalWrite(LED_BUILTIN, HIGH);
        }
        
 
        // Copy the serial data back to to the serial monitor. 
        // This makes it easy to follow the commands and replies
        
        Serial.write(c);
        Serial1.write(c);  
    }
 
}
