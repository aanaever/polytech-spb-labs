      SUBROUTINE SVD(NM,M,N,A,W,MATU,U,MATV,V,IERR,RV1)

      INTEGER I,J,K,L,M,N,II,I1,KK,K1,LL,L1,MN,NM,ITS,IERR
      REAL A(NM,N),W(N),U(NM,N),V(NM,N),RV1(N)

      REAL C,F,G,H,S,X,Y,Z,SCALE,ANORM
      LOGICAL MATU,MATV

      IERR=0
      DO 100 I=1,M
      DO 100 J=1,N
      U(I,J)=A(I,J)
  100 CONTINUE


      G=0.0
      SCALE=0.0
      ANORM=0.0

      DO 300 I=1,N
         L=I+1
         RV1(I)=SCALE*G
         G=0.0
         S=0.0
         SCALE=0.0
         IF(I.GT.M)GO TO 210

         DO 120 K=I,M
  120       SCALE=SCALE+ABS(U(K,I))
         IF(SCALE.EQ.0.0)GO TO 210

         DO 130 K=I,M
            U(K,I)=U(K,I)/SCALE
            S=S+U(K,I)**2
  130    CONTINUE

         F=U(I,I)
         G=-SIGN(SQRT(S),F)
         H=F*G-S
         U(I,I)=F-G
         IF(I.EQ.N)GO TO 190

         DO 150 J=L,N
            S=0.0
            DO 140 K=I,M
  140          S=S+U(K,I)*U(K,J)
               F=S/H
            DO 150 K=I,M
               U(K,J)=U(K,J)+F*U(K,I)
  150    CONTINUE

  190    DO 200 K=I,M
  200       U(K,I)=SCALE*U(K,I)
  210    W(I)=SCALE*G
         G=0.0
         S=0.0
         SCALE=0.0
         IF(I.GT.M.OR.I.EQ.N)GO TO 290

         DO 220 K=L,N
  220       SCALE=SCALE+ABS(U(I,K))

         IF(SCALE.EQ.0.0)GO TO 290

         DO 230 K=L,N
            U(I,K)=U(I,K)/SCALE
            S=S+U(I,K)**2
  230    CONTINUE

         F=U(I,L)
         G=-SIGN(SQRT(S),F)
         H=F*G-S
         U(I,L)=F-G

         DO 240 K=L,N
  240       RV1(K)=U(I,K)/H

         IF(I.EQ.M)GO TO 270

         DO 260 J=L,M
            S=0.0
            DO 250 K=L,N
  250          S=S+U(J,K)*U(I,K)
            DO 260 K=L,N
               U(J,K)=U(J,K)+S*RV1(K)
  260    CONTINUE

  270    DO 280 K=L,N
  280    U(I,K)=SCALE*U(I,K)

  290    ANORM=AMAX1(ANORM,ABS(W(I))+ABS(RV1(I)))
  300 CONTINUE

      IF(.NOT.MATV)GO TO 410

      DO 400 II=1,N
         I=N+1-II
         IF(I.EQ.N)GO TO 390
         IF(G.EQ.0.0)GO TO 360

         DO 320 J=L,N

  320    V(J,I)=(U(I,J)/U(I,L))/G

         DO 350 J=L,N
            S=0.0
            DO 340 K=L,N
  340       S=S+U(I,K)*V(K,J)
            DO 350 K=L,N
            V(K,J)=V(K,J)+S*V(K,I)
  350 CONTINUE

  360    DO 380 J=L,N
            V(I,J)=0.0
            V(J,I)=0.0
  380    CONTINUE

  390    V(I,I)=1.0
         G=RV1(I)
         L=I
  400 CONTINUE

  410 IF(.NOT.MATU)GO TO 510

      MN=N
      IF(M.LT.N)MN=M

      DO 500 II=1,MN
         I=MN+1-II
         L=I+1
         G=W(I)
         IF(I.EQ.N)GO TO 430

         DO 420 J=L,N
  420    U(I,J)=0.0

  430    IF(G.EQ.0.0)GO TO 475
         IF(I.EQ.MN)GO TO 460

         DO 450 J=L,N
            S=0.0
            DO 440 K=L,M
  440       S=S+U(K,I)*U(K,J)

            F=(S/U(I,I))/G

            DO 450 K=I,M
               U(K,J)=U(K,J)+F*U(K,I)
  450    CONTINUE

  460    DO 470 J=I,M
  470    U(J,I)=U(J,I)/G

         GO TO 490

  475    DO 480 J=I,M
  480    U(J,I)=0.0

  490    U(I,I)=U(I,I)+1.0
  500 CONTINUE

  510 DO 700 KK=1,N
         K1=N-KK
         K=K1+1
         ITS=0

  520    DO 530 LL=1,K
            L1=K-LL
            L=L1+1
            IF(ABS(RV1(L))+ANORM.EQ.ANORM)GO TO 565


            IF(ABS(W(L1))+ANORM.EQ.ANORM)GO TO 540
  530    CONTINUE

  540    C=0.0
         S=1.0

         DO 560 I=L,K
            F=S*RV1(I)
            RV1(I)=C*RV1(I)
            IF(ABS(F)+ANORM.EQ.ANORM)GO TO 565
            G=W(I)
            H=SQRT(F*F+G*G)
            W(I)=H
            C=G/H
            S=-F/H
            IF(.NOT.MATU)GO TO 560

            DO 550 J=1,M
               Y=U(J,L1)
               Z=U(J,I)
               U(J,L1)=Y*C+Z*S
               U(J,I)=-Y*S+Z*C
  550       CONTINUE
  560    CONTINUE

  565    Z=W(K)
         IF(L.EQ.K)GO TO 650

         IF(ITS.EQ.30)GO TO 1000
         ITS=ITS+1
         X=W(L)
         Y=W(K1)
         G=RV1(K1)
         H=RV1(K)
         F=((Y-Z)*(Y+Z)+(G-H)*(G+H))/(2.0*H*Y)
         G=SQRT(F*F+1.0)
         F=((X-Z)*(X+Z)+H*(Y/(F+SIGN(G,F))-H))/X

         C=1.0
         S=1.0

         DO 600 I1=L,K1
            I=I1+1
            G=RV1(I)
            Y=W(I)
            H=S*G
            G=C*G
            Z=SQRT(F*F+H*H)
            RV1(I1)=Z
            C=F/Z
            S=H/Z
            F=X*C+G*S
            G=-X*S+G*C
            H=Y*S
            Y=Y*C
            IF(.NOT.MATV)GO TO 575

            DO 570 J=1,N
               X=V(J,I1)
               Z=V(J,I)
               V(J,I1)=X*C+Z*S
               V(J,I)=-X*S+Z*C
  570       CONTINUE

  575       Z=SQRT(F*F+H*H)
            W(I1)=Z

            IF(Z.EQ.0.0)GO TO 580
            C=F/Z
            S=H/Z
  580       F=C*G+S*Y
            X=-S*G+C*Y
            IF(.NOT.MATU)GO TO 600

            DO 590 J=1,M
               Y=U(J,I1)
               Z=U(J,I)
               U(J,I1)=Y*C+Z*S
               U(J,I)=-Y*S+Z*C
  590       CONTINUE
  600    CONTINUE
         RV1(L)=0.0
         RV1(K)=F
         W(K)=X
         GO TO 520

  650    IF(Z.GE.0.0)GO TO 700

         W(K)=-Z
         IF(.NOT.MATV)GO TO 700

         DO 690 J=1,N
  690    V(J,K)=-V(J,K)
  700 CONTINUE
      GO TO 1001

 1000 IERR=K
 1001 RETURN
      END
