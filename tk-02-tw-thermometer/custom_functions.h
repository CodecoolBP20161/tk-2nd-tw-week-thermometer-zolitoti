/*
 * custom_functions.h
 *
 *  Created on: Feb 24, 2017
 *      Author: mz
 */

#ifndef CUSTOM_FUNCTIONS_H_
#define CUSTOM_FUNCTIONS_H_

// modifies intervals of the temperature limits
int limit_modification(float x){
	if(x>0.5 && x<0.66){
		return 2;
	}else if(x<0.5 && x>0.34){
		return -2;
	}else if(x>0.66 && x<0.82){
		return 4;
	}else if(x<0.34 && x>0.18){
		return -4;
	}else if(x>0.82){
		return 6;
	}else if(x<0.18){
		return -6;
	}else return 0;
}


// modifies temperature with +-10 degree depending on the state of the potmeter
float temp_send_modify(float x){
	return (x-0.5)*20;
}



float temp_recieve_modify(float x){
	return (x/100)*50;
}


#endif /* CUSTOM_FUNCTIONS_H_ */
