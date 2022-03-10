


#define led 13




int s1,s2,range;
char dir;
unsigned long lastm;



void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);

digitalWrite(led,0);

range=100;
dir='x';

}//setup




void loop() {
s1=analogRead(A0);
s1=analogRead(A1);
delay(50);



if (s1>range){//sensor 1 detects object
  
if(dir=='x'){//if the last movement was unkown
dir='o';//movement is out going 
lastm=millis();  //give 2 seconds before ignoring the direction
}

if(dir=='i'){//sensor 2 is trigger first
Serial.println("direction is IN");
dir='x';
delay(1000);
}

}





if (s2>range){//sensor 2 detects object
  
if(dir=='x'){//if the last movement was unkown
dir='i';//movement is in going 
lastm=millis();  //give 2 seconds before ignoring the direction
}

if(dir=='o'){//sensor 1 is trigger first
Serial.println("direction is OUT");
dir='x';
delay(1000);
}

}


if(millis()-lastm>2000){//clear the direction flag every 2 seconds
dir='x';

lastm=millis();  
}

}//lop
