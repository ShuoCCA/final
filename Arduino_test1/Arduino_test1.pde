
import processing.serial.Serial;

// import arduino

Serial myPort;
String Val;
 int Value;






 void setup(){
 size(800,800);
background(0);
 //printArray(Serial.list());
 String portName = Serial.list()[9];
 myPort = new Serial(this,portName,9600);
 myPort.bufferUntil('.');
 
  ellipseMode(RADIUS);

  frameRate(50);
 
 
 }
 
 void draw (){
 background(0);
  fill(200,0,200);
  textSize(100);
  
  
   
// printArray(Serial.list());
 
 if (myPort.available()>0)
 { Val = myPort.readString();
 
 }
//print("test-");
 //println(Val.trim());
 String testString = Val.trim();
 int i = parseInt(testString);
 float test = map(i, 0, 850, 0, 70);
 float testcolor =map(i, 0, 850, 50, 250);
 println(testString);
 
  text(Val.trim(),600,730);
  fill(testcolor, 100,100);

 ellipse(400,400,test+20,test+20);





 
 
 }
