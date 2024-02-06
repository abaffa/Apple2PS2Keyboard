/*
 * Apple][+ Keyboard Emulator v1 by Augusto Baffa, augbaffa@gmail.com, October, 27th 2023
 * based on Tek-Keyboard Emulator v2 by Daniel Jos� Viana, danjovic@hotmail.com
*/

#define _PS2_RIGHT_ALT   0x11
#define _PS2_RIGHT_CTRL  0x14
#define _PS2_LEFT_GUI    0x1F
#define _PS2_RIGHT_GUI   0x27
#define _PS2_KPSLASH     0x4A
#define _PS2_KPENTER     0x5A
#define _PS2_END         0x69
#define _PS2_LEFT_ARROW  0x6B
#define _PS2_HOME        0x6C
#define _PS2_INSERT      0x70
#define _PS2_DELETE      0x71
#define _PS2_DOWN_ARROW  0x72
#define _PS2_RIGHT_ARROW 0x74
#define _PS2_UP_ARROW    0x75
#define _PS2_PGDN        0x7A
#define _PS2_PGUP        0x7D
#define _PS2_BKSP        0x66

//       KEY       COL     LINE 
#define _KEY_0  0x30
#define _KEY_1  0x31 
#define _KEY_2  0x32 
#define _KEY_3  0x33 
#define _KEY_4  0x34 
#define _KEY_5  0x35 
#define _KEY_6  0x36 
#define _KEY_7  0x37 
#define _KEY_8  0x38 
#define _KEY_9  0x39 
#define _KEY_COLON  0x2d
#define _KEY_MINUS  0x3d 
#define _KEY_SEMICOLON  0x3B 
#define _KEY_A  0x41  
#define _KEY_B  0x42 
#define _KEY_C  0x43 
#define _KEY_D  0x44
#define _KEY_E  0x45 
#define _KEY_F  0x46
#define _KEY_G  0x47
#define _KEY_H  0x48 
#define _KEY_I  0x49 
#define _KEY_J  0x4A 
#define _KEY_K  0x4B 
#define _KEY_L  0x4C 
#define _KEY_M  0x4D 
#define _KEY_N  0x4E 
#define _KEY_O  0x4F 
#define _KEY_P  0x50 
#define _KEY_Q  0x51 
#define _KEY_R  0x52 
#define _KEY_S  0x53
#define _KEY_T  0x54 
#define _KEY_U  0x55 
#define _KEY_V  0x56 
#define _KEY_W  0x57 
#define _KEY_X  0x58 
#define _KEY_Y  0x59 
#define _KEY_Z  0x5A 
  
#define _KEY_SLASH  0x2F 
#define _KEY_COMMA  0x2C 
#define _KEY_DOT  0x2E 
#define _KEY_SP 0x20 
#define _KEY_SH (0<<3) + 0 // Shift
#define _KEY_NL 0x0D 
#define _KEY_ESC  0x1b
#define _KEY_BKSP 0x08 //_KEY_H - 0x40
#define _KEY_PLUS 0x2B
#define _KEY_TIMES 0x2A
#define _KEY_NONE 0
 
#define _SHIFT 0x80 

#define _KEY_UP_ARROW     0x8B// _KEY_K - 0x40
#define _KEY_DOWN_ARROW   0x8A // _KEY_J - 0x40
#define _KEY_LEFT_ARROW   0x88 // _KEY_H - 0x40
#define _KEY_RIGHT_ARROW  0x95 // _KEY_U - 0x40


