/*********************************************************************************************************************
 * @file            isr.c
 * @author          L
 * @version         1.0
 * @Target core     CH32V307VCT6
 * @date            2022-3-26
 ********************************************************************************************************************/
#include <isr.h>

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void NMI_Handler(void)       __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void USART3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART4_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART5_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART6_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART7_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void UART8_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void DVP_IRQHandler (void) __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM1_UP_IRQHandler         (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM2_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM3_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM4_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM5_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM6_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM7_IRQHandler            (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM8_UP_IRQHandler         (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM9_UP_IRQHandler         (void)  __attribute__((interrupt("WCH-Interrupt-fast")));
void TIM10_UP_IRQHandler        (void)  __attribute__((interrupt("WCH-Interrupt-fast")));

void EXTI0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI3_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI4_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI9_5_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void EXTI15_10_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));



/*******************************************************************************
* Function Name  : NMI_Handler
* Description    : This function handles NMI exception.
* Input          : None
* Return         : None
*******************************************************************************/
void NMI_Handler(void)
{

}

/*******************************************************************************
* Function Name  : HardFault_Handler
* Description    : This function handles Hard Fault exception.
* Input          : None
* Return         : None
*******************************************************************************/
void HardFault_Handler(void)
{

}


//����Ϊ�жϷ��������û��ɸ�����Ҫ���ڶ�Ӧ��������������

/* USART1 �жϷ����� */
void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {

        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}

/* USART2 �жϷ����� */
void USART2_IRQHandler(void)
{
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
    }
}

/* USART3 �жϷ����� */
void USART3_IRQHandler(void)
{
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {

        USART_ClearITPendingBit(USART3, USART_IT_RXNE);
    }
}

/* UART4 �жϷ����� */
void UART4_IRQHandler (void)
{
    if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
    {

        USART_ClearITPendingBit(UART4, USART_IT_RXNE);
    }
}

/* UART5 �жϷ����� */
void UART5_IRQHandler (void)
{
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)
    {
        mt9v03x_uart_callback_dvp();
        USART_ClearITPendingBit(UART5, USART_IT_RXNE);
    }
}

/* UART6 �жϷ����� */
void UART6_IRQHandler (void)
{
    if(USART_GetITStatus(UART6, USART_IT_RXNE) != RESET)
    {

        USART_ClearITPendingBit(UART6, USART_IT_RXNE);
    }
}

/* UART7 �жϷ����� */
void UART7_IRQHandler (void)
{
    if(USART_GetITStatus(UART7, USART_IT_RXNE) != RESET)
    {
        USART_ClearITPendingBit(UART7, USART_IT_RXNE);
    }
}

/* UART8 �жϷ����� */
void UART8_IRQHandler (void)
{
    if(USART_GetITStatus(UART8, USART_IT_RXNE) != RESET)
    {
        USART_ClearITPendingBit(UART8, USART_IT_RXNE);
    }
}



/* DVP �жϷ����� */
void DVP_IRQHandler(void)
{
    if (DVP->IFR & RB_DVP_IF_FRM_DONE)
    {
        DVP->IFR &= ~RB_DVP_IF_FRM_DONE;
        mt9v03x_handler_dvp();
    }
}



/* EXTI0 �жϷ����� */
void EXTI0_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line0))
    {

        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}

/* EXTI1 �жϷ����� */
void EXTI1_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line1))
    {
        EXTI_ClearITPendingBit(EXTI_Line1);

    }
}

/* EXTI2 �жϷ����� */
void EXTI2_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line2))
    {
        minusSpeed++;
        Delay_Ms(200);
        EXTI_ClearITPendingBit(EXTI_Line2);
    }
}

/* EXTI3 �жϷ����� */
void EXTI3_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line3))
    {
        Delay_Ms(200);
        EXTI_ClearITPendingBit(EXTI_Line3);
        triangle_turn=0;
        car_start=1;
        ips114_show_string(200, 20, " left");

    }
}

/* EXTI4 �жϷ����� */
void EXTI4_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line4))
    {
        EXTI_ClearITPendingBit(EXTI_Line4);
        triangle_turn=1;;
        car_start=1;
        ips114_show_string(200, 20, "right");

    }
}

/* EXTI5-9 �жϷ����� */
void EXTI9_5_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line5))
    {
        EXTI_ClearITPendingBit(EXTI_Line5);
        crossDelay = (crossDelay + 1) % 2;
        Delay_Ms(200);



    }
    if(SET == EXTI_GetITStatus(EXTI_Line6))
    {
        EXTI_ClearITPendingBit(EXTI_Line6);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line7))
    {
        EXTI_ClearITPendingBit(EXTI_Line7);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line8))
    {
        EXTI_ClearITPendingBit(EXTI_Line8);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line9))
    {
        EXTI_ClearITPendingBit(EXTI_Line9);

    }

}

