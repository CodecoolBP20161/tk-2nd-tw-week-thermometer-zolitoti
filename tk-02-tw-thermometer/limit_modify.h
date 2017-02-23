/*
 * limit_modify.h
 *
 *  Created on: Feb 22, 2017
 *      Author: matetotesi
 */

#ifndef LIMIT_MODIFY_H_
#define LIMIT_MODIFY_H_


int limit_modification(float x){
	if(x>0.5 && x<0.66){
		return 2;
	}
	if(x<0.5 && x>0.34){
		return -2;
	}
	if(x>0.66 && x<0.82){
		return 4;
	}
	if(x<0.34 && x>0.18){
		return -4;
	}
	if(x>0.82){
		return 6;
	}
	if(x<0.18){
		return -6;
	}

}



#endif /* LIMIT_MODIFY_H_ */