//
// Associacao das teclas com Scancodes normais para teclados ABNT2
// Tabela foi reduzida para caber em 128 bytes. Caso seja necessario
// usar a tecla F7, considerar o scancode 0x7f em vez do scancode 
// nativo (0x83)
const PROGMEM unsigned char PS2Keymap_KEY_ABNT[] = { 
_KEY_NONE,         // 0x00   
_KEY_NONE,         // 0x01  F9
_KEY_NONE,         // 0x02  
_KEY_NONE,         // 0x03  F5
_KEY_NONE,         // 0x04  F3
_KEY_NONE,         // 0x05  F1
_KEY_NONE,         // 0x06  F2
_KEY_NONE,         // 0x07  F12           
_KEY_NONE,         // 0x08                
_KEY_NONE,         // 0x09  F10           
_KEY_NONE,         // 0x0A  F8            
_KEY_NONE,         // 0x0B  F6            
_KEY_NONE,         // 0x0C  F4            
_KEY_NONE,         // 0x0D  TAB           
_KEY_NONE,         // 0x0E  APOSTROPHE    '  (ASPAS)
_KEY_NONE,         // 0x0F                
_KEY_NONE,         // 0x10                
_KEY_NONE,         // 0x11  L ALT         
_KEY_NONE,               // 0x12  L SHFT        
_KEY_NONE,         // 0x13  L CTRL        
_KEY_NONE,         // 0x14               
_KEY_Q,            // 0x15  Q             
_KEY_1,            // 0x16  1              
_KEY_NONE,         // 0x17                
_KEY_NONE,         // 0x18                
_KEY_NONE,         // 0x19                
_KEY_Z   ,         // 0x1A  Z             
_KEY_S   ,         // 0x1B  S             
_KEY_A   ,         // 0x1C  A             
_KEY_W   ,         // 0x1D  W             
_KEY_2   ,         // 0x1E  2             
_KEY_NONE,         // 0x1F                
_KEY_NONE,         // 0x20                
_KEY_C   ,         // 0x21  C             
_KEY_X   ,         // 0x22  X             
_KEY_D   ,         // 0x23  D             
_KEY_E   ,         // 0x24  E             
_KEY_4   ,         // 0x25  4             
_KEY_3   ,         // 0x26  3             
_KEY_NONE,         // 0x27                
_KEY_NONE,         // 0x28                
_KEY_SP,           // 0x29  SPACE         
_KEY_V ,           // 0x2A  V             
_KEY_F ,           // 0x2B  F             
_KEY_T ,           // 0x2C  T             
_KEY_R ,           // 0x2D  R             
_KEY_5 ,           // 0x2E  5             
_KEY_NONE,         // 0x2F                
_KEY_NONE,         // 0x30                
_KEY_N,            // 0x31  N             
_KEY_B,            // 0x32  B             
_KEY_H,            // 0x33  H             
_KEY_G,            // 0x34  G             
_KEY_Y,            // 0x35  Y             
_KEY_6,            // 0x36  6             
_KEY_NONE,         // 0x37                
_KEY_NONE,         // 0x38                
_KEY_NONE,         // 0x39                
_KEY_M,            // 0x3A  M             
_KEY_J,            // 0x3B  J             
_KEY_U,            // 0x3C  U             
_KEY_7,            // 0x3D  7             
_KEY_8,            // 0x3E  8             
_KEY_NONE,         // 0x3F                
_KEY_NONE,         // 0x40                
_KEY_COMMA, // 0x41  COMMA         ,
_KEY_K,            // 0x42  K             
_KEY_I,            // 0x43  I             
_KEY_O,            // 0x44  O             
_KEY_0,            // 0x45  0             
_KEY_9,            // 0x46  9             
_KEY_NONE,         // 0x47                
_KEY_NONE,         // 0x48                
_KEY_DOT,          // 0x49  DOT           .
_KEY_SLASH,   // 0x4A  SEMICOLON     ;
_KEY_L   ,         // 0x4B  L             
_KEY_SEMICOLON,         // 0x4C  CCCEDIL       �
_KEY_P,            // 0x4D  P             
_KEY_COLON,   // 0x4E  MINUS         -
_KEY_NONE,         // 0x4F  
_KEY_NONE,         // 0x50  
_KEY_SLASH,   // 0x51  SLASH         /
_KEY_NONE,         // 0x52  TILDE         ~
_KEY_NONE,         // 0x53  
_KEY_NONE,         // 0x54  ACUTE         `
_KEY_MINUS,   // 0x55  EQUAL         =
_KEY_NONE,         // 0x56  
_KEY_NONE,         // 0x57  
_KEY_NONE,         // 0x58  CAPS
_KEY_NONE,           // 0x59  R SHFT
_KEY_NL,           // 0x5A  ENTER
_KEY_NONE,         // 0x5B  OPENBRACKET   [
_KEY_NONE,         // 0x5C  
_KEY_NONE,         // 0x5D  CLOSEBRACKET  ]
_KEY_NONE,         // 0x5E  
_KEY_NONE,         // 0x5F  
_KEY_NONE,         // 0x60  
_KEY_NONE,         // 0x61  BACKSLASH     
_KEY_NONE,         // 0x62  
_KEY_NONE,         // 0x63  
_KEY_NONE,         // 0x64  
_KEY_NONE,         // 0x65  
_KEY_BKSP,   // 0x66  BKSP
_KEY_NONE,         // 0x67  
_KEY_NONE,         // 0x68  
_KEY_1,            // 0x69  KP1
_KEY_NONE,         // 0x6A  
_KEY_4,            // 0x6B  KP4
_KEY_7,            // 0x6C  KP7
_KEY_DOT,          // 0x6D  KPDOT         .
_KEY_NONE,         // 0x6E  
_KEY_NONE,         // 0x6F  
_KEY_0,            // 0x70  KP0
_KEY_COMMA, // 0x71  KPCOMMA       ,
_KEY_2,            // 0x72  KP2
_KEY_5,            // 0x73  KP5
_KEY_6,            // 0x74  KP6
_KEY_8,            // 0x75  KP8
_KEY_ESC,  // 0x76  ESC
_KEY_NONE,         // 0x77  NUM
_KEY_NONE,         // 0x78  F11
_KEY_PLUS,   // 0x79  KPPLUS        +
_KEY_3,            // 0x7A  KP3
_KEY_MINUS,   // 0x7B  KPMINUS       -
_KEY_TIMES,   // 0x7C  KPTIMES       *
_KEY_9,            // 0x7D  KP9
_KEY_NONE,         // 0x7E  SCROLL
_KEY_NONE         // 0x7F  F7 - O scancode original da tecla F7 e o 0x83 mas foi
};             //            movido para 0x7f para que a tabela caiba em 128 bytes




