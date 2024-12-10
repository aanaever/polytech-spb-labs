Program lab3_2
use Environment
implicit none

INTEGER, PARAMETER  :: NEQN = 2
REAL(R_), PARAMETER :: h_custom

WRITE(*, '(A)') "Runge-Kutta method (h = 0.02):"
!WRITE(*, '(A)') "Runge-Kutta method (h = 0.01):"

h_custom = 0.02
! h_custom = 0.01

CALL RK()

Contains
 subroutine F (t, x, YP)
   REAL(R_), INTENT(IN) :: t
   REAL(R_), INTENT(IN) :: x(neqn)
   REAL(R_), INTENT(OUT) :: YP(neqn)
 
YP(1) = -155.0 * x(1) - 750.0 *x(2) + SIN(1.0 + T)
YP(2) = x(1) + COS(1.0 - T) + T + 1.0

End subroutine F
 
subroutine RK()
 REAL(R_) :: K1(neqn), K2(neqn)
 REAL(R_):: Zn(neqn), Zn1(neqn), Zn2(neqn)
 REAL(R_) :: h, t
 
real(R_) :: F_val(neqn)
 h = h_custom
 t = 0
 Zn(1) = 5.0
 Zn(2) = -1.0
write (*, '(A, f9.6, 2(A, F9.6))') " t = " , t, " x1 = ", Zn(1), " x2 = ", Zn(2)
do while(t <= 1)
 call f(t, Zn, F_val)
 k1 = h* F_val
 call F(t + (2.0 * h / 3.0), Zn + (2.0 * K1 / 3.0), F_val)
 k2 = h * F_val
 
 Zn1 = Zn + (K1 + 3.0 * K2) / 4.0
 Zn = Zn1
 
 write (*, '(A, f9.6, 2(A, F9.6))') " t = " , t+h, " x1 = ", Zn1(1), " 
x2 = ", Zn1(2) 
 t = t + h
 end do 
 
 end subroutine RK
end program lab3_2
