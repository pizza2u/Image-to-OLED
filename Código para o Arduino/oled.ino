#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Dimensões do OLED (128x64)
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET 4 //Define pino reset do display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Instância de classe
// O objeto 'display' é criado, passando as dimensões do display, e o objeto 'Wire" para comunicação I2C e pino de reset

#define LOGO_HEIGHT   64
#define LOGO_WIDTH    128

//Define a imagem BitMap 
// Obtidas através do software online: https://diyusthad.com/image2cpp
const unsigned char logo_bmp [] PROGMEM = {
  0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0x00, 
	0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xfe, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x06, 0x01, 0xc0, 0x20, 0x01, 0xe0, 0x01, 0x8f, 0xff, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xc0, 0x20, 0x03, 0xfe, 0x0f, 0x8f, 0xff, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xe0, 0x00, 0x03, 0xff, 0xff, 0x9f, 0xff, 0xf8, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xf0, 0x00, 0x01, 0xff, 0xff, 0x9f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x03, 0xf0, 0x00, 0x00, 0x3f, 0xfe, 0x9f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0xe0, 0xbf, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1f, 0x07, 0xf0, 0x00, 0x00, 0x03, 0x80, 0xbf, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x07, 0xf0, 0x00, 0x00, 0x03, 0x80, 0xbf, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x07, 0xf0, 0x20, 0x01, 0xe3, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x0f, 0xf0, 0x20, 0x0f, 0xf3, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x8f, 0xf0, 0x60, 0x0f, 0xf7, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x9f, 0xf0, 0x60, 0x07, 0xe3, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x9f, 0xf0, 0xe0, 0x07, 0xe7, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x9f, 0xf1, 0xf0, 0x03, 0xc7, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x9f, 0xf7, 0xf0, 0x03, 0xc7, 0xff, 0xff, 0xff, 0x40, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x01, 0x83, 0xff, 0xff, 0xff, 0x20, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x81, 0xff, 0xff, 0xd0, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x01, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xbf, 0x00, 0x80, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x7f, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0xfe, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xf1, 0xfc, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe0, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void setup() { //Faz a comunicação com o Display OLED, e exibe uma mensagem de erro de alocação falha chamando a função testebitmap()
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Endereço 0x3D para 128x64
    Serial.println(F("Falha na alocação da Biblioteca"));
    for(;;); // Loop Infinito
// O loop infinito for(;;); é utilizado para interromper o programa caso a inicialização da biblioteca SSD1306 (utilizada para controlar um display OLED) falhe. 
// A linha de código Serial.println(F("Falha na alocação da Biblioteca")); imprime uma mensagem de erro e, em seguida, o loop infinito é executado com for(;;);, fazendo com que o programa fique preso nesse loop e não prossiga para o restante do código.
  }

  testebitmap();    // Faz o formato da imagem necessária
}

void loop() {
}

void testebitmap(void) { // Desenha a imagem bitmap no centro do display com a função drawBitmap()
  display.clearDisplay();

  display.drawBitmap( // Desenha um bitmap no display
    (display.width()  - LOGO_WIDTH ) / 2, // Calcula a posição centralizada x onde o bitmap será desenhado
    (display.height() - LOGO_HEIGHT) / 2, // Calcula a posição centralizada y onde o bitmap será desenhado
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1); // logo_bmp é a variável que contém o bitmap que vai ser desenhado
    // O valor 1 indica que o bitmap está em escala cinza
  display.display(); // Atualiza o display
  delay(1000);
}