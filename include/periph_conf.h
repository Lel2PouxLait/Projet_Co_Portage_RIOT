/*
 * Copyright (C) 2018 Inria
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */


/**
 * Projet STM32@FABLAB Polytech
 * Portage de la carte wyres sur RiotOs
 * Sur une base du processeur stm32l0538
 * Changement de la configuration pour un cpu STM32L151CC
 * Changements signalés avec des commentaires
 */

#ifndef PERIPH_CONF_H
#define PERIPH_CONF_H

#include "periph_cpu.h"
#include "clk_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Timer configuration
 * @{
 */
static const timer_conf_t timer_config[] = {
    {
        .dev      = TIM2,
        .max      = 0x0000ffff,
        .rcc_mask = RCC_APB1ENR_TIM2EN,
        .bus      = APB1,
        .irqn     = TIM2_IRQn
    }
};

#define TIMER_0_ISR         isr_tim2

#define TIMER_NUMOF         ARRAY_SIZE(timer_config)
/** @} */

/**
 * @name    UART configuration
 * @{
 */
static const uart_conf_t uart_config[] = {
    {
        .dev        = USART1,                   //Configuré liaison UART
        .rcc_mask   = RCC_APB2ENR_USART1EN,     //non changé
        .rx_pin     = GPIO_PIN(PORT_A, 10),      //Pin changé
        .tx_pin     = GPIO_PIN(PORT_A, 9),     //Pin changé
        .rx_af      = GPIO_AF7,                 //alternate func à vérifier p.46 doc stm32l151cc
        .tx_af      = GPIO_AF7,                 //alternate func à vérifier
        .bus        = APB2,                     // non changé
        .irqn       = USART1_IRQn,              // non changé
        //.type       = STM32_USART,
        //.clk_src    = 0, /* Use APB clock */
    }
};

#define UART_0_ISR          (isr_usart1)

#define UART_NUMOF          ARRAY_SIZE(uart_config)
/** @} */

/**
 * @name    SPI configuration
 * @{
 */
static const spi_conf_t spi_config[] = {
    {
        .dev      = SPI1,                   //Pin pour la liaison Serial Peripheral Interface 1
        .mosi_pin = GPIO_PIN(PORT_A, 7),    //Pin changé
        .miso_pin = GPIO_PIN(PORT_A, 6),    //Pin changé
        .sclk_pin = GPIO_PIN(PORT_A, 5),    //Pin changé
        .cs_pin   = GPIO_PIN(PORT_B, 0),    //Pin changé
        .mosi_af  = GPIO_AF5,               //redéfini
        .miso_af  = GPIO_AF5,               //redéfini
        .sclk_af  = GPIO_AF5,               //redéfini
        //.cs_af    = NULL,                   //indéfinie
        //.rccmask  = NULL//RCC_APB2ENR_SPI1EN,     //indéfinie
        //.apbbus   = NULL//APB2                    //indéfinie
    },
    {
        .dev      = SPI2,.                  //Pin pour la liaison Serial Peripheral Interface 2
        //.mosi_pin = GPIO_PIN(PORT_B, 15),   //N'existe pas sur la board
        .miso_pin = GPIO_PIN(PORT_B, 14),   //Pin changé
        .sclk_pin = GPIO_PIN(PORT_B, 13),   //Pin changé
        .cs_pin   = GPIO_PIN(PORT_B, 12),   //Pin changé
        .mosi_af  = GPIO_AF5,               //redéfini
        .miso_af  = GPIO_AF5,               //redéfini
        .sclk_af  = GPIO_AF5,               //redéfini
        .cs_af    = GPIO_AF5,               //redéfini
        .rccmask  = RCC_APB1ENR_SPI2EN,
        .apbbus   = APB1
    },
};

#define SPI_NUMOF           ARRAY_SIZE(spi_config)
/** @} */

#ifdef __cplusplus
}
#endif

#endif /* PERIPH_CONF_H */
