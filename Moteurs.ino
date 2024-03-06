// Moteur Droite
int ENB = 8;
int IN4 = 9;  // arrière
int IN3 = 10; // avant

// Moteur Gauche
int ENA = 3;
int IN1 = 4;  // avant
int IN2 = 5;  // arrière

// Déclaration des broches pour les capteurs infrarouges
const int capteurGauche = 7;
const int capteurDroit = 6;

void setup() {
  // Initialisation des broches en tant qu'entrées
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  // Gestion de la vitesse des moteurs
  analogWrite(ENB, 150);  
  analogWrite(ENA, 150);

  // Initialisation des broches en tant qu'entrées
  pinMode(capteurGauche, INPUT);
  pinMode(capteurDroit, INPUT);

  // Démarrage de la communication série pour afficher les résultats
  Serial.begin(9600);
}

void loop() {
  // Lecture des valeurs des capteurs infrarouges
  int valeurGauche = digitalRead(capteurGauche);
  int valeurDroit = digitalRead(capteurDroit);

  // Vérification des valeurs des capteurs et affichage du résultat
  if (valeurGauche == HIGH && valeurDroit == LOW) {
    Serial.println("Tourne à droite");
    tournerDroite();
  } else if (valeurGauche == LOW && valeurDroit == HIGH) {
    Serial.println("Tourne à gauche");
    tournerGauche();
  } else if (valeurGauche == HIGH && valeurDroit == HIGH) {
    Serial.println("Marche arrière");
    reculer();
    delay(1000);  // Adjust the delay to approximate a 90-degree turn
    arreter();    // Stop the robot after turning
    Serial.println("Tourne à droite (90 degrés)");
    tournerDroite();
    delay(1000);  // Adjust the delay to control the turn duration
    arreter();    // Stop turning
    Serial.println("Continue tout droit");
    avancer();
  } else {
    Serial.println("Tout droit");
    avancer();
  }

  // Attente pour éviter un rafraîchissement trop rapide
  delay(100);
}

void reculer() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void arreter() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void avancer() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tournerDroite() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void tournerGauche() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
