/* Coódigo utilizado en Arduino Nano
  -> Sensor MQ5:
      - A0 conectado al A0 de Arduino Nano
      - GND conectado al GND de los analógicos
      - VCC conectado a 5V del Arduino Nano

  -> Zumbador pasivo:
      - Positivo conectado al pin D4
      - Negativo conectado al GND de los pines digitales    
*/

// Valor a partir del cual sonará el zumbador (si se supera) 
int valor_limite= 150;                     

// Funcion para configurar el estado inicial
void setup() {    
  // Serial es un objeto que representa la comunicación serial. Permite enviar y recibir datos a través de los pines        
  Serial.begin(9600); // Inicia la comunicacion serial a 9600 bits por seg (utilizadopara comunicacion serial)
  // Configura el pin 4 digital para la salida del zumbador
  pinMode(4,OUTPUT);     

  // Bucle para hacer 2 pitidos al inicio del programa
  for (int i = 0; i < 2; i++) {
    tone(4, 1000); // Emite un tono de 1000 Hz
    delay(100);    // Espera 100 ms
    noTone(4);     // Apaga el zumbador
    delay(100);    // Espera 100 ms antes del siguiente pitido
  }     
}

// Funcion para ejecutarse siempre
void loop() {     
  // Lee los datos del sensor MQ5, lo guarda en la variable y lo imprime en el monitor serie del IDE de Arduino  
  int valorSensor = analogRead(A0);
  Serial.println(valorSensor);       

  // Si la medida de gas natural es mayor que la puesta como límite...
  if (valorSensor > valor_limite) {  
    // Activa el zumbador en el pin 4 a 2000Hz 
    tone(4, 2000); 
  } else { // Si el valor registrado es menor que el limite...
    noTone(4); // Apaga el Zumbador
  }

  delay (1500); // Espera de 2000ms para volver al principio del bucle
}