program lab3
use Environment
implicit none

integer, parameter :: neqn = 2
REAL(R_)           :: x(neqn), t, tout, relerr, abserr, tfinal, tprint, work(15)
Integer            :: IFLAG, iWork(5)

WRITE(*, '(A)') "RKF45 method:"

  t = 0
  tfinal = 1
  tprint = 0.04
  x(1) = 5
  x(2) = -1
  relerr = 0.0001
  abserr = 0.0
  iFlag = 1
  
do while (t <= tfinal)
call RKF45(F, neqn, x, t, tout, relerr, abserr, iFlag, work, iWork)
write(*, '(a, f9.4, 2(a, f20.6))') "t = ", t, " x1 = ", x(1), " x2 = 
", x(2)

  select case (iFlag)
   case (1, 8)
     exit
   case (2)
     tout = t + tprint
       if (t < tfinal) then
         continue
       end if
   case (4)
     continue
   case (5)
     abserr = 1e-9
     continue
   case (6)
     relerr = 10 * relerr
     iFlag = 2
       continue
   case (7)
     iFlag = 2
       continue
  end select
end do 

contains
  subroutine F (t, x, YP)
     REAL(R_), INTENT(IN)  :: T
     REAL(R_), INTENT(IN)  :: x(2)
     REAL(R_), INTENT(OUT) :: YP(2)
   
   YP(1) = -155.0 * x(1) - 750.0 *x(2) + SIN(1.0 + T)
   YP(2) = x(1) + COS(1.0 - T) + T + 1.0
end subroutine F
end program lab3
