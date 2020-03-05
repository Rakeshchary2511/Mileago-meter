#include&lt;LiquidCrystal.h&gt; // including Liquid Crystal
display
LiquidCrystal lcd (7,9,10,11,12,13); /*Setting pin configuration to

Arduino*/

int trigPin =3; //setting trigger pin of sensor
int echoPin = 2; // setting echo pin of sensor
void setup () { //programming starts
long duration, distance; //variables initialization
float k, v, f; //variables initialization
Serial.begin(9600); /* beginning of
microprocessor with 9600 baud
rate*/

pinMode (trigPin, OUTPUT); //setting trigPin as output
pinMode (echoPin, INPUT); //setting echoPin as input
digitalWrite (trigPin, HIGH); /*applying voltage by
making trigPin high. */
delayMicroseconds (2); //delaying for 2 microseconds
digitalWrite (trigPin, LOW); //making trigPin low
duration = pulseIn (echoPin, HIGH); //delaying for 2 microseconds
distance = (duration/2)/29.1; /*calculating distance

of object placed*/

Serial.println(distance); /*printing distance in serial

monitor*/

k = (21 - distance); /*calculating effective
height upto where the fuel was filled up.
*/

v = ((22/7) *3.5*3.5*k); /*calculating volume of the

fuel present*/
lcd.begin (16,2); // starting up lcd
lcd.clear (); // this function clears the screen
f=v/1000; // effective volume in in litres
dis(f); /*calling “dis”
function by passing volume as parameter.
*/

lcd.print(&quot;10kmph-&gt;&quot;); /*printing first variable

speed i.e. 10kmph on lcd*/
lcd.print(51*f); //first value approximation
lcd.print (&quot; km &quot;); //printing along with calculated value

dis(f);
delay (3000);
lcd.print(&quot;20kmph-&gt;&quot;);
lcd.print(54*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;30kmph-&gt;&quot;);
lcd.print(56*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;40kmph-&gt;&quot;);
lcd.print(60*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;50kmph-&gt;&quot;);
lcd.print(58*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;60kmph-&gt;&quot;);
lcd.print(56*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;70kmph-&gt;&quot;);
lcd.print(50*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;80kmph-&gt;&quot;);
lcd.print(44*f);
lcd.print (&quot; km &quot;);
dis(f);
delay (3000);
lcd.print(&quot;90kmph-&gt;&quot;);
lcd.print(28*f);
lcd.print (&quot; km &quot;);
}
void loop () { //acts like while(1){. . . . . };
// put your main code here, to run repeatedly
}
void dis (float p) { // function displays the fuel and

set //cursor to next row

delay (1000);

lcd.clear ();
lcd.print (p);
lcd.print (&quot; litres&quot;);
lcd.setCursor (0,1);
}
