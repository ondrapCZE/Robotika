#include "tim310.h"
#include <stdio.h>
#include <iostream>
#include <vector>

int main(){

	Tim310_CLASS tim;
	if(!tim.open()){
		std::cerr << "Nepovedlo se otevrit Tim310" << std::endl ;
		return 1;
	}


	while(true){
		std::vector<uint16_t> data = tim.readData();
		for(int i=0; i<10; ++i)
			printf(" %i6 ,",data[i]);
		printf("\n\r");
	}	
}