/* EXTI10-15 �жϷ����� */
void EXTI15_10_IRQHandler(void)
{
    if(SET == EXTI_GetITStatus(EXTI_Line10))
    {
        EXTI_ClearITPendingBit(EXTI_Line10);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line11))
    {
        EXTI_ClearITPendingBit(EXTI_Line11);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line12))
    {
        EXTI_ClearITPendingBit(EXTI_Line12);
    }
    if(SET == EXTI_GetITStatus(EXTI_Line13))
    {
        EXTI_ClearITPendingBit(EXTI_Line13);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line14))
    {
        EXTI_ClearITPendingBit(EXTI_Line14);

    }
    if(SET == EXTI_GetITStatus(EXTI_Line15))
    {
        EXTI_ClearITPendingBit(EXTI_Line15);

    }
}



/* TIM1_UP �жϷ����� */
void TIM1_UP_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
       {
           countTIM1 += 1;
           get_dis = Get_Distance_TOF400C();
           if ( get_dis  > 500 && count_tri == 1){
               const_speed = 0;
               TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
               if(count_tri == 1) count_tri++;
               ips114_show_int(200, 80, (int) ( countTIM1 / 3), 7);
               TIM_Cmd(TIM1, DISABLE);
               isTOF = 0;
           }
           TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
       }
}

/* TIM2 �жϷ����� */
void TIM2_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM2, TIM_IT_Update );
    }
}

/* TIM3 �жϷ����� */
void TIM3_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM3, TIM_IT_Update );


    }
}

/* TIM4 �жϷ����� */
void TIM4_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM4, TIM_IT_Update );


    }
}

/* TIM5 �жϷ����� */
void TIM5_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM5, TIM_IT_Update );


    }
}

/* TIM6 �жϷ����� */
void TIM6_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM6, TIM_IT_Update );


    }
}

/* TIM7 �жϷ����� */
void TIM7_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET)
    {
       TIM_ClearITPendingBit(TIM7, TIM_IT_Update );


    }
}

/* TIM8_UP �жϷ����� */
int LEDCount = 0;
void TIM8_UP_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM8, TIM_IT_Update) != RESET)
        {
        if(count_tri <= 3 && count_tri >= 1){
              if(LEDCount % 2 == 0){
                  if(triangle_turn==0)
                      car_yellow_left();
                  if(triangle_turn==1)
                      car_yellow_right();
              }
              else   car_both_rgb_off();
              LEDCount++;
              if(LEDCount == 6){ TIM_Cmd(TIM8,DISABLE); car_both_rgb_off(); LEDCount = 0; }

        }
        TIM_ClearITPendingBit(TIM8, TIM_IT_Update);
        }
}


/* TIM9_UP �жϷ����� */
void TIM9_UP_IRQHandler(void)
{

}

/* TIM10_UP �жϷ����� */
void TIM10_UP_IRQHandler(void)
{
    if(TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM10, TIM_IT_Update);

    }
}

//.section    .text.vector_handler, "ax", @progbits

