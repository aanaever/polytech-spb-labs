program spline_root
    use Environment
    implicit none
    integer, parameter :: N = 6
    real(R_) :: X(N) = [1.0, 1.2, 1.5, 1.6, 1.8, 2.0]
    real(R_) :: Y(N) = [5.000, 6.899, 11.180, 13.133, 18.119, 25.000]
    real(R_) :: B(N), C(N), D(N), sev
    real(R_), external :: SEVAL
    real(R_) ::  mid, left_border, right_border
    real(R_), parameter :: EPS = 0.00001
    

    call SPLINE(N, X, Y, B, C, D)
    write(*, '(A)') 'X'
    write(*, '(6(F9.2))') X

    write(*, '(A)') 'f(x)'
    write(*, '(6(F9.4))') Y

    left_border = 1.0
    right_border = 2.0

    write(*, '(A)') 'Cubic spline values: '
    write(*, '(2A)') 'X values: ', 'Spline values: '

   do
   mid = (left_border + right_border) * 0.5
   sev = SEVAL(N,mid, X, Y, B, C, D)-6.0*mid-3

   write(*, '(2(F11.5))') mid, sev
   
   if(abs(sev) < EPS) then
   exit

   else if (sev < 0 ) then
      left_border = mid
   else 
      right_border = mid
   end if
end do 
 write(*, '(A)') 'Root f(x)=6x + 3 on interval [1,2]: '
write(*, '(1(F11.5))') mid
end program spline_root
