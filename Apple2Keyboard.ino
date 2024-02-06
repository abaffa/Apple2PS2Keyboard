/****************************************************************************
 * Apple][+ Keyboard Emulator v1 by Augusto Baffa, augbaffa@gmail.com, October, 27th 2023
 * based on Tek-Keyboard Emulator v2 by Daniel Jos� Viana, danjovic@hotmail.com
*/

#include "ps2.h" //  PS2 library by Chris J. Kiick

/****************************************************************************
   ___       __ _      _ _   _
  |   \ ___ / _(_)_ _ (_) |_(_)___ _ _  ___
  | |) / -_)  _| | ' \| |  _| / _ \ ' \(_-<
  |___/\___|_| |_|_||_|_|\__|_\___/_||_/__/

*/

// Uncomment the line below to enable debug.
//#define DEBUG

#define Pin_PS2_DAT A5
#define Pin_PS2_CLK A4

#include "Apple2scancodesToKeycodes.h"

/****************************************************************************
  __   __        _      _    _
  \ \ / /_ _ _ _(_)__ _| |__| |___ ___
   \ V / _` | '_| / _` | '_ \ / -_|_-<
    \_/\__,_|_| |_\__,_|_.__/_\___/__/

*/


PS2 kbd(Pin_PS2_CLK, Pin_PS2_DAT);

bool EXT = false;
bool BRK = false;

/****************************************************************************
   ___             _   _
  | __|  _ _ _  __| |_(_)___ _ _  ___
  | _| || | ' \/ _|  _| / _ \ ' \(_-<
  |_| \_,_|_||_\__|\__|_\___/_||_/__/

*/

//
// Initialize Keyboard
//
bool kbd_init()
{
  char ack;

#ifdef DEBUG
  Serial.print("\nInit KBD:");
#endif

  kbd.write(0xff);  // send reset code
  ack = kbd.read();  // byte, kbd does self test

#ifdef DEBUG
  Serial.print("[");
  Serial.print(ack,HEX);
  Serial.print("]");    
#endif

  ack = kbd.read();  // another ack when self test is done

#ifdef DEBUG
  Serial.print("[");
  Serial.print(ack,HEX);
  Serial.print("]");    
#endif

  return true;
}


/****************************************************************************
     _          _      _             ___     _
    /_\  _ _ __| |_  _(_)_ _  ___   / __|___| |_ _  _ _ __
   / _ \| '_/ _` | || | | ' \/ _ \  \__ Y -_)  _| || | '_ \
  /_/ \_\_| \__,_|\_,_|_|_||_\___/  |___|___|\__|\_,_| .__/
                                                   |_|
*/
void setup()
{


  cli();
  
#ifdef DEBUG
  Serial.begin(9600);
  Serial.print("\n\rInit\n\r");
#endif

  //CLK.CLK.Enabled.Ps2Clk.Ps2dat.A11.A10.A12
  DDRD = 0xFF ;  // output
  PORTD = 0x00;
  
  // Initialize PS/2 keyboard
  kbd_init();
  
  //DDRB = 0x00 ;  // all pins from port B as inputs
  //PORTB = 0x00;

  DDRB &= ~(1 << DDB1); // Seta D12 como entrada;
  PORTB |= (1 << PORTB1); // Liga Pull-up;
  // Seta as "chaves" necessárias para que a interrupção chegue a seu vetor;
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT0)|(1 << PCINT1);

  ///////////// A13 Timer Setup
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
 
  TCNT1 = 0xF244;                    // incia timer com valor para que estouro ocorra em 242ms
                                     // 65536-(16MHz/1024/4Hz) = 969.8842975 = 0x3CA
  
  TIMSK1 |= (1 << TOIE1);           // Enable TIMER1 interruption
  ///////////

#ifdef DEBUG
  Serial.print("\n\rInit Keyboard \n\r");
#endif

   sei();

}

ISR(PCINT0_vect) {

  // bit7 = indicates keyboard off
  if (PINB & (1 << PINB1)) { //low to high
    PORTD = 0x0;
  }
  else { // high to low
    PORTD = 0x0;
  }
}

