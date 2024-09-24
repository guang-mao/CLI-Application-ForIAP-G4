

#include "main.h"
#include "bsp_usart.h"
#include "sys_queue.h"
#include "sys_command_line.h"

/**
 * @brief  UART RX interrupt func.
 * @param  null
 * @retval null
 */
void USART2_IRQHandler(void)
{
    uint8_t ucData;

    if ( LL_USART_IsActiveFlag_RXNE_RXFNE(DEBUG_USARTx) != RESET )
    {
        ucData = LL_USART_ReceiveData8(DEBUG_USARTx);
        /* save char */
        QUEUE_IN(cli_rx_buff, ucData);
        //printf("%02x", ucTemp);
    }
}

/**
 * @brief  USART GPIO init.
 * @param  null
 * @retval null
 */
void debug_usart_init(uint32_t baud)
{

}

/*****************  send a char **********************/
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
    /* send a char */
    LL_USART_TransmitData8(pUSARTx, ch);
    /* wait */
    while ( LL_USART_IsActiveFlag_TXE_TXFNF(pUSARTx) == RESET );
}

/****************** send a array ************************/
void Usart_SendArray( USART_TypeDef * pUSARTx, uint8_t *array, uint16_t num)
{
    uint8_t i;

    for(i=0; i<num; i++) {
        /* send a char */
        Usart_SendByte(pUSARTx,array[i]);

    }

    /* wait */
    while( LL_USART_IsActiveFlag_TC(pUSARTx) == RESET );
}

/*****************  send a string **********************/
void Usart_SendString( USART_TypeDef * pUSARTx, char *str)
{
    unsigned int k=0;
    do {
        Usart_SendByte( pUSARTx, *(str + k) );
        k++;
    } while(*(str + k)!='\0');

    /* wait */
    while( LL_USART_IsActiveFlag_TC(pUSARTx) == RESET );
}

/*****************  send half word **********************/
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch)
{
    uint8_t temp_h, temp_l;

    /* get higher byte */
    temp_h = (ch&0XFF00)>>8;
    /* get lower byte */
    temp_l = ch&0XFF;

    /* send higher byte */
    LL_USART_TransmitData8(pUSARTx,temp_h);
    while ( LL_USART_IsActiveFlag_TXE_TXFNF(pUSARTx) == RESET );

    /* send lower byte */
    LL_USART_TransmitData8(pUSARTx,temp_l);
    while ( LL_USART_IsActiveFlag_TXE_TXFNF(pUSARTx) == RESET );
}


int fputc(int ch, FILE *f)
{
    /* send a char */
	LL_USART_TransmitData8(DEBUG_USARTx, (uint8_t) ch);

    /* wait */
    while ( LL_USART_IsActiveFlag_TXE_TXFNF(DEBUG_USARTx) == RESET );

    return (ch);
}


int fgetc(FILE *f)
{
    /* get a char */
    while ( LL_USART_IsActiveFlag_RXNE_RXFNE(DEBUG_USARTx) == RESET );

    return (int) LL_USART_ReceiveData8(DEBUG_USARTx);
}

