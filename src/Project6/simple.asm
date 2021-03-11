//add R0 + R1 store in R2
@0		//[1,@0,@,0,]
D=M		//[3,D=M,D,M,]
@1		//[1,@1,@,1,]
D=D+M	//[3,D=D+M,D,D+M,]
@2		//[1,@2,@,2,]
M=D		//[3,M=D,M,D,]

//instructions:
//open question: how do you convert from decimal to binary
//0000000000000000
//1111110000010000
//0000000000000001
//1111000010010000
//0000000000000010
//1111001100001000