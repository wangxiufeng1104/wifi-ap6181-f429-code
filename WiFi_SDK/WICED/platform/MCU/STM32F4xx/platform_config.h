/*
 * Copyright 2018, Cypress Semiconductor Corporation or a subsidiary of 
 * Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/** @file
 * Defines internal configuration of the BCM943362WCD4 board
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 * Restore default and start easylink after press down EasyLink button for 3 seconds. */
#define RestoreDefault_TimeOut                      (3000)

/*************************************************************************/
#define MCU_CLOCK_HZ            					(180000000)

/************************************************************************
 * How many bits are used in NVIC priority configuration */
#define CORTEX_NVIC_PRIO_BITS   					(4)

/************************************************************************
 * Enable write protection to write-disabled embedded flash sectors */
//#define MCU_EBANLE_FLASH_PROTECT

#define HSE_SOURCE              RCC_HSE_ON               /* Use external crystal                 */
#define AHB_CLOCK_DIVIDER       RCC_SYSCLK_Div1          /* AHB clock = System clock             */
#define APB1_CLOCK_DIVIDER      RCC_HCLK_Div4            /* APB1 clock = AHB clock / 2           */
#define APB2_CLOCK_DIVIDER      RCC_HCLK_Div2            /* APB2 clock = AHB clock / 1           */
#define PLL_SOURCE              RCC_PLLSource_HSE        /* PLL source = external crystal        */
#define PLL_M_CONSTANT          25                       /* PLLM = 25                            */
#define PLL_N_CONSTANT          360                      /* PLLN = 360                           */
#define PLL_P_CONSTANT          2                        /* PLLP = 2                             */
#define PPL_Q_CONSTANT          8                        /* PLLQ = 7                             */
#define PLL_Q_CONSTANT					7//自己添加的，先注释

#define SYSTEM_CLOCK_SOURCE     RCC_SYSCLKSource_PLLCLK  /* System clock source = PLL clock      */
#define SYSTICK_CLOCK_SOURCE    SysTick_CLKSource_HCLK   /* SysTick clock source = AHB clock     */
#define INT_FLASH_WAIT_STATE    FLASH_Latency_5          /* Internal flash wait state = 3 cycles */



///*  GPIO pins are used to bootstrap Wi-Fi to SDIO or gSPI mode */
//#define WICED_WIFI_USE_GPIO_FOR_BOOTSTRAP_0
//#define WICED_WIFI_USE_GPIO_FOR_BOOTSTRAP_1

//*  Wi-Fi GPIO0 pin is used for out-of-band interrupt */
#define WICED_WIFI_OOB_IRQ_GPIO_PIN  ( 0 )

///*  Wi-Fi power pin is present */
//#define WICED_USE_WIFI_POWER_PIN

///*  Wi-Fi reset pin is present */
#define WICED_USE_WIFI_RESET_PIN

///*  WLAN Powersave Clock Source
// *  The WLAN sleep clock can be driven from one of two sources:
// *  1. MCO (MCU Clock Output) - default
// *     NOTE: Versions of BCM943362WCD4 up to and including P200 require a hardware patch to enable this mode
// *     - Connect STM32F205RGT6 pin 41 (PA8) to pin 44 (PA11)
// *  2. WLAN 32K internal oscillator (30% inaccuracy)
// *     - Comment the following directive : WICED_USE_WIFI_32K_CLOCK_MCO
// */
//#define WICED_USE_WIFI_32K_CLOCK_MCO

///*  OTA */
//#define PLATFORM_HAS_OTA

#ifdef __cplusplus
} /* extern "C" */
#endif
