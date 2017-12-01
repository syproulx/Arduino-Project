//Test l envoie de charactere sur le port serie vers le PC
//

char receivedChar;
boolean newData = false;

void setup() {
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
}

void loop() {
 recvOneChar();
 showNewData();
}

void recvOneChar() {
 if (Serial.available() > 0) {
   receivedChar = Serial.read();
   newData = true;
 }
}
//test pour git
void showNewData() {
 if (newData == true) {
   //Pour pouvoir afficher dans le moniteur serie Arduino un string avec une variable sur la 
   //meme commande il faut utilsier la sybtaxe suivante
   Serial.println(String("This just in ... ") + receivedChar);
   //Serial.println(receivedChar);
   newData = false;
 }
}



