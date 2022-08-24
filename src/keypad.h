// Copyright 2022  William Henrique (william.martins@ee.ufcg.edu.br)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#ifndef KEYPAD_H
#define KEYPAD_H

/**
 * @file keypad.h
 * @author William Henrique (william.martins@ee.ufcg.edu.br)
 * @brief 4x4 Keypad library for ESP-IDF framework
 * @version 0.1
 * @date 2022-07-30
 * 
 */

#include <driver/gpio.h>

#define KEYPAD_DEBOUNCING 100   ///< time in ms
#define KEYPAD_STACKSIZE  5

/**
 * @brief Initialize Keypad settings and start it, setup up directions and isr and initialize
 * key pressed queue.
 * 
 * @param keypad_pins Keypad Connections Array following this template: 
 *  {R1, R2, R3, R4, C1, C2, C3, C4}
 * 
 * @return esp_err_t returns ESP_OK if succeful initialize
 */
esp_err_t keypad_initalize(gpio_num_t keypad_pins[8]);

/**
 * @brief Returns pressed key on keypad
 * 
 * @return Returns an pressed key on keypad, if key wasn't pressed returns an terminator character. 
 */
char keypad_getkey();

/**
 * @brief Delete Keyboard and free resources
 * 
 */
void keypad_delete(void);

#endif