# include <stdio.h>
# include <string.h>
# include <string.h>
# include <math.h>

int main(int argc, char const *argv[]){
	char templet[2][100] = {"-dis", "-area"};
	// 讀取 x1~ y2
	int xy[4] = {0}; // 0: x1, 1:y1 ..
	for(int i=2;i<6;i++){
		sscanf(argv[i],"%d", &xy[i-2]);
	}
	// 判斷是 dis or area
	if( strcmp(argv[1],templet[0]) == 0){ // dis
		printf("distance: %lf\n", sqrt( (double)((xy[2]-xy[0])*(xy[2]-xy[0])+(xy[3]-xy[1])*(xy[3]-xy[1])) ) );
	}
	else{
		int ret = (xy[2]-xy[0])*(xy[3]-xy[1]);
		if(ret < 0)
			ret *= -1;
		printf("area: %d\n",  ret);
	}
	return 0;
}