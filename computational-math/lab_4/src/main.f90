PROGRAM CourseWork
USE Environment
  IMPLICIT NONE 
  
  REAL(R_), dimension(:), allocatable :: t, y, b1, b2,b3, b, c, d
    REAL(R_), dimension(:,:), allocatable :: A1, A2
    REAL(R_):: Q, P, R
    integer, dimension(:), allocatable :: ipvt
    REAL(R_), dimension(:), allocatable :: work
    integer :: i, j, N
    REAL(R_), external  :: SEVAl
    REAL(R_) :: cond, t0, y1, y2, y_spline

    
    N = 8
    allocate(t(N), y(N), b1(N), b2(N),b3(N), b(N), c(N), d(N), A1(N,N), A2(N,N), ipvt(N), work(N))
    t = (/ 1900, 1910, 1920, 1930, 1940, 1950, 1960, 1970 /)
   ! y = (/ 75994575, 91972266, 105710620, 123203000, 131669275, 150697361, 179323175, 203211926 /)
    
   
    !!! +1%
   ! y = (/76754529, 92991989, 106767726, 124435230, 133986967, 152204334, 181116406, 205243045/)
    
    !!! -1%
   ! y = (/75134600, 90952543, 104653513, 121971770, 130352582, 149190387, 177529943, 201180806/)
 
    y = (/79794353, 96570879, 111496151, 129363150, 138252738, 158232229, 188289333, 213372522/)
    Q = integral()
    print *, "Q =", Q
 
    P = calculateP()
    print *, "P=", P
  
    R = minFunc()
    print *, "R=", R
    write(*,*)
    ! Prepare the A matrices
    do j = 1, N
        A1(:,j) = (t - Q)**(j-1)
        A2(:,j) = ((t - P) / R)**(j-1)
    end do

    ! Copy the population data into b vectors
    b1 = y
    b2 = y
    b3 = y

    ! first polynomial
    call DECOMP(N, N, A1, cond, ipvt, work)
    print*, "1 poly COND: ", cond
    call SOLVE(N, N, A1, b1, ipvt)
    write(*,*)
    !second polynomial
    call DECOMP(N, N, A2, cond, ipvt, work)
    print*, "2 poly COND: ", cond 
    call SOLVE(N, N, A2, b2, ipvt)
   write(*,*)
   print "('Year: ',' 1 Poly ', ' 2 Poly ')"
    do i = 1900, 1980, 2
       t0=REAL(i)
       y1 = sum(b1*(t0-Q)**((/(j-1, j=1, N)/)))
       y2 = sum(b2*((t0-P)/R)**((/ (j-1, j=1, N) /)))
       print "(I4, F15.2, F15.2)", i, y1, y2
    end do
    write(*,*)
    print*, "Spline Function: "
      call SPLINE(N, t, b3, b, c, d)
      
      do i = 1900, 1980, 2
         t0 = REAL(i)
         y_spline = SEVAL(n, t0, t, b3, b, c , d)
         print "(I4, F15.2)", i, y_spline
      end do

contains

!using for Q 
real function qFunc(x)
   real, intent(in) :: x
   qFunc = sin(x) / x
end function qFunc

!using for Q
real function integral()
   real :: f, A, B, ABSERR, RELERR, RESULT, ERREST, FLAG
   real, parameter  :: PI = 3.141592653589793
   integer  ::  nofun

   A = PI/4.0
   B = PI/2.0
   ABSERR = 0.0
   RELERR = 1.0E-6
   
   CALL QUANC8(qFunc, A, B, ABSERR, RELERR, RESULT, ERREST, NOFUN, FLAG)
  ! print *, "ERREST=", ERREST
  ! print*, "NOFUN=", NOFUN
  ! print*, "FLAG=", FLAG
    result = result * 3105.659
    integral = result 

 END function integral

! for P
real function pFunc(x)
   real, intent(in) :: x
   pFunc = 1.8 * x**2 - sin(10.0 *x)
end function pFunc

!for P
real function calculateP()
   real :: AX, BX, TOL, P
   real, external :: ZEROIN
   AX = -0.5
   BX = -0.1
   TOL = 1.0E-6

   P = -5785.971 *  ZEROIN(AX, BX, pFunc, TOL)
   calculateP = P
end function calculateP

!R
real function zFunc(z)
   real, intent(in) :: z
   zFunc = (z + 1.0/z)**2 + (2.0 * log(z) + z) * (2.0 * log(z)-z) - 4.0*log(z)/z
end function zFunc

!R
real function minFunc()
   real :: AX, BX, TOL, R
   real, external :: FMIN
   AX = 1.0
   BX = 2.0
   TOL = 1.0E-6

   R = 24.62174* FMIN(AX, BX, zFunc, TOL)

   minFunc = R
end function minFunc   

  
 end program CourseWork
 
