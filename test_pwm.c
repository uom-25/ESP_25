//Matthias Franke (9907512), Group 3, Pair Number 1

#include "main.h"
#include "Clk_Config.h"
#include "stdio.h"


int PRE = 299;
int ARR = 299;
float D = 0.5f;

int main(void){
LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA); //Set up the General-Purpose Input Output Pins to act as a Timer //Enable CLK to GPIOA
LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_ALTERNATE); //Set GPIO Alternate Function Mode //GPIOA5 set as alternate
LL_GPIO_SetAFPin_0_7(GPIOA, LL_GPIO_PIN_5, LL_GPIO_AF_1); //Define alternate function as a timer //GPIOA5 linked to timer 2
LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_MEDIUM); //Set GPIO speed //GPIOA5 medium speed
LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2); //Enable clock to timer //Timer 2
LL_TIM_SetPrescaler(TIM2, PRE); //Set the timer peripheral operating frequency //Load value PRE to Timer 2 prescaler
LL_TIM_SetAutoReload(TIM2, ARR); //Set the autoreload value to set the period //Load ARR to Timer 2 autoreload register

LL_TIM_OC_SetMode(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM1); //Set Timer output mode //Timer 2 to PWM
LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1); //Enable output channel //Timer 2 to output channel 1
LL_TIM_EnableCounter(TIM2); //Enable counter// Timer 2

LL_TIM_OC_SetCompareCH1(TIM2, D); //Set duty //Duty cycle D (float), 0-100 (% or period)
}
