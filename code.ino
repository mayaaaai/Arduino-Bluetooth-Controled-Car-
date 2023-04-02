int val;

void setup()
{
    Serial.begin(38400);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

void loop()
{
    if (Serial.available() > 0)
    {
        val = Serial.read();
    }


    if(val=='3'){
        Serial.println("Stanga");
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);   
    }

    if(val=='4'){
        Serial.println("Dreapta");
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);   
    }

    if(val=='1'){
        Serial.println("Inainte");
        digitalWrite(2,HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);   
    }
    if(val=='2'){
        Serial.println("Inapoi");
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);   
    }

    if(val=='5'){
        Serial.println("Stop");
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);   
    }
}
