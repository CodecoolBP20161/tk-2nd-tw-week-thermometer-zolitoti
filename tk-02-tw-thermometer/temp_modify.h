/*
 * temp_modify.h
 *
 *  Created on: Feb 21, 2017
 *      Author: mz
 */

#ifndef CODECOOL_TEMP_MODIFY_H_
#define CODECOOL_TEMP_MODIFY_H_

float temp_send_modify(float x){
	return (x-0.5)*20;
}

float temp_recieve_modify(float x){
	return (x/100)*50;
}

#endif /* CODECOOL_TEMP_MODIFY_H_ */
