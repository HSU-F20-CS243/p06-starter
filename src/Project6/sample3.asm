//x = R0 + R1
@R0		//[2,@R0,@,R0,0]
D=M		//[3,D=M,D,M,]
@R1		//[2,@R1,@,R1,1]
D=D+M	//[3,D=D+M,D,D+M,]
@x		//[2,@x,@,x,16]
M=D		//[3,M=D,M,D,]

//@x -> @16