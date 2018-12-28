#include <stdio.h>
int goto_ad(int x, int y){
	int result;
	if (x>y){
		result = x-y;
	}else{
		result = y-x;
	}
	return result;
}