#include "main.h"

void SystemClock_Config(void){
  /* Enable HSE oscillator */
  LL_RCC_HSE_EnableBypass();
  LL_RCC_HSE_Enable();
  while(LL_RCC_HSE_IsReady() != 1)
  {
  };

  /* Set FLASH latency */
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);

  /* Main PLL configuration and activation */
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 336, LL_RCC_PLLP_DIV_4);
  LL_RCC_PLL_Enable();
  while(LL_RCC_PLL_IsReady() != 1)
  {
  };

  /* Sysclk activation on the main PLL */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  };

  /* Set APB1 & APB2 prescaler */
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);

  /* Set systick to 1ms */
  SysTick_Config(84000000 / 1000);

  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  SystemCoreClock = 84000000;
}






void Set_PREARR(TIM_TypeDef *TIMx, uint32_t Frequency){
}

uint32_t calc_compare(float Duty, uint32_t ARR){
}

void Setup_PWM_One(GPIO_TypeDef* GPIOx, uint32_t Pin){
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
//Set up the General-Purpose Input Output Pins to act as a Timer //Enable CLK to GPIOA
	
LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
//Enable clock to timer //Timer 3
	

	
LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_ALTERNATE);
//Set GPIO Alternate Function Mode //GPIOB4 set as alternate
	
LL_GPIO_SetAFPin_0_7(GPIOA, LL_GPIO_PIN_5, LL_GPIO_AF_1);
//Define alternate function as a timer //GPIOB4 linked to timer 3
	
LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_MEDIUM);
//Set GPIO speed //GPIOB4 medium speed

LL_TIM_SetCounterMode(TIM2, LL_TIM_COUNTERMODE_UP);
//Count up timer

LL_TIM_EnableARRPreload(TIM2);
//Enable ARR

LL_TIM_OC_EnablePreload(TIM2, LL_TIM_CHANNEL_CH1);
//Enable PRE

LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);
//Enable output channel //Timer 3 to output channel 1

LL_TIM_OC_SetMode(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1);
//Set Timer output mode //Timer 3 to PWM

LL_TIM_OC_SetPolarity(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCPOLARITY_HIGH);
//Set Polarity to positive



}

int main(void){
SystemClock_Config(); 	
int PRE = 9999;
int ARR = 500;
int D = 400;
//
LL_TIM_SetPrescaler(TIM2, PRE);
//Set the timer peripheral operating frequency //Load value PRE to Timer 3 prescaler
	
LL_TIM_SetAutoReload(TIM2, ARR);
//Set the autoreload value to set the period //Load ARR to Timer 3 autoreload register

	
	

LL_TIM_EnableCounter(TIM2);
//Enable counter// Timer 3	
	
LL_TIM_OC_SetCompareCH1(TIM2, D);
//Set duty //Duty cycle D (float), 0-100 (% or period)



while(1);

}