//
// Associacao das teclas com Scancodes extendidos para teclados ABNT2
// E possivel economizar algum espaco reduzindo a tabela do codigo 0x10 ao 0x7d
// porem isso nao foi feito em funcao da clareza do codigo.
const PROGMEM  unsigned char PS2Keymap_Ext_KEY_ABNT[] = { 
_KEY_NONE,         // 0x00
_KEY_NONE,         // 0x01
_KEY_NONE,         // 0x02
_KEY_NONE,         // 0x03
_KEY_NONE,         // 0x04
_KEY_NONE,         // 0x05
_KEY_NONE,         // 0x06
_KEY_NONE,         // 0x07
_KEY_NONE,         // 0x08
_KEY_NONE,         // 0x09
_KEY_NONE,         // 0x0A
_KEY_NONE,         // 0x0B
_KEY_NONE,         // 0x0C
_KEY_NONE,         // 0x0D
_KEY_NONE,         // 0x0E
_KEY_NONE,         // 0x0F
_KEY_NONE,         // 0x10  WWW_Search (Multimedia)                          
_KEY_NONE,         // 0x11  Right ALT                                            
_KEY_NONE,         // 0x12                           
_KEY_NONE,         // 0x13                       
_KEY_NONE,         // 0x14  Right Control        
_KEY_NONE,         // 0x15  Previous_Track  (Multimedia)                     
_KEY_NONE,         // 0x16                       
_KEY_NONE,         // 0x17                       
_KEY_NONE,         // 0x18  WWW_Favorites   (Multimedia)                     
_KEY_NONE,         // 0x19                       
_KEY_NONE,         // 0x1A                       
_KEY_NONE,         // 0x1B                       
_KEY_NONE,         // 0x1C                     
_KEY_NONE,         // 0x1D                     
_KEY_NONE,         // 0x1E                     
_KEY_NONE,         // 0x1F  Left Windows                  
_KEY_NONE,         // 0x20  WWW_Refresh     (Multimedia)                   
_KEY_NONE,         // 0x21  Volume_Down     (Multimedia)                   
_KEY_NONE,         // 0x22                     
_KEY_NONE,         // 0x23  Mute            (Multimedia)                   
_KEY_NONE,         // 0x24                     
_KEY_NONE,         // 0x25                     
_KEY_NONE,         // 0x26                     
_KEY_NONE,         // 0x27  Right Windows                   
_KEY_NONE,         // 0x28  WWW_Stop        (Multimedia)                   
_KEY_NONE,         // 0x29                     
_KEY_NONE,         // 0x2A                     
_KEY_NONE,         // 0x2B  Calculator      (Multimedia)
_KEY_NONE,         // 0x2C                         
_KEY_NONE,         // 0x2D                         
_KEY_NONE,         // 0x2E                      
_KEY_NONE,         // 0x2F  Context menu                      
_KEY_NONE,         // 0x30  WWW_Forward   (Multimedia)                   
_KEY_NONE,         // 0x31                     
_KEY_NONE,         // 0x32  Volume_Up     (Multimedia)                   
_KEY_NONE,         // 0x33                     
_KEY_NONE,         // 0x34  Play/Pause    (Multimedia)                   
_KEY_NONE,         // 0x35                     
_KEY_NONE,         // 0x36                     
_KEY_NONE,         // 0x37  Power         (Multimedia)                   
_KEY_NONE,         // 0x38  WWW_Back      (Multimedia)                   
_KEY_NONE,         // 0x39                     
_KEY_NONE,         // 0x3A  WWW_Home      (Multimedia)                   
_KEY_NONE,         // 0x3B  Stop          (Multimedia)                   
_KEY_NONE,         // 0x3C                     
_KEY_NONE,         // 0x3D                     
_KEY_NONE,         // 0x3E                                
_KEY_NONE,         // 0x3F  Sleep         (Multimedia)                      
_KEY_NONE,         // 0x40  My_Computer   (Multimedia)                      
_KEY_NONE,         // 0x41                        
_KEY_NONE,         // 0x42                        
_KEY_NONE,         // 0x43                        
_KEY_NONE,         // 0x44                        
_KEY_NONE,         // 0x45                        
_KEY_NONE,         // 0x46                         
_KEY_NONE,         // 0x47                         
_KEY_NONE,         // 0x48  E_Mail        (Multimedia)    
_KEY_NONE,         // 0x49                     
_KEY_SLASH,        // 0x4A  Keypad SLASH                   
_KEY_NONE,         // 0x4B                     
_KEY_NONE,         // 0x4C                     
_KEY_NONE,         // 0x4D  Next_Track    (Multimedia)                   
_KEY_NONE,         // 0x4E                      
_KEY_NONE,         // 0x4F                      
_KEY_NONE,         // 0x50  Media_Select  (Multimedia)                    
_KEY_NONE,         // 0x51                      
_KEY_NONE,         // 0x52                      
_KEY_NONE,         // 0x53                      
_KEY_NONE,         // 0x54                      
_KEY_NONE,         // 0x55                      
_KEY_NONE,         // 0x56                      
_KEY_NONE,         // 0x57                     
_KEY_NONE,         // 0x58                     
_KEY_NONE,         // 0x59                     
_KEY_NL,           // 0x5A  Keypad Enter              
_KEY_NONE,         // 0x5B                      
_KEY_NONE,         // 0x5C                      
_KEY_NONE,         // 0x5D                      
_KEY_NONE,         // 0x5E  Wake          (Multimedia)                    
_KEY_NONE,         // 0x5F                      
_KEY_NONE,         // 0x60                      
_KEY_NONE,         // 0x61                      
_KEY_NONE,         // 0x62                      
_KEY_NONE,         // 0x63                      
_KEY_NONE,         // 0x64                      
_KEY_NONE,         // 0x65                      
_KEY_NONE,         // 0x66
_KEY_NONE,         // 0x67
_KEY_NONE,         // 0x68
_KEY_NONE,         // 0x69  END
_KEY_NONE,         // 0x6A  
_KEY_NONE,         // 0x6B  LEFT Arrow
_KEY_NONE,         // 0x6C  HOME 
_KEY_NONE,         // 0x6D  
_KEY_NONE,         // 0x6E  
_KEY_NONE,         // 0x6F           
_KEY_NONE,         // 0x70  INSERT                        
_KEY_NONE,         // 0x71  DELETE                       
_KEY_NONE,          // 0x72  DOWN Arrow                      
_KEY_NONE,         // 0x73                       
_KEY_NONE,          // 0x74  RIGHT Arrow                     
_KEY_NONE,         // 0x75  UP Arrow                      
_KEY_NONE,         // 0x76                        
_KEY_NONE,         // 0x77                           
_KEY_NONE,         // 0x78                        
_KEY_NONE,         // 0x79                       
_KEY_NONE,         // 0x7A  PG_DN
_KEY_NONE,         // 0x7B  
_KEY_NONE,         // 0x7C  
_KEY_NONE,         // 0x7D  PG_UP 
_KEY_NONE,         // 0x7E
_KEY_NONE          // 0x7F
};