ISR(TIMER1_OVF_vect) // TIMER1 interrupt
{
  TCNT1 = 0xF244;     // Restart TIMER
  PORTD = 0x0;
}
/****************************************************************************
   __  __      _        _
  |  \/  |__ _(_)_ _   | |   ___ ___ _ __
  | |\/| / _` | | ' \  | |__/ _ Y _ \ '_ \
  |_|  |_\__,_|_|_||_| |____\___|___/ .__/
                                  |_|
*/
void loop()
{
  uint8_t code;
  uint8_t m;
  bool shift = false;
  bool ctrl = false;
  PORTD = 0x0; 
  
  // Loop principal de leitura do teclado PS/2 e atualização da matriz 
  for (;;) {
    
    code=kbd.read(); 

#ifdef DEBUG
    Serial.print("Read:"); 
    Serial.print(code,HEX); 
    Serial.print(" ;");
#endif   

    // Clean keyboard matrix on buffer overflows
    if ( (code == 0x00) | (code == 0xff) ) {  // Error codes
     //clearMatrix();
      shift = false;
      ctrl = false;
      EXT = false;
      BRK = false;
    } else { // not error codes

      if (code==0xE0)         EXT = true;
      else if (code==0xF0)  BRK = true;

      else {
			  
        if (EXT == true) {  // extended keys
          EXT = false;
          
          if (BRK == true) { // break code
            BRK = false;    
          }
          else{
          switch (code) {
            case _PS2_UP_ARROW:     m = _KEY_K - 0x40;     ; break;
            case _PS2_DOWN_ARROW:   m = _KEY_J - 0x40;     ; break;
            case _PS2_LEFT_ARROW:   m = _KEY_H - 0x40;     ; break;
            case _PS2_RIGHT_ARROW:  m = _KEY_U - 0x40;   ; break;
            //case _PS2_RIGHT_ALT:    m = _CODE    ; break;
            //case _PS2_RIGHT_CTRL:   m = _CONTROL ; break;
            //case _PS2_LEFT_GUI:     m = _SPACE   ; break;
            //case _PS2_RIGHT_GUI:    m = _SPACE   ; break;
            //case _PS2_KPSLASH:      m = _KPSLASH ; break;
            //case _PS2_KPENTER:      m = _ENTER   ; break;
            //case _PS2_END:          m = _STOP    ; break;
            //case _PS2_HOME:         m = _HOME    ; break;
            //case _PS2_INSERT:       m = _INSERT  ; break;
            //case _PS2_DELETE:       m = _DELETE  ; break;

            default:  
              if (code < 128) {           
                m = pgm_read_byte(PS2Keymap_Ext_KEY_ABNT + code); // Associa o Scancode ao keymaps
              } else {
                m = _KEY_NONE;
              }  
              break;
          } // switch

          TCNT1 = 0xF244;
          PORTD = m; // bit7 = indicates keyboard on
          }
          
        } else { // Caracteres normais <Scancode>

          if (code < 128) {
            m = pgm_read_byte(PS2Keymap_KEY_ABNT + code); // Associa o Scancode ao keymaps         
          } else {
            m = _KEY_NONE;
          } 
           

       if (BRK == true) { // break code
            BRK = false;    
            if(code == 0x12)      shift = false;
            else if(code == 0x14) ctrl = false;
        } else {  
          if(code == 0x12)      shift = true;
          else if(code == 0x14) ctrl = true;
          else if(m != _KEY_NONE){
			  
				if (shift) m = (m & 0x10) ? m - 0x10 : m + 0x10;
	
				if (ctrl && (m >= 0x40 && m <= 0x5F))  m -= 0x40;
                
                TCNT1 = 0xF244;
                PORTD = (m & 0x7f) | ((m & 0x80) ^ 0x80); // bit7 = indicates keyboard on
                
              }
          }
         }
      }
	  
    }
  }  
}
