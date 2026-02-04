#ifndef CONFIG_USART1_H_
#define CONFIG_USART1_H_

#ifdef  __cplusplus
extern "C" {
#endif

// <<< Use Configuration Wizard in Context Menu >>>

// <h> USART1 Configuration

#ifndef USART1_DEFAULT_BAUD_RATE
// <o USART1_DEFAULT_BAUD_RATE> USART1 Default Baud Rate  <1-1000000000>
//  <1200=> 1200
//  <2400=> 2400
//  <4800=> 4800
//  <9600=> 9600
//  <14400=> 14400
//  <19200=> 19200
//  <28800=> 28800
//  <38400=> 38400
//  <57600=> 57600
//  <115200=> 115200
//  <230400=> 230400
//  <460800=> 460800
// <i> Default: 115200                                                   
// <d> 115200UL   
#define USART1_DEFAULT_BAUD_RATE 115200
#endif

#ifndef SERCOM1_USART_CLOCK_FREQUENCY
// <o> USART1 Clock Configuration <1-100000000>                          
// <i> SERCOM1 peripheral clock frequency in Hertz.
// <i> Default: 4000000UL                                                   
// <d> 4000000UL                                            
#define SERCOM1_USART_CLOCK_FREQUENCY 4000000UL
#endif

#ifndef USART1_TX_PAD
// <o USART1_TX_PAD> USART1 TX PAD Configuration <0-3>
//  <0=> PAD[0]=TxD, PAD[1]=XCK 
//  <1=> PAD[2]=TxD, PAD[3]=XCK
//  <2=> PAD[0]=TxD, PAD[2]=RTS/TE, PAD[3]=CTS
//  <3=> PAD[0]=TxD, PAD[1]=XCK, PAD[2]=RTS/TE
// <i> Defines the SERCOM PAD used for USART TX.
// <i> Default: 0
#define USART1_TX_PAD    0
#endif

#ifndef USART1_RX_PAD
// <o USART1_RX_PAD> USART1 RX PAD Configuration <0-3>
//  <0=> SERCOM PAD[0] is used for data reception 
//  <1=> SERCOM PAD[1] is used for data reception 
//  <2=> SERCOM PAD[2] is used for data reception
//  <3=> SERCOM PAD[3] is used for data reception
// <i> Defines the SERCOM PAD used for USART RX.
// <i> Default: 1
#define USART1_RX_PAD    1
#endif

// </h>

// <<< end of configuration section >>>


#ifndef USART1_OPERATING_MODE
// USART1 operating mode: options include USART_INT (Internal clock), USART_EXT (External clokc)
#define USART1_OPERATING_MODE USART_INT
#endif

#ifndef USART1_COMMUNICATION_MODE
// USART1 communication mode: options include USART_ASYNC_MODE (asynchronous) or USART_SYNC_MODE (synchronous)
#define USART1_COMMUNICATION_MODE USART_ASYNC_MODE
#endif

#ifndef USART1_DATA_SIZE
// USART1 data size: options include USART_DATA_5_BIT, USART_DATA_6_BIT, USART_DATA_7_BIT, USART_DATA_8_BIT, or USART_DATA_9_BIT
#define USART1_DATA_SIZE USART_DATA_8_BIT
#endif

#ifndef USART1_DATA_ORDER
// USART1 data order: options include USART_LSB_FIRST or USART_MSB_FIRST
#define USART1_DATA_ORDER USART_LSB_FIRST
#endif

#ifndef USART1_FRAME_FORMAT
// USART1 frame format: options include USART_FRAME (standard) or USART_FRAME_CUSTOM (custom)
#define USART1_FRAME_FORMAT USART_FRAME
#endif

#ifndef USART1_STOP_BITS
// USART1 stop bits: options include USART_STOP_1_BIT or USART_STOP_2_BIT
#define USART1_STOP_BITS USART_STOP_1_BIT
#endif


/**
 * @def USART1_RX_PAD_CONFIG
 * @brief Macro definition for USART1 RX PAD configuration.
 */
#ifdef USART1_RX_PAD
    #if (USART1_RX_PAD == 0)
        #define USART1_RX_PAD_CONFIG    USART_RX_PAD0
    #elif (USART1_RX_PAD == 1)
        #define USART1_RX_PAD_CONFIG    USART_RX_PAD1
    #elif (USART1_RX_PAD == 2)
        #define USART1_RX_PAD_CONFIG    USART_RX_PAD2
    #elif (USART1_RX_PAD == 3)
        #define USART1_RX_PAD_CONFIG    USART_RX_PAD3
    #else
        #define USART1_RX_PAD_CONFIG    USART_RX_PAD0
    #endif
#else
#define USART1_RX_PAD_CONFIG    USART_RX_PAD0
#endif

/**
 * @def USART1_TX_PAD_CONFIG
 * @brief Macro definition for USART1 TX PAD configuration.
 */
#ifdef USART1_TX_PAD
    #if (USART1_TX_PAD == 0)
        #define USART1_TX_PAD_CONFIG    USART_TX_PAD0
    #elif (USART1_TX_PAD == 1)
        #define USART1_TX_PAD_CONFIG    USART_TX_PAD2
    #elif (USART1_TX_PAD == 2)
        #define USART1_TX_PAD_CONFIG    USART_TX_PAD0_WITH_RTS_CTS
    #elif (USART1_TX_PAD == 3)
        #define USART1_TX_PAD_CONFIG    USART_TX_PAD0_WITH_TE  
    #else
        #define USART1_TX_PAD_CONFIG    USART_TX_PAD0
    #endif
#else
#define USART1_TX_PAD_CONFIG    USART_TX_PAD0
#endif

    
#ifdef  __cplusplus
}
#endif

#endif /* CONFIG_USART1_H_ */