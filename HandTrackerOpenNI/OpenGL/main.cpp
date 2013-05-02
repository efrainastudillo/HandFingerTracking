#include "Vector3"


int main(int argc,char* argv[]){
	Vec3 v1;
	Vec3 v2(2,4,5);
	Vec3 v3(v2);
	LOG(v3);
	Vec3 v4=v3*v2;
	LOG(v4);
	LOG(v2-v4);
	LOG(v4+10);

	LOG(v2/0);

	LOG(v2/v1);
	return 0;
}