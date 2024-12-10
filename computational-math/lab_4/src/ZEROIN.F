      REAL FUNCTION ZEROIN(AX,BX,F,TOL)
      REAL AX,BX,F,TOL

      REAL A,B,C,D,E,EPS,FA,FB,FC,TOL1,XM,P,Q,R,S

      EPS=1.0
   10 EPS=EPS/2.0
      TOL1=1.0+EPS
      IF(TOL1.GT.1.0) GO TO 10

      A=AX
      B=BX
      FA=F(A)
      FB=F(B)

   20 C=A
      FC=FA
      D=B-A
      E=D
   30 IF(ABS(FC).GE.ABS(FB)) GO TO 40
      A=B
      B=C
      C=A
      FA=FB
      FB=FC
      FC=FA

   40 TOL1=2.0*EPS*ABS(B)+0.5*TOL
      XM=0.5*(C-B)
      IF(ABS(XM).LE.TOL1) GO TO 90

      IF(FB.EQ.0.0) GO TO 90
      IF(ABS(E).LT.TOL1) GO TO 70
      IF(ABS(FA).LE.ABS(FB)) GO TO 70

      IF(A.NE.C)GO TO 50

      S=FB/FA
      P=2.0*XM*S
      Q=1.0-S
      GO TO 60

   50 Q=FA/FC
      R=FB/FC
      S=FB/FA
       P=S*(2.0*XM*Q*(Q-R)-(B-A)*(R-1.0))
      Q=(Q-1.0)*(R-1.0)*(S-1.0)

   60 IF(P.GT.0.0) Q=-Q
      P=ABS(P)

      IF((2.0*P).GE.(3.0*XM*Q-ABS(TOL1*Q))) GO TO 70
      IF(P.GE.ABS(0.5*E*Q)) GO TO 70
      E=D
      D=P/Q
      GO TO 80

   70 D=XM
      E=D

   80 A=B
      FA=FB
      IF(ABS(D).GT.TOL1) B=B+D
      IF(ABS(D).LE.TOL1) B=B+SIGN(TOL1,XM)
      FB=F(B)
      IF((FB*(FC/ABS(FC))).GT.0.0) GO TO 20
      GO TO 30

   90 ZEROIN=B
      RETURN
      END
