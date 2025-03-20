// Valor a partir del cual sonará el zumbador (si se supera) 
int valor_limite= 80;                     

// Funcion para configurar el estado inicial
void setup() {    
  // Serial es un objeto que representa la comunicación serial. Permite enviar y recibir datos a través de los pines        
  Serial.begin(9600); // Inicia la comunicacion serial a 9600 bits por seg (utilizadopara comunicacion serial)
  // Configura el pin 13 digital para la salida del zumbador
  pinMode(13,OUTPUT);                   
}

// Funcion para ejecutarse siempre
void loop() {     
  // Lee los datos del sensor MQ5, lo guarda en la variable y lo imprime en el monitor serie del IDE de Arduino  
  int valorSensor = analogRead(A0);
  Serial.println(valorSensor);       

  // Si la medida de gas natural es mayor que la puesta como límite...
  if (valorSensor > valor_limite) {  
    // Activa el zumbador en el pin 13 a 2000Hz 
    tone(13, 2000); 
  } else { // Si el valor registrado es menor que el limite...
    noTone(13); // Apaga el Zumbador
  }

  delay (1500); // Espera de 2000ms para volver al principio del bucle
}