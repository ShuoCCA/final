#include<IRremote.h>
#include <Servo.h>

Servo myservo; 

int IR = 7;
IRrecv irrecv(IR);
decode_results irIn;
//define ir reciver

int sensorpin = A4;   
int speedval = 0;  

int led = 12;
//define pin code
int pressureSensorPin = A1;

char val;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

const int leftForward = 2; 
const int leftBackward = 3; 
const int rightForward = 4; 
const int rightBackward = 5;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  irrecv.enableIRIn();

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  


   pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5, OUTPUT);




myservo.attach(3);

  
}


void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
  
}


void decodeIR ( ) 
// This will tell us which key Is pressed.
{


   Serial.println("aaaaaaaa");
  switch (irIn.value)
  {


   
   // lack 1379
      
       case 0xFF30CF: 
  Serial.println( "1" );
     break;
      
      case 0xFF629D: 
 Serial.println( "2" );
     break;

    case 0xFF7A85:
 Serial.println( "3" );
    break;


    case 0xFF22DD:
  Serial.println( "4" );
    break;
    
      case 0xFF02FD:
  Serial.println ( "5" ) ;
       break;
       
 
      case 0xFFC23D:
    Serial.println ( "6" ) ;
      break;

         case 0xFF42BD:
    Serial.println ( "7" ) ;
      break;


      case 0xFFA857:
    Serial.println ( "8" ) ;
      break ;
      
      case 0xFF52AD:
    Serial.println ( "9" ) ;
      break ;
/////////////

 case 0xFFB04F :
   Serial.println ( "#" ) ;
     setColor(255,255,255);
       break;

 case 0xFF6897:
 // Serial.println ( "*" ) ;
 //Serial.println ( "333" ) ;
  setColor(0,0,0);

  digitalWrite(2 , LOW);
  digitalWrite(3 , LOW);
    digitalWrite(4 , LOW);
    digitalWrite(5 , LOW);
    break;
  
    break;

    case 0xFF9867:
  Serial.println ( "0" ) ;

     setColor(0, 255, 255);  // aqua
  delay(100);
    break;


    case 0xFF38C7:
 Serial.println( "ok" );
     setColor(255, 0, 0);  // red
  delay(100);
    break;

    case 0xFF10EF :
   Serial.println ( " left" ) ;
    setColor(0, 255, 0);  // green

    digitalWrite(2 , LOW);
  digitalWrite(3 , HIGH);

  digitalWrite(4 , LOW);
  digitalWrite(5 , HIGH);

    
  delay(100);
    break;

    case 0xFF5AA5:
    Serial.println ( "right " ) ;
     setColor(0, 0, 255);  // blue

digitalWrite(3 , LOW);
  digitalWrite(2 , HIGH);

  digitalWrite(5 , LOW);
  digitalWrite(4 , HIGH);

     
  delay(100);
     break;

    case 0xFF18E7 :
  Serial.println ( " uppppppppppppppppppppppp" ) ;
     setColor(255, 255, 0);  // yellow
  delay(100);  
    break;
    
  case 0xFF4AB5 :
 Serial.println ( "down " );
    setColor(255, 0, 255);  // purple
  delay(100);
       break;





    default:
    break;

  }


  }



  void loop() {
    // put your main code here, to run repeatedly:
    int pressureSensorState = analogRead(pressureSensorPin);
speedval = analogRead(sensorpin); 
 // int pressureSensorState2 = Serial.parseInt();
//Serial.println(speedval); 


 //Serial.println (pressureSensorState);
//     myservo.write(pressureSensorState);
   
    //Serial.println ("~");
    //Serial.println("Hello, world!");
    // print pressure in test window
    //Serial.write(pressureSensorState);
    //delay(10);


    if (speedval > 350) {
      digitalWrite(led, HIGH);
      delay(10);
    }
    else {
      digitalWrite(led, LOW);
    }
    delay(10);


    if (irrecv.decode(&irIn ) ) {

      decodeIR ( ) ;

      irrecv.resume ( ) ;



    }



    delay(50); // Slows down writing to Serial so there is less lag in Processing
  }