//   .weak   EXTI0_IRQHandler           /* EXTI Line 0 */
//   .weak   EXTI1_IRQHandler           /* EXTI Line 1 */
//   .weak   EXTI2_IRQHandler           /* EXTI Line 2 */
//   .weak   EXTI3_IRQHandler           /* EXTI Line 3 */
//   .weak   EXTI4_IRQHandler           /* EXTI Line 4 */
//   .weak   DMA1_Channel1_IRQHandler   /* DMA1 Channel 1 */
//   .weak   DMA1_Channel2_IRQHandler   /* DMA1 Channel 2 */
//   .weak   DMA1_Channel3_IRQHandler   /* DMA1 Channel 3 */
//   .weak   DMA1_Channel4_IRQHandler   /* DMA1 Channel 4 */
//   .weak   DMA1_Channel5_IRQHandler   /* DMA1 Channel 5 */
//   .weak   DMA1_Channel6_IRQHandler   /* DMA1 Channel 6 */
//   .weak   DMA1_Channel7_IRQHandler   /* DMA1 Channel 7 */
//   .weak   ADC1_2_IRQHandler          /* ADC1_2 */
//   .weak   USB_HP_CAN1_TX_IRQHandler  /* USB HP and CAN1 TX */
//   .weak   USB_LP_CAN1_RX0_IRQHandler /* USB LP and CAN1RX0 */
//   .weak   CAN1_RX1_IRQHandler        /* CAN1 RX1 */
//   .weak   CAN1_SCE_IRQHandler        /* CAN1 SCE */
//   .weak   EXTI9_5_IRQHandler         /* EXTI Line 9..5 */
//   .weak   TIM1_BRK_IRQHandler        /* TIM1 Break */
//   .weak   TIM1_UP_IRQHandler         /* TIM1 Update */
//   .weak   TIM1_TRG_COM_IRQHandler    /* TIM1 Trigger and Commutation */
//   .weak   TIM1_CC_IRQHandler         /* TIM1 Capture Compare */
//   .weak   TIM2_IRQHandler            /* TIM2 */
//   .weak   TIM3_IRQHandler            /* TIM3 */
//   .weak   TIM4_IRQHandler            /* TIM4 */
//   .weak   I2C1_EV_IRQHandler         /* I2C1 Event */
//   .weak   I2C1_ER_IRQHandler         /* I2C1 Error */
//   .weak   I2C2_EV_IRQHandler         /* I2C2 Event */
//   .weak   I2C2_ER_IRQHandler         /* I2C2 Error */
//   .weak   SPI1_IRQHandler            /* SPI1 */
//   .weak   SPI2_IRQHandler            /* SPI2 */
//   .weak   USART1_IRQHandler          /* USART1 */
//   .weak   USART2_IRQHandler          /* USART2 */
//   .weak   USART3_IRQHandler          /* USART3 */
//   .weak   EXTI15_10_IRQHandler       /* EXTI Line 15..10 */
//   .weak   RTCAlarm_IRQHandler        /* RTC Alarm through EXTI Line */
//   .weak   USBWakeUp_IRQHandler       /* USB Wakeup from suspend */
//   .weak   TIM8_BRK_IRQHandler        /* TIM8 Break */
//   .weak   TIM8_UP_IRQHandler         /* TIM8 Update */
//   .weak   TIM8_TRG_COM_IRQHandler    /* TIM8 Trigger and Commutation */
//   .weak   TIM8_CC_IRQHandler         /* TIM8 Capture Compare */
//   .weak   RNG_IRQHandler             /* RNG */
//   .weak   FSMC_IRQHandler            /* FSMC */
//   .weak   SDIO_IRQHandler            /* SDIO */
//   .weak   TIM5_IRQHandler            /* TIM5 */
//   .weak   SPI3_IRQHandler            /* SPI3 */
//   .weak   UART4_IRQHandler           /* UART4 */
//   .weak   UART5_IRQHandler           /* UART5 */
//   .weak   TIM6_IRQHandler            /* TIM6 */
//   .weak   TIM7_IRQHandler            /* TIM7 */
//   .weak   DMA2_Channel1_IRQHandler   /* DMA2 Channel 1 */
//   .weak   DMA2_Channel2_IRQHandler   /* DMA2 Channel 2 */
//   .weak   DMA2_Channel3_IRQHandler   /* DMA2 Channel 3 */
//   .weak   DMA2_Channel4_IRQHandler   /* DMA2 Channel 4 */
//   .weak   DMA2_Channel5_IRQHandler   /* DMA2 Channel 5 */
//   .weak   ETH_IRQHandler             /* ETH */
//   .weak   ETH_WKUP_IRQHandler        /* ETH WakeUp */
//   .weak   CAN2_TX_IRQHandler         /* CAN2 TX */
//   .weak   CAN2_RX0_IRQHandler        /* CAN2 RX0 */
//   .weak   CAN2_RX1_IRQHandler        /* CAN2 RX1 */
//   .weak   CAN2_SCE_IRQHandler        /* CAN2 SCE */
//   .weak   OTG_FS_IRQHandler          /* OTGFS */
//   .weak   USBHSWakeup_IRQHandler     /* USBHS Wakeup */
//   .weak   USBHS_IRQHandler           /* USBHS */
//   .weak   DVP_IRQHandler             /* DVP */
//   .weak   UART6_IRQHandler           /* UART6 */
//   .weak   UART7_IRQHandler           /* UART7 */
//   .weak   UART8_IRQHandler           /* UART8 */
//   .weak   TIM9_BRK_IRQHandler        /* TIM9 Break */
//   .weak   TIM9_UP_IRQHandler         /* TIM9 Update */
//   .weak   TIM9_TRG_COM_IRQHandler    /* TIM9 Trigger and Commutation */
//   .weak   TIM9_CC_IRQHandler         /* TIM9 Capture Compare */
//   .weak   TIM10_BRK_IRQHandler       /* TIM10 Break */
//   .weak   TIM10_UP_IRQHandler        /* TIM10 Update */
//   .weak   TIM10_TRG_COM_IRQHandler   /* TIM10 Trigger and Commutation */
//   .weak   TIM10_CC_IRQHandler        /* TIM10 Capture Compare */
//   .weak   DMA2_Channel6_IRQHandler   /* DMA2 Channel 6 */
//   .weak   DMA2_Channel7_IRQHandler   /* DMA2 Channel 7 */
//   .weak   DMA2_Channel8_IRQHandler   /* DMA2 Channel 8 */
//   .weak   DMA2_Channel9_IRQHandler   /* DMA2 Channel 9 */
//   .weak   DMA2_Channel10_IRQHandler  /* DMA2 Channel 10 */
//   .weak   DMA2_Channel11_IRQHandler  /* DMA2 Channel 11 */

