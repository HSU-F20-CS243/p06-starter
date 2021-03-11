//Loop R0 times
@x					//0 -	[2,@x,@,x,16]
(:LoopBegin)		//NO-OP [0,(:LoopBegin),:LoopBegin,]
@R0					//1		[2,@R0,@,R0,0]
D=M-1				//2		[3,D=M-1,D,M-1,]
@:LoopBegin			//3		[2,@:LoopBegin,@,:LoopBegin,17]
D;JGT				//4		[4,D;JGT,D,JGT,]

