module Source_process
   use Environment
   use Source_IO

   implicit none

contains
   pure recursive subroutine Get_list(List, Amount)
       type(Student),intent(in)        :: List 
       integer(I_), intent(inout)      :: Amount
 
       Amount = Amount + 1
       if (Associated(List%next)) then
          call Get_list(List%next, Amount)
       end if
   end subroutine Get_list



  recursive function Sort_list(List) result(Sorted)

      type(Student), pointer, intent(in)     :: List
      type(Student), pointer                 :: Sorted
 
     character(2), parameter                 :: str = "wi"

     If(Associated(List)) then
     if(List%Surname(:2) == str) then
         allocate(Sorted)
         Sorted%Surname = List%Surname
         Sorted => Sort_list(List%next)
         write(*,*) Sorted%Surname
      end if
   else
      if(Associated(List%next)) then
         Sorted => Sort_list(List%next)
      end if
   end if
!end if

   end function Sort_list

end module Source_process
