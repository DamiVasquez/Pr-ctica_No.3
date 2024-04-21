//Damasco Oxcal 2023442//

/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Catalogo de Productos
   Dev: Profe. Alejandro Lopez Navas
   Fecha: 19 de abril 
*/


  struct Producto { 
  char nombre[50];
  byte cantidad; 
  float precio; 
};

Producto pro1 = {"Doritos", 45, 12.00}; 
Producto pro2 = {"Taqueritos", 45, 15.00};   
Producto pro3 = {"Galletas Rich", 45, 10.50};  
Producto pro4 = {"Ranchitas", 45, 7.00};    

byte no = 1; 
bool mostrar = true; 

//Funcion donde realizo las configuraciones.
void setup() {

  Serial.begin(9600);    //Inicio la comunicación serial.
  Serial.println("Maquina Expendedora");
  Serial.println("Pulsador Izquierda Retrocede, Pulsador Derecha Avanza");
  pinMode(11, INPUT);    //Pin 11 del arduino como entrada.
  pinMode(12, INPUT);    //Pin 12 del arduino como entrada.
}

//Funcion donde se ejecutan de manera "infinita" el código.
void loop() {
  if (mostrar) {
    Serial.print("Producto: ");
    if (no == 1) {
      Serial.println(pro1.nombre);
      Serial.print("Cantidad: ");
      Serial.println(pro1.cantidad);
      Serial.print("Precio: Q");
      Serial.println(pro1.precio, 2);
      Serial.println("-----------------------------------------------------------------------------------------"); 
    }
    if (no == 2) {
      Serial.println(pro2.nombre);
      Serial.print("Cantidad: ");
      Serial.println(pro2.cantidad);
      Serial.print("Precio: Q");
      Serial.println(pro2.precio, 2);
      Serial.println("----------------------------------------------------------------------------------------");
    }
    if (no == 3) {
      Serial.println(pro3.nombre);
      Serial.print("Cantidad: ");
      Serial.println(pro3.cantidad);
      Serial.print("Precio: Q");
      Serial.println(pro3.precio, 2);
      Serial.println("--------------------------------------------------------------------------------------");
    }
    if (no == 4) {
      Serial.println(pro4.nombre);
      Serial.print("Cantidad: ");
      Serial.println(pro4.cantidad);
      Serial.print("Precio: Q");
      Serial.println(pro4.precio, 2);
      Serial.println("-------------------------------------------------------------------------------------");
    }
    mostrar = false;
  }
  if (digitalRead(11) == HIGH) {
    delay(50);
    if (no < 4) {
      no++;
    } else {
      no = 1;
    }
    mostrar = true;
  }
  if (digitalRead(12) == HIGH) {
    delay(50);
    if (no > 1) {
      no--;
    } else {
      no = 4;
    }
    mostrar = true;
  }
  delay(20);
}
